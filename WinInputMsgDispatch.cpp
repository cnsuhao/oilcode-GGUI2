//----------------------------------------------------------------
#include "WinInputMsgDispatch.h"
#include "WinInputMsg.h"
#include "GGUIInputHelp.h"
//----------------------------------------------------------------
void WinInputMsgDispatch_Process(stInputEvent* pInputEvent)
{
	//响应消息逻辑，各个模块在下面排队。
	//
	GGUIInputProcess(pInputEvent);
	if (pInputEvent->bSwallowed == true)
	{
		return;
	}
}
//----------------------------------------------------------------
