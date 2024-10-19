#ifndef USBCARD_H
#define USBCARD_H
#include <windows.h>
#include <QObject>
#include <QThread>
#include <usb2070.h>
#include <QMetaType>


class USBcard: public QThread
{
    Q_OBJECT
public:
    USBcard();
    USB2070_PARA_INIT myADParameter;
signals:

    void sendMsg2Main(const QString&);

public slots:
    void ADinit();
};

#endif // USBCARD_H
