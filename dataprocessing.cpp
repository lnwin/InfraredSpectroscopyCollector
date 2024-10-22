#include "dataprocessing.h"

dataProcessing::dataProcessing()
{

}


void dataProcessing::receiveBuff(const PUSHORT myBuffer)
{
    float A1,A2,A3;
    findExtrema(myBuffer,10000, A1,A2,A3);

    float AVE=(A1+A2)/2-A3;

    float ND=myM*AVE+myN;



    emit sendConcentration2Chart(myBuffer,ND);

};



void dataProcessing::findExtrema(const PUSHORT myBuffer, int dataSize, float &A1Index, float &A2Index, float &A3Index)
{
    if (dataSize <= 0) return;

    // 初始化变量
    float max1 = (std::numeric_limits<float>::min)();
    float max2 = (std::numeric_limits<float>::min)();
    float min1 = (std::numeric_limits<float>::max)();
    A1Index = A2Index = A3Index = -1;

    // 第一次遍历，找到第一个最大值 A1 和最小值 A3
    for (int i = 0; i < dataSize; ++i) {
        if (myBuffer[i] > max1) {
            max1 = myBuffer[i];
            A1Index = i;
        }
        if (myBuffer[i] < min1) {
            min1 = myBuffer[i];
            A3Index = i;
        }
    }

    // 第二次遍历，找到第二个最大值 A2（排除 A1 的位置）
    for (int i = 0; i < dataSize; ++i) {
        if (i != A1Index && myBuffer[i] > max2) {
            max2 = myBuffer[i];
            A2Index = i;
        }
    }
}
