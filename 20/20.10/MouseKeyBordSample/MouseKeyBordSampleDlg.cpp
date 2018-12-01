// MouseKeyBordSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MouseKeyBordSample.h"
#include "MouseKeyBordSampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBordSampleDlg dialog

CMouseKeyBordSampleDlg::CMouseKeyBordSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMouseKeyBordSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMouseKeyBordSampleDlg)
	m_DoubleClickTime = 0;
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseKeyBordSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMouseKeyBordSampleDlg)
	DDX_Control(pDX, IDC_BUT_HWND, m_ButHWND);
	DDX_Text(pDX, IDC_EDIT_DOUBLECLICKTIME, m_DoubleClickTime);
	DDV_MinMaxInt(pDX, m_DoubleClickTime, 0, 999999);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMouseKeyBordSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMouseKeyBordSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_SETDOUBLETIME, OnButSetdoubletime)
	ON_BN_CLICKED(IDC_BUT_SWAP, OnButSwap)
	ON_BN_CLICKED(IDC_BUT_RESTORESWAP, OnButRestoreswap)
	ON_BN_CLICKED(IDC_BUT_HWND, OnButHwnd)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_GETBUTTONS, OnButtonGetbuttons)
	ON_BN_CLICKED(IDC_BUT_SENDMOUSE, OnButSendmouse)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON_GETKEYBOARD, OnButtonGetkeyboard)
	ON_BN_CLICKED(IDC_BUT_CONTROLKEY, OnButControlkey)
	ON_BN_CLICKED(IDC_BUT_REGISTHOTKEY, OnButRegisthotkey)	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBordSampleDlg message handlers

BOOL CMouseKeyBordSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMouseKeyBordSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMouseKeyBordSampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMouseKeyBordSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


#define	MAX_LOG_LENGTH	1024
// 记录日志
void CMouseKeyBordSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.10.1(OK)
void CMouseKeyBordSampleDlg::OnButSwap()	// 交换鼠标左右键
{	
	if (SwapMouseButton(TRUE))				// 交换鼠标左右键
		WriteLog("鼠标左右键已经交换");		// 输出错误提示信息
	else
        WriteLog("交换鼠标左右键成功");	// 输出提示信息
}

void CMouseKeyBordSampleDlg::OnButRestoreswap()		// 恢复鼠标左右键
{	
	if (SwapMouseButton(FALSE))				// 恢复鼠标左右键
		WriteLog("恢复鼠标左右键成功");		// 输出提示信息
	else
        WriteLog("交换鼠标左右键成功");	// 输出错误提示信息
}

// 21.10.2(OK)
void CMouseKeyBordSampleDlg::OnButSetdoubletime()	// 设置鼠标双击时间间隔
{
	UpdateData(TRUE);						// 获取要设置的鼠标双击时间间隔
	BOOL bResult = SetDoubleClickTime(m_DoubleClickTime);	// 设置双击时间间隔值
	UINT dcTime = GetDoubleClickTime();						// 获取双击时间间隔值
	WriteLog("设置鼠标双击时间间隔%s，当前值为%d", bResult ? "成功": "失败", dcTime);		
}

// 21.10.3(OK)
void CMouseKeyBordSampleDlg::OnButtonGetbuttons()	// 获得鼠标键数
{
	int iButtons = GetSystemMetrics(SM_CMOUSEBUTTONS);	// 调用GetSystemMetrics函数获取按键数
	if (iButtons > 0)									// 如果大于0，输出按键数
		WriteLog("当前系统中共有%d个鼠标按键", iButtons);
	else
        WriteLog("当前系统中没有安装鼠标");			// 否则，系统中没有安装鼠标
}

// 21.10.4(OK)
void CMouseKeyBordSampleDlg::OnButHwnd()	// 启动捕获鼠标窗体的定时器
{
	SetTimer(100, 1000, NULL);	
}

void CMouseKeyBordSampleDlg::OnTimer(UINT nIDEvent)		// 定时器处理函数
{	
	HWND m_hWnd  = ::GetCapture();						// 捕获鼠标窗体
	WriteLog("当前捕获鼠标的窗体的HWND=0x%08X", m_hWnd);// 输出句柄
	CDialog::OnTimer(nIDEvent);							// 调用基类处理函数
}

// 21.10.5(OK)
void CMouseKeyBordSampleDlg::OnButSendmouse()			// 模拟鼠标左键
{
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP , 0, 0, NULL, NULL);	// 模拟鼠标左键
}

