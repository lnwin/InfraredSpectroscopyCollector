#include "usbcard.h"

USBcard::USBcard()
{

    HANDLE hDevice ; //设备句柄
    hDevice = INVALID_HANDLE_VALUE;
    hDevice = USB2070_Link(0);
    if(hDevice != INVALID_HANDLE_VALUE)
    {

    }
    else
    {

    }

}
void USBcard::ADinit()
{



    myADParameter.ADFREQ=32000000/160;
    myADParameter.TriggerMode=TRIG_MODE_CONTINUE;
    myADParameter.TriggerSource=TRIG_SRC_SOFT ;//软件触发
                               // TRIG_SRC_EXT_FALLING     = 1,  //外负沿触发
                               //TRIG_SRC_EXT_RISING  外正沿触发


};
