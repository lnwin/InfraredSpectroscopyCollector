#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myusbcard=new USBcard( );
    mymyusbcardThread=new  QThread ();
    myusbcard->moveToThread(mymyusbcardThread);
    mymyusbcardThread->start();


    connect(myusbcard,&USBcard::sendMsg2Main,this,&MainWindow::receiveMSG);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::receiveMSG(const QString& myMSG)
{
    QMessageBox myMessageBos;
    myMessageBos.setText(myMSG);
    myMessageBos.exec();

};
