#ifndef USBCARD_H
#define USBCARD_H
#include <windows.h>
#include <QObject>
#include <QThread>
#include <usb2070.h>
#include <QMetaType>
#include <QDebug>
#include <QTime>
#include <QCoreApplication>
class USBcard: public QThread
{
    Q_OBJECT
public:
    USBcard();
    USB2070_PARA_INIT myADParameter;
    void findDevice();
    HANDLE hDevice ; //设备句柄
    CARD_INFO  ccardInfo;			//板卡信息
    bool needRead=true;
    BOOL readUSB(PUSHORT pBuf, int bufSiz);
    bool checkNeed();
    void Delay_MSec(unsigned int msec);
signals:

    void sendMsg2Main(const QString&);
    void sendCardInfor(const CARD_INFO&);
    void sendBuffer2P(const PUSHORT);
public slots:
    void ADinit();
    void readAD();
    void stopRead();
};

#endif // USBCARD_H
