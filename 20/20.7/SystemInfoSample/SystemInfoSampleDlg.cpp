// SystemInfoSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SystemInfoSample.h"
#include "SystemInfoSampleDlg.h"
#include "mmsystem.h"

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
// CSystemInfoSampleDlg dialog

CSystemInfoSampleDlg::CSystemInfoSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemInfoSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSystemInfoSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSystemInfoSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSystemInfoSampleDlg)
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSystemInfoSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSystemInfoSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GET_SYSVERSION, OnButtonGetSysversion)
	ON_BN_CLICKED(IDC_BUTTON_GET_WINDOWPATH, OnButtonGetWindowpath)
	ON_BN_CLICKED(IDC_BUTTON_GET_SYSTEMPATH, OnButtonGetSystempath)
	ON_BN_CLICKED(IDC_BUTTON_GET_USERNAME, OnButtonGetUsername)
	ON_BN_CLICKED(IDC_BUTTON_SET_COMPUTE_NAME, OnButtonSetComputeName)
	ON_BN_CLICKED(IDC_BUTTON_GETRUNTIME, OnButtonGetruntime)
	ON_BN_CLICKED(IDC_BUTTON_GETSTARTTIME, OnButtonGetstarttime)
	ON_BN_CLICKED(IDC_BUTTON_GETSTARTMODE, OnButtonGetstartmode)
	ON_BN_CLICKED(IDC_BUTTON_GET_PROCESSOR, OnButtonGetProcessor)
	ON_BN_CLICKED(IDC_BUTTON_GET_SCREENXY, OnButtonGetScreenxy)
	ON_BN_CLICKED(IDC_BUTTON_GET_SCREENCOLOR, OnButtonGetScreencolor)
	ON_BN_CLICKED(IDC_BUTTON_GET_ENROVAR, OnButtonGetEnrovar)
	ON_BN_CLICKED(IDC_BUTTON_GET_CPUID, OnButtonGetCpuid)
	ON_BN_CLICKED(IDC_BUTTON_GET_CPUFREQUENCY, OnButtonGetCpufrequency)
	ON_BN_CLICKED(IDC_BUTTON_ISAUDIO, OnButtonIsaudio)
	ON_BN_CLICKED(IDC_BUTTON_GETSPECIALPATH, OnButtonGetspecialpath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemInfoSampleDlg message handlers

BOOL CSystemInfoSampleDlg::OnInitDialog()
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

void CSystemInfoSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSystemInfoSampleDlg::OnPaint() 
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
HCURSOR CSystemInfoSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define MAX_LOG_LENGTH 1024
// 记录日志
void CSystemInfoSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.7.1(OK)
void CSystemInfoSampleDlg::OnButtonGetCpuid()	// 获取CPU ID值
{
	BYTE szCPU[16]= {0};			// 定义存放CPU类型的数组
	UINT uCPUID = 0U;				// 定义存放CPUID的数组
	_asm							// 开始执行汇编
	{
		mov eax, 0					// 获取CPU型号
		cpuid						
		mov dword ptr szCPU[0], ebx	// 取CPU型号的前4个字符
		mov dword ptr szCPU[4], edx	// 取CPU型号的中间4个字符
		mov dword ptr szCPU[8], ecx	// 取CPU型号的最后4个字符
		mov eax, 1					// 取CPUID
		cpuid
		mov uCPUID, edx				// 取CPUID的值
	}
	WriteLog("当前系统的CPU类型为=%s----CPU ID=%u", szCPU, uCPUID);	// 输出CPU信息
}

// 21.7.2(OK)
void CSystemInfoSampleDlg::OnButtonGetCpufrequency()	// 获取CPU时钟频率
{
	unsigned long ulSpeed=0;	// 定义CPU时钟频率变量  
	HKEY hKey;					// 定义注册表键
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey) == ERROR_SUCCESS)   
	{   // 打开注册表
		unsigned long ulLen= sizeof(ulSpeed);	// 赋值长度	
		RegQueryValueEx(hKey, "~MHz", NULL, NULL, (LPBYTE)&ulSpeed, &ulLen);   // 查询CPU时钟频率
		RegCloseKey(hKey);		// 关闭注册表
		WriteLog("CPU时钟频率＝%ldMHz",ulSpeed);// 显示获取的信息
	}
	else WriteLog("获取CPU时钟频率失败");		// 输出错误信息
}

