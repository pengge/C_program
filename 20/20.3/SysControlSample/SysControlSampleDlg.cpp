// SysControlSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SysControlSample.h"
#include "SysControlSampleDlg.h"
#include "imm.h"
#include "mmsystem.h"
#include "winuser.h"
#include <afx.h>
#include <afxwin.h>

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
// CSysControlSampleDlg dialog

CSysControlSampleDlg::CSysControlSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSysControlSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysControlSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSysControlSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysControlSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSysControlSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSysControlSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXE, OnButtonExe)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SCREENSAVER, OnButtonOpenScreensaver)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_MONITOR, OnButtonCloseMonitor)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_MONITOR, OnButtonOpenMonitor)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_SCREENSAVER, OnButtonDisableScreensaver)
	ON_BN_CLICKED(IDC_BUTTON_ENABLE_SCREENSAVER, OnButtonEnableScreensaver)
	ON_BN_CLICKED(IDC_BUTTON_CLOSEIMM, OnButtonCloseimm)
	ON_BN_CLICKED(IDC_BUTTON_BEEP, OnButtonBeep)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_CDROM, OnButtonOpenCdrom)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_CDROM, OnButtonCloseCdrom)
	ON_BN_CLICKED(IDC_BUTTON_LOGOFF_OS, OnButtonLogoffOs)
	ON_BN_CLICKED(IDC_BUTTON_RESTART_OS, OnButtonRestartOs)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_OS, OnButtonCloseOs)
	ON_BN_CLICKED(IDC_BUTTON_LINK_WIZARD, OnButtonLinkWizard)
	ON_BN_CLICKED(IDC_BUTTON_EXE_CONTROLITEM, OnButtonExeControlitem)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_SEARCHFILE, OnButtonCloseSearchfile)
	ON_BN_CLICKED(IDC_BUTTON_LOCK_SYSTEM, OnButtonLockSystem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysControlSampleDlg message handlers

BOOL CSysControlSampleDlg::OnInitDialog()
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

void CSysControlSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSysControlSampleDlg::OnPaint() 
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
HCURSOR CSysControlSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 记录日志
void CSysControlSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[1024]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.3.1(OK)
void CSysControlSampleDlg::OnButtonExe()	// 调用外部程序
{
	STARTUPINFO    si;						// 定义启动信息变量
	PROCESS_INFORMATION    pi;				// 定义进程信息变量
	HANDLE     hProcess,hThread;			// 定义进程句柄和线程句柄
	si.cb =sizeof(STARTUPINFO);				// 为启动信息变量大小赋值
	si.lpReserved = NULL;					// 预留
	si.lpDesktop=NULL;						// 桌面句柄
	si.lpTitle=NULL;						// 进程标题，只对控制台程序有效
	si.cbReserved2=0;						// 预留
	si.lpReserved2=NULL;					// 预留
	if (CreateProcess("C:\\WINDOWS\\NOTEPAD.EXE", NULL,
           NULL, NULL, TRUE, 0, NULL,NULL, &si,&pi))     // 启动记事本      
	{		
		hProcess = pi.hProcess;
        hThread = pi.hThread;	// 保存进程和线程句柄
		WriteLog("调用外部程序成功。\n进程Id = %d\n线程Id = %d\n",pi.dwProcessId,pi.dwThreadId);	// 输出进程信息
	}
	else WriteLog("调用记事本失败。错误代码=%X",GetLastError());	// 输出错误代码	
}

// 21.3.2(OK)
void CSysControlSampleDlg::OnButtonLinkWizard()		// 调用创建快捷方式向导
{	
	WinExec("rundll32.exe appwiz.cpl,NewLinkHere C:\\", SW_SHOW);
}

// 21.3.3(OK)
void CSysControlSampleDlg::OnButtonExeControlitem() // 访问启动控制面板中的各项
{
	if (SUCCEEDED(CoInitialize(NULL))) 			// 初始化COM工作环境
	{
		IShellDispatch* pShellDispatch=NULL; 		// 定义接口指针
		// 创建CLSID_Shell接口实例
		if (SUCCEEDED(CoCreateInstance(CLSID_Shell, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&pShellDispatch))) 
		{	// 如果成功，则
			COleVariant   OleVariant("sysdm.cpl"); 	// 初始化控制面板对应的cpl名
			// 调用指定cpl名对应的对话框程序
			HRESULT hResult = pShellDispatch->ControlPanelItem(OleVariant.bstrVal); 
			pShellDispatch->Release(); 
		} 
		else WriteLog("创建CLSID_Shell实例失败");	// 如果创建实例失败，则显示错误信息
		CoUninitialize();							// 清理COM工作环境
	}
	else WriteLog("初始化Shell失败");			// 初始化COM环境失败，则显示错误信息
}

// 21.3.4(OK)
void CSysControlSampleDlg::OnButtonOpenCdrom()	// 控制光驱的弹开
{	   
	MCI_OPEN_PARMS   mciOpenParms;    
	mciOpenParms.lpstrDeviceType   =   "cdaudio";
	if (!mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE,
        (DWORD)(LPVOID)&mciOpenParms))	  
		mciSendCommand(mciOpenParms.wDeviceID, MCI_SET, MCI_SET_DOOR_OPEN, NULL); 	
}

