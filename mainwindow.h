#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <usbcard.h>
#include <QDateTime>
#include <datachart.h>
#include <dataprocessing.h>
#include <datasaving.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    USBcard *myusbcard;
    QThread *mymyusbcardThread;
    dataChart *mydataChart;
    QThread *mydataChartThread;
    dataProcessing *mydataProcessing;
    QThread *mydataProcessingThread;
    dataSaving*mydataSaving;
    QThread *mydataSavingThread;

private:
    Ui::MainWindow *ui;
public slots:
    void receiveMSG(const QString&);
    void receiveCardInfor(const CARD_INFO&);
private slots:
    void on_findDevice_clicked();
    void on_InitDevice_clicked();
    void on_startread_clicked();
    void on_stopread_clicked();

    void on_test_clicked();

    void on_Mvalue_textChanged(const QString &arg1);

    void on_Nvalue_textChanged(const QString &arg1);

    void on_pushButton_clicked();

signals:
    void startRead();
    void stopRead();
};
#endif // MAINWINDOW_H
