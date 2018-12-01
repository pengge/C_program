// DiskInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include <dbt.h>
#include "DiskInfo.h"
#include "DiskInfoDlg.h"

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
// CDiskInfoDlg dialog

CDiskInfoDlg::CDiskInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiskInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiskInfoDlg)
	m_DiskName = _T("C:\\");
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiskInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiskInfoDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_DISKNAME, m_DiskName);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDiskInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CDiskInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CHECK_A, OnButtonCheckA)
	ON_BN_CLICKED(IDC_BUTTON_GETVOL, OnButtonGetvol)
	ON_BN_CLICKED(IDC_BUTTON_GETMEDIATYPE, OnButtonGetmediatype)
	ON_BN_CLICKED(IDC_BUTTON_GETSERIAL, OnButtonGetserial)
	ON_BN_CLICKED(IDC_BUTTON_GETFREESPACE, OnButtonGetfreespace)
	ON_BN_CLICKED(IDC_BUTTON_CHECKCDROM, OnButtonCheckcdrom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiskInfoDlg message handlers

BOOL CDiskInfoDlg::OnInitDialog()
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

void CDiskInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDiskInfoDlg::OnPaint() 
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
HCURSOR CDiskInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 记录日志
void CDiskInfoDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 20.1.1(OK)
void CDiskInfoDlg::OnButtonGetvol()		// 获取驱动器卷标
{
	UpdateData(TRUE);					// 从控件中更新数据，更新要获取的驱动器名称	
	char szVolume[MAX_PATH]={0};		// 存放卷标信息的字符数组
	 
	if (GetVolumeInformation(m_DiskName,szVolume,MAX_PATH,NULL,NULL,NULL,NULL,0))	// 获取卷标
		WriteLog("驱动器%s的卷标=%s",m_DiskName, szVolume);	// 记录日志
	else	// 获取卷标失败
	{
		if (GetLastError() == ERROR_DEVICE_NOT_CONNECTED)	// 检测是否没有插入盘
			WriteLog("没有插入盘");			
		else	WriteLog("获取驱动器卷标失败");				// 显示错误提示	
	}	
}

// 20.1.2(OK)
void CDiskInfoDlg::OnButtonGetserial()	// 获取磁盘序列号
{
	UpdateData(TRUE);					// 从控件中更新数据，更新要获取的驱动器名称	
	DWORD dwSerial;						// 存放磁盘序列号的字符数组	 
	if (GetVolumeInformation(m_DiskName,NULL,0,&dwSerial,NULL,NULL,NULL,0))	// 获取磁盘序列号
		WriteLog("磁盘%s的磁盘序列号=%X", m_DiskName, dwSerial);			// 显示获取的磁盘序列号	
	else WriteLog("获取驱动器卷标失败");// 显示错误提示
}

// 20.1.3(OK)
void CDiskInfoDlg::OnButtonCheckA()		// 检测软驱是否有软盘
{
	BOOL bResult = FALSE;				// 操作结果
	DWORD cb = 0;						// 输出字节数，此处无实际意义
	HANDLE hDevice = NULL;				// 设备句柄
	hDevice = CreateFile("\\\\.\\A:\\", GENERIC_READ, 0, 0,	OPEN_EXISTING, FILE_SHARE_WRITE, NULL); // 打开到软驱的连接句柄	
	if (hDevice != NULL)
	{
		if (DeviceIoControl((HANDLE) hDevice, IOCTL_STORAGE_CHECK_VERIFY, NULL, 0, NULL, 0,&cb, NULL))	// 检测软驱中是否有软盘
		{
			WriteLog("软驱中有软盘");	// 输出信息提示
			return;						// 返回
		}		
	}
	WriteLog("软驱中没有软盘");			// 输出信息提示
}

// 21.1.4(OK)
LRESULT CDiskInfoDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == WM_DEVICECHANGE)
	{
		HandleDeviceChange(message, wParam, lParam);
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

// 获取驱动器的卷标
char CDiskInfoDlg::GetDriveFromMask (ULONG unitmask)
{
	char i;
	for (i = 0; i < 26; ++i)
	{
		if (unitmask & 0x1)
			break;
		unitmask = unitmask >> 1;
	}
	return (i + 'A');
}
 
// 检测驱动器插入和移除
void   CDiskInfoDlg::HandleDeviceChange(UINT message,   WPARAM   wParam,   LPARAM   lParam)   
{   
	PDEV_BROADCAST_HDR lpdb=(PDEV_BROADCAST_HDR)lParam;    
	switch   (wParam)   
	{   
		case   DBT_DEVICEARRIVAL:   // 插入新硬件
		if   (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)   
		{   
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;   
			if (!((lpdbv->dbcv_flags & DBTF_MEDIA)
				|| (lpdbv->dbcv_flags & DBTF_NET)))
			{   
				char volumn = GetDriveFromMask(lpdbv->dbcv_unitmask);				
				WriteLog("插入%c新存储器", volumn);				
			}   
		}   
		break;
		case   DBT_DEVICEREMOVECOMPLETE:   
		if   (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)   
		{   
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;   
			if (!((lpdbv->dbcv_flags & DBTF_MEDIA)
				|| (lpdbv->dbcv_flags & DBTF_NET)))
			{   
				char volumn = GetDriveFromMask(lpdbv->dbcv_unitmask);				
				WriteLog("移除%c存储器", volumn);	
			}   
		}   
		break; 
		default:   
		break;
	}
}

// 20.1.5(OK)
void CDiskInfoDlg::OnButtonCheckcdrom()		// 判断光驱是否有光盘
{
	DWORD dwReturn;
	char strDrivers[MAX_PATH];
	dwReturn = GetLogicalDriveStrings(MAX_PATH, (LPSTR)&strDrivers);
	CString log;
	for (int i = 0;i < (int)dwReturn; i++)
	{
		if ((strDrivers[i] <= 'Z') && (strDrivers[i] >= 'A'))
		{
			CString driver;
			driver.Format("%c:\\", strDrivers[i]);
			UINT type = GetDriveType(driver);
			if (type == DRIVE_CDROM)	// 如果是光驱
			{
				int bResult = GetVolumeInformation(driver,  NULL, 0,   NULL,   NULL,   NULL,   NULL,   0); 
				CString info;
				if (bResult == 0)
				{					
					info.Format("光驱%c中没有光盘\r\n", strDrivers[i]);
				}
				else
				{
					info.Format("光驱%c中有光盘\r\n", strDrivers[i]);
				}
				log += info;
			}
		}
	}
	WriteLog(log);
}

// 20.1.6(OK)
void CDiskInfoDlg::OnButtonGetmediatype()	// 判断驱动器类型
{
	UpdateData(TRUE);						// 从控件中更新数据，更新要获取的驱动器名称	
	CString   csType; 						// 存放驱动器类型的字符串
	UINT uiType = GetDriveType(m_DiskName);	// 获取驱动器类型
	switch (uiType)							// 根据返回值判断驱动器类型
	{
	case DRIVE_UNKNOWN:
		csType = "驱动器类型不能确定。";
		break;

	case DRIVE_NO_ROOT_DIR:
		csType = "指定的根目录不存在。";
		break;

	case DRIVE_REMOVABLE:
		csType = "可移动的存储器。";
		break;

	case DRIVE_FIXED:
		csType = "固定的驱动器，也就是通常所说的磁盘。";
		break;

	case DRIVE_REMOTE:
		csType = "远程驱动器，也称为网络驱动器。";
		break;

	case DRIVE_CDROM:
		csType = "CD-ROM驱动器";
		break;

	case DRIVE_RAMDISK:
		csType = "内存驱动器，驱动器将内存的一部分划分出来当作硬盘使用。";
		break;

	default:
		csType = "未知";
	}
	WriteLog("驱动器%s的类型返回值=%d（%s）", m_DiskName, uiType, csType);	// 显示操作信息
}





// 20.1.7(OK)
void CDiskInfoDlg::OnButtonGetfreespace()	// 获取磁盘空间信息
{
	UpdateData(TRUE);					// 从控件中更新数据，更新要获取的磁盘名称	
	DWORD   lSPC,lBPS,lNOFC,lTNOC;		// 存放磁盘空间的变量	 
	if (GetDiskFreeSpace(m_DiskName,&lSPC, &lBPS, &lNOFC, &lTNOC))	// 获取磁盘空间信息
		WriteLog("%s盘的磁盘空间情况：\r\n空闲字节数=%d;每柱面包含的扇区数=%d; \
			\r\n每扇区包含的字节数=%d;空闲柱面数=%d;总柱面数=%d.", m_DiskName, lSPC*lBPS*lNOFC, lSPC, lBPS, lNOFC, lTNOC);			// 显示获取的磁盘空间信息	
	else WriteLog("获取磁盘空间信息失败");// 显示错误提示
}
