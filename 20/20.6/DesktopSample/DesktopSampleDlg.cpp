// DesktopSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DesktopSample.h"
#include "DesktopSampleDlg.h"

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
// CDesktopSampleDlg dialog

CDesktopSampleDlg::CDesktopSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDesktopSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDesktopSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDesktopSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDesktopSampleDlg)
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDesktopSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CDesktopSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SHOW_START, OnButtonShowStart)
	ON_BN_CLICKED(IDC_BUTTON_HIDE_START, OnButtonHideStart)
	ON_BN_CLICKED(IDC_BUTTON_HIDE_BAR, OnButtonHideBar)
	ON_BN_CLICKED(IDC_BUTTON_SHOW_BAR, OnButtonShowBar)
	ON_BN_CLICKED(IDC_BUTTON_GET_FONT, OnButtonGetFont)
	ON_BN_CLICKED(IDC_BUTTON_GET_BAR, OnButtonGetBar)
	ON_BN_CLICKED(IDC_BUTTON_SHOW_CLOCK, OnButtonShowClock)
	ON_BN_CLICKED(IDC_BUTTON_HIDE_CLOCK, OnButtonHideClock)
	ON_BN_CLICKED(IDC_BUTTON_HIDE_DESKTOP, OnButtonHideDesktop)
	ON_BN_CLICKED(IDC_BUTTON_SHOW_DESKTOP, OnButtonShowDesktop)
	ON_BN_CLICKED(IDC_BUTTON_SAVERSCREEN_RUNNING, OnButtonSaverscreenRunning)
	ON_BN_CLICKED(IDC_BUTTON_SET_BACKGROUD, OnButtonSetBackgroud)
	ON_BN_CLICKED(IDC_BUTTON_GET_DESKLIST, OnButtonGetDesklist)
	ON_BN_CLICKED(IDC_BUTTON_GETTOOLBARPRO, OnButtonGettoolbarpro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesktopSampleDlg message handlers

BOOL CDesktopSampleDlg::OnInitDialog()
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

void CDesktopSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDesktopSampleDlg::OnPaint() 
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
HCURSOR CDesktopSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define MAX_LOG_LENGTH 1024
// 记录日志
void CDesktopSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.6.2(OK)
void CDesktopSampleDlg::OnButtonGetBar()	// 获取任务栏对话框句柄
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// 获取任务栏对话框
	if(hWinBar != NULL)	WriteLog("获取任务栏窗口句柄成功=0x%08X", hWinBar);	// 输出信息
	else WriteLog("获取任务栏窗口句柄失败");			// 输出错误信息
}

// 21.6.3(OK)
void CDesktopSampleDlg::OnButtonGetDesklist()		// 获取桌面列表视图句柄
{
	HWND hDeskWnd = ::FindWindow("Progman",NULL);	// 获取桌面程序对象
	if(hDeskWnd == NULL)							// 如果获取失败
	{
		WriteLog("获取桌面句柄失败。");	return;		// 显示错误信息并返回		
	}	
	HWND  hSubDeskWnd=::GetDlgItem(hDeskWnd, 0L);	// 获取桌面对象中的第一个对象
	if(hSubDeskWnd == NULL)								// 如果获取失败
	{
		WriteLog("获取桌面窗体中的对象失败。");	return;	// 显示错误信息并返回
	}  
	HWND  hDeskList=::GetDlgItem(hSubDeskWnd, 1L);		// 获取桌面对象中的第一个对象的第二个对象
	if(hDeskList == NULL)								// 如果获取失败
	{	
		WriteLog("获取桌面窗体中的对象失败。");	return;	// 显示错误信息并返回
	}
	WriteLog("获取桌面列表视图句柄成功=0x%08X", hDeskList);	// 输出获取的信息
}

