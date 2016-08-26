//----------------------------------------------------------------
//1�����ڴ�����Ϻ��޸Ĵ���titleʹ�õĺ����� SetWindowText ��
//   �޸Ĵ��ڷ�� SetWindowLong(m_hWnd, GWL_STYLE, dwStyle);
//   �޸���Ϣ��Ӧ���� SetWindowLongW(m_hWnd, GWLP_WNDPROC, (LONG)DefWindowProc);
//
//2�����������m_hWND���ڸ�Ȩ�޽��̣���ô�������޷��յ����Ե�Ȩ�޽��̵�Windows��Ϣ��
//   ������������޸Ĺ��˹���ʹ�ñ������ܹ��յ����Ե�Ȩ�޽��̵�Windows��Ϣ��
//   void myChangeWindowMessageFilter();
//
//3��Ϊ���յ���WM_LBUTTONDBLCLK��WM_MBUTTONDBLCLK��WM_RBUTTONDBLCLK�����˫����Ϣ����Ҫ
//   ��Window��Style���������CS_DBLCLKS�������ʱ���֣�Windowsʡȥ��һЩ������Ϣ��
//   ���ԱȽϺõķ�ʽ�����Լ�ģ�����˫����Ϣ��
//----------------------------------------------------------------
#include "WinApp.h"
//----------------------------------------------------------------
//������Ϣ����
extern LRESULT CALLBACK myWindowMsgProcess(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//----------------------------------------------------------------
WinApp* WinApp::ms_pInstance = NULL;
//----------------------------------------------------------------
void WinApp::CreateWinApp()
{
	if (ms_pInstance == NULL)
	{
		ms_pInstance = new WinApp;
	}
}
//----------------------------------------------------------------
void WinApp::ReleaseWinApp()
{
	if (ms_pInstance)
	{
		delete ms_pInstance;
		ms_pInstance = NULL;
	}
}
//----------------------------------------------------------------
WinApp::WinApp()
:m_hInstance(NULL)
,m_hWND(NULL)
,m_szWindowTitle("come on")
,m_szWCName("my_dx11")
,m_nClientWidth(1024)
,m_nClientHeight(768)
,m_dwBgColor(0x999999)
,m_bCreateBrush(false)
,m_bSizeAble(false)
,m_bAcceptFiles(false)
,m_bActive(false)
,m_bMinimize(false)
,m_bBlockMsgLoopWhenDragWindow(false)
{

}
//----------------------------------------------------------------
WinApp::~WinApp()
{
	ReleaseAppWindow();
}
//----------------------------------------------------------------
bool WinApp::CreateAppWindow(HINSTANCE hInstance)
{
	//����ͼ�꣬ʹ��Ĭ�ϵ�Ӧ�ó���ͼ��
	HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//������꣬ʹ��Ĭ�ϵĹ��
	HCURSOR hCursor = LoadCursor(NULL, IDC_ARROW);
	//����������ˢ
	HBRUSH hBrush = NULL;
	if (m_bCreateBrush)
	{
		hBrush = CreateSolidBrush(m_dwBgColor);
	}

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; //�ƶ�ʱ�ػ�����Ϊ����ȡ��DC
	wc.lpfnWndProc = myWindowMsgProcess;
	wc.cbClsExtra = 0; //�޶��ⴰ������
	wc.cbWndExtra = 0; //�޶��ⴰ������
	wc.hInstance = hInstance;
	wc.hIcon = hIcon;
	wc.hCursor = hCursor;
	wc.hbrBackground = hBrush;
	wc.lpszMenuName = NULL; //����Ҫ�˵�
	wc.lpszClassName = m_szWCName;

	//ע�ᴰ����
	if (RegisterClass(&wc) == 0)
	{
		return false;
	}

	//���ô��ڷ��
	DWORD dwWinStyle = WS_BORDER|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX; //|WS_MAXIMIZEBOX
	//����m_bSizeAble��ֵ,�Դ��ڷ����е���
	if (m_bSizeAble)
	{
		dwWinStyle |= WS_THICKFRAME;
	}
	DWORD dwWinStyleEx = 0;
	if (m_bAcceptFiles)
	{
		dwWinStyleEx |= WS_EX_ACCEPTFILES;
	}
	//���ڵĳ�ʼλ��
	int nPosX = 0;
	int nPosY = 0;
	//û�и�����
	HWND hWndParent = NULL;
	//û�в˵�
	HMENU hMenu = NULL;
	//û����Ҫ���ݵĲ���
	LPVOID lpParam = NULL;

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	RECT winRect;
	winRect.left = nPosX;
	winRect.top = nPosY;
	winRect.right = nPosX + m_nClientWidth;
	winRect.bottom = nPosY + m_nClientHeight;
	BOOL bHaveMenu = FALSE; //û�в˵���
	BOOL bAdjustResult = AdjustWindowRectEx(&winRect, dwWinStyle, bHaveMenu, dwWinStyleEx);
	if (bAdjustResult == FALSE)
	{
		//������
	}
	const int nRealWidth = winRect.right-winRect.left;
	const int nRealHeight = winRect.bottom-winRect.top;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	HWND hWnd = CreateWindowEx(dwWinStyleEx, m_szWCName, m_szWindowTitle, dwWinStyle, 
		nPosX, nPosY, nRealWidth, nRealHeight,
		hWndParent, hMenu, hInstance, lpParam);
	if (hWnd == NULL) 
	{
		return false;
	}

	//ǰ��Ĳ������ɹ���
	m_hInstance = hInstance;
	m_hWND = hWnd;
	//
	myChangeWindowMessageFilter();
	return true;
}
//----------------------------------------------------------------
void WinApp::ReleaseAppWindow()
{
	if (m_hWND)
	{
		//���ٴ���
		BOOL br = DestroyWindow(m_hWND);
		if (br == FALSE)
		{

		}
		m_hWND = NULL;
	}
	//��ע�ᴰ����
	if (m_hInstance)
	{
		BOOL bResult = UnregisterClass(m_szWCName, m_hInstance);
		if (bResult == FALSE)
		{

		}
		m_hInstance = NULL;
	}
}
//----------------------------------------------------------------
void WinApp::myChangeWindowMessageFilter()
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	typedef struct tagCHANGEFILTERSTRUCT
	{
		DWORD cbSize;
		DWORD ExtStatus;
	} CHANGEFILTERSTRUCT, *PCHANGEFILTERSTRUCT;

#define MSGFLT_ALLOW 1
#define MSGFLT_DISALLOW 2
#define MSGFLT_RESET 0

	typedef BOOL (WINAPI *LPFUNC)(HWND, UINT, DWORD, PCHANGEFILTERSTRUCT);
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	HMODULE hLib = LoadLibrary("user32.dll");
	if (hLib == NULL)
	{
		return;
	}
	LPFUNC dllFunc = (LPFUNC)GetProcAddress(hLib, "ChangeWindowMessageFilterEx");
	if (dllFunc == NULL)
	{
		FreeLibrary(hLib);
		return;
	}
	CHANGEFILTERSTRUCT chfit = { sizeof(CHANGEFILTERSTRUCT) };

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//�û���������Ӵ���
	dllFunc(m_hWND, WM_COPYDATA, MSGFLT_ALLOW, &chfit);
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	FreeLibrary(hLib);
}
//----------------------------------------------------------------
