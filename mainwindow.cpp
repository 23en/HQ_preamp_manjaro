#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"

#include <QFile>
#include <QThread>
#include <QMenu>
#include <QScreen>
#include <QKeyEvent>
#include <QDebug>
#include <qbluetoothlocaldevice.h>

static const QLatin1String serviceUuid("e8e10f95-1a70-4b27-9ccf-02010264e9c8");

/* Application specific macro definations */
#define SPI_DEVICE_BUFFER_SIZE		256
#define SPI_WRITE_COMPLETION_RETRY		10
#define START_ADDRESS_EEPROM 	0x00 /*read/write start address inside the EEPROM*/
#define END_ADDRESS_EEPROM		0x10
#define RETRY_COUNT_EEPROM		10	/* number of retries if read/write fails */
#define CHANNEL_TO_OPEN			0	/*0 for first available channel, 1 for next... */
#define SPI_SLAVE_0				0
#define SPI_SLAVE_1				1
#define SPI_SLAVE_2				2
#define DATA_OFFSET				4
#define USE_WRITEREAD			0

/******************************************************************************/
/*								Global variables							  	    */
/******************************************************************************/
static FT_HANDLE ftHandle;
static uint8 buffer[SPI_DEVICE_BUFFER_SIZE] = {0};

#define APP_CHECK_STATUS(exp) {if(exp!=FT_OK){printf("%s:%d:%s(): status(0x%x) \
!= FT_OK\n",__FILE__, __LINE__, __FUNCTION__,exp);exit(1);}else{;}};
#define CHECK_NULL(exp){if(exp==NULL){printf("%s:%d:%s():  NULL expression \
encountered \n",__FILE__, __LINE__, __FUNCTION__);exit(1);}else{;}};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    this->setWindowFlag(Qt::Popup);
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    QMenu *trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(quitAction);

    sticon = new QSystemTrayIcon(this);
    sticon->setIcon(QIcon(":/icons/megaman_petit2.png"));
    sticon->show();
    sticon->setToolTip("Mets du son !!!");
    sticon->setContextMenu(trayIconMenu);
    connect(sticon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(SysTrayIconClicked(QSystemTrayIcon::ActivationReason)));

    chosen_device=-1;

    QList<QBluetoothHostInfo> localAdapters = QBluetoothLocalDevice::allDevices();
    if (localAdapters.count() < 1) {
        qDebug()<<"BL not detected";
    } else {
        QBluetoothLocalDevice adapter(localAdapters.at(0).address());
        adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
        const QBluetoothHostInfo info = localAdapters.at(0);
        startBLServer(info.address());
        qDebug()<<info.name();
        qDebug()<<info.address();
    }

    timer.setInterval(1000);
    timer.setSingleShot(false);
    timer.start();
    connect(&timer,SIGNAL(timeout()),this,SLOT(UpdateFTDITimerFinished()));

    QRect r = QGuiApplication::screens().at(0)->availableGeometry();
    QRect main_rect = this->geometry();
    main_rect.moveTopRight(r.topRight());
    this->move(main_rect.topLeft());
    this->hide();
    //    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(on_input_selection_changed(int)));
    //#ifndef __linux__
    //    system("pause");
    //#endif
}

MainWindow::~MainWindow()
{
    stopBLServer();
    SPI_CloseChannel(ftHandle);
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type()==QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key()==Qt::Key_Plus)
            ui->Vol_Masta->setValue(ui->Vol_Masta->value()+2);
        if(keyEvent->key()==Qt::Key_Minus)
            ui->Vol_Masta->setValue(ui->Vol_Masta->value()-2);
        return true;
    }
    return QObject::eventFilter(obj,event);
}

//    // kernel ALLPASS (pas de filtrage)
//    QVector<unsigned int> datas = QVector<unsigned int>(1023,0);
////    datas.append(0);
////    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA90000,datas);
//    datas[0]=0x3f800000;
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0x9F0000,datas);
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA00000,datas);
////    datas[0]=0;
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA10000,datas);
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA20000,datas);
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA30000,datas);
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA40000,datas);

