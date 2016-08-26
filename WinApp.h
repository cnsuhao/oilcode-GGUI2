//----------------------------------------------------------------
#ifndef _WinApp_h_
#define _WinApp_h_
//----------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//----------------------------------------------------------------
class WinApp
{
public:
	static void CreateWinApp();
	static void ReleaseWinApp();
	static WinApp* Get();

	//����Windows����
	bool CreateAppWindow(HINSTANCE hInstance);
	//����Windows����
	void ReleaseAppWindow();

	HWND GetHWND();
	int GetClientWidth();
	int GetClientHeight();

	void SetClientWidthHeight(int nWidth, int nHeight);
	bool GetWindowSizeAble();

	void SetWindowActive(bool bActive);
	bool GetWindowActive();

	void SetWindowMinimize(bool bMini);
	bool GetWindowMinimize();

	bool GetBlockMsgLoopWhenDragWindow();

private:
	WinApp();
	~WinApp();
	//���������m_hWND���ڸ�Ȩ�޽��̣���ô�������޷��յ����Ե�Ȩ�޽��̵�Windows��Ϣ��
	//������������޸Ĺ��˹���ʹ�ñ������ܹ��յ����Ե�Ȩ�޽��̵�Windows��Ϣ��
	void myChangeWindowMessageFilter();

private:
	static WinApp* ms_pInstance;
	HINSTANCE m_hInstance; //���̾��
	HWND m_hWND; //���ھ��
	const char* m_szWindowTitle; //���ڱ������ַ���
	const char* m_szWCName; //�����������
	int m_nClientWidth; //���ڿͻ����Ŀ�
	int m_nClientHeight; //���ڿͻ����ĸ�
	DWORD m_dwBgColor; //������ˢ����ɫ
	bool m_bCreateBrush; //�Ƿ񴴽�������ˢ����Щ����²���Ҫ����������ˢ��������D3D����OpenGL�������档
	bool m_bSizeAble; //�Ƿ���Ե������ڿ��
	bool m_bAcceptFiles; //�����Ƿ���Ӧ�����ļ��Ϸŵ������ڡ�����Ϣ
	bool m_bActive; //���ڵ�ǰ�Ƿ��ڼ���״̬
	bool m_bMinimize; //���ڵ�ǰ�Ƿ�����С��״̬
	bool m_bBlockMsgLoopWhenDragWindow; //������϶�����ʱ���Ƿ�������Ϣѭ�������������Ϣѭ��������Ϸ���治�ܸ��¡�
};
//----------------------------------------------------------------
inline WinApp* WinApp::Get()
{
	return ms_pInstance;
}
//----------------------------------------------------------------
inline HWND WinApp::GetHWND()
{
	return m_hWND;
}
//----------------------------------------------------------------
inline int WinApp::GetClientWidth()
{
	return m_nClientWidth;
}
//----------------------------------------------------------------
inline int WinApp::GetClientHeight()
{
	return m_nClientHeight;
}
//----------------------------------------------------------------
inline void WinApp::SetClientWidthHeight(int nWidth, int nHeight)
{
	m_nClientWidth = nWidth;
	m_nClientHeight = nHeight;
}
//----------------------------------------------------------------
inline bool WinApp::GetWindowSizeAble()
{
	return m_bSizeAble;
}
//----------------------------------------------------------------
inline void WinApp::SetWindowActive(bool bActive)
{
	m_bActive = bActive;
}
//----------------------------------------------------------------
inline bool WinApp::GetWindowActive()
{
	return m_bActive;
}
//----------------------------------------------------------------
inline void WinApp::SetWindowMinimize(bool bMini)
{
	m_bMinimize = bMini;
}
//----------------------------------------------------------------
inline bool WinApp::GetWindowMinimize()
{
	return m_bMinimize;
}
//----------------------------------------------------------------
inline bool WinApp::GetBlockMsgLoopWhenDragWindow()
{
	return m_bBlockMsgLoopWhenDragWindow;
}
//----------------------------------------------------------------
#endif //_WinApp_h_
//----------------------------------------------------------------
