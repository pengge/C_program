// SysToolSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SysToolSample.h"
#include "SysToolSampleDlg.h"
#include <shlguid.h> 
#include <shlobj.h>
#include <mmsystem.h>
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>


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
// CSysToolSampleDlg dialog

CSysToolSampleDlg::CSysToolSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSysToolSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysToolSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSysToolSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysToolSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSysToolSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSysToolSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATELINK, OnButtonCreatelink)
	ON_BN_CLICKED(IDC_BUTTON_CLEARBIN, OnButtonClearbin)
	ON_BN_CLICKED(IDC_BUTTON_GETMILLSECOND, OnButtonGetmillsecond)
	ON_BN_CLICKED(IDC_BUTTON_REGISTCOM, OnButtonRegistcom)
	ON_BN_CLICKED(IDC_BUTTON_UNREGISTCOM, OnButtonUnregistcom)
	ON_BN_CLICKED(IDC_BUTTON_SHOWPRODIG, OnButtonShowprodig)
	ON_BN_CLICKED(IDC_BUTTON_GETPROCLIST, OnButtonGetproclist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysToolSampleDlg message handlers

BOOL CSysToolSampleDlg::OnInitDialog()
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

void CSysToolSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSysToolSampleDlg::OnPaint() 
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
HCURSOR CSysToolSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define MAX_LOG_LENGTH	1024
// 记录日志
void CSysToolSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.5.1(OK)
void CSysToolSampleDlg::OnButtonCreatelink()	// 为程序添加快捷方式
{
	if (!SUCCEEDED(CoInitialize(NULL)))			// 初始化COM组件
	{
		WriteLog("初始化Shell失败");			// 初始化失败显示信息
		return;									// 返回
	}
	IShellLink *pisl;							// 定义快捷方式接口变量
	if (SUCCEEDED(CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkA, (void**)&pisl))) 
	{	// 创建快捷方式实例
		IPersistFile* pIPF;						// 定义文件接口变量
		CString szPath;							// 定义文件名变量
		GetModuleFileName(GetModuleHandle(NULL), szPath.GetBuffer(MAX_PATH), MAX_PATH); // 获取运行路径
		pisl->SetPath(szPath);					// 设置文件接口的路径为当前运行路径
		szPath.ReleaseBuffer();					// 释放路径变量
		if (SUCCEEDED(pisl->QueryInterface(IID_IPersistFile, (void**)&pIPF))) 
		{	// 创建文件实例		
			CString szLinkPath;					// 定义创建的快捷方式的路径			
			SHGetSpecialFolderPath(0, szLinkPath.GetBuffer(MAX_PATH), CSIDL_DESKTOPDIRECTORY, 0);// 获取桌面对应的路径
			szLinkPath.ReleaseBuffer();			// 释放快捷方式路径变量
			szLinkPath += szPath.Mid(szPath.ReverseFind('\\'));	// 设置快捷方式的文件名
			szLinkPath += ".lnk";								// 设置快捷方式的扩展名
			WCHAR wpath[MAX_PATH] = { 0 };						// 定义Unicode字符串
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szLinkPath, -1, wpath, MAX_PATH);	// 将快捷方式的完整文件名转换为Unicode
			pIPF->Save(wpath, FALSE);			// 设置快捷方式对应的文件名
			pIPF->Release();					// 释放文件接口
			WriteLog("创建快捷方式成功，快捷方式路径=%s", szLinkPath);	// 显示创建的快捷方式信息
		}
		else
            WriteLog("创建文件接口IID_IPersistFile失败");		// 显示错误信息			
		pisl->Release();						// 释放文件接口
	} 
	else WriteLog("创建CLSID_ShellLink实例失败");				// 显示错误信息	
	CoUninitialize();							// 释放COM组件工作环境
}

// 21.5.2(OK)
void CSysToolSampleDlg::OnButtonGetproclist()	// 显示系统正在运行的程序
{
	HANDLE hPS=NULL;				// 定义进程快照句柄
    PROCESSENTRY32 pe32={0};		// 定义进程结构变量
    hPS = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);				// 创建进程快照
    if (hPS == (HANDLE)-1) 
	{
		WriteLog("调用CreateToolhelp32Snapshot函数创建进程快照失败");	// 显示错误信息
		return;						// 返回
	}
    pe32.dwSize = sizeof(PROCESSENTRY32);		// 为进程结构的大小分量赋值
    if (Process32First(hPS, &pe32))				// 检索快照中的第一个进程
    {
        do 
        {									// 显示检索到得进程信息
			WriteLog("\n优先级=%d\t进程ID=%d\t线程数目=%d\t模块名称=%s",pe32.pcPriClassBase, pe32.th32ProcessID, pe32.cntThreads, pe32.szExeFile);     
        } 
        while (Process32Next(hPS, &pe32));		// 检索快照中的下一个进程
    } 
    else
        WriteLog("调用Process32First函数枚举运行程序失败");	// 显示错误信息
    CloseHandle (hPS);				// 关闭进程快照句柄
}