void MainWindow::VolTimerFinished()
{
    int vol[6];
    //    vol[0] = ui->Vol1->value();
    //    vol[1] = ui->Vol2->value();
    //    vol[2] = ui->Vol3->value();
    //    vol[3] = ui->Vol4->value();
    //    vol[4] = ui->Vol5->value();
    vol[0] = ui->Vol_aigu->value();
    vol[1] = ui->Vol_medium->value();
    vol[2] = ui->Vol_bass->value();
    vol[3] = ui->Vol_medium->value();
    vol[4] = 0;
    vol[5] = ui->Vol_Masta->value();
    if(thing_changed)
    {
        QVector<unsigned int> datas = QVector<unsigned int>();
        for(int i = 0; i < 6; ++i)
            datas.append((unsigned int)vol[i]);
        SendSPIcmdToVHDL(0xBE,0xB00000,datas);
    }
    //    timer_update.start();
    UpdateFromFTDI();
}

void MainWindow::on_reset_clicked()
{
    SendSPIcmdToVHDL(0xBE,0xA90008,QVector<unsigned int>()<<1);
    SendSPIcmdToVHDL(0xBE,0xA90008,QVector<unsigned int>()<<0);
}

void MainWindow::on_mute_clicked()
{
    SendSPIcmdToVHDL(0xDD,0x00,QVector<unsigned int>()<<1);
}

void MainWindow::on_compressor_clicked()
{
    //    QVector<unsigned int> datas = QVector<unsigned int>();
    //    datas.append(ui->Vol1->value());
    //    FTDI_utils::SendSPIcmdToFSPI(chosen_device,0x06,0,QVector<unsigned int>());
    //    FTDI_utils::SendSPIcmdToFSPI(chosen_device,0xD8,0x290000,QVector<unsigned int>());
    //    QThread::msleep(1000);
    //    FTDI_utils::SendSPIcmdToFSPI(chosen_device,0x06,0,QVector<unsigned int>());
    //    FTDI_utils::SendSPIcmdToFSPI(chosen_device,0x02,0x290000,datas);

    SendSPIcmdToVHDL(0xBE,0xA90007,QVector<unsigned int>()<<1); // soft mute

    SendSPIcmdToVHDL(0xBE,0xA90009,QVector<unsigned int>()<<ui->comp_level->currentIndex());
    SendSPIcmdToVHDL(0xBE,0xA90001,QVector<unsigned int>()<<ui->high_th->value());
    SendSPIcmdToVHDL(0xBE,0xA90002,QVector<unsigned int>()<<-ui->high_th->value());
    SendSPIcmdToVHDL(0xBE,0xA90004,QVector<unsigned int>()<<ui->symm->isChecked());
    unsigned int boost = ui->boost->value();
    SendSPIcmdToVHDL(0xBE,0xA9000D,QVector<unsigned int>()<<boost);
    SendSPIcmdToVHDL(0xBE,0xA90003,QVector<unsigned int>()<<ui->bypass_compressor->isChecked());

    SendSPIcmdToVHDL(0xBE,0xA90007,QVector<unsigned int>()<<0); // soft unmute
}

void MainWindow::on_load_kernel_clicked()
{
    unsigned int addr = 0x9F0000;
    SendSPIcmdToVHDL(0xBE,0xA90007,QVector<unsigned int>()<<1); // soft mute
    for(int i = 0; i < 6; ++i)
    {
        QVector<unsigned int> coeffs;
        QFile file("/home/ben/foo"+ QString::number(i+1) + ".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        while (!file.atEnd()) {
            QString line = file.readLine().right(9);
            coeffs << line.toUInt(NULL,16);
        }
        file.close();
        SendSPIcmdToVHDL(0xBE,addr,coeffs); // voie gauche
        addr += 0x010000;
    }
    SendSPIcmdToVHDL(0xBE,0xA90007,QVector<unsigned int>()<<0); // soft unmute
}

