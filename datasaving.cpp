#include "datasaving.h"

dataSaving::dataSaving()
{

}
QList<float> convertToQList(const PUSHORT myBUF, int dataSize)
{
    QList<float> floatList;

    // 遍历 myBUF，将每个元素转换为 float 并添加到 QList
    for (int i = 0; i < dataSize; ++i) {
        floatList.append(static_cast<float>(myBUF[i]));
    }

    return floatList;
}
void dataSaving::getData2Save(const PUSHORT myBUF,const float ConCTr)
{
    if(read2Save)
    {
        saveTime  = QDateTime::currentDateTime();
        read2Save=false;
    }

    QDateTime CCT  = QDateTime::currentDateTime();

    QList<float> floatList = convertToQList(myBUF, 10000);
    QPair<QList<float>, float> newPair(floatList, ConCTr); // 创建新键值对
    myDataMap.insert(CCT, newPair);

    if(myDataMap.size()>=300)//1Hz  5分钟存储一次
    {
        saveMydata();
        read2Save=true;
        myDataMap.clear();
    }


};
void dataSaving::saveMydata()
{
    QDir dir0(mySavePath+"/originData");
    QDir dir1(mySavePath +"/concentrationData");
    // 如果文件夹不存在，则创建它
    if (!dir0.exists())
    {
        dir0.mkpath(mySavePath+"/originData");
    }
    if (!dir1.exists())
    {
        dir1.mkpath(mySavePath +"/concentrationData");
    }

    QString originFileName="originData"+saveTime.toString("yyyy_hh_mm_ss");
     QString cctFileName="concentrationData"+saveTime.toString("yyyy_hh_mm_ss");

    // 打开第一个文件（存储 QList<float>）
    QFile bufFile(originFileName);
    if (!bufFile.open(QIODevice::WriteOnly | QIODevice::Text)) {

        return;
    }
    QTextStream bufStream(&bufFile);

    // 打开第二个文件（存储 float 值）
    QFile concFile(cctFileName);
    if (!concFile.open(QIODevice::WriteOnly | QIODevice::Text)) {

        bufFile.close();
        return;
    }
    QTextStream concStream(&concFile);

    // 遍历 myDataMap
    for (auto it = myDataMap.constBegin(); it != myDataMap.constEnd(); ++it) {
        QString timeStr = it.key().toString("yyyy-MM-dd HH:mm:ss");  // 格式化时间

        // 写入第一个文件：时间和 QList<float>
        for (float value : it.value().first) {
            bufStream << timeStr << "\t" << value << "\n";
        }

        // 写入第二个文件：时间和 float 值
        concStream << timeStr << "\t" << it.value().second << "\n";
    }

    // 关闭文件
    bufFile.close();
    concFile.close();


};
