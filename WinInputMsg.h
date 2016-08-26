//----------------------------------------------------------------
#ifndef _WinInputMsg_h_
#define _WinInputMsg_h_
//----------------------------------------------------------------
//�����¼���ö��ֵ
enum eInputEventType
{
	InputEvent_Invalid = -1, //��Чֵ
	InputEvent_Down, //��ť��������
	InputEvent_Up, //��ť��̧����
	InputEvent_MouseMove, //����ƶ���
	InputEvent_MouseWheel, //�����ֹ�����
	InputEvent_MouseMove_CameraOp, //ר��Ϊ�������ת������������¼�
	InputEvent_Max, //���ֵ
};
//----------------------------------------------------------------
//���̺����İ�ť��ö��ֵ
enum eInputKeyType
{
	InputKey_Invalid = -1, //��Чֵ
	InputKey_A,
	InputKey_B,
	InputKey_C,
	InputKey_D,
	InputKey_E,
	InputKey_F,
	InputKey_G,
	InputKey_H,
	InputKey_I,
	InputKey_J,
	InputKey_K,
	InputKey_L,
	InputKey_M,
	InputKey_N,
	InputKey_O,
	InputKey_P,
	InputKey_Q,
	InputKey_R,
	InputKey_S,
	InputKey_T,
	InputKey_U,
	InputKey_V,
	InputKey_W,
	InputKey_X,
	InputKey_Y,
	InputKey_Z,
	InputKey_F1,
	InputKey_F2,
	InputKey_F3,
	InputKey_Space,
	InputKey_Delete,
	InputKey_Shift,
	InputKey_Ctrl,
	InputKey_Alt,
	InputKey_LMouse, //������
	InputKey_MMouse, //����м�
	InputKey_RMouse, //����Ҽ�
	InputKey_Max,
};
//----------------------------------------------------------------
struct stInputEvent
{
	eInputEventType theEvent;
	eInputKeyType theKey;
	int nParam1;
	int nParam2;
	bool bIsJustDown; //�����InputEvent_Down�¼����ü�λ�Ƿ�ոձ�����
	bool bIsJustUp; //�����InputEvent_Up�¼����ü�λ�Ƿ�ոձ�̧��
	bool bShiftKeyDown; //��ʱShift���Ƿ��ڰ���״̬
	bool bCtrlKeyDown; //��ʱCtrl���Ƿ��ڰ���״̬
	bool bAltKeyDown; //��ʱAlt���Ƿ��ڰ���״̬
	bool bSwallowed; //ֵΪtrue����ʾ����Ϣ�Ѿ��������ˣ�������Ӧ���к����ģ�齫�����յ�����Ϣ��

	stInputEvent()
	:theEvent(InputEvent_Invalid), theKey(InputKey_Invalid), nParam1(0), nParam2(0)
	,bIsJustDown(false), bIsJustUp(false)
	,bShiftKeyDown(false), bCtrlKeyDown(false), bAltKeyDown(false), bSwallowed(false)
	{
	}
	void Swallow()
	{
		bSwallowed = true;
	}
};
//----------------------------------------------------------------
#endif //_WinInputMsg_h_
//----------------------------------------------------------------
