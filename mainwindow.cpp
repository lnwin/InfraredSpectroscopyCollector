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

    mydataChart=new dataChart(ui);
    mydataChartThread=new QThread ();
    mydataChart->moveToThread(mydataChartThread);
    mydataChartThread->start();
    mydataProcessing=new dataProcessing();
    mydataProcessingThread=new QThread();
    mydataProcessing->moveToThread(mydataProcessingThread);
    mydataProcessingThread->start();
    mydataSaving = new dataSaving();
    mydataSavingThread=new QThread();
    mydataSaving->moveToThread(mydataSavingThread);
    mydataSavingThread->start();

    connect(myusbcard,&USBcard::sendMsg2Main,this,&MainWindow::receiveMSG);
    connect(myusbcard,&USBcard::sendCardInfor,this,&MainWindow::receiveCardInfor);
    connect(myusbcard,&USBcard::sendBuffer2P,mydataProcessing,&dataProcessing::receiveBuff);


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


void MainWindow::on_test_clicked()
{
    PUSHORT sssd;
    sssd=new USHORT[10000];

    for (int i = 0; i < 10000; ++i) {
        // 计算正弦波值
        double sineValue = 300 * (1 + std::sin(2 * M_PI * 1 * i / 10000)) / 2;

        // 将值转换为 unsigned short，并防止溢出
        sssd[i] = static_cast<unsigned short>(std::min(std::max(sineValue, 0.0), static_cast<double>(std::numeric_limits<unsigned short>::max())));
    }


    mydataChart-> receiveConcentration2(sssd,220);
}


void MainWindow::on_Mvalue_textChanged(const QString &arg1)
{
    mydataProcessing->myM=arg1.toFloat();
}


void MainWindow::on_Nvalue_textChanged(const QString &arg1)
{
    mydataProcessing->myN=arg1.toFloat();
}


void MainWindow::on_pushButton_clicked()
{

    QString filePath=QFileDialog::getExistingDirectory();
    ui->savePath->setText(filePath);
    mydataSaving->mySavePath=filePath;

}

