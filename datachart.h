#ifndef DATACHART_H
#define DATACHART_H
#include <QObject>
#include <QThread>
#include <ui_mainwindow.h>
#include <QVector>
#include <usbcard.h>
class dataChart: public QThread
{
    Q_OBJECT
public:
    dataChart(Ui::MainWindow *myui);
    Ui::MainWindow * myUI;
    // 初始化全局变量
    // 静态成员变量声明
    static QVector<double> xData;
    static QVector<double> yData;
    USBcard *myUSB;
public slots:
     void receiveConcentration2(const PUSHORT,const float ConCTr);
     void showDataAtMouse(QMouseEvent *event);

};

#endif // DATACHART_H
