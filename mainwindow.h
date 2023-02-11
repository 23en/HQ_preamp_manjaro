#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSlider>
#include <QAction>
#include <qbluetoothaddress.h>
#include <qbluetoothserviceinfo.h>
#include <qbluetoothserver.h>
#include <QSystemTrayIcon>

#include "libMPSSE_spi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter(QObject* obj,QEvent* event) override;

private slots:
    void UpdateFTDITimerFinished();
    void VolTimerFinished();
    void on_reset_clicked();
    void on_mute_clicked();
    void on_compressor_clicked();
    void on_load_kernel_clicked();
    void UpdateFromFTDI();
    void on_PWM_valueChanged(int arg1);
    void on_symm_clicked();
    void on_boost_valueChanged(int value);
    void on_bypass_compressor_clicked();
    void on_threshold_valueChanged(int value);
    //    void on_Vol1_actionTriggered(int action);
    //    void on_Vol2_actionTriggered(int action);
    //    void on_Vol3_actionTriggered(int action);
    //    void on_Vol4_actionTriggered(int action);
    //    void on_Vol5_actionTriggered(int action);
    //    void on_Vol_bass_actionTriggered(int action);
    //    void on_Vol_medium_actionTriggered(int action);
    //    void on_Vol_aigu_actionTriggered(int action);
    //    void on_Vol_Masta_actionTriggered(int action);
    void one_value_changed();
    //    void on_input_selection_changed(int button);
    void on_hide_show_fft_toggled(bool checked);
    void on_bypass_preamp_toggled(bool checked);
    void clientConnected();
    void clientDisconnected();
    void readSocket();
    void SysTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
private:
    Ui::MainWindow *ui;
    int chosen_device;
    QStringList IDs;
    QTimer timer;
    QTimer timer_update;
    bool thing_changed;
    QBluetoothServer *rfcommServer = nullptr;
    QBluetoothServiceInfo serviceInfo;
    QList<QBluetoothSocket *> clientSockets;
    void startBLServer(const QBluetoothAddress &localAdapter = QBluetoothAddress());
    void stopBLServer();
    FT_STATUS openFTDI();
    QVector<unsigned int> RcvSPIcmdFromVHDL(unsigned int addr, int size);
    void SendSPIcmdToVHDL(BYTE cmd, unsigned int addr, QVector<unsigned int> datas);
    QSystemTrayIcon* sticon;
    QAction* quitAction;
};

#endif // MAINWINDOW_H
