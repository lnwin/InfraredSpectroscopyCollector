#ifndef DATASAVING_H
#define DATASAVING_H

#include <QObject>
#include <QThread>
#include <windows.h>
#include <QDir>
#include <QDateTime>
#include <QMap>
#include <QFile>
#include <QTextStream>
class dataSaving:public QThread
{
    Q_OBJECT
public:
    dataSaving();
    QString mySavePath;
    void saveMydata();
    bool read2Save=true;
    QDateTime saveTime;

    QMap<QDateTime, QPair<QList<float>, float>> myDataMap;

public slots:
    void getData2Save(const PUSHORT,const float ConCTr);
};

#endif // DATASAVING_H