// 21.6.4(OK)
void CDesktopSampleDlg::OnButtonGettoolbarpro()			// 获取任务栏属性
{	   
	if(FAILED(CoInitialize(NULL)))						// 初始化COM工作环境
	{
		WriteLog("初始化COM工作环境失败");	return;		// 显示错误信息并返回
	}
	IShellDispatch* pShellDispatch=NULL;				// 定义IShellDispatch接口变量
	if(SUCCEEDED(CoCreateInstance(CLSID_Shell,NULL,CLSCTX_INPROC_SERVER, IID_IDispatch,(LPVOID*)&pShellDispatch)))   
	{	// 创建IShellDispatch实例
		if(SUCCEEDED(pShellDispatch->TrayProperties())) WriteLog("显示任务栏属性窗口成功");	// 显示成功信息
		else WriteLog("显示任务栏属性窗口失败");		// 显示错误信息
	}
	else WriteLog("创建IShellDispatch接口实例失败");	// 显示错误信息
	CoUninitialize();									// 释放COM工作环境
}

// 21.6.5(OK)	
void CDesktopSampleDlg::OnButtonHideDesktop()			// 隐藏桌面文件
{	
	HWND hDeskWnd = ::FindWindow("Progman",NULL);		// 获取桌面文件句柄	
	if(hDeskWnd!=NULL)	::ShowWindow(hDeskWnd, SW_HIDE);// 隐藏桌面文件
}
void CDesktopSampleDlg::OnButtonShowDesktop()			// 显示桌面文件
{	
	HWND hDeskWnd = ::FindWindow("Progman",NULL);		// 获取桌面文件句柄	
	if(hDeskWnd!=NULL)	::ShowWindow(hDeskWnd, SW_SHOW);// 显示桌面
}

// 21.6.6(OK)
void CDesktopSampleDlg::OnButtonHideBar()				// 隐藏任务栏
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// 获取任务栏句柄
	if(hWinBar!=NULL)	::ShowWindow(hWinBar, SW_HIDE);	// 隐藏任务栏
}
void CDesktopSampleDlg::OnButtonShowBar()				// 显示任务栏
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// 获取任务栏句柄	
	if(hWinBar!=NULL)	::ShowWindow(hWinBar, SW_SHOW);	// 显示任务栏
}

// 21.6.7(OK)
void CDesktopSampleDlg::OnButtonShowStart()				// 显示开始按钮
{
    HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// 获取任务栏句柄
    if(hWinBar!=NULL)
    {
        HWND hMenu = ::FindWindowEx(hWinBar, 0, "Button", NULL);	// 获取开始按钮句柄
        if(hMenu!=NULL)	::ShowWindow(hMenu, SW_SHOW);	// 显示开始按钮
        else WriteLog("获取开始按钮对话框句柄失败");	// 输出错误信息
    }
    else WriteLog("获取Windows任务栏句柄失败");			// 输出错误信息
}
void CDesktopSampleDlg::OnButtonHideStart()				// 隐藏开始按钮
{
    HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// 获取任务栏句柄
    if(hWinBar!=NULL)
    {
        HWND hMenu = ::FindWindowEx(hWinBar, 0, "Button", NULL);	// 获取开始按钮句柄
        if(hMenu!=NULL)	::ShowWindow(hMenu, SW_HIDE);	// 隐藏开始按钮
        else WriteLog("获取开始按钮对话框句柄失败");	// 输出错误信息
    }
    else WriteLog("获取Windows任务栏句柄失败");			// 输出错误信息
}

