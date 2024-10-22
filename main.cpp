#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<PUSHORT>("PUSHORT");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