// 21.5.3(OK)
void CSysToolSampleDlg::OnButtonGetmillsecond()		// 如何获得毫秒级时间
{	
	DWORD t1 = timeGetTime();						// 获取自系统启动到现在经过的毫秒数
	Sleep(10);										// 程序休眠10毫秒
	DWORD t2 = timeGetTime();						// 获取自系统启动到现在经过的毫秒数
	WriteLog("开始时间=%u", t1);					// 输出开始时间
	WriteLog("结束时间=%u", t2);					// 输出结束时间
	WriteLog("计时器10毫秒持续的时间=%u", (t2- t1));// 输出10毫秒经过的时间间隔
}

// 21.5.4(OK)
void CSysToolSampleDlg::OnButtonRegistcom()			// 注册组件
{
	CString szPath= "COMSample.dll";				// 定义组件路径名称
	HINSTANCE hLib=LoadLibrary(szPath);				// 装载组件
	if (hLib == NULL)								// 如果装载失败，
	{
		WriteLog("装载%s组件文件失败!", szPath);	// 输出错误信息
		return;										// 并返回
	} 	
	FARPROC lpEntryPoint = GetProcAddress(hLib,_T("DllRegisterServer")); // 获取DllRegisterServer函数指针
	if (lpEntryPoint != NULL)						// 如果入口函数不为NULL，则
	{	// 调用函数注册组件
		if(FAILED((*lpEntryPoint)()))	WriteLog("调用组件%s的DllRegisterServer函数失败!", szPath);// 输出错误信息
		else WriteLog("注册%s组件成功!", szPath);	// 输出成功信息
	}
	else WriteLog("没有找到组件%s的入口函数DllRegisterServer,无法注册!", szPath);	// 输出错误信息
	FreeLibrary(hLib);								// 释放对组件的引用
}

void CSysToolSampleDlg::OnButtonUnregistcom()		// 卸载组件
{
	CString szPath= "COMSample.dll";				// 定义组件路径名称
	HINSTANCE hLib=LoadLibrary(szPath);				// 装载组件
	if (hLib == NULL)								// 如果装载失败，
	{
		WriteLog("装载%s组件文件失败!", szPath);	// 输出错误信息
		return;										// 并返回
	}	
	FARPROC lpEntryPoint = GetProcAddress(hLib,_T("DllUnregisterServer"));	// 获取DllUnregisterServer函数指针
	if (lpEntryPoint != NULL)						// 如果入口函数不为NULL，则
	{	// 调用函数卸载组件
		if(FAILED((*lpEntryPoint)()))	WriteLog("调用组件%s的DllUnregisterServer失败!", szPath);	// 输出错误信息
		else WriteLog("卸载%s组件成功!", szPath);	// 输出成功信息
	}
	else WriteLog("没有找到组件%s的入口函数DllUnregisterServer,无法卸载!", szPath);					// 输出错误信息
	FreeLibrary(hLib);								// 释放对组件的引用
}

// 21.5.5(OK)
void CSysToolSampleDlg::OnButtonClearbin()			// 清空回收站
{
	if( SHEmptyRecycleBin(this->m_hWnd, NULL, NULL) == S_OK)	// 清空回收站
		WriteLog("清空回收站完成");					// 输出成功信息
	else WriteLog("清空回收站失败");				// 输出错误信息
}

// 21.5.6(OK)
void CSysToolSampleDlg::OnButtonShowprodig()		// 在程序中显示文件属性对话框
{	
	CString szPath;									// 定义路径
	GetCurrentDirectory(MAX_PATH, szPath.GetBuffer(MAX_PATH));	// 获取当前运行路径
	szPath.ReleaseBuffer();							// 释放路径变量
	SHELLEXECUTEINFO   seci;						// 定义可执行信息
	ZeroMemory(&seci,sizeof(seci));					// 初始化可行性信息变量
	seci.cbSize = sizeof(SHELLEXECUTEINFO);			// 赋值可执行变量的大小
	seci.hwnd = this->m_hWnd;						// 赋值窗体句柄
	seci.lpParameters = NULL;						// 赋值参数为NULL
	seci.lpDirectory = szPath;						// 赋值文件夹
	seci.nShow = 0;									// 不显示文件	
	seci.hInstApp = 0;								// 赋值应用实例
	szPath += "\\ReadMe.txt";						// 文件名
	seci.lpFile = szPath;							// 赋值文件名	
	seci.lpVerb = "properties";						// 赋值调用版本为属性
	seci.fMask = SEE_MASK_NOCLOSEPROCESS|SEE_MASK_INVOKEIDLIST|SEE_MASK_FLAG_NO_UI;  // 设置选项 
	ShellExecuteEx(&seci);							// 调用文件属性对话框
}

