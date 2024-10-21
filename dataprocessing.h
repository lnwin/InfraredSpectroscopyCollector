#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <QObject>
#include <QThread>
#include <windows.h>
class dataProcessing:public QThread
{
    Q_OBJECT
public:
    dataProcessing();
public slots:
    void receiveBuff(const PUSHORT);
signals:
    void sendConcentration2Chart(const float ConCTr);
};

#endif // DATAPROCESSING_H