FT_STATUS MainWindow::openFTDI()
{
    ////////////////////////////////////
    FT_STATUS status = FT_OK;
    FT_DEVICE_LIST_INFO_NODE devList = {0};
    ChannelConfig channelConf = {0};
    uint8 address = 0;
    uint32 channels = 0;
    uint16 data = 0;
    uint8 i = 0;
    uint8 latency = 255;
    channelConf.ClockRate = 500000;
    channelConf.LatencyTimer = latency;
    channelConf.configOptions = SPI_CONFIG_OPTION_MODE2 | SPI_CONFIG_OPTION_CS_DBUS3 | SPI_CONFIG_OPTION_CS_ACTIVELOW;
    channelConf.Pin = 0x00000000;/*FinalVal-FinalDir-InitVal-InitDir (for dir 0=in, 1=out)*/
    /////////////////////////
    /// \brief localAdapters
    /////////////////////////////////////////////
    status = SPI_GetNumChannels(&channels);
    APP_CHECK_STATUS(status);
    printf("Number of available SPI channels = %d\n",(int)channels);

    if(channels>0)
    {
        for(i=0;i<channels;i++)
        {
            status = SPI_GetChannelInfo(i,&devList);
            APP_CHECK_STATUS(status);
            printf("Information on channel number %d:\n",i);
            /* print the dev info */
            printf("Flags=0x%x\n",devList.Flags);
            printf("Type=0x%x\n",devList.Type);
            printf("ID=0x%x\n",devList.ID);
            printf("LocId=0x%x\n",devList.LocId);
            printf("SerialNumber=%s\n",devList.SerialNumber);
            printf("Description=%s\n",devList.Description);
            //printf("ftHandle=0x%x\n",(unsigned int)devList.ftHandle);/*is 0 unless open*/
        }

        /* Open the first available channel */
        status = SPI_OpenChannel(CHANNEL_TO_OPEN,&ftHandle);
        APP_CHECK_STATUS(status);
        //printf("\nhandle=0x%x status=0x%x\n",(unsigned int)ftHandle,status);
        status = SPI_InitChannel(ftHandle,&channelConf);
        APP_CHECK_STATUS(status);
    }
    return status;
}

QVector<unsigned int> MainWindow::RcvSPIcmdFromVHDL(unsigned int addr, int size)
{
    uint32 sizeToTransfer = 0;
    uint32 sizeTransfered;
    FT_STATUS status;

    buffer[0] = 0xBB;
    buffer[1] = (addr>>16) & 0xFF;
    buffer[2] = (addr>>8)  & 0xFF;
    buffer[3] = addr       & 0xFF;

    /* CS_High + Write command + Address */
    sizeToTransfer=4;
    sizeTransfered=0;
    status = SPI_Write(ftHandle, buffer, sizeToTransfer, &sizeTransfered,
                       SPI_TRANSFER_OPTIONS_SIZE_IN_BYTES|
                       SPI_TRANSFER_OPTIONS_CHIPSELECT_ENABLE);
    APP_CHECK_STATUS(status);

    //    if(addr < 0x800000) // pourquoi j'ai fait ca ?
    //    {
    //        FT_Write(ftHandle[device_idx], serial_value, bits_to_write, &bits_written);
    //        bits_to_write=0;
    //    }
    sizeToTransfer = size*4;
    status = SPI_Read(ftHandle, buffer, sizeToTransfer, &sizeTransfered,
                      SPI_TRANSFER_OPTIONS_SIZE_IN_BYTES|
                      SPI_TRANSFER_OPTIONS_CHIPSELECT_DISABLE);
    APP_CHECK_STATUS(status);
    QVector<unsigned int> out;
    out.clear();
    for(int i = 0; i < size; ++i)
    {
        out << (buffer[i*4+0]<<24) + (buffer[i*4+1]<<16) + (buffer[i*4+2]<<8) + (buffer[i*4+3]);
    }
    return out;
}