// 21.7.3(OK)
void CSystemInfoSampleDlg::OnButtonGetWindowpath()			// 获得Windows路径
{
	TCHAR szPath[MAX_PATH]={0};								// 定义路径变量
	int nLength = GetWindowsDirectory(szPath, MAX_PATH);	// 获取Windows路径
	if (nLength > 0) WriteLog("获取Window路径=%s", szPath);	// 输出路径信息
	else WriteLog("获取Window路径失败");					// 输出错误信息
}
void CSystemInfoSampleDlg::OnButtonGetSystempath()			// 获得System路径
{
	TCHAR szPath[MAX_PATH]={0};								// 定义路径变量
	int nLength =  GetSystemDirectory(szPath, MAX_PATH);	// 获取System路径
	if (nLength > 0) WriteLog("获取System路径=%s", szPath);	// 输出路径信息
	else WriteLog("获取System路径失败");					// 输出错误信息
}

// 21.7.4(OK)
void CSystemInfoSampleDlg::OnButtonGetspecialpath()			// 获取特殊文件夹路径
{
	TCHAR  szPath[MAX_PATH];								// 定义路径变量
	int	iIndex[]={CSIDL_ALTSTARTUP, CSIDL_APPDATA, CSIDL_BITBUCKET, CSIDL_COMMON_ALTSTARTUP, 
		CSIDL_COMMON_DESKTOPDIRECTORY, CSIDL_COMMON_FAVORITES, CSIDL_COMMON_PROGRAMS, 
		CSIDL_COMMON_STARTMENU, CSIDL_COMMON_STARTUP, CSIDL_CONTROLS, CSIDL_COOKIES, 
		CSIDL_DESKTOP, CSIDL_DESKTOPDIRECTORY, CSIDL_DRIVES,  CSIDL_FAVORITES, 
		CSIDL_FONTS, CSIDL_HISTORY, CSIDL_INTERNET, CSIDL_INTERNET_CACHE, 
		CSIDL_NETHOOD, CSIDL_NETWORK, CSIDL_PERSONAL, CSIDL_PRINTERS, CSIDL_PRINTHOOD,
		CSIDL_PROGRAMS, CSIDL_RECENT, CSIDL_SENDTO, CSIDL_STARTMENU, CSIDL_STARTUP,
		CSIDL_TEMPLATES};									// 路径CSIDL数组
	CString	csIndex[]={"CSIDL_ALTSTARTUP", "CSIDL_APPDATA", "CSIDL_BITBUCKET", "CSIDL_COMMON_ALTSTARTUP", 
		"CSIDL_COMMON_DESKTOPDIRECTORY", "CSIDL_COMMON_FAVORITES", "CSIDL_COMMON_PROGRAMS", 
		"CSIDL_COMMON_STARTMENU", "CSIDL_COMMON_STARTUP", "CSIDL_CONTROLS", "CSIDL_COOKIES", 
		"CSIDL_DESKTOP", "CSIDL_DESKTOPDIRECTORY", "CSIDL_DRIVES",  "CSIDL_FAVORITES", 
		"CSIDL_FONTS", "CSIDL_HISTORY", "CSIDL_INTERNET", "CSIDL_INTERNET_CACHE", 
		"CSIDL_NETHOOD", "CSIDL_NETWORK", "CSIDL_PERSONAL", "CSIDL_PRINTERS", "CSIDL_PRINTHOOD",
		"CSIDL_PROGRAMS", "CSIDL_RECENT", "CSIDL_SENDTO", "CSIDL_STARTMENU", "CSIDL_STARTUP",
		"CSIDL_TEMPLATES"};									// 路径名称数组
	for (int i = 0;i < 30; i++)								// 使用for循环依次获取文件夹
	{
		memset(szPath, 0x00, sizeof(szPath));				// 清空变量值
		if (SHGetSpecialFolderPath(HWND_DESKTOP, szPath, iIndex[i], FALSE) != 0)	// 获取特殊文件夹
			WriteLog("%s=%s", csIndex[i], szPath);			// 输出文件夹路径
		else WriteLog("获取%s失败", csIndex[i]);			// 输出错误信息
	}
}

