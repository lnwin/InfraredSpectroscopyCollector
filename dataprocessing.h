#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <QObject>
#include <QThread>
#include <windows.h>
#include <limits> // 用于 std::numeric_limits

class dataProcessing:public QThread
{
    Q_OBJECT
public:
    dataProcessing();
    void findExtrema(const PUSHORT myBuffer, int dataSize, float &A1Index, float &A2Index, float &A3Index);
    float myM=1;
    float myN=1;
public slots:
    void receiveBuff(const PUSHORT);
signals:
    void sendConcentration2Chart(const PUSHORT,const float ConCTr);
};

#endif // DATAPROCESSING_H
