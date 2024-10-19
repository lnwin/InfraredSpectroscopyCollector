//AD初始化参数
#ifndef _USB2070_PARA_INIT
typedef struct _USB2070_PARA_INIT    
{
	LONG    lADRange;			 //输入范围 
	LONG    ADFREQ;              //采样率
	LONG	TriggerMode;         //触发模式
	LONG	TriggerSource;	     //触发源 
	LONG    TriggerDelay;        //触发延时
	LONG    TriggerLength;       //触发长度
	LONG    TriggerLevel;        //模拟触发电平,板卡出厂默认数字触发，参数无效
	LONG    lEnCh[80];           //通道使能; 数组从48升级到80
} USB2070_PARA_INIT,*PUSB2070_PARA_INIT;
#endif

//板卡信息
#ifndef _CARD_INFO
typedef struct _CARD_INIT    
{
	LONG  CARD_VER;   //版本号
	LONG  AD_BIT;     //AD位数   
	LONG  AD_CHCNT;   //AD通道数
	LONG  AD_SPEED;   //AD速度   
	LONG  AD_FIFO;    //AD板载FIFO
	LONG  DA_BIT;     //DA位数   
	LONG  DA_CHCNT;   //DA通道数
	LONG  DA_SPEED;   //DA速度   
	LONG  DA_FIFO;    //DA板载FIFO
} CARD_INFO,*PCARD_INFO;
#endif

//选择AD量程
typedef enum EmADRange
{
	AD_RG_B10V     = 0, //单端±5 V 
	AD_RG_B20V     = 1, //单端±10 V 
	AD_RG_B5V      = 2, //单端±2.5 V 
	AD_RG_B12V5    = 3, //单端±6.25 V 
	AD_RG_B25V	   = 4, //单端±20 V 
	AD_RG_U5V      = 5, //单端0~5 V 
	AD_RG_U10V     = 6, //单端0~10 V 
	AD_RG_U12V5    = 7 //单端0~12.5V 
} AD_RANGE;

//触发模式
typedef enum EmTriggerMode
{
	TRIG_MODE_CONTINUE        = 0, //连续采集
	TRIG_MODE_POST            = 1, //后触发		
	TRIG_MODE_DELAY           = 2, //延时触发
	TRIG_MODE_PRE			  = 3, //前触发，USB2070不支持		
	TRIG_MODE_MIDDLE          = 4  //中触发，USB2070不支持		
} TRIGGER_MODE;

//触发源
typedef enum EmTriggerSource
{
	TRIG_SRC_EXT_RISING      = 0,  //外正沿触发
	TRIG_SRC_EXT_FALLING     = 1,  //外负沿触发	
	TRIG_SRC_SOFT            = 2   //软件触发
} TRIGGER_SOURCE;


//选择DA 
typedef enum EmSelDA
{
	SEL_DA0       = 0, //选择DA0 
	SEL_DA1       = 1, //选择DA1
	SEL_DA2       = 2, //选择DA2,预留
	SEL_DA3       = 3  //选择DA3,预留
} SEL_DA;

//脉冲发生器初始化参数
#ifndef _USB2070_PWM_INIT
typedef struct _USB2070_PWM_INIT    
{
	LONG    lMode;          //PWM模式
	LONG    lAllCnt;        //单脉冲基准时钟周期个数
	LONG	lHighCnt;       //高脉冲基准时钟周期个数
	LONG	bEnable;	    //使能
	LONG    bLoop;          //有限/无限输出
	LONG    lCycleCnt;      //有限输出时，脉冲个数
} USB2070_PWM_INIT,*PUSB2070_PWM_INIT;
#endif

//定时器/脉冲发生器工作方式选择
typedef enum EmSelCntPwm
{
	TYPE_COUNTER    = 0,  //计数器模式
	TYPE_PWM        = 1   //脉冲发生器模式
} CNTPWM_TYPE;

//计数器工作模式
typedef enum EmCounterMode
{
	CNT_NOGATE_EXT        = 0,  //GATE不使用门控信号，事件是外事件CLK
	CNT_GATE_RISING_EXT   = 1,  //GATE上边沿触发，事件是外事件CLK	
	CNT_GATE_FALLING_EXT  = 2,  //GATE下边沿触发，事件是外事件CLK		
	CNT_GATE_1_EXT        = 3,  //GATE高电平有效，事件是外事件CLK	
	CNT_GATE_0_EXT        = 4,  //GATE低电平有效，事件是外事件CLK
	CNT_GATE_S_R2F_EXT    = 5,  //GATE上边沿触发，下边沿停止，仅第一个GATE门有效（单触发），事件是外事件CLK
	CNT_GATE_S_F2R_EXT    = 6,  //GATE下边沿触发，上边沿停止，仅第一个GATE门有效（单触发），事件是外事件CLK
	CNT_GATE_S_R2R_EXT    = 7,  //GATE上边沿触发，下一个上边沿停止，仅第一个GATE门有效（单触发），事件是外事件CLK
	CNT_GATE_S_F2F_EXT    = 8,  //GATE下边沿触发，下一个下边沿停止，仅第一个GATE门有效（单触发），事件是外事件CLK
	CNT_GATE_R_R2F_EXT    = 9,  //GATE上边沿触发，下边沿停止，GATE门始终有效（重复触发），事件是外事件CLK
	CNT_GATE_R_F2R_EXT    = 10, //GATE下边沿触发，上边沿停止，GATE门始终有效（重复触发），事件是外事件CLK	
	CNT_GATE_R_R2R_EXT    = 11, //GATE上边沿触发，下一个上边沿停止，GATE门始终有效（重复触发），事件是外事件CLK
	CNT_GATE_R_F2F_EXT    = 12, //GATE下边沿触发，下一个下边沿停止，GATE门始终有效（重复触发），事件是外事件CLK	
	CNT_GATE_R_R2F_INT    = 13, //GATE上边沿触发，下边沿停止，GATE门始终有效（重复触发），事件是48M内时钟
	CNT_GATE_R_F2R_INT    = 14, //GATE下边沿触发，上边沿停止，GATE门始终有效（重复触发），事件是48M内时钟	
	CNT_GATE_R_R2R_INT    = 15, //GATE上边沿触发，下一个上边沿停止，GATE门始终有效（重复触发），事件是48M内时钟
	CNT_GATE_R_F2F_INT    = 16  //GATE下边沿触发，下一个下边沿停止，GATE门始终有效（重复触发），事件是48M内时钟
} COUNTER_MODE;

