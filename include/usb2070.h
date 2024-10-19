//AD��ʼ������
#ifndef _USB2070_PARA_INIT
typedef struct _USB2070_PARA_INIT    
{
	LONG    lADRange;			 //���뷶Χ 
	LONG    ADFREQ;              //������
	LONG	TriggerMode;         //����ģʽ
	LONG	TriggerSource;	     //����Դ 
	LONG    TriggerDelay;        //������ʱ
	LONG    TriggerLength;       //��������
	LONG    TriggerLevel;        //ģ�ⴥ����ƽ,�忨����Ĭ�����ִ�����������Ч
	LONG    lEnCh[80];           //ͨ��ʹ��; �����48������80
} USB2070_PARA_INIT,*PUSB2070_PARA_INIT;
#endif

//�忨��Ϣ
#ifndef _CARD_INFO
typedef struct _CARD_INIT    
{
	LONG  CARD_VER;   //�汾��
	LONG  AD_BIT;     //ADλ��   
	LONG  AD_CHCNT;   //ADͨ����
	LONG  AD_SPEED;   //AD�ٶ�   
	LONG  AD_FIFO;    //AD����FIFO
	LONG  DA_BIT;     //DAλ��   
	LONG  DA_CHCNT;   //DAͨ����
	LONG  DA_SPEED;   //DA�ٶ�   
	LONG  DA_FIFO;    //DA����FIFO
} CARD_INFO,*PCARD_INFO;
#endif

//ѡ��AD����
typedef enum EmADRange
{
	AD_RG_B10V     = 0, //���ˡ�5 V 
	AD_RG_B20V     = 1, //���ˡ�10 V 
	AD_RG_B5V      = 2, //���ˡ�2.5 V 
	AD_RG_B12V5    = 3, //���ˡ�6.25 V 
	AD_RG_B25V	   = 4, //���ˡ�20 V 
	AD_RG_U5V      = 5, //����0~5 V 
	AD_RG_U10V     = 6, //����0~10 V 
	AD_RG_U12V5    = 7 //����0~12.5V 
} AD_RANGE;

//����ģʽ
typedef enum EmTriggerMode
{
	TRIG_MODE_CONTINUE        = 0, //�����ɼ�
	TRIG_MODE_POST            = 1, //�󴥷�		
	TRIG_MODE_DELAY           = 2, //��ʱ����
	TRIG_MODE_PRE			  = 3, //ǰ������USB2070��֧��		
	TRIG_MODE_MIDDLE          = 4  //�д�����USB2070��֧��		
} TRIGGER_MODE;

//����Դ
typedef enum EmTriggerSource
{
	TRIG_SRC_EXT_RISING      = 0,  //�����ش���
	TRIG_SRC_EXT_FALLING     = 1,  //�⸺�ش���	
	TRIG_SRC_SOFT            = 2   //�������
} TRIGGER_SOURCE;


//ѡ��DA 
typedef enum EmSelDA
{
	SEL_DA0       = 0, //ѡ��DA0 
	SEL_DA1       = 1, //ѡ��DA1
	SEL_DA2       = 2, //ѡ��DA2,Ԥ��
	SEL_DA3       = 3  //ѡ��DA3,Ԥ��
} SEL_DA;

//���巢������ʼ������
#ifndef _USB2070_PWM_INIT
typedef struct _USB2070_PWM_INIT    
{
	LONG    lMode;          //PWMģʽ
	LONG    lAllCnt;        //�������׼ʱ�����ڸ���
	LONG	lHighCnt;       //�������׼ʱ�����ڸ���
	LONG	bEnable;	    //ʹ��
	LONG    bLoop;          //����/�������
	LONG    lCycleCnt;      //�������ʱ���������
} USB2070_PWM_INIT,*PUSB2070_PWM_INIT;
#endif

//��ʱ��/���巢����������ʽѡ��
typedef enum EmSelCntPwm
{
	TYPE_COUNTER    = 0,  //������ģʽ
	TYPE_PWM        = 1   //���巢����ģʽ
} CNTPWM_TYPE;

//����������ģʽ
typedef enum EmCounterMode
{
	CNT_NOGATE_EXT        = 0,  //GATE��ʹ���ſ��źţ��¼������¼�CLK
	CNT_GATE_RISING_EXT   = 1,  //GATE�ϱ��ش������¼������¼�CLK	
	CNT_GATE_FALLING_EXT  = 2,  //GATE�±��ش������¼������¼�CLK		
	CNT_GATE_1_EXT        = 3,  //GATE�ߵ�ƽ��Ч���¼������¼�CLK	
	CNT_GATE_0_EXT        = 4,  //GATE�͵�ƽ��Ч���¼������¼�CLK
	CNT_GATE_S_R2F_EXT    = 5,  //GATE�ϱ��ش������±���ֹͣ������һ��GATE����Ч�������������¼������¼�CLK
	CNT_GATE_S_F2R_EXT    = 6,  //GATE�±��ش������ϱ���ֹͣ������һ��GATE����Ч�������������¼������¼�CLK
	CNT_GATE_S_R2R_EXT    = 7,  //GATE�ϱ��ش�������һ���ϱ���ֹͣ������һ��GATE����Ч�������������¼������¼�CLK
	CNT_GATE_S_F2F_EXT    = 8,  //GATE�±��ش�������һ���±���ֹͣ������һ��GATE����Ч�������������¼������¼�CLK
	CNT_GATE_R_R2F_EXT    = 9,  //GATE�ϱ��ش������±���ֹͣ��GATE��ʼ����Ч���ظ����������¼������¼�CLK
	CNT_GATE_R_F2R_EXT    = 10, //GATE�±��ش������ϱ���ֹͣ��GATE��ʼ����Ч���ظ����������¼������¼�CLK	
	CNT_GATE_R_R2R_EXT    = 11, //GATE�ϱ��ش�������һ���ϱ���ֹͣ��GATE��ʼ����Ч���ظ����������¼������¼�CLK
	CNT_GATE_R_F2F_EXT    = 12, //GATE�±��ش�������һ���±���ֹͣ��GATE��ʼ����Ч���ظ����������¼������¼�CLK	
	CNT_GATE_R_R2F_INT    = 13, //GATE�ϱ��ش������±���ֹͣ��GATE��ʼ����Ч���ظ����������¼���48M��ʱ��
	CNT_GATE_R_F2R_INT    = 14, //GATE�±��ش������ϱ���ֹͣ��GATE��ʼ����Ч���ظ����������¼���48M��ʱ��	
	CNT_GATE_R_R2R_INT    = 15, //GATE�ϱ��ش�������һ���ϱ���ֹͣ��GATE��ʼ����Ч���ظ����������¼���48M��ʱ��
	CNT_GATE_R_F2F_INT    = 16  //GATE�±��ش�������һ���±���ֹͣ��GATE��ʼ����Ч���ظ����������¼���48M��ʱ��
} COUNTER_MODE;

