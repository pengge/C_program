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

// ��¼��־
void CDiskOperDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[1024]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// fmtID������Ψһȡֵ
#define SHFMT_ID_DEFAULT   0xFFFF
// Option��������Ч����
#define SHFMT_OPT_FULL     0x0001
#define SHFMT_OPT_SYSONLY  0x0002
// ����ֵ
#define SHFMT_ERROR     0xFFFFFFFFL    // ���һ�θ�ʽ����������
#define SHFMT_CANCEL    0xFFFFFFFEL    // ��ʽ����ȡ�� 
#define SHFMT_NOFORMAT  0xFFFFFFFDL    // ���ܽ��д��̸�ʽ��
// ��ʽ�����̵ĺ���ԭ��
typedef DWORD (WINAPI  *PFUNCTIONFORMAT)(HWND hwnd, UINT drive, UINT fmtID, UINT options);     
  
// 21.2.1(OK)
void CDiskOperDlg::OnButtonFormat()		// ��ʽ������
{	
	UpdateData(TRUE);
	UINT uiDriver = m_DiskName[0] - 'A';
	HINSTANCE   hInstance=LoadLibrary(_T("Shell32.dll"));     
	if (hInstance == NULL)   return; 
	PFUNCTIONFORMAT   pFunctionFormat=(PFUNCTIONFORMAT)GetProcAddress(hInstance, _T("SHFormatDrive"));       
	if(pFunctionFormat==NULL)     
	{     // ���û�л�ȡ��ʽ��SHFormatDrive������ָ�룬�򷵻�
		FreeLibrary(hInstance);     
		return;     
	}
	DWORD dwResult = (pFunctionFormat)(this->m_hWnd, uiDriver, SHFMT_ID_DEFAULT, SHFMT_OPT_FULL);
	switch (dwResult)
	{
	case SHFMT_ERROR:
		WriteLog("��ʽ������%s��������", m_DiskName);
		break;
	case SHFMT_CANCEL:
		WriteLog("ȡ����ʽ������%s", m_DiskName);
		break;
	case SHFMT_NOFORMAT:
		WriteLog("���ܸ�ʽ������%s", m_DiskName);
		break;
	default:
		WriteLog("��ʽ������%s�ɹ�", m_DiskName);
		break;
	}
	FreeLibrary(hInstance);  
	return; 
}

// 21.2.2(OK)
void CDiskOperDlg::OnButtonDelshare()	// �رմ��̹���
{
	UpdateData(TRUE);					// �ӿؼ���ȡ����			
	WCHAR wsz[MAX_PATH];				// ����Unicode�ַ�����
	CString disk;						// ������̹������Ʊ���	
	disk.Format("%c$", m_DiskName[0]);	// ��ʽ�����̹�������
	wcscpy(wsz, disk.AllocSysString()); // ����������ת����Unicode�ַ�����
	NET_API_STATUS dwStatus = NetShareDel(NULL,(LPWSTR)wsz,0);	// �رմ��̹���
	switch(dwStatus)					// �жϲ�������ֵ���������ʾ��Ϣ
	{
	case NERR_Success:
		WriteLog("�ɹ��ر�%s���̹���\n", disk);
		break;
	case ERROR_ACCESS_DENIED:
		WriteLog("�ر�%s���̹������\nԭ��=�û�û��Ȩ��ִ�д��������", disk); 
		break;
	case ERROR_INVALID_PARAMETER:
		WriteLog("�ر�%s���̹������\nԭ��=������Ч��", disk); 
		break;
	case ERROR_NOT_ENOUGH_MEMORY:
		WriteLog("�ر�%s���̹������\nԭ��=�ڴ治�㡣", disk); 
		break;
	case NERR_NetNameNotFound:
		WriteLog("�ر�%s���̹������\nԭ��=�����ڴ˹������ơ�", disk); 
		break;
	default:
		WriteLog("�ر�%s���̹������\nԭ��=δ֪��", disk); 
		break;
	}
}

// 21.2.3(OK)
void CDiskOperDlg::OnButtonSetvolum()	// ���ô��̾��
{
	UpdateData(TRUE);					// �ӿؼ���ȡ����
	if (SetVolumeLabel(m_DiskName, "�ҵ�ϵͳ��")) // ���ô��̾��
		WriteLog("����%s���̾��ɹ�", m_DiskName);	
	else  WriteLog("����%s���̾��ʧ��", m_DiskName);
}


// 21.2.4(OK)
void CDiskOperDlg::OnButtonSpzl()	// ������Ƭ����
{
	system("defrag E:");
}

// 21.2.5(OK)
void CDiskOperDlg::OnButtonFat32tontfs() // ��FAT32ת��ΪNTFS
{
	system("convert E: /FS:NTFS");
}