// 21.7.5(OK)
void CSystemInfoSampleDlg::OnButtonGetstartmode()	// 检测系统启动模式
{
	int iMode = GetSystemMetrics(SM_CLEANBOOT);		// 获取系统启动模式
	switch (iMode)									// 判断返回的模式值
	{
	case 0:	// 正常模式
		WriteLog("系统启动模式为--正常模式");break;
	case 1:	// 安全模式
		WriteLog("系统启动模式为--安全模式");break;
	case 2:	// 网络环境下安全模式
		WriteLog("系统启动模式为--网络环境下安全模式");break;
	default:// 其他模式
		WriteLog("系统启动模式为--其他");break;
	}
}

// 21.7.6(OK)
void CSystemInfoSampleDlg::OnButtonGetSysversion()	// 判断操作系统类型
{
	OSVERSIONINFO osvi;								// 定义版本信息结构
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);	// 设置版本结构大小
	if (GetVersionEx (&osvi))							// 获取版本信息
		WriteLog("获取操作系统版本成功，主版本=%d;次版本=%d;\r\n生成版本=%d;平台ID=%d;系统描述=%s",
			osvi.dwMajorVersion, osvi.dwMinorVersion, 
			osvi.dwBuildNumber,	osvi.dwPlatformId, osvi.szCSDVersion);	// 输出版本信息
	else WriteLog("获取操作系统版本失败");				// 输出错误信息	
}

// 21.7.7(OK)
void CSystemInfoSampleDlg::OnButtonGetruntime()			// 获取当前系统的运行时间
{	
	DWORD dwTicks = GetTickCount();						// 获取运行的单位时间数
	CTimeSpan timeSpan(dwTicks/1000);					// 将其转换为CTimeSpan类型
	// 输出运行时间信息
	WriteLog("系统已经运行了%d天，%d小时，%d分钟，%d秒", timeSpan.GetDays(), timeSpan.GetHours(), timeSpan.GetMinutes(), timeSpan.GetSeconds());	
}

// 21.7.8(OK)
void CSystemInfoSampleDlg::OnButtonGetstarttime()		// 获取Windows 2000系统启动时间
{	
	DWORD dwTicks = GetTickCount();						// 获取运行的单位时间数
	CTime time = CTime::GetCurrentTime();				// 获取当前时间
	CTimeSpan timeSpan(dwTicks/1000);					// 将其转换为CTimeSpan类型
	time -= timeSpan;									// 当前时间减去已经运行的时间
	WriteLog("系统启动时间为：%s", time.Format("%Y-%m-%d %H:%M:%S"));	// 输出启动时间
}

// 21.7.9(OK)
void CSystemInfoSampleDlg::OnButtonGetProcessor()		// 获取处理器信息
{
	SYSTEM_INFO sysinfo;								// 定义系统信息结构
	GetSystemInfo(&sysinfo);							// 获取处理器信息
	switch(sysinfo.wProcessorArchitecture)				// 判断处理器种类
	{
	case PROCESSOR_ARCHITECTURE_INTEL:					// Intel处理器
		switch (sysinfo.wProcessorLevel)				// 判断处理器型号
		{
		case 3:
			WriteLog("处理器类型=PROCESSOR_ARCHITECTURE_INTEL--Intel 80386");	break; 
		case 4:
			WriteLog("处理器类型=PROCESSOR_ARCHITECTURE_INTEL--Intel 80486");	break;
		case 5:
			WriteLog("处理器类型=PROCESSOR_ARCHITECTURE_INTEL--Pentium"); break;
		default:
			WriteLog("处理器类型=PROCESSOR_ARCHITECTURE_INTEL"); break;
		}
		break;
	case PROCESSOR_ARCHITECTURE_MIPS :					// MIPS
		WriteLog("处理器类型=MIPS--R%d000", sysinfo.wProcessorLevel);
		break;
	case PROCESSOR_ARCHITECTURE_ALPHA:					// ALPHA
		WriteLog("处理器类型=ALPHA--%d", sysinfo.wProcessorLevel);
		break;
	case PROCESSOR_ARCHITECTURE_PPC:					// PPC
		switch (sysinfo.wProcessorLevel)				// 判断处理器型号
		{
		case 1:
			WriteLog("处理器类型=PPC--PPC 601");break;
		case 3:
			WriteLog("处理器类型=PPC--PPC 603");break;
		case 4:
			WriteLog("处理器类型=PPC--PPC 604");break;
		case 6:
			WriteLog("处理器类型=PPC--PPC 603+");break;
		case 9:
			WriteLog("处理器类型=PPC--PPC 604+");break;
		case 20:
			WriteLog("处理器类型=PPC--PPC 620");break;
		default:
			WriteLog("处理器类型=PPC--PPC PPC");		
		}
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN :			// 处理器未知
		WriteLog("处理器类型未知");break;
	default:										// 其他未知值
		WriteLog("处理器类型未知");break;
	}
	WriteLog("系统中的处理器数目为%d", sysinfo.dwNumberOfProcessors);	// 输出处理器数目
}

