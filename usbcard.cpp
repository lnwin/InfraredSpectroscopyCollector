#include "usbcard.h"

USBcard::USBcard()
{



}
void USBcard::findDevice()
{

    hDevice = INVALID_HANDLE_VALUE;
    hDevice = USB2070_Link(0);
    if(hDevice != INVALID_HANDLE_VALUE)
    {
        CARD_INFO carInfo;
        USB2070_GetDevInfo(hDevice,&carInfo);
        ccardInfo=carInfo;
        emit sendMsg2Main("find device!");
        emit sendCardInfor(ccardInfo);
    }
    else
    {
        emit sendMsg2Main("find no device!");
    }
}
void USBcard::ADinit()
{



    myADParameter.ADFREQ=1;
    myADParameter.TriggerMode=TRIG_MODE_POST;
                               ////TRIG_MODE_CONTINUE;
    myADParameter.TriggerSource=TRIG_SRC_EXT_FALLING;
                               //TRIG_SRC_SOFT ;//软件触发
                               // TRIG_SRC_EXT_FALLING     = 1,  //外负沿触发
                               //TRIG_SRC_EXT_RISING  外正沿触发
    myADParameter.TriggerDelay=0;
    myADParameter.TriggerLength=10;
    myADParameter.lADRange=0;//，0对应-5V~+5V量程，1对应-10V~10V量程。
    myADParameter.TriggerLevel=0;//触发电平设置，采样12位DA，取值0～4095，0对应触发电平-5V，4095对应触发电平5V。
   //－通道使能，lEnCh[0]~ lEnCh[79]分别对应CH1~CH80使能，1表示该通道使能，0表示该通道非使能。
    for(int i=0;i<1;i++)
    {
     myADParameter.lEnCh[i] = TRUE;
    }

    if(!USB2070_InitAD(hDevice,&myADParameter))
    {
        emit sendMsg2Main("init device fail !");

    }
    else
    {
         emit sendMsg2Main("init device success !");
    }

};
void USBcard::readAD()
{

    LONG ad_size = 1;//样点长度，14bit/16bit AD长度1个USHORT，18bit AD长度2个USHORT
    if(ccardInfo.AD_BIT==18) ad_size = 2;
    PUSHORT inBuffer = NULL;
    ULONG samcnt = (ULONG)(100000*ad_size);	   //单个通道采集点数
    LONG all_cnt=1;		//统计通道数
    samcnt = samcnt*all_cnt;
    inBuffer = new USHORT[samcnt];
    needRead=true;


    while(checkNeed())
    {

        qDebug()<<"is reading";

        if(!USB2070_ReadAD(hDevice,inBuffer,samcnt))
        {

             continue;
        }
        else
        {
            emit sendBuffer2P(inBuffer);
        }


    }

     qDebug()<<" read stoped";
     delete[] inBuffer;


};
void USBcard::stopRead()
{

    needRead=false;

};
bool USBcard::checkNeed()
{
    return needRead;
}
// BOOL USBcard::readUSB(PUSHORT pBuf, int bufSiz)//存盘
// {
//     //一次读完samcnt长度数据，例如一个触发长度，如果samcnt大于READ_MAX_LEN，则分为多次读取
//     ULONG DataOver =0; //缓存区溢出指示
//     ULONG rlen=0;//每次读取长度
//     ULONG alen=0;//已经读取长度
//     int rcnt = 0;//总共需要读取的次数
//     if((bufSiz%READ_MAX_LEN) == 0)//如果读取的长度，刚好是最大允许读取长度的整数倍
//         rcnt = (bufSiz/READ_MAX_LEN);
//     else
//         rcnt = (bufSiz/READ_MAX_LEN)+1;
//     //分多次读取，每次读最大长度是READ_MAX_LEN
//     for(int i=0;i<rcnt;i++)
//     {
//         if(i==(rcnt-1))//如果是最后一次
//         {
//             if ((bufSiz%READ_MAX_LEN) ==0)//如果刚好是整数倍
//                 rlen = READ_MAX_LEN;
//             else
//                 rlen = bufSiz%READ_MAX_LEN;
//         }
//         else
//         {
//             rlen = READ_MAX_LEN;
//         }
//         //读数
//         if (!USB2070_ReadAD(hDevice,pBuf+alen,rlen))
//         {
//             qDebug()<<"读取数据失败";
//            // UpdateData(FALSE);
//             break;
//             return FALSE;
//         }
//         //判断数据是否溢出
//         alen += rlen;
//     }
//     return TRUE;
// }