// 21.2.6(OK)
void CDiskOperDlg::OnButtonHidedisk()	// ���ش��̷���
{	
	UpdateData(TRUE);					// �ӿؼ���ȡ����
	memset(szPath,0x00, sizeof(szPath));// ��ʼ��·������
	CString csDisk;						// �����������
	csDisk.Format("%c:", m_DiskName[0]);// ��ʽ��Ҫ���صĴ�������
	if (QueryDosDeviceA(csDisk, szPath, MAX_PATH) == 0)	// ��ѯ���̶�Ӧ���豸·��
	{
		WriteLog("��ȡ���̷���%s·����ʧ��", csDisk);	// ��ѯʧ�ܣ���ʾ���
		return;							// ��ѯʧ�ܣ�����
	}
	if (DefineDosDeviceA(DDD_REMOVE_DEFINITION, csDisk, NULL))	// ɾ���豸·�����ƵĶ��壬�����ش��̷���
		WriteLog("���ش��̷���%s�ɹ���\r\n·������=%s", csDisk, szPath);	// �����ɹ�����ʾ������־
	else
		WriteLog("���ش��̷���%sʧ�ܡ�\r\n·������=%s", csDisk, szPath);	// ����ʧ�ܣ���ʾ������־
}

// 21.2.7(OK)
void CDiskOperDlg::OnButtonShowdisk()	// ��ʾ�����صĴ��̷���
{	
	UpdateData(TRUE);					// �ӿؼ���ȡ����
	CString csDisk;						// �����������
	csDisk.Format("%c:", m_DiskName[0]);// ��ʽ��Ҫ���صĴ�������
	if (DefineDosDevice(DDD_RAW_TARGET_PATH, csDisk, szPath))	// ����ָ���豸·����Ӧ�Ĵ�������
		WriteLog("��ʾ�����صĴ��̷���%s�ɹ���\r\n·������=%s", csDisk, szPath);// �����ɹ�����ʾ������־
	else
		WriteLog("��ʾ�����صĴ��̷���%sʧ�ܡ�\r\n·������=%s", csDisk, szPath);// ����ʧ�ܣ���ʾ������־
}


// 21.2.8(OK)
typedef BOOL  (WINAPI *PROCGET)  (LPCTSTR,LPCTSTR,LPDWORD); 
typedef BOOL  (WINAPI *PROCDEL)  (LPCTSTR);
typedef BOOL  (WINAPI *PROCSET)  (LPCTSTR,LPCTSTR);
void CDiskOperDlg::OnButtonUpdatediskno()	// ���ķ�����
{
	UpdateData(TRUE);						// �ӿؼ���ȡ����
	HMODULE hKernel = GetModuleHandle("kernel32");	// װ��kernel32.dll
	if (hKernel)
	{		
		// ��ȡGetVolumeNameForVolumeMountPointA�������
		PROCGET getAPI = (PROCGET)GetProcAddress(hKernel,"GetVolumeNameForVolumeMountPointA");
		// ��ȡDeleteVolumeMountPointA�������
		PROCDEL delAPI = (PROCDEL)GetProcAddress(hKernel,"DeleteVolumeMountPointA");
		// ��ȡSetVolumeMountPointA�������
		PROCSET setAPI = (PROCSET)GetProcAddress(hKernel,"SetVolumeMountPointA"); 
		char szVolName [MAX_PATH];					// �����������
		DWORD dwLen;								// ����������ȱ���
		if (!getAPI(m_DiskName, szVolName, &dwLen)) // ��ѯָ�������ľ���
		{
			WriteLog("��ѯ����%s�ľ���ʧ�ܡ�", m_DiskName);	// ��ʾ������Ϣ
			return;									// ��ѯʧ�ܣ�����
		}
		if (!delAPI(m_DiskName))					// ɾ��������Ӧ�ķ�����
		{
			WriteLog("ɾ������Ϊ%s��Ӧ��%s�����š�", szVolName, m_DiskName);	// ��ʾ������Ϣ
			return;									// ɾ��ʧ�ܣ�����
		}
		if (!setAPI(_T("Z:\\"), szVolName))			// Ϊ�������µķ�����ΪZ
		{
			WriteLog("������Ϊ%s�ķ����Ÿ�ΪZ:ʧ�ܡ�", szVolName);	// ��ʾ������Ϣ
			return;									// ����ʧ�ܣ�����
		}
		WriteLog("������Ϊ%s�ķ����Ÿ�ΪZ:�ɹ���\r\nԭ���ķ�����=%s", szVolName, m_DiskName);// ��ʾ��־
	}
	else	WriteLog("װ��kernel32ʧ�ܣ�");			// ��ʾװ��DLLʧ����Ϣ
}

// 21.2.9(OK)
void CDiskOperDlg::OnButtonMonitorDisk()			// ����Ӳ��
{	
	UpdateData(TRUE);								// �ӿؼ���ȡ����
	DWORD dwWaitStatus; 
	HANDLE dwChangeHandle;
	dwChangeHandle=FindFirstChangeNotification(m_DiskName, TRUE, FILE_NOTIFY_CHANGE_FILE_NAME); 
 	if (dwChangeHandle==INVALID_HANDLE_VALUE)
        return; 
	bMonitor = TRUE;
	WriteLog("���ڼ���%c������������......", m_DiskName[0]);
	while (bMonitor) 
	{  
		dwWaitStatus = WaitForSingleObject(dwChangeHandle, INFINITE); 
		if (dwWaitStatus == WAIT_OBJECT_0)
		{
			WriteLog("��⵽%s�ļ�����������",m_DiskName);
            MessageBox(m_DiskName,"��⵽��������������");
			if (FindNextChangeNotification(dwChangeHandle) == FALSE) 
				bMonitor = FALSE;		
		}
		Sleep(100);
    } 
	FindCloseChangeNotification(dwChangeHandle);
}
