void CSysControlSampleDlg::OnButtonCloseCdrom() // 控制光驱的关闭
{
	mciSendCommand(mciGetDeviceID("cdaudio"), MCI_SET, MCI_SET_DOOR_CLOSED, NULL); 
}

// 21.3.5(OK)
void CSysControlSampleDlg::OnButtonLogoffOs()	// 注销
{
	ExitWindowsEx(EWX_LOGOFF,NULL);				// 注销操作系统
}

void CSysControlSampleDlg::OnButtonRestartOs()	// 重启
{
	ExitWindowsEx(EWX_REBOOT,NULL);				// 重启操作系统
}

void CSysControlSampleDlg::OnButtonCloseOs()	// 关机
{
	ExitWindowsEx(EWX_POWEROFF,NULL);			// 关机操作系统
}

typedef BOOL (*LOCKFUN)(VOID);					// 定义LockWorkStation函数原型
void CSysControlSampleDlg::OnButtonLockSystem() // 锁定计算机
{
	HINSTANCE hInstance = ::LoadLibrary("user32.dll");	// 装载user32.dll
	LOCKFUN pFun = (LOCKFUN)::GetProcAddress(hInstance,"LockWorkStation");// 获取函数指针
	pFun();						// 执行函数，锁定计算机
}

// 21.3.6(OK)
void CSysControlSampleDlg::OnButtonOpenMonitor() // 打开显示器
{
	::SendMessage(GetSafeHwnd(),WM_SYSCOMMAND,SC_MONITORPOWER,-1);	
}

void CSysControlSampleDlg::OnButtonCloseMonitor() // 关闭显示器
{
	::SendMessage(GetSafeHwnd(),WM_SYSCOMMAND,SC_MONITORPOWER,2);	
}

// 21.3.7(OK)
void CSysControlSampleDlg::OnButtonDisableScreensaver() // 禁用屏幕保护程序
{
    SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, FALSE, NULL, 0); 
}

void CSysControlSampleDlg::OnButtonEnableScreensaver() // 启用屏幕保护程序
{
	SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, TRUE, NULL, 0);  
}

void CSysControlSampleDlg::OnButtonOpenScreensaver()	// 打开屏幕保护程序
{
	::SendMessage(GetSafeHwnd(),WM_SYSCOMMAND,SC_SCREENSAVE,2);	
}

// 21.3.8(OK)
void CSysControlSampleDlg::OnButtonCloseimm()	// 关闭当前输入法
{
	HIMC  himc = ImmGetContext(m_editLog.m_hWnd);
	ImmSetOpenStatus(himc, FALSE);
}

// 21.3.9(OK)
void CSysControlSampleDlg::OnButtonBeep()	// 程序发出提示音
{
	MessageBeep(MB_ICONASTERISK);	
}


// 21.3.10(OK)
void CSysControlSampleDlg::OnButtonCloseSearchfile()	// 列举系统中的可执行文件
{	
	iFileCount = 0;
	::SetCursor(LoadCursor(NULL, IDC_WAIT));	
	char szDrivers[MAX_PATH]={0};
	CString szPath;
	DWORD dwLen = GetLogicalDriveStrings(MAX_PATH, szDrivers);
	for (int i = 0;i < (int)dwLen; i++)
	{
		if (((szDrivers[i] <='Z') && (szDrivers[i] >='A'))
			|| ((szDrivers[i] <='z') && (szDrivers[i] >='a')))
		{
			szPath.Format("%c:", szDrivers[i]);
			FindExe(szPath);
		}
	}
	::SetCursor(LoadCursor(NULL, IDC_ARROW));	
}

void CSysControlSampleDlg::FindExe(CString szPath)
{
	CFileFind ff;
	BOOL bContinue = ff.FindFile(szPath + "\\*");
	while (bContinue)
	{
		if (iFileCount > 10) return;
		bContinue = ff.FindNextFile();
		if (ff.IsDirectory())
		{
			if (ff.GetFileName().Left(1) != ".")
			{
				CString szRecuPath;
				szRecuPath.Format("%s\\%s", szPath, ff.GetFileName());
				FindExe(szRecuPath);
				continue;
			}			
		}
		if (ff.GetFileName().Right(3) == "exe")
		{
			iFileCount++;
			WriteLog("%s%s", ff.GetFilePath(), ff.GetFileName());					
		}
	}
}