// 21.10.6、21.10.9(OK)
BOOL CMouseKeyBordSampleDlg::PreTranslateMessage(MSG* pMsg)		// 消息预处理
{	
	if (pMsg->message == WM_KEYDOWN)	// 判断是否是按键按下
	{
		char szName[MAX_PATH]={0};		// 定义按键名称数组
		UINT uVirtKey = MapVirtualKey(pMsg->wParam, 0)<<16;	// 获取按键值	
		if (GetKeyNameText(uVirtKey, (LPTSTR)szName, sizeof(szName)))	// 获取按键名称
			WriteLog("按下键盘=%s按键", szName);		// 输出按键名称
	}
	if(GetAsyncKeyState(VK_F5))		// 判断是否所要设置的快捷键
	{   
		OnButtonGetbuttons();		// 执行快捷键要处理的函数
		return  TRUE;				// 返回
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

// 21.10.7(OK)
void CMouseKeyBordSampleDlg::OnButRegisthotkey()	// 在对话框中使用加速键
{
	if(RegisterHotKey(this->m_hWnd, VK_F1+1, MOD_CONTROL, VK_F1+1))	// 注册加速键
		WriteLog("注册加速键成功");					// 输出提示信息
	else WriteLog("注册加速键失败");				// 输出错误信息	
}


LRESULT CMouseKeyBordSampleDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) // 窗口消息处理函数
{
	char szName[MAX_PATH]={0};				// 定义名称变量
	UINT fuModifiers,uVirtKey;				// 定义按键变量
	switch(message)							// 判断消息
	{
	case WM_LBUTTONDOWN:
		WriteLog("按下鼠标左键");	
		break;
	case WM_LBUTTONUP:
		WriteLog("抬起鼠标左键");
		break;
	case WM_KEYDOWN:		
		TCHAR szName[200];
		GetKeyNameText(wParam, szName, sizeof(szName));
		WriteLog("按下%s按键", szName);
		break;
	case WM_HOTKEY:							// 接收到加速键
		uVirtKey = MapVirtualKey((UINT)HIWORD(lParam), 0)<<16;		// 获取功能按键
		if (GetKeyNameText(uVirtKey, (LPTSTR)szName, sizeof(szName)))	// 获取按键名称
			WriteLog("加速键=%s", szName);							// 输出按键名称
		fuModifiers = (UINT) LOWORD(lParam);						// 取组合功能键		
		switch(fuModifiers)		// 判断组合键
		{
		case MOD_ALT:			// ALT键
			WriteLog("（按下ALT组合键）");	break;
		case MOD_CONTROL:		// CTRL键
			WriteLog("（按下CTRL组合键）");	break;
		case MOD_SHIFT:			// SHIFT键
			WriteLog("（按下SHIFT组合键）");break;
		case MOD_WIN:			// WIN键
			WriteLog("（按下WIN组合键）");	break;
		}		
		break;
	default:
		break;
	}	
	return CDialog::WindowProc(message, wParam, lParam);
}

// 21.10.8(OK)
BOOL CMouseKeyBordSampleDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) // 处理鼠标滚轮消息
{
	WriteLog("发生鼠标滚轮事件--");		// 输出提示信息
	switch(nFlags)						// 判断有没有按下组合键，并输出
	{
	case MK_CONTROL:
		WriteLog("CTRL按键按下。");	break;
	case MK_LBUTTON:
		WriteLog("鼠标左键按下。");	break;
	case MK_MBUTTON:
		WriteLog("鼠标中键按下。");	break;
	case MK_RBUTTON:
		WriteLog("鼠标右键按下。");	break;
	case MK_SHIFT:
		WriteLog("SHIFT按键按下。");break;
	default:
		WriteLog("没有功能键按下。");break;
	}
	if (zDelta > 0)						// 输出滚轮移动的方向和大小
		WriteLog("滚轮向前移动%d", abs(zDelta));
	else
        WriteLog("滚轮向后移动%d", abs(zDelta));
	WriteLog("鼠标当前位置(相对于屏幕左上角)，X=%d;Y=%d", pt.x, pt.y);	// 输出鼠标当前位置
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);		// 基类处理函数
}

// 21.10.10(OK)
void CMouseKeyBordSampleDlg::OnButtonGetkeyboard()	// 获取键盘类型
{
	CString type[8]={"获取键盘类型失败", "IBM PC/XT or compatible (83-key) keyboard",
	"Olivetti 'ICO' (102-key) keyboard", "IBM PC/AT (84-key) or similar keyboard",
	"IBM enhanced (101- or 102-key) keyboard", "Nokia 1050 and similar keyboards",
	"Nokia 9140 and similar keyboards", "Japanese keyboard"};	// 定义键盘类型名称
	CString funKeys[8]={"获取键盘功能键数目失败", "10", "12,有时是18","10", "12",
	"10", "24","根据OEM厂商而定"};				// 定义键盘功能按键数
	int keyboardType = GetKeyboardType(0);		// 获取键盘类型
	int keyboardSubType = GetKeyboardType(1);	// 获取键盘子类型
	int functionsKeys = GetKeyboardType(2);		// 获取键盘功能按键数	
	if (keyboardType < 8)	WriteLog("键盘类型=%s", type[keyboardType]);	// 输出键盘类型
	else WriteLog("键盘类型未知");
	WriteLog("键盘子类型=%d(具体含义，需要根据键盘类型的不同进行判断)", keyboardSubType);	// 输出键盘子类型
	if (functionsKeys < 8)	WriteLog("键盘功能键数目=%s\r\n", type[functionsKeys]);	// 输出键盘功能按键数
	else WriteLog("键盘功能键数目未知");	
}

// 21.10.11(OK)
void CMouseKeyBordSampleDlg::OnButControlkey()	// 控制键盘指示灯
{
	int keys[] = {VK_CAPITAL, VK_NUMLOCK,VK_SCROLL};	// 定义控制的指示灯
	CString keysName[] = {"VK_CAPITAL", "VK_NUMLOCK","VK_SCROLL"};	// 定义指示灯名称
	for (int i = 0;i < sizeof(keys)/sizeof(int);i ++)	// 依次控制各个指示灯状态
	{	
		keybd_event( keys[i], 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );  // 切换指示灯状态
		keybd_event( keys[i], 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);// 切换指示灯状态
	}
	BYTE keyState[MAX_PATH]={0};				// 指示灯状态数组
	GetKeyboardState((LPBYTE)&keyState);		// 获取键盘状态
	for (int i = 0;i < sizeof(keys)/sizeof(int);i ++)		// 依次获取指示灯状态
		WriteLog("%s当前%s", keysName[i], keyState[keys[i]] == 1 ? "灯灭" : "灯亮");// 输出指示灯状态
}