//���巢��������ģʽ
typedef enum EmPwmMode
{
	PWM_NOGATE        = 0,  //GATE��ʹ���ſ��źţ��¼���48M��ʱ��
	PWM_GATE_RISING   = 1,  //GATE�ϱ��ش������¼���48M��ʱ��
	PWM_GATE_FALLING  = 2,  //GATE�±��ش������¼���48M��ʱ��	
	PWM_GATE_1        = 3,  //GATE�ߵ�ƽ��Ч���¼���48M��ʱ��	
	PWM_GATE_0        = 4   //GATE�͵�ƽ��Ч���¼���48M��ʱ��
} PWM_MODE;

//�������ȵ�λ
#define   TRIG_UNIT   8 //8��ͨ��

//���βɼ���ȡ����
#define READ_MAX_LEN   1572864L  

//DAֹͣ����
#define DA_END_NO_PRD 1 //�յ�DAֹͣ�����,����ֹͣ���
#define DA_END_YES_PRD 0 //�յ�DAֹͣ����������ǰ���ں���ֹͣ

//��/д��ƫ
#define WRITEOFFSET 0 //д��ƫ
#define READOFFSET  1 //����ƫ

//��Ƶ��׼ʱ��
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

	//�ж��Ƿ�Ϊ����USB�豸
	DEVAPI BOOL FAR PASCAL USB2070_IsHighDevice(HANDLE hDevice,PUCHAR pDat);
	//�����豸�Ŵ��豸
	DEVAPI HANDLE FAR PASCAL USB2070_Link(UCHAR DeviceNO);
	//�Ͽ��豸
	DEVAPI BOOL FAR PASCAL USB2070_UnLink(HANDLE hDevice);
	//��ʼ����������ʼ�ɼ�
	DEVAPI BOOL FAR PASCAL USB2070_InitAD(HANDLE hDevice, PUSB2070_PARA_INIT para_init);
	//��ȡAD����
	DEVAPI BOOL FAR PASCAL USB2070_ReadAD(HANDLE hDevice,PUSHORT pBuf, ULONG nCount);
	//�����ɼ�
	DEVAPI BOOL FAR PASCAL USB2070_StopAD(HANDLE hDevice, UCHAR devNum);
	//����DO
	DEVAPI BOOL FAR PASCAL USB2070_SetDO(HANDLE hDevice, LONG lDO);
	//��ȡDI
	DEVAPI BOOL FAR PASCAL USB2070_GetDI(HANDLE hDevice, PLONG pDI);
	//����DA
	DEVAPI BOOL FAR PASCAL USB2070_SetDA(HANDLE hDevice, UCHAR bySelDA, BOOL bEnable, PLONG pFreq,
		BOOL bLoop, LONG lCycleCnt,LONG bEndPrd,PUSHORT pDABuf, ULONG nCount);
	//����AD��ƫ
	DEVAPI BOOL FAR PASCAL USB2070_ADoffset(HANDLE hDevice, BOOL bWtRd,LONG lSelReg,PLONG plADoffset);
	//��ȡӲ���������λ
	DEVAPI BOOL FAR PASCAL USB2070_GetBufOver(HANDLE hDevice, PLONG pBufOver);
	//�������
	DEVAPI BOOL FAR PASCAL USB2070_ExeSoftTrig(HANDLE hDevice);
	//���ü�����
	DEVAPI BOOL FAR PASCAL USB2070_initCnt(HANDLE hdl, LONG lSelCh,LONG lMode,BOOL bEnCnt,BOOL bOverMode);
	//�������巢����
	DEVAPI BOOL FAR PASCAL USB2070_SetPwm(HANDLE hdl, LONG lSelCh,PUSB2070_PWM_INIT ppwm_init);
	//��ȡ��������ֵ
	DEVAPI BOOL FAR PASCAL USB2070_GetCntValue(HANDLE hdl, LONG lSelCh,ULONG* pCntBuf);
	//��ȡ�忨��Ϣ������ADλ��������ͨ����
	DEVAPI BOOL FAR PASCAL USB2070_GetDevInfo(HANDLE hdl,PCARD_INFO pCardInfo);

#ifdef __cplusplus
}
#endif