// 21.6.8(OK)
void CDesktopSampleDlg::OnButtonHideClock()					// 隐藏任务栏时钟
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd",NULL);		// 获取任务栏句柄
	if (hWinBar != NULL)									// 如果成功，则
	{
		HWND hNotifyWnd = ::FindWindowEx(hWinBar, 0, "TrayNotifyWnd",NULL);	// 获取通知托盘句柄
		if (hNotifyWnd != NULL)								// 如果成功，则
		{
			HWND hClockWnd = ::FindWindowEx(hNotifyWnd, 0, "TrayClockWClass", NULL);	// 获取时钟句柄
			if(hClockWnd!=NULL)	::ShowWindow(hClockWnd, SW_HIDE);	// 如果成功，则隐藏时钟
			else  WriteLog("获取时钟句柄失败");				// 显示错误信息
		}
		else WriteLog("获取通知托盘句柄失败");				// 显示错误信息
	}
	else WriteLog("获取任务栏句柄失败");					// 显示错误信息
}
void CDesktopSampleDlg::OnButtonShowClock()					// 显示任务栏时钟
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd",NULL);		// 获取任务栏句柄
	if (hWinBar != NULL)									// 如果成功，则
	{
		HWND hNotifyWnd = ::FindWindowEx(hWinBar, 0, "TrayNotifyWnd",NULL);	// 获取通知托盘句柄
		if (hNotifyWnd != NULL)								// 如果成功，则
		{
			HWND hClockWnd = ::FindWindowEx(hNotifyWnd, 0, "TrayClockWClass", NULL);	// 获取时钟句柄
			if(hClockWnd!=NULL)	::ShowWindow(hClockWnd, SW_SHOW);	// 如果成功，则显示时钟
			else  WriteLog("获取时钟句柄失败");				// 显示错误信息
		}
		else WriteLog("获取通知托盘句柄失败");				// 显示错误信息
	}
	else WriteLog("获取任务栏句柄失败");					// 显示错误信息	
}

// 21.6.9(OK)
void CDesktopSampleDlg::OnButtonSaverscreenRunning()	// 判断屏幕保护程序是否在运行
{
	HDESK hDesktop;										// 定义桌面句柄
    hDesktop = OpenDesktop(TEXT("screen-saver"), 0, FALSE, MAXIMUM_ALLOWED );	// 打开桌面屏保程序
    if(hDesktop == NULL)								// 如果返回的句柄无效，则
	{
		if(GetLastError() == ERROR_ACCESS_DENIED)		// 如果返回ERROR_ACCESS_DENIED错误=屏保正在运行
			WriteLog("屏保正在运行");					// 输出信息提示
		else WriteLog("没有运行屏保");					// 否则=屏保没有运行
	}
	else												// 如果返回的句柄有效=屏保正在运行
	{
		WriteLog("屏保正在运行");						// 输出信息提示
		CloseDesktop(hDesktop);							// 关闭桌面
	}
}

// 21.6.10(OK)
void CDesktopSampleDlg::OnButtonGetFont()				// 判断系统是否使用大字体
{
	HWND hWnd = ::GetDesktopWindow();					// 获取桌面句柄
	if (hWnd != NULL)									// 如果成功，则
	{
		HDC	hDC = ::GetWindowDC(hWnd);					// 获取桌面上下文
		if (hDC != NULL)								// 如果成功，则
		{
			int	iOldMode = SetMapMode(hDC, MM_TEXT);	// 设置上下文映射模式 
			TEXTMETRIC   tm;							// 定义字体结构变量
			if (GetTextMetrics(hDC,&tm))				// 获取桌面上下文字体信息
			{
				SetMapMode(hDC,iOldMode);				// 恢复桌面上下文的映射模式
				::ReleaseDC(hWnd,hDC);					// 释放上下文资源
				if (tm.tmHeight > 16)					// 使用大字体
					WriteLog("系统使用的是大字体，大小=%d", tm.tmHeight);	
				else WriteLog("系统使用的不是大字体，大小=%d", tm.tmHeight);   // 没有使用大字体
			}
			else WriteLog("获取字体信息失败");			// 输出错误信息
		}
		else WriteLog("获取桌面上下文失败");			// 输出错误信息
	}
	else WriteLog("获取桌面句柄失败");					// 输出错误信息
}

// 21.6.11(OK)
void CDesktopSampleDlg::OnButtonSetBackgroud()			// 改变桌面背景颜色
{
	if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "River Sumida.jpg", 0))	// 修改桌面背景
		WriteLog("设置桌面背景成功");					// 输出提示信息
	else WriteLog("设置桌面背景失败");					// 输出错误信息
}




