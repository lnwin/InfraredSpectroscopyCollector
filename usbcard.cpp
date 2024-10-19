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



    myADParameter.ADFREQ=32000000/160;
    myADParameter.TriggerMode=TRIG_MODE_CONTINUE;
    myADParameter.TriggerSource=TRIG_SRC_SOFT ;//软件触发
                               // TRIG_SRC_EXT_FALLING     = 1,  //外负沿触发
                               //TRIG_SRC_EXT_RISING  外正沿触发
    myADParameter.TriggerDelay=0;
    myADParameter.TriggerLength=1024;
    myADParameter.lADRange=0;//，0对应-5V~+5V量程，1对应-10V~10V量程。
    myADParameter.TriggerLevel=0;//触发电平设置，采样12位DA，取值0～4095，0对应触发电平-5V，4095对应触发电平5V。
   //－通道使能，lEnCh[0]~ lEnCh[79]分别对应CH1~CH80使能，1表示该通道使能，0表示该通道非使能。
    for(int i=0;i<24;i++)
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
