// DiskOperDlg.cpp : implementation file
//

#define   UNICODE
#define       _WIN32_WINNT       0x0500   

#include "stdafx.h"
#include "DiskOper.h"
#include "DiskOperDlg.h"
#include "windows.h"
#include "SHELLAPI.H"
#include <lm.h>
#include "winioctl.h"
#include "stdio.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 




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
// CDiskOperDlg dialog

CDiskOperDlg::CDiskOperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiskOperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiskOperDlg)
	m_Log = _T("");
	m_DiskName = _T("I:\\");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiskOperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiskOperDlg)
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	DDX_Text(pDX, IDC_EDIT_DISKNAME, m_DiskName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDiskOperDlg, CDialog)
	//{{AFX_MSG_MAP(CDiskOperDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FORMAT, OnButtonFormat)
	ON_BN_CLICKED(IDC_BUTTON_MONITOR_DISK, OnButtonMonitorDisk)
	ON_BN_CLICKED(IDC_BUTTON_HIDEDISK, OnButtonHidedisk)
	ON_BN_CLICKED(IDC_BUTTON_DELSHARE, OnButtonDelshare)
	ON_BN_CLICKED(IDC_BUTTON_SETVOLUM, OnButtonSetvolum)
	ON_BN_CLICKED(IDC_BUTTON_FAT32TONTFS, OnButtonFat32tontfs)
	ON_BN_CLICKED(IDC_BUTTON_UPDATEDISKNO, OnButtonUpdatediskno)
	ON_BN_CLICKED(IDC_BUTTON_SHOWDISK, OnButtonShowdisk)
	ON_BN_CLICKED(IDC_BUTTON_SPZL, OnButtonSpzl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiskOperDlg message handlers

BOOL CDiskOperDlg::OnInitDialog()
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

void CDiskOperDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDiskOperDlg::OnPaint() 
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
HCURSOR CDiskOperDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 记录日志
void CDiskOperDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[1024]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// fmtID参数的唯一取值
#define SHFMT_ID_DEFAULT   0xFFFF
// Option参数的有效设置
#define SHFMT_OPT_FULL     0x0001
#define SHFMT_OPT_SYSONLY  0x0002
// 返回值
#define SHFMT_ERROR     0xFFFFFFFFL    // 最后一次格式化发生错误
#define SHFMT_CANCEL    0xFFFFFFFEL    // 格式化被取消 
#define SHFMT_NOFORMAT  0xFFFFFFFDL    // 不能进行磁盘格式化
// 格式化磁盘的函数原型
typedef DWORD (WINAPI  *PFUNCTIONFORMAT)(HWND hwnd, UINT drive, UINT fmtID, UINT options);     
  
// 21.2.1(OK)
void CDiskOperDlg::OnButtonFormat()		// 格式化磁盘
{	
	UpdateData(TRUE);
	UINT uiDriver = m_DiskName[0] - 'A';
	HINSTANCE   hInstance=LoadLibrary(_T("Shell32.dll"));     
	if (hInstance == NULL)   return; 
	PFUNCTIONFORMAT   pFunctionFormat=(PFUNCTIONFORMAT)GetProcAddress(hInstance, _T("SHFormatDrive"));       
	if(pFunctionFormat==NULL)     
	{     // 如果没有获取格式化SHFormatDrive函数的指针，则返回
		FreeLibrary(hInstance);     
		return;     
	}
	DWORD dwResult = (pFunctionFormat)(this->m_hWnd, uiDriver, SHFMT_ID_DEFAULT, SHFMT_OPT_FULL);
	switch (dwResult)
	{
	case SHFMT_ERROR:
		WriteLog("格式化磁盘%s发生错误", m_DiskName);
		break;
	case SHFMT_CANCEL:
		WriteLog("取消格式化磁盘%s", m_DiskName);
		break;
	case SHFMT_NOFORMAT:
		WriteLog("不能格式化磁盘%s", m_DiskName);
		break;
	default:
		WriteLog("格式化磁盘%s成功", m_DiskName);
		break;
	}
	FreeLibrary(hInstance);  
	return; 
}

// 21.2.2(OK)
void CDiskOperDlg::OnButtonDelshare()	// 关闭磁盘共享
{
	UpdateData(TRUE);					// 从控件获取数据			
	WCHAR wsz[MAX_PATH];				// 定义Unicode字符数组
	CString disk;						// 定义磁盘共享名称变量	
	disk.Format("%c$", m_DiskName[0]);	// 格式化磁盘共享名称
	wcscpy(wsz, disk.AllocSysString()); // 将共享名称转换到Unicode字符数组
	NET_API_STATUS dwStatus = NetShareDel(NULL,(LPWSTR)wsz,0);	// 关闭磁盘共享
	switch(dwStatus)					// 判断操作返回值，并输出提示信息
	{
	case NERR_Success:
		WriteLog("成功关闭%s磁盘共享\n", disk);
		break;
	case ERROR_ACCESS_DENIED:
		WriteLog("关闭%s磁盘共享错误\n原因=用户没有权限执行此项操作。", disk); 
		break;
	case ERROR_INVALID_PARAMETER:
		WriteLog("关闭%s磁盘共享错误\n原因=参数无效。", disk); 
		break;
	case ERROR_NOT_ENOUGH_MEMORY:
		WriteLog("关闭%s磁盘共享错误\n原因=内存不足。", disk); 
		break;
	case NERR_NetNameNotFound:
		WriteLog("关闭%s磁盘共享错误\n原因=不存在此共享名称。", disk); 
		break;
	default:
		WriteLog("关闭%s磁盘共享错误\n原因=未知。", disk); 
		break;
	}
}

// 21.2.3(OK)
void CDiskOperDlg::OnButtonSetvolum()	// 设置磁盘卷标
{
	UpdateData(TRUE);					// 从控件获取数据
	if (SetVolumeLabel(m_DiskName, "我的系统盘")) // 设置磁盘卷标
		WriteLog("设置%s磁盘卷标成功", m_DiskName);	
	else  WriteLog("设置%s磁盘卷标失败", m_DiskName);
}


// 21.2.4(OK)
void CDiskOperDlg::OnButtonSpzl()	// 磁盘碎片整理
{
	system("defrag E:");
}

// 21.2.5(OK)
void CDiskOperDlg::OnButtonFat32tontfs() // 从FAT32转换为NTFS
{
	system("convert E: /FS:NTFS");
}

// 21.2.6(OK)
void CDiskOperDlg::OnButtonHidedisk()	// 隐藏磁盘分区
{	
	UpdateData(TRUE);					// 从控件获取数据
	memset(szPath,0x00, sizeof(szPath));// 初始化路径变量
	CString csDisk;						// 定义磁盘名称
	csDisk.Format("%c:", m_DiskName[0]);// 格式化要隐藏的磁盘名称
	if (QueryDosDeviceA(csDisk, szPath, MAX_PATH) == 0)	// 查询磁盘对应的设备路径
	{
		WriteLog("获取磁盘分区%s路径名失败", csDisk);	// 查询失败，显示结果
		return;							// 查询失败，返回
	}
	if (DefineDosDeviceA(DDD_REMOVE_DEFINITION, csDisk, NULL))	// 删除设备路径名称的定义，即隐藏磁盘分区
		WriteLog("隐藏磁盘分区%s成功。\r\n路径名称=%s", csDisk, szPath);	// 操作成功，显示操作日志
	else
		WriteLog("隐藏磁盘分区%s失败。\r\n路径名称=%s", csDisk, szPath);	// 操作失败，显示操作日志
}

// 21.2.7(OK)
void CDiskOperDlg::OnButtonShowdisk()	// 显示被隐藏的磁盘分区
{	
	UpdateData(TRUE);					// 从控件获取数据
	CString csDisk;						// 定义磁盘名称
	csDisk.Format("%c:", m_DiskName[0]);// 格式化要隐藏的磁盘名称
	if (DefineDosDevice(DDD_RAW_TARGET_PATH, csDisk, szPath))	// 增加指定设备路径对应的磁盘名称
		WriteLog("显示被隐藏的磁盘分区%s成功。\r\n路径名称=%s", csDisk, szPath);// 操作成功，显示操作日志
	else
		WriteLog("显示被隐藏的磁盘分区%s失败。\r\n路径名称=%s", csDisk, szPath);// 操作失败，显示操作日志
}


// 21.2.8(OK)
typedef BOOL  (WINAPI *PROCGET)  (LPCTSTR,LPCTSTR,LPDWORD); 
typedef BOOL  (WINAPI *PROCDEL)  (LPCTSTR);
typedef BOOL  (WINAPI *PROCSET)  (LPCTSTR,LPCTSTR);
void CDiskOperDlg::OnButtonUpdatediskno()	// 更改分区号
{
	UpdateData(TRUE);						// 从控件获取数据
	HMODULE hKernel = GetModuleHandle("kernel32");	// 装载kernel32.dll
	if (hKernel)
	{		
		// 获取GetVolumeNameForVolumeMountPointA函数入口
		PROCGET getAPI = (PROCGET)GetProcAddress(hKernel,"GetVolumeNameForVolumeMountPointA");
		// 获取DeleteVolumeMountPointA函数入口
		PROCDEL delAPI = (PROCDEL)GetProcAddress(hKernel,"DeleteVolumeMountPointA");
		// 获取SetVolumeMountPointA函数入口
		PROCSET setAPI = (PROCSET)GetProcAddress(hKernel,"SetVolumeMountPointA"); 
		char szVolName [MAX_PATH];					// 定义卷名变量
		DWORD dwLen;								// 定义卷名长度变量
		if (!getAPI(m_DiskName, szVolName, &dwLen)) // 查询指定分区的卷名
		{
			WriteLog("查询分区%s的卷名失败。", m_DiskName);	// 显示错误信息
			return;									// 查询失败，返回
		}
		if (!delAPI(m_DiskName))					// 删除卷名对应的分区号
		{
			WriteLog("删除卷名为%s对应的%s分区号。", szVolName, m_DiskName);	// 显示错误信息
			return;									// 删除失败，返回
		}
		if (!setAPI(_T("Z:\\"), szVolName))			// 为卷设置新的分区号为Z
		{
			WriteLog("将卷名为%s的分区号改为Z:失败。", szVolName);	// 显示错误信息
			return;									// 设置失败，返回
		}
		WriteLog("将卷名为%s的分区号改为Z:成功。\r\n原来的分区号=%s", szVolName, m_DiskName);// 显示日志
	}
	else	WriteLog("装载kernel32失败！");			// 显示装载DLL失败信息
}

// 21.2.9(OK)
void CDiskOperDlg::OnButtonMonitorDisk()			// 监视硬盘
{	
	UpdateData(TRUE);								// 从控件获取数据
	DWORD dwWaitStatus; 
	HANDLE dwChangeHandle;
	dwChangeHandle=FindFirstChangeNotification(m_DiskName, TRUE, FILE_NOTIFY_CHANGE_FILE_NAME); 
 	if (dwChangeHandle==INVALID_HANDLE_VALUE)
        return; 
	bMonitor = TRUE;
	WriteLog("正在监视%c盘重命名操作......", m_DiskName[0]);
	while (bMonitor) 
	{  
		dwWaitStatus = WaitForSingleObject(dwChangeHandle, INFINITE); 
		if (dwWaitStatus == WAIT_OBJECT_0)
		{
			WriteLog("检测到%s文件重命名操作",m_DiskName);
            MessageBox(m_DiskName,"检测到磁盘重命名操作");
			if (FindNextChangeNotification(dwChangeHandle) == FALSE) 
				bMonitor = FALSE;		
		}
		Sleep(100);
    } 
	FindCloseChangeNotification(dwChangeHandle);
}
