//脉冲发生器工作模式
typedef enum EmPwmMode
{
	PWM_NOGATE        = 0,  //GATE不使用门控信号，事件是48M内时钟
	PWM_GATE_RISING   = 1,  //GATE上边沿触发，事件是48M内时钟
	PWM_GATE_FALLING  = 2,  //GATE下边沿触发，事件是48M内时钟	
	PWM_GATE_1        = 3,  //GATE高电平有效，事件是48M内时钟	
	PWM_GATE_0        = 4   //GATE低电平有效，事件是48M内时钟
} PWM_MODE;

//触发长度单位
#define   TRIG_UNIT   8 //8个通道

//单次采集读取长度
#define READ_MAX_LEN   1572864L  

//DA停止设置
#define DA_END_NO_PRD 1 //收到DA停止命令后,立刻停止输出
#define DA_END_YES_PRD 0 //收到DA停止命令后，输出当前周期后再停止

//读/写零偏
#define WRITEOFFSET 0 //写零偏
#define READOFFSET  1 //读零偏

//测频基准时钟
#define  FRQ_BASE_CLOCK  48000000L 

//***********************************************************
#ifndef DEFINING
#define DEVAPI __declspec(dllimport)
#else
#define DEVAPI __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	//判断是否为高速USB设备
	DEVAPI BOOL FAR PASCAL USB2070_IsHighDevice(HANDLE hDevice,PUCHAR pDat);
	//根据设备号打开设备
	DEVAPI HANDLE FAR PASCAL USB2070_Link(UCHAR DeviceNO);
	//断开设备
	DEVAPI BOOL FAR PASCAL USB2070_UnLink(HANDLE hDevice);
	//初始化参数并开始采集
	DEVAPI BOOL FAR PASCAL USB2070_InitAD(HANDLE hDevice, PUSB2070_PARA_INIT para_init);
	//读取AD数据
	DEVAPI BOOL FAR PASCAL USB2070_ReadAD(HANDLE hDevice,PUSHORT pBuf, ULONG nCount);
	//结束采集
	DEVAPI BOOL FAR PASCAL USB2070_StopAD(HANDLE hDevice, UCHAR devNum);
	//设置DO
	DEVAPI BOOL FAR PASCAL USB2070_SetDO(HANDLE hDevice, LONG lDO);
	//读取DI
	DEVAPI BOOL FAR PASCAL USB2070_GetDI(HANDLE hDevice, PLONG pDI);
	//设置DA
	DEVAPI BOOL FAR PASCAL USB2070_SetDA(HANDLE hDevice, UCHAR bySelDA, BOOL bEnable, PLONG pFreq,
		BOOL bLoop, LONG lCycleCnt,LONG bEndPrd,PUSHORT pDABuf, ULONG nCount);
	//设置AD零偏
	DEVAPI BOOL FAR PASCAL USB2070_ADoffset(HANDLE hDevice, BOOL bWtRd,LONG lSelReg,PLONG plADoffset);
	//读取硬件缓存溢出位
	DEVAPI BOOL FAR PASCAL USB2070_GetBufOver(HANDLE hDevice, PLONG pBufOver);
	//软件触发
	DEVAPI BOOL FAR PASCAL USB2070_ExeSoftTrig(HANDLE hDevice);
	//设置计数器
	DEVAPI BOOL FAR PASCAL USB2070_initCnt(HANDLE hdl, LONG lSelCh,LONG lMode,BOOL bEnCnt,BOOL bOverMode);
	//设置脉冲发生器
	DEVAPI BOOL FAR PASCAL USB2070_SetPwm(HANDLE hdl, LONG lSelCh,PUSB2070_PWM_INIT ppwm_init);
	//读取计数器数值
	DEVAPI BOOL FAR PASCAL USB2070_GetCntValue(HANDLE hdl, LONG lSelCh,ULONG* pCntBuf);
	//读取板卡信息，例如AD位数，板载通道数
	DEVAPI BOOL FAR PASCAL USB2070_GetDevInfo(HANDLE hdl,PCARD_INFO pCardInfo);

#ifdef __cplusplus
}
#endif