// 21.7.10(OK)
void CSystemInfoSampleDlg::OnButtonIsaudio()		// 检测是否安装声卡
{	// 打开音频播放
	MMRESULT mmResult = waveOutOpen(NULL, WAVE_MAPPER, NULL, NULL, NULL,WAVE_FORMAT_QUERY);
	if (GetLastError() == MMSYSERR_NODRIVER)	// 如果错误结果为没有驱动=没有安装声卡
		WriteLog("系统中没有安装声卡");			// 输出提示信息
	else  WriteLog("系统中安装了声卡");			// 输出提示信息
}

// 21.7.11(OK)
void CSystemInfoSampleDlg::OnButtonGetUsername()	// 获取当前用户名
{	
	TCHAR szName[MAX_PATH];							// 定义用户名数组
	DWORD dwLen = MAX_PATH;							// 定义用户名长度
	if (GetUserName(szName, &dwLen))				// 获取用户名
		WriteLog("获取用户名成功,长度=%d;用户名=%s", dwLen, szName);// 输出用户名
	else WriteLog("获取用户名失败");				// 输出错误信息
}

// 21.7.12(OK)
void CSystemInfoSampleDlg::OnButtonGetEnrovar()		// 获取系统环境变量
{
	char szBuffer[1024] = {0};						// 定义环境变量值数组
	DWORD dwSize=1024;								// 定义数组大小
	if (GetEnvironmentVariable("PATH",(LPTSTR)szBuffer, dwSize) > 0)	// 获取环境变量值
		WriteLog("环境变量PATH=%s", szBuffer);		// 输出环境变量值
	else WriteLog("获取环境变量失败");				// 输出错误提示
}

// 21.7.13(OK)
void CSystemInfoSampleDlg::OnButtonSetComputeName() // 修改计算机名称
{
	if (SetComputerName("huge-lln"))			// 修改计算机名称
	{
		char szName[128] = "";	// 定义计算机名称数组
		DWORD dwLen = 128;		// 定义计算机名称长度
		if (GetComputerName(szName, &dwLen))		// 获取计算机名称
			WriteLog("设置计算机名称成功，修改后的计算机名称=%s", szName);	// 输出计算机名称	
	}
	else
        WriteLog("设置计算机名称失败");			// 输出错误提示   
}

// 21.7.14(OK)
void CSystemInfoSampleDlg::OnButtonGetScreencolor()		// 获取当前屏幕颜色质量
{
	HDC hdc = GetDC()->m_hDC;							// 获取设备上下文句柄
	int iColors = GetDeviceCaps(hdc, BITSPIXEL);		// 获取屏幕颜色质量
	WriteLog("当前屏幕颜色质量为%d", iColors);			// 输出屏幕颜色质量
}

// 21.7.15(OK)
void CSystemInfoSampleDlg::OnButtonGetScreenxy()		// 获得当前屏幕的分辨率
{
	int iScreenX = GetSystemMetrics(SM_CXSCREEN);		// X分辨率
	int iScreenY = GetSystemMetrics(SM_CYSCREEN);		// Y分辨率
	WriteLog("当前屏幕分辨率为%d*%d", iScreenX, iScreenY);	// 输出屏幕分辨率
}










typedef HRESULT (WINAPI  *PFUNCTIONPATH)(HWND hwndOwner, int nFolder, LPITEMIDLIST *ppidl);     
	

