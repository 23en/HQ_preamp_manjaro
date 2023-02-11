/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QSpinBox *vol_indic_masta;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_17;
    QSlider *Vol_Masta;
    QSpacerItem *horizontalSpacer_16;
    QCheckBox *advanced;
    QGroupBox *groupAdvance;
    QVBoxLayout *verticalLayout_15;
    QCheckBox *hide_show_fft;
    QCheckBox *bypass_preamp;
    QFrame *line;
    QRadioButton *in_hdmi;
    QRadioButton *in_aux;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_4;
    QSpinBox *PWM;
    QPushButton *reset;
    QPushButton *mute;
    QPushButton *load_kernel;
    QGroupBox *group_display;
    QVBoxLayout *verticalLayout_14;
    QCheckBox *checkBox_channels;
    QCheckBox *checkBox_equal;
    QCheckBox *checkBox_compressor;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *channels;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpinBox *vol_indic1;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QSlider *Vol1;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *vol_indic2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QSlider *Vol2;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *vol_indic3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QSlider *Vol3;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *vol_indic4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QSlider *Vol4;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_5;
    QSpinBox *vol_indic5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_15;
    QSlider *Vol5;
    QSpacerItem *horizontalSpacer_14;
    QGroupBox *equal;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_11;
    QSpinBox *vol_indicbass;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_19;
    QSlider *Vol_bass;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label;
    QVBoxLayout *verticalLayout_12;
    QSpinBox *vol_indicmed;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_21;
    QSlider *Vol_medium;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_13;
    QSpinBox *vol_indicaigu;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_23;
    QSlider *Vol_aigu;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_17;
    QListWidget *blue_devices;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupcompressor;
    QVBoxLayout *verticalLayout_7;
    QPushButton *compressor;
    QComboBox *comp_level;
    QSpinBox *high_th;
    QCheckBox *bypass_compressor;
    QCheckBox *symm;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_13;
    QSlider *threshold;
    QSpacerItem *horizontalSpacer_2;
    QSlider *boost;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *reg0;
    QSpinBox *reg1;
    QSpacerItem *verticalSpacer_3;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(645, 739);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setToolTipDuration(3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_14 = new QHBoxLayout(centralWidget);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(150, 16777215));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        vol_indic_masta = new QSpinBox(groupBox);
        vol_indic_masta->setObjectName(QString::fromUtf8("vol_indic_masta"));
        vol_indic_masta->setMaximum(255);

        verticalLayout_6->addWidget(vol_indic_masta);


        verticalLayout_8->addLayout(verticalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_17);

        Vol_Masta = new QSlider(groupBox);
        Vol_Masta->setObjectName(QString::fromUtf8("Vol_Masta"));
        Vol_Masta->setMinimumSize(QSize(0, 200));
        Vol_Masta->setMaximumSize(QSize(16777215, 200));
        Vol_Masta->setMaximum(200);
        Vol_Masta->setOrientation(Qt::Vertical);

        horizontalLayout_9->addWidget(Vol_Masta);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_16);


        verticalLayout_8->addLayout(horizontalLayout_9);

        advanced = new QCheckBox(groupBox);
        advanced->setObjectName(QString::fromUtf8("advanced"));

        verticalLayout_8->addWidget(advanced);


        verticalLayout_16->addWidget(groupBox);

        groupAdvance = new QGroupBox(centralWidget);
        groupAdvance->setObjectName(QString::fromUtf8("groupAdvance"));
        groupAdvance->setEnabled(false);
        groupAdvance->setMaximumSize(QSize(150, 16777215));
        verticalLayout_15 = new QVBoxLayout(groupAdvance);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        hide_show_fft = new QCheckBox(groupAdvance);
        hide_show_fft->setObjectName(QString::fromUtf8("hide_show_fft"));

        verticalLayout_15->addWidget(hide_show_fft);

        bypass_preamp = new QCheckBox(groupAdvance);
        bypass_preamp->setObjectName(QString::fromUtf8("bypass_preamp"));

        verticalLayout_15->addWidget(bypass_preamp);

        line = new QFrame(groupAdvance);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_15->addWidget(line);

        in_hdmi = new QRadioButton(groupAdvance);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(in_hdmi);
        in_hdmi->setObjectName(QString::fromUtf8("in_hdmi"));
        in_hdmi->setChecked(true);

        verticalLayout_15->addWidget(in_hdmi);

        in_aux = new QRadioButton(groupAdvance);
        buttonGroup->addButton(in_aux);
        in_aux->setObjectName(QString::fromUtf8("in_aux"));

        verticalLayout_15->addWidget(in_aux);

        line_2 = new QFrame(groupAdvance);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_15->addWidget(line_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_4 = new QLabel(groupAdvance);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_4);

        PWM = new QSpinBox(groupAdvance);
        PWM->setObjectName(QString::fromUtf8("PWM"));
        PWM->setMaximum(127);
        PWM->setValue(10);

        horizontalLayout_13->addWidget(PWM);


        verticalLayout_15->addLayout(horizontalLayout_13);

        reset = new QPushButton(groupAdvance);
        reset->setObjectName(QString::fromUtf8("reset"));

        verticalLayout_15->addWidget(reset);

        mute = new QPushButton(groupAdvance);
        mute->setObjectName(QString::fromUtf8("mute"));
        mute->setCheckable(true);
        mute->setChecked(false);

        verticalLayout_15->addWidget(mute);

        load_kernel = new QPushButton(groupAdvance);
        load_kernel->setObjectName(QString::fromUtf8("load_kernel"));

        verticalLayout_15->addWidget(load_kernel);


        verticalLayout_16->addWidget(groupAdvance);

        group_display = new QGroupBox(centralWidget);
        group_display->setObjectName(QString::fromUtf8("group_display"));
        group_display->setEnabled(false);
        group_display->setMaximumSize(QSize(150, 16777215));
        verticalLayout_14 = new QVBoxLayout(group_display);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        checkBox_channels = new QCheckBox(group_display);
        checkBox_channels->setObjectName(QString::fromUtf8("checkBox_channels"));

        verticalLayout_14->addWidget(checkBox_channels);

        checkBox_equal = new QCheckBox(group_display);
        checkBox_equal->setObjectName(QString::fromUtf8("checkBox_equal"));

        verticalLayout_14->addWidget(checkBox_equal);

        checkBox_compressor = new QCheckBox(group_display);
        checkBox_compressor->setObjectName(QString::fromUtf8("checkBox_compressor"));
        checkBox_compressor->setChecked(false);

        verticalLayout_14->addWidget(checkBox_compressor);


        verticalLayout_16->addWidget(group_display);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer);


        horizontalLayout_14->addLayout(verticalLayout_16);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetNoConstraint);
        channels = new QGroupBox(centralWidget);
        channels->setObjectName(QString::fromUtf8("channels"));
        channels->setEnabled(false);
        channels->setMinimumSize(QSize(0, 0));
        channels->setMaximumSize(QSize(280, 243));
        horizontalLayout_2 = new QHBoxLayout(channels);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vol_indic1 = new QSpinBox(channels);
        vol_indic1->setObjectName(QString::fromUtf8("vol_indic1"));
        vol_indic1->setEnabled(false);
        vol_indic1->setReadOnly(false);
        vol_indic1->setMaximum(255);
        vol_indic1->setValue(15);

        verticalLayout->addWidget(vol_indic1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        Vol1 = new QSlider(channels);
        Vol1->setObjectName(QString::fromUtf8("Vol1"));
        Vol1->setMinimumSize(QSize(0, 180));
        Vol1->setMaximum(255);
        Vol1->setValue(0);
        Vol1->setOrientation(Qt::Vertical);
        Vol1->setInvertedAppearance(false);

        horizontalLayout_4->addWidget(Vol1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        vol_indic2 = new QSpinBox(channels);
        vol_indic2->setObjectName(QString::fromUtf8("vol_indic2"));
        vol_indic2->setMaximum(255);

        verticalLayout_2->addWidget(vol_indic2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        Vol2 = new QSlider(channels);
        Vol2->setObjectName(QString::fromUtf8("Vol2"));
        Vol2->setMaximum(255);
        Vol2->setValue(15);
        Vol2->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(Vol2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        vol_indic3 = new QSpinBox(channels);
        vol_indic3->setObjectName(QString::fromUtf8("vol_indic3"));
        vol_indic3->setMaximum(255);

        verticalLayout_3->addWidget(vol_indic3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        Vol3 = new QSlider(channels);
        Vol3->setObjectName(QString::fromUtf8("Vol3"));
        Vol3->setMaximum(255);
        Vol3->setValue(6);
        Vol3->setOrientation(Qt::Vertical);

        horizontalLayout_6->addWidget(Vol3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        vol_indic4 = new QSpinBox(channels);
        vol_indic4->setObjectName(QString::fromUtf8("vol_indic4"));
        vol_indic4->setMaximum(255);

        verticalLayout_4->addWidget(vol_indic4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        Vol4 = new QSlider(channels);
        Vol4->setObjectName(QString::fromUtf8("Vol4"));
        Vol4->setMaximum(255);
        Vol4->setValue(15);
        Vol4->setOrientation(Qt::Vertical);
        Vol4->setInvertedAppearance(false);

        horizontalLayout_7->addWidget(Vol4);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        vol_indic5 = new QSpinBox(channels);
        vol_indic5->setObjectName(QString::fromUtf8("vol_indic5"));
        vol_indic5->setMaximum(255);

        verticalLayout_5->addWidget(vol_indic5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);

        Vol5 = new QSlider(channels);
        Vol5->setObjectName(QString::fromUtf8("Vol5"));
        Vol5->setToolTipDuration(0);
        Vol5->setMaximum(255);
        Vol5->setValue(0);
        Vol5->setOrientation(Qt::Vertical);
        Vol5->setInvertedAppearance(false);

        horizontalLayout_8->addWidget(Vol5);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_9->addWidget(channels);

        equal = new QGroupBox(centralWidget);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setEnabled(false);
        equal->setMaximumSize(QSize(280, 16777215));
        horizontalLayout_3 = new QHBoxLayout(equal);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        vol_indicbass = new QSpinBox(equal);
        vol_indicbass->setObjectName(QString::fromUtf8("vol_indicbass"));
        vol_indicbass->setMaximum(31);

        verticalLayout_11->addWidget(vol_indicbass);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_19);

        Vol_bass = new QSlider(equal);
        Vol_bass->setObjectName(QString::fromUtf8("Vol_bass"));
        Vol_bass->setMinimumSize(QSize(0, 180));
        Vol_bass->setMaximum(31);
        Vol_bass->setPageStep(1);
        Vol_bass->setValue(0);
        Vol_bass->setOrientation(Qt::Vertical);

        horizontalLayout_10->addWidget(Vol_bass);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_18);


        verticalLayout_11->addLayout(horizontalLayout_10);

        label = new QLabel(equal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        vol_indicmed = new QSpinBox(equal);
        vol_indicmed->setObjectName(QString::fromUtf8("vol_indicmed"));
        vol_indicmed->setMaximum(31);

        verticalLayout_12->addWidget(vol_indicmed);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_21);

        Vol_medium = new QSlider(equal);
        Vol_medium->setObjectName(QString::fromUtf8("Vol_medium"));
        Vol_medium->setMaximum(31);
        Vol_medium->setPageStep(1);
        Vol_medium->setValue(0);
        Vol_medium->setOrientation(Qt::Vertical);
        Vol_medium->setInvertedAppearance(false);

        horizontalLayout_11->addWidget(Vol_medium);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_20);


        verticalLayout_12->addLayout(horizontalLayout_11);

        label_2 = new QLabel(equal);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_2);


        horizontalLayout_3->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        vol_indicaigu = new QSpinBox(equal);
        vol_indicaigu->setObjectName(QString::fromUtf8("vol_indicaigu"));
        vol_indicaigu->setMaximum(31);

        verticalLayout_13->addWidget(vol_indicaigu);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_23);

        Vol_aigu = new QSlider(equal);
        Vol_aigu->setObjectName(QString::fromUtf8("Vol_aigu"));
        Vol_aigu->setMaximum(31);
        Vol_aigu->setPageStep(1);
        Vol_aigu->setValue(0);
        Vol_aigu->setOrientation(Qt::Vertical);
        Vol_aigu->setInvertedAppearance(false);

        horizontalLayout_12->addWidget(Vol_aigu);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_22);


        verticalLayout_13->addLayout(horizontalLayout_12);

        label_3 = new QLabel(equal);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_3);


        horizontalLayout_3->addLayout(verticalLayout_13);


        verticalLayout_9->addWidget(equal);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_17 = new QVBoxLayout(groupBox_2);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        blue_devices = new QListWidget(groupBox_2);
        blue_devices->setObjectName(QString::fromUtf8("blue_devices"));

        verticalLayout_17->addWidget(blue_devices);


        verticalLayout_9->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(306, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        horizontalLayout_14->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupcompressor = new QGroupBox(centralWidget);
        groupcompressor->setObjectName(QString::fromUtf8("groupcompressor"));
        groupcompressor->setEnabled(false);
        groupcompressor->setMaximumSize(QSize(280, 16777215));
        verticalLayout_7 = new QVBoxLayout(groupcompressor);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        compressor = new QPushButton(groupcompressor);
        compressor->setObjectName(QString::fromUtf8("compressor"));

        verticalLayout_7->addWidget(compressor);

        comp_level = new QComboBox(groupcompressor);
        comp_level->addItem(QString());
        comp_level->addItem(QString());
        comp_level->addItem(QString());
        comp_level->addItem(QString());
        comp_level->setObjectName(QString::fromUtf8("comp_level"));

        verticalLayout_7->addWidget(comp_level);

        high_th = new QSpinBox(groupcompressor);
        high_th->setObjectName(QString::fromUtf8("high_th"));
        high_th->setEnabled(false);
        high_th->setReadOnly(true);
        high_th->setMaximum(8388607);
        high_th->setSingleStep(1000);
        high_th->setValue(8388607);

        verticalLayout_7->addWidget(high_th);

        bypass_compressor = new QCheckBox(groupcompressor);
        bypass_compressor->setObjectName(QString::fromUtf8("bypass_compressor"));
        bypass_compressor->setChecked(true);

        verticalLayout_7->addWidget(bypass_compressor);

        symm = new QCheckBox(groupcompressor);
        symm->setObjectName(QString::fromUtf8("symm"));

        verticalLayout_7->addWidget(symm);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        threshold = new QSlider(groupcompressor);
        threshold->setObjectName(QString::fromUtf8("threshold"));
        threshold->setMinimumSize(QSize(0, 180));
        threshold->setMaximum(500000);
        threshold->setSingleStep(10000);
        threshold->setValue(500000);
        threshold->setSliderPosition(500000);
        threshold->setOrientation(Qt::Vertical);
        threshold->setInvertedAppearance(false);

        horizontalLayout->addWidget(threshold);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        boost = new QSlider(groupcompressor);
        boost->setObjectName(QString::fromUtf8("boost"));
        boost->setMaximum(11);
        boost->setPageStep(1);
        boost->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(boost);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout_10->addWidget(groupcompressor);

        reg0 = new QSpinBox(centralWidget);
        reg0->setObjectName(QString::fromUtf8("reg0"));
        reg0->setReadOnly(true);
        reg0->setButtonSymbols(QAbstractSpinBox::NoButtons);
        reg0->setMaximum(999999999);

        verticalLayout_10->addWidget(reg0);

        reg1 = new QSpinBox(centralWidget);
        reg1->setObjectName(QString::fromUtf8("reg1"));
        reg1->setReadOnly(true);
        reg1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        reg1->setMaximum(999999999);

        verticalLayout_10->addWidget(reg1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);


        horizontalLayout_14->addLayout(verticalLayout_10);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(Vol1, SIGNAL(valueChanged(int)), vol_indic1, SLOT(setValue(int)));
        QObject::connect(threshold, SIGNAL(valueChanged(int)), high_th, SLOT(setValue(int)));
        QObject::connect(Vol2, SIGNAL(valueChanged(int)), vol_indic2, SLOT(setValue(int)));
        QObject::connect(Vol3, SIGNAL(valueChanged(int)), vol_indic3, SLOT(setValue(int)));
        QObject::connect(Vol4, SIGNAL(valueChanged(int)), vol_indic4, SLOT(setValue(int)));
        QObject::connect(Vol5, SIGNAL(valueChanged(int)), vol_indic5, SLOT(setValue(int)));
        QObject::connect(Vol_Masta, SIGNAL(valueChanged(int)), vol_indic_masta, SLOT(setValue(int)));
        QObject::connect(Vol_bass, SIGNAL(valueChanged(int)), vol_indicbass, SLOT(setValue(int)));
        QObject::connect(Vol_medium, SIGNAL(valueChanged(int)), vol_indicmed, SLOT(setValue(int)));
        QObject::connect(Vol_aigu, SIGNAL(valueChanged(int)), vol_indicaigu, SLOT(setValue(int)));
        QObject::connect(vol_indic_masta, SIGNAL(valueChanged(int)), Vol_Masta, SLOT(setValue(int)));
        QObject::connect(vol_indic1, SIGNAL(valueChanged(int)), Vol1, SLOT(setValue(int)));
        QObject::connect(vol_indic2, SIGNAL(valueChanged(int)), Vol2, SLOT(setValue(int)));
        QObject::connect(vol_indic3, SIGNAL(valueChanged(int)), Vol3, SLOT(setValue(int)));
        QObject::connect(vol_indic4, SIGNAL(valueChanged(int)), Vol4, SLOT(setValue(int)));
        QObject::connect(vol_indic5, SIGNAL(valueChanged(int)), Vol5, SLOT(setValue(int)));
        QObject::connect(vol_indicbass, SIGNAL(valueChanged(int)), Vol_bass, SLOT(setValue(int)));
        QObject::connect(vol_indicmed, SIGNAL(valueChanged(int)), Vol_medium, SLOT(setValue(int)));
        QObject::connect(vol_indicaigu, SIGNAL(valueChanged(int)), Vol_aigu, SLOT(setValue(int)));
        QObject::connect(checkBox_channels, SIGNAL(toggled(bool)), channels, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_equal, SIGNAL(toggled(bool)), equal, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_compressor, SIGNAL(toggled(bool)), groupcompressor, SLOT(setEnabled(bool)));
        QObject::connect(advanced, SIGNAL(toggled(bool)), groupAdvance, SLOT(setEnabled(bool)));
        QObject::connect(advanced, SIGNAL(toggled(bool)), group_display, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pr\303\251amp", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "G\303\251n\303\251ral", nullptr));
        advanced->setText(QCoreApplication::translate("MainWindow", "R\303\251g. Avanc\303\251s", nullptr));
        groupAdvance->setTitle(QCoreApplication::translate("MainWindow", "R\303\251glages avanc\303\251s", nullptr));
        hide_show_fft->setText(QCoreApplication::translate("MainWindow", "Show FFT", nullptr));
        bypass_preamp->setText(QCoreApplication::translate("MainWindow", "Direct HDMI", nullptr));
        in_hdmi->setText(QCoreApplication::translate("MainWindow", "HDMI", nullptr));
        in_aux->setText(QCoreApplication::translate("MainWindow", "Aux", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ventilo", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        mute->setText(QCoreApplication::translate("MainWindow", "Mute", nullptr));
        load_kernel->setText(QCoreApplication::translate("MainWindow", "Load Kernel", nullptr));
        group_display->setTitle(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        checkBox_channels->setText(QCoreApplication::translate("MainWindow", "Channels", nullptr));
        checkBox_equal->setText(QCoreApplication::translate("MainWindow", "Equalization", nullptr));
        checkBox_compressor->setText(QCoreApplication::translate("MainWindow", "Compressor", nullptr));
        channels->setTitle(QCoreApplication::translate("MainWindow", "Channels", nullptr));
        equal->setTitle(QCoreApplication::translate("MainWindow", "Equalisation", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bass", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Aigu", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Bluetooh Devices", nullptr));
        groupcompressor->setTitle(QCoreApplication::translate("MainWindow", "Compressor", nullptr));
        compressor->setText(QCoreApplication::translate("MainWindow", "Compressor", nullptr));
        comp_level->setItemText(0, QCoreApplication::translate("MainWindow", "2:1", nullptr));
        comp_level->setItemText(1, QCoreApplication::translate("MainWindow", "4:1", nullptr));
        comp_level->setItemText(2, QCoreApplication::translate("MainWindow", "8:1", nullptr));
        comp_level->setItemText(3, QCoreApplication::translate("MainWindow", "Hard", nullptr));

        bypass_compressor->setText(QCoreApplication::translate("MainWindow", "Bypass Compressor", nullptr));
        symm->setText(QCoreApplication::translate("MainWindow", "Symmetric", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
