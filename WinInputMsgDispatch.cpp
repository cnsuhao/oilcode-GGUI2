//----------------------------------------------------------------
#include "WinInputMsgDispatch.h"
#include "WinInputMsg.h"
#include "GGUIInputHelp.h"
//----------------------------------------------------------------
void WinInputMsgDispatch_Process(stInputEvent* pInputEvent)
{
	//��Ӧ��Ϣ�߼�������ģ���������Ŷӡ�
	//
	GGUIInputProcess(pInputEvent);
	if (pInputEvent->bSwallowed == true)
	{
		return;
	}
}
//----------------------------------------------------------------
