//----------------------------------------------------------------
#include "WinApp.h"
#include "WinAppHelp.h"
//----------------------------------------------------------------
//�������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	do 
	{
		bool bEventResult = true;

		bEventResult = WinAppHelp_OnPreCreateWinApp();
		if (bEventResult == false)
		{
			//ĳЩģ���ʼ��ʧ��
			break;
		}
		WinApp::CreateWinApp();
		bEventResult = WinAppHelp_OnPostCreateWinApp();
		if (bEventResult == false)
		{
			//ĳЩģ���ʼ��ʧ��
			break;
		}

		bEventResult = WinAppHelp_OnPreCreateAppWindow();
		if (bEventResult == false)
		{
			//ĳЩģ���ʼ��ʧ��
			break;
		}
		bool bCreateAppWindow = WinApp::Get()->CreateAppWindow(hInstance);
		if (bCreateAppWindow == false)
		{
			break;
		}
		bEventResult = WinAppHelp_OnPostCreateAppWindow();
		if (bEventResult == false)
		{
			//ĳЩģ���ʼ��ʧ��
			break;
		}

		bEventResult = WinAppHelp_OnPreShowCreatedAppWindow();
		if (bEventResult == false)
		{
			//ĳЩģ���ʼ��ʧ��
			break;
		}
		HWND mainHWND = WinApp::Get()->GetHWND();
		ShowWindow(mainHWND, SW_SHOW);
		SetForegroundWindow(mainHWND); //��΢������ȼ�
		SetFocus(mainHWND); //���ü��̵Ľ������˴���
		bEventResult = WinAppHelp_OnPostShowCreatedAppWindow();
		if (bEventResult == false)
		{
			//ĳЩģ���ʼ��ʧ��
			break;
		}

		//��Ϣ��ѭ��
		bool bDone = false;
		MSG msg;
		while (bDone == false)
		{
			//����Ҫ���ĵ�һ�����Ǽ���Ƿ�����Ϣ�ڵȴ���
			//ʹ��PeekMessage()�����ڲ���ס���ǵĳ����ǰ���¶���Ϣ���м�顣
			//������ʹ��GetMessage()��Ҳ���ԺܺõĹ�����
			//��ʹ��GetMessage()���������յ�paint��Ϣ���������ʲô������Ϣ֮ǰ�������κ��¡�
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				//����Ƿ�����˳���Ϣ��
				//�����ǰ����Ϣ����PostQuitMessage(0)�����WM_QUIT�����˳���ѭ����
				if (msg.message == WM_QUIT)
				{
					bDone = true;
				}
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else
			{
				//û��Windows��Ϣ�����ºͻ������ǵ���Ϸ������
				WinAppHelp_OnAppUpdate();
				WinAppHelp_OnAppRender();
			}
		} //��Ϣ��ѭ��

	} while (0);

	//�����˳����ͷ�����
	WinAppHelp_OnPreReleaseWinApp();
	WinApp::ReleaseWinApp();
	WinAppHelp_OnPostReleaseWinApp();
	return 0;
}
//----------------------------------------------------------------
//������Ϣ����
LRESULT CALLBACK myWindowMsgProcess(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//�������ķ���ֵ��ȡ���ڴ�����Ϣ���͡���ͬ����ϢID��Ҫ��ķ���ֵ��ͬ��
	//����Ҫ���� WM_DESTROY ��Ϣ��
	switch (uMsg)
	{
	case WM_CLOSE:
		{
			//Windows���ڽ����رա������׳��˳���Ϣ����ѭ�������жϣ�Ȼ��ִ���˳����̡�
			PostQuitMessage(0);
			return 0;
		}
		break;
	}

	const int nResult = WinAppHelp_WindowMsgProc(uMsg, wParam, lParam);
	if (nResult == -1)
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	else
	{
		return nResult;
	}
}
//------------------------------------------------------------
