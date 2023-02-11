#include "mainwindow.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile f(":qdarkstyle/dark/style.qss");

    if (!f.exists())   {
        qWarning()<<"Unable to set stylesheet, file not found";
    }
    else   {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    return a.exec();
}
