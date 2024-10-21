#ifndef DATASAVING_H
#define DATASAVING_H

#include <QObject>
#include <QThread>
class dataSaving:public QThread
{
    Q_OBJECT
public:
    dataSaving();
};

#endif // DATASAVING_H
