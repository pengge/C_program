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

// ��¼��־
void CDiskInfoDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 20.1.1(OK)
void CDiskInfoDlg::OnButtonGetvol()		// ��ȡ���������
{
	UpdateData(TRUE);					// �ӿؼ��и������ݣ�����Ҫ��ȡ������������	
	char szVolume[MAX_PATH]={0};		// ��ž����Ϣ���ַ�����
	 
	if (GetVolumeInformation(m_DiskName,szVolume,MAX_PATH,NULL,NULL,NULL,NULL,0))	// ��ȡ���
		WriteLog("������%s�ľ��=%s",m_DiskName, szVolume);	// ��¼��־
	else	// ��ȡ���ʧ��
	{
		if (GetLastError() == ERROR_DEVICE_NOT_CONNECTED)	// ����Ƿ�û�в�����
			WriteLog("û�в�����");			
		else	WriteLog("��ȡ���������ʧ��");				// ��ʾ������ʾ	
	}	
}

// 20.1.2(OK)
void CDiskInfoDlg::OnButtonGetserial()	// ��ȡ�������к�
{
	UpdateData(TRUE);					// �ӿؼ��и������ݣ�����Ҫ��ȡ������������	
	DWORD dwSerial;						// ��Ŵ������кŵ��ַ�����	 
	if (GetVolumeInformation(m_DiskName,NULL,0,&dwSerial,NULL,NULL,NULL,0))	// ��ȡ�������к�
		WriteLog("����%s�Ĵ������к�=%X", m_DiskName, dwSerial);			// ��ʾ��ȡ�Ĵ������к�	
	else WriteLog("��ȡ���������ʧ��");// ��ʾ������ʾ
}

// 20.1.3(OK)
void CDiskInfoDlg::OnButtonCheckA()		// ��������Ƿ�������
{
	BOOL bResult = FALSE;				// �������
	DWORD cb = 0;						// ����ֽ������˴���ʵ������
	HANDLE hDevice = NULL;				// �豸���
	hDevice = CreateFile("\\\\.\\A:\\", GENERIC_READ, 0, 0,	OPEN_EXISTING, FILE_SHARE_WRITE, NULL); // �򿪵����������Ӿ��	
	if (hDevice != NULL)
	{
		if (DeviceIoControl((HANDLE) hDevice, IOCTL_STORAGE_CHECK_VERIFY, NULL, 0, NULL, 0,&cb, NULL))	// ����������Ƿ�������
		{
			WriteLog("������������");	// �����Ϣ��ʾ
			return;						// ����
		}		
	}
	WriteLog("������û������");			// �����Ϣ��ʾ
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

// ��ȡ�������ľ��
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
 
// ���������������Ƴ�
void   CDiskInfoDlg::HandleDeviceChange(UINT message,   WPARAM   wParam,   LPARAM   lParam)   
{   
	PDEV_BROADCAST_HDR lpdb=(PDEV_BROADCAST_HDR)lParam;    
	switch   (wParam)   
	{   
		case   DBT_DEVICEARRIVAL:   // ������Ӳ��
		if   (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)   
		{   
			PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;   
			if (!((lpdbv->dbcv_flags & DBTF_MEDIA)
				|| (lpdbv->dbcv_flags & DBTF_NET)))
			{   
				char volumn = GetDriveFromMask(lpdbv->dbcv_unitmask);				
				WriteLog("����%c�´洢��", volumn);				
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
				WriteLog("�Ƴ�%c�洢��", volumn);	
			}   
		}   
		break; 
		default:   
		break;
	}
}

// 20.1.5(OK)
void CDiskInfoDlg::OnButtonCheckcdrom()		// �жϹ����Ƿ��й���
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
			if (type == DRIVE_CDROM)	// ����ǹ���
			{
				int bResult = GetVolumeInformation(driver,  NULL, 0,   NULL,   NULL,   NULL,   NULL,   0); 
				CString info;
				if (bResult == 0)
				{					
					info.Format("����%c��û�й���\r\n", strDrivers[i]);
				}
				else
				{
					info.Format("����%c���й���\r\n", strDrivers[i]);
				}
				log += info;
			}
		}
	}
	WriteLog(log);
}

// 20.1.6(OK)
void CDiskInfoDlg::OnButtonGetmediatype()	// �ж�����������
{
	UpdateData(TRUE);						// �ӿؼ��и������ݣ�����Ҫ��ȡ������������	
	CString   csType; 						// ������������͵��ַ���
	UINT uiType = GetDriveType(m_DiskName);	// ��ȡ����������
	switch (uiType)							// ���ݷ���ֵ�ж�����������
	{
	case DRIVE_UNKNOWN:
		csType = "���������Ͳ���ȷ����";
		break;

	case DRIVE_NO_ROOT_DIR:
		csType = "ָ���ĸ�Ŀ¼�����ڡ�";
		break;

	case DRIVE_REMOVABLE:
		csType = "���ƶ��Ĵ洢����";
		break;

	case DRIVE_FIXED:
		csType = "�̶�����������Ҳ����ͨ����˵�Ĵ��̡�";
		break;

	case DRIVE_REMOTE:
		csType = "Զ����������Ҳ��Ϊ������������";
		break;

	case DRIVE_CDROM:
		csType = "CD-ROM������";
		break;

	case DRIVE_RAMDISK:
		csType = "�ڴ������������������ڴ��һ���ֻ��ֳ�������Ӳ��ʹ�á�";
		break;

	default:
		csType = "δ֪";
	}
	WriteLog("������%s�����ͷ���ֵ=%d��%s��", m_DiskName, uiType, csType);	// ��ʾ������Ϣ
}





// 20.1.7(OK)
void CDiskInfoDlg::OnButtonGetfreespace()	// ��ȡ���̿ռ���Ϣ
{
	UpdateData(TRUE);					// �ӿؼ��и������ݣ�����Ҫ��ȡ�Ĵ�������	
	DWORD   lSPC,lBPS,lNOFC,lTNOC;		// ��Ŵ��̿ռ�ı���	 
	if (GetDiskFreeSpace(m_DiskName,&lSPC, &lBPS, &lNOFC, &lTNOC))	// ��ȡ���̿ռ���Ϣ
		WriteLog("%s�̵Ĵ��̿ռ������\r\n�����ֽ���=%d;ÿ���������������=%d; \
			\r\nÿ�����������ֽ���=%d;����������=%d;��������=%d.", m_DiskName, lSPC*lBPS*lNOFC, lSPC, lBPS, lNOFC, lTNOC);			// ��ʾ��ȡ�Ĵ��̿ռ���Ϣ	
	else WriteLog("��ȡ���̿ռ���Ϣʧ��");// ��ʾ������ʾ
}
