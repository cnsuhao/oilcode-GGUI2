//----------------------------------------------------------------
#ifndef _WinInputMsgManager_h_
#define _WinInputMsgManager_h_
//----------------------------------------------------------------
#include "SoArray.h"
#include "WinInputMsg.h"
//----------------------------------------------------------------
class WinInputMsgManager
{
public:
	static bool CreateInputMsgManager();
	static void ReleaseInputMsgManager();
	static WinInputMsgManager* Get();

	//��ȡĳ����λ��ǰ�Ƿ��ڰ���״̬��
	bool IsKeyDown(eInputKeyType theKey);
	//��ȡĳ����λ�Ƿ�ոհ��£�����һ֡û�а��£���ǰ֡�����ˡ�
	bool IsKeyJustDown(eInputKeyType theKey);
	//��ȡĳ����λ�Ƿ�ո�̧�𣬼���һ֡���ڰ��£���ǰ̧֡���ˡ�
	bool IsKeyJustUp(eInputKeyType theKey);
	//��һ֡��ʼʱ���ѵ�ǰ֡�ļ�λ״̬���浽��һ֡�ļ�λ״̬�С�
	void SaveKeyDownState();
	//���ղ�����Windows��Ϣ�е�Input��Ϣ��
	int ReceiveInputMsg(unsigned int uiMsg, unsigned int wParam, unsigned int lParam);
	//��Input��Ϣ�ַ�����Ϸ�߼���
	void DispatchInputMsg();
	//����Windows���ڼ�����Ϣ�뷴������Ϣ��
	void ProcessWindowActivateChangeMsg();

	//�����߼�����
	void SetMouseMoveForCameraOp(bool bFlag);

private:
	WinInputMsgManager();
	~WinInputMsgManager();
	bool InitInputMsgManager();
	void ClearInputMsgManager();

	//�����еİ���״̬���������
	void ClearKeyDownState();
	eInputKeyType ConvertWinVirtualKeyCode2InputKeyType(unsigned int uiVirtualKeyCode);
	int ConvertInputKeyType2WinVirtualKeyCode(eInputKeyType theKey);

private:
	static WinInputMsgManager* ms_pInstance;
	SoArray m_kMsgArray1;
	SoArray m_kMsgArray2;
	//��ǰ���������Ϣ�����顣
	SoArray* m_pReceive;
	//��ǰ����ַ���Ϣ�����顣
	SoArray* m_pDispatch;
	//��¼��һ֡�ļ�λ״̬���Ƿ��ڰ���״̬��
	bool m_bKeyDownState_PreFrame[InputKey_Max];
	//��¼��ǰ֡�ļ�λ״̬���Ƿ��ڰ���״̬��
	bool m_bKeyDownState[InputKey_Max];
	//�����߼�����
	bool m_bMouseMove_CameraOp;
};
//----------------------------------------------------------------
inline WinInputMsgManager* WinInputMsgManager::Get()
{
	return ms_pInstance;
}
//----------------------------------------------------------------
inline bool WinInputMsgManager::IsKeyDown(eInputKeyType theKey)
{
	return m_bKeyDownState[theKey];
}
//----------------------------------------------------------------
inline bool WinInputMsgManager::IsKeyJustDown(eInputKeyType theKey)
{
	return (m_bKeyDownState_PreFrame[theKey] == false && m_bKeyDownState[theKey] == true);
}
//----------------------------------------------------------------
inline bool WinInputMsgManager::IsKeyJustUp(eInputKeyType theKey)
{
	return (m_bKeyDownState_PreFrame[theKey] == true && m_bKeyDownState[theKey] == false);
}
//----------------------------------------------------------------
inline void WinInputMsgManager::SetMouseMoveForCameraOp(bool bFlag)
{
	m_bMouseMove_CameraOp = bFlag;
}
//----------------------------------------------------------------
#endif //_WinInputMsgManager_h_
//----------------------------------------------------------------