void MainWindow::SendSPIcmdToVHDL(BYTE cmd, unsigned int addr, QVector<unsigned int> datas)
{
    uint32 sizeToTransfer = 0;
    uint32 sizeTransfered;
    FT_STATUS status;
    int bits_to_write = 4;

    buffer[0] = cmd;
    buffer[1] = (addr>>16) & 0xFF;
    buffer[2] = (addr>>8)  & 0xFF;
    buffer[3] = addr       & 0xFF;
    for(int i = 0; i < datas.size(); ++i)
    {
        // decoupe mots de 32bits en BYTES
        buffer[bits_to_write++] = (datas.at(i)>>24) & 0xFF;
        buffer[bits_to_write++] = (datas.at(i)>>16) & 0xFF;
        buffer[bits_to_write++] = (datas.at(i)>>8) & 0xFF;
        buffer[bits_to_write++] = (datas.at(i)>>0) & 0xFF;
    }

    /* CS_High + Write command + Address */
    sizeToTransfer=datas.size()*4+4;
    sizeTransfered=0;
    status = SPI_Write(ftHandle, buffer, sizeToTransfer, &sizeTransfered,
                       SPI_TRANSFER_OPTIONS_SIZE_IN_BYTES|
                       SPI_TRANSFER_OPTIONS_CHIPSELECT_ENABLE|
                       SPI_TRANSFER_OPTIONS_CHIPSELECT_DISABLE);
    APP_CHECK_STATUS(status);
}

