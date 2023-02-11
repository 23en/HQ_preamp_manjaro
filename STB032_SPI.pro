#-------------------------------------------------
#
# Project created by QtCreator 2017-10-05T14:50:25
#
#-------------------------------------------------

QT       += core gui bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = STB032_SPI
#TEMPLATE = app

SOURCES += main.cpp\
        ftdi_common.c \
        ftdi_i2c.c \
        ftdi_infra.c \
        ftdi_mid.c \
        ftdi_spi.c \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    ftdi_common.h \
    ftdi_i2c.h \
    ftdi_infra.h \
    ftdi_mid.h \
    ftdi_spi.h \
    libMPSSE_spi.h

FORMS    += mainwindow.ui

#LIBS += -L/opt/lib64 -lftd2xx
#LIBS += -L/usr/local/lib -lftd2xx
#LIBS += -L/home/ben/SVN/libs/External_DLL/ftdi/build -lftd2xx
#LIBS += -lftd2xx

LIBS += /home/ben/STB032_SPI/libMPSSE.a
LIBS += /home/ben/STB032_SPI/libftd2xx.a
LIBS += -ldl

RESOURCES += qdarkstyle/dark/style.qrc \
    icons/icons.qrc
