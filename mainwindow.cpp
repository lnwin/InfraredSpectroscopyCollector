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
    connect(myusbcard,&USBcard::sendCardInfor,this,&MainWindow::receiveCardInfor);

    connect(this,&MainWindow::startRead ,myusbcard,&USBcard::readAD);
    connect(this,&MainWindow::stopRead ,myusbcard,&USBcard::stopRead);



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::receiveMSG(const QString& myMSG)
{

    QDateTime currentT=QDateTime::currentDateTime();
    QString TS=currentT.toString("yyyy-mm-dd HH:mm:ss");
    QString deviceInfor;
    deviceInfor+=TS+ " "+myMSG;
    ui->textEdit->append(deviceInfor);

};
void MainWindow::receiveCardInfor(const CARD_INFO&myCI)
{   QDateTime currentT=QDateTime::currentDateTime();
    QString TS=currentT.toString("yyyy-mm-dd HH:mm:ss");
    QString deviceInfor;

    deviceInfor+=TS+ " current card version:"+ QString::number(myCI.CARD_VER);
    ui->textEdit->append(deviceInfor);
};
void MainWindow::on_findDevice_clicked()
{
    myusbcard->findDevice();
}

void MainWindow::on_InitDevice_clicked()
{
    myusbcard->ADinit();
}


void MainWindow::on_startread_clicked()
{
    emit startRead();
}


void MainWindow::on_stopread_clicked()
{
    myusbcard->needRead=false;
}