void MainWindow::UpdateFromFTDI()
{
    disconnect(ui->vol_indic_masta,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    disconnect(ui->Vol_aigu,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    disconnect(ui->Vol_medium,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    disconnect(ui->Vol_bass,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    //    disconnect(ui->vol_indic4,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    //    disconnect(ui->vol_indic5,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    QVector<unsigned int> read_bytes = RcvSPIcmdFromVHDL(0xB00000,6);
    unsigned int master_vol = read_bytes.at(5)&0xFF;
    ui->Vol1->setValue((read_bytes.at(0)&0xFF)+master_vol);
    ui->Vol2->setValue((read_bytes.at(1)&0xFF)+master_vol);
    ui->Vol3->setValue((read_bytes.at(2)&0xFF)+master_vol);
    ui->Vol4->setValue((read_bytes.at(3)&0xFF)+master_vol);
    ui->Vol5->setValue((read_bytes.at(4)&0xFF)+master_vol);
    ui->Vol_Masta->setValue(master_vol);
    ui->Vol_bass->setValue(read_bytes.at(2)&0xFF);
    ui->Vol_medium->setValue(read_bytes.at(1)&0xFF);
    ui->Vol_aigu->setValue(read_bytes.at(0)&0xFF);
    ui->bypass_preamp->setChecked((bool)RcvSPIcmdFromVHDL(0xA9000E,1).at(0));
    ui->PWM->setValue(RcvSPIcmdFromVHDL(0xA9000C,1).at(0));
    read_bytes = RcvSPIcmdFromVHDL(0xA9000F,1);
    ui->in_aux->setChecked((bool)read_bytes.at(0));
    //    if(FTDI_utils::GetStatus(chosen_device)>1)
    //    {
    //        FTDI_utils::CloseFTDI(chosen_device);
    //        disconnect(&timer,SIGNAL(timeout()),this,SLOT(VolTimerFinished()));
    //        disconnect(&timer_update,SIGNAL(timeout()),this,SLOT(UpdateFromFTDI()));
    //        timer.setSingleShot(false);
    //        timer.start();
    //        connect(&timer,SIGNAL(timeout()),this,SLOT(UpdateFTDITimerFinished()));
    //    }
    //    else
    //    {
    read_bytes = RcvSPIcmdFromVHDL(0xB10000,2);
    ui->reg0->setValue(read_bytes.at(0));
    ui->reg1->setValue(read_bytes.at(1));
    connect(ui->vol_indic_masta,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    connect(ui->Vol_aigu,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    connect(ui->Vol_medium,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    connect(ui->Vol_bass,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    //        connect(ui->vol_indic4,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    //        connect(ui->vol_indic5,SIGNAL(valueChanged(int)),this,SLOT(one_value_changed()));
    //    }
}

void MainWindow::on_PWM_valueChanged(int arg1)
{
    SendSPIcmdToVHDL(0xBE,0xA9000C,QVector<unsigned int>()<<arg1);
}

void MainWindow::on_symm_clicked()
{
    SendSPIcmdToVHDL(0xBE,0xA90004,QVector<unsigned int>()<<ui->symm->isChecked());
}

void MainWindow::on_boost_valueChanged(int value)
{
    SendSPIcmdToVHDL(0xBE,0xA9000D,QVector<unsigned int>()<<value);
}

void MainWindow::on_bypass_compressor_clicked()
{
    SendSPIcmdToVHDL(0xBE,0xA90003,QVector<unsigned int>()<<ui->bypass_compressor->isChecked());
}

void MainWindow::on_threshold_valueChanged(int value)
{
    SendSPIcmdToVHDL(0xBE,0xA90001,QVector<unsigned int>()<<value);
    SendSPIcmdToVHDL(0xBE,0xA90002,QVector<unsigned int>()<<-value);
}
#define BUF_SIZE 0x10

#define MAX_DEVICES		5
void MainWindow::UpdateFTDITimerFinished()
{
    qDebug()<<"First timer finished";
    FT_STATUS status = openFTDI();
    qDebug()<<"openFTDI finished";

    if(status!=FT_OK)
        return;
//    FTDI_utils::SendMPSSE_GPIO(chosen_device,FTDI_BUS::ADBUS,0xC9,0xFB);
//    FTDI_utils::SendMPSSE_GPIO(chosen_device,FTDI_BUS::ACBUS,0x00,0x00);
    qDebug()<<"ftdi open status=OK";

    timer.stop();
    disconnect(&timer,SIGNAL(timeout()),this,SLOT(UpdateFTDITimerFinished()));
    timer.setInterval(100);
    timer.setSingleShot(true);
    connect(&timer,SIGNAL(timeout()),this,SLOT(VolTimerFinished()));

    qDebug()<<"First read from preamp";
    UpdateFromFTDI();
    qDebug()<<"First read from preamp finished";
    SendSPIcmdToVHDL(0xBE,0xA9000A,QVector<unsigned int>()<<1);
    SendSPIcmdToVHDL(0xBE,0xA9000B,QVector<unsigned int>()<<1);
    SendSPIcmdToVHDL(0xBE,0xA9000C,QVector<unsigned int>()<<ui->PWM->value());

    // inutile tant que pas de bouton
    timer_update.setInterval(200);
    timer_update.setSingleShot(false);
    timer_update.start();
    connect(&timer_update,SIGNAL(timeout()),this,SLOT(UpdateFromFTDI()));
}

void MainWindow::one_value_changed()
{
    thing_changed = true;
    timer_update.stop();
    timer.start();
}

//void MainWindow::on_input_selection_changed(int button)
//{
//    FTDI_utils::SendSPIcmdToVHDL(chosen_device,0xBE,0xA9000F,QVector<unsigned int>()<<(unsigned int)button);
//}

void MainWindow::on_hide_show_fft_toggled(bool checked)
{
    SendSPIcmdToVHDL(0xBE,0xA90005,QVector<unsigned int>()<<(unsigned int)checked);
}

void MainWindow::on_bypass_preamp_toggled(bool checked)
{
    SendSPIcmdToVHDL(0xBE,0xA9000E,QVector<unsigned int>()<<(unsigned int)checked);
}

void MainWindow::clientConnected()
{
    QBluetoothSocket *socket = rfcommServer->nextPendingConnection();
    if (!socket)
        return;
    ui->blue_devices->addItem(socket->peerName());
    socket->write(QString::number(ui->Vol_Masta->value()).toLatin1());
    connect(socket, &QBluetoothSocket::readyRead, this, &MainWindow::readSocket);
    connect(socket, &QBluetoothSocket::disconnected, this, QOverload<>::of(&MainWindow::clientDisconnected));
    clientSockets.append(socket);
}

void MainWindow::clientDisconnected()
{
    QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
    if (!socket)
        return;
    ui->blue_devices->clear();
    clientSockets.removeOne(socket);
    for(int i=0;i<clientSockets.size();++i)
        if(clientSockets.at(i)->peerName()!="")
            ui->blue_devices->addItem(clientSockets.at(i)->peerName());
    socket->deleteLater();
}

void MainWindow::readSocket()
{
    QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
    if (!socket)
        return;
    //  while (socket->canReadLine()) {
    QByteArray line = socket->readLine().trimmed();
    qDebug()<<QString::fromUtf8(line.constData(), line.length());
    if(QString::fromUtf8(line.constData(), line.length())=="+")
        ui->Vol_Masta->setValue(ui->Vol_Masta->value()+1);
    else if(QString::fromUtf8(line.constData(), line.length())=="-")
        ui->Vol_Masta->setValue(ui->Vol_Masta->value()-1);
    socket->write(QString::number(ui->Vol_Masta->value()).toLatin1());
    //    }
}

void MainWindow::SysTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason!=QSystemTrayIcon::Trigger)
        return;
    this->setHidden(!this->isHidden());
}

void MainWindow::startBLServer(const QBluetoothAddress &localAdapter)
{
    if (rfcommServer)
        return;

    //! [Create the server]
    rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);
    connect(rfcommServer, &QBluetoothServer::newConnection,
            this, QOverload<>::of(&MainWindow::clientConnected));
    bool result = rfcommServer->listen(localAdapter);
    if (!result) {
        qWarning() << "Cannot bind chat server to" << localAdapter.toString();
        return;
    }
    //! [Create the server]

    //serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceRecordHandle, (uint)0x00010010);

    QBluetoothServiceInfo::Sequence profileSequence;
    QBluetoothServiceInfo::Sequence classId;
    classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));
    classId << QVariant::fromValue(quint16(0x100));
    profileSequence.append(QVariant::fromValue(classId));
    serviceInfo.setAttribute(QBluetoothServiceInfo::BluetoothProfileDescriptorList,
                             profileSequence);

    classId.clear();
    classId << QVariant::fromValue(QBluetoothUuid(serviceUuid));
    classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));

    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceClassIds, classId);

    //! [Service name, description and provider]
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceName, tr("HQ Volume"));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceDescription,
                             tr("Fais péter le son !!!"));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceProvider, tr("Ben&Co"));
    //! [Service name, description and provider]

    //! [Service UUID set]
    serviceInfo.setServiceUuid(QBluetoothUuid(serviceUuid));
    //! [Service UUID set]

    //! [Service Discoverability]
    QBluetoothServiceInfo::Sequence publicBrowse;
    publicBrowse << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::PublicBrowseGroup));
    serviceInfo.setAttribute(QBluetoothServiceInfo::BrowseGroupList,
                             publicBrowse);
    //! [Service Discoverability]

    //! [Protocol descriptor list]
    QBluetoothServiceInfo::Sequence protocolDescriptorList;
    QBluetoothServiceInfo::Sequence protocol;
    protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::L2cap));
    protocolDescriptorList.append(QVariant::fromValue(protocol));
    protocol.clear();
    protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::Rfcomm))
             << QVariant::fromValue(quint8(rfcommServer->serverPort()));
    protocolDescriptorList.append(QVariant::fromValue(protocol));
    serviceInfo.setAttribute(QBluetoothServiceInfo::ProtocolDescriptorList,
                             protocolDescriptorList);
    //! [Protocol descriptor list]

    //! [Register service]
    serviceInfo.registerService(localAdapter);
    //! [Register service]
}

void MainWindow::stopBLServer()
{
    // Unregister service
    serviceInfo.unregisterService();

    // Close sockets
    qDeleteAll(clientSockets);

    // Close server
    if(rfcommServer)
        delete rfcommServer;
    rfcommServer = nullptr;
}
