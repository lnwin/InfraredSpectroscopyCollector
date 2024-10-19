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
void MainWindow::receiveCardInfor(const CARD_INFO&myCI)
{
    QString deviceInfor;
    deviceInfor+="current card version:"+ QString::number(myCI.CARD_VER);
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

