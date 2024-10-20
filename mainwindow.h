#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <usbcard.h>
#include <QDateTime>
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

signals:
    void startRead();
    void stopRead();
};
#endif // MAINWINDOW_H
