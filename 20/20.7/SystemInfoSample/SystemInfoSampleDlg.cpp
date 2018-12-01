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
// ��¼��־
void CSystemInfoSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.7.1(OK)
void CSystemInfoSampleDlg::OnButtonGetCpuid()	// ��ȡCPU IDֵ
{
	BYTE szCPU[16]= {0};			// ������CPU���͵�����
	UINT uCPUID = 0U;				// ������CPUID������
	_asm							// ��ʼִ�л��
	{
		mov eax, 0					// ��ȡCPU�ͺ�
		cpuid						
		mov dword ptr szCPU[0], ebx	// ȡCPU�ͺŵ�ǰ4���ַ�
		mov dword ptr szCPU[4], edx	// ȡCPU�ͺŵ��м�4���ַ�
		mov dword ptr szCPU[8], ecx	// ȡCPU�ͺŵ����4���ַ�
		mov eax, 1					// ȡCPUID
		cpuid
		mov uCPUID, edx				// ȡCPUID��ֵ
	}
	WriteLog("��ǰϵͳ��CPU����Ϊ=%s----CPU ID=%u", szCPU, uCPUID);	// ���CPU��Ϣ
}

// 21.7.2(OK)
void CSystemInfoSampleDlg::OnButtonGetCpufrequency()	// ��ȡCPUʱ��Ƶ��
{
	unsigned long ulSpeed=0;	// ����CPUʱ��Ƶ�ʱ���  
	HKEY hKey;					// ����ע����
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey) == ERROR_SUCCESS)   
	{   // ��ע���
		unsigned long ulLen= sizeof(ulSpeed);	// ��ֵ����	
		RegQueryValueEx(hKey, "~MHz", NULL, NULL, (LPBYTE)&ulSpeed, &ulLen);   // ��ѯCPUʱ��Ƶ��
		RegCloseKey(hKey);		// �ر�ע���
		WriteLog("CPUʱ��Ƶ�ʣ�%ldMHz",ulSpeed);// ��ʾ��ȡ����Ϣ
	}
	else WriteLog("��ȡCPUʱ��Ƶ��ʧ��");		// ���������Ϣ
}

// 21.7.3(OK)
void CSystemInfoSampleDlg::OnButtonGetWindowpath()			// ���Windows·��
{
	TCHAR szPath[MAX_PATH]={0};								// ����·������
	int nLength = GetWindowsDirectory(szPath, MAX_PATH);	// ��ȡWindows·��
	if (nLength > 0) WriteLog("��ȡWindow·��=%s", szPath);	// ���·����Ϣ
	else WriteLog("��ȡWindow·��ʧ��");					// ���������Ϣ
}
void CSystemInfoSampleDlg::OnButtonGetSystempath()			// ���System·��
{
	TCHAR szPath[MAX_PATH]={0};								// ����·������
	int nLength =  GetSystemDirectory(szPath, MAX_PATH);	// ��ȡSystem·��
	if (nLength > 0) WriteLog("��ȡSystem·��=%s", szPath);	// ���·����Ϣ
	else WriteLog("��ȡSystem·��ʧ��");					// ���������Ϣ
}

// 21.7.4(OK)
void CSystemInfoSampleDlg::OnButtonGetspecialpath()			// ��ȡ�����ļ���·��
{
	TCHAR  szPath[MAX_PATH];								// ����·������
	int	iIndex[]={CSIDL_ALTSTARTUP, CSIDL_APPDATA, CSIDL_BITBUCKET, CSIDL_COMMON_ALTSTARTUP, 
		CSIDL_COMMON_DESKTOPDIRECTORY, CSIDL_COMMON_FAVORITES, CSIDL_COMMON_PROGRAMS, 
		CSIDL_COMMON_STARTMENU, CSIDL_COMMON_STARTUP, CSIDL_CONTROLS, CSIDL_COOKIES, 
		CSIDL_DESKTOP, CSIDL_DESKTOPDIRECTORY, CSIDL_DRIVES,  CSIDL_FAVORITES, 
		CSIDL_FONTS, CSIDL_HISTORY, CSIDL_INTERNET, CSIDL_INTERNET_CACHE, 
		CSIDL_NETHOOD, CSIDL_NETWORK, CSIDL_PERSONAL, CSIDL_PRINTERS, CSIDL_PRINTHOOD,
		CSIDL_PROGRAMS, CSIDL_RECENT, CSIDL_SENDTO, CSIDL_STARTMENU, CSIDL_STARTUP,
		CSIDL_TEMPLATES};									// ·��CSIDL����
	CString	csIndex[]={"CSIDL_ALTSTARTUP", "CSIDL_APPDATA", "CSIDL_BITBUCKET", "CSIDL_COMMON_ALTSTARTUP", 
		"CSIDL_COMMON_DESKTOPDIRECTORY", "CSIDL_COMMON_FAVORITES", "CSIDL_COMMON_PROGRAMS", 
		"CSIDL_COMMON_STARTMENU", "CSIDL_COMMON_STARTUP", "CSIDL_CONTROLS", "CSIDL_COOKIES", 
		"CSIDL_DESKTOP", "CSIDL_DESKTOPDIRECTORY", "CSIDL_DRIVES",  "CSIDL_FAVORITES", 
		"CSIDL_FONTS", "CSIDL_HISTORY", "CSIDL_INTERNET", "CSIDL_INTERNET_CACHE", 
		"CSIDL_NETHOOD", "CSIDL_NETWORK", "CSIDL_PERSONAL", "CSIDL_PRINTERS", "CSIDL_PRINTHOOD",
		"CSIDL_PROGRAMS", "CSIDL_RECENT", "CSIDL_SENDTO", "CSIDL_STARTMENU", "CSIDL_STARTUP",
		"CSIDL_TEMPLATES"};									// ·����������
	for (int i = 0;i < 30; i++)								// ʹ��forѭ�����λ�ȡ�ļ���
	{
		memset(szPath, 0x00, sizeof(szPath));				// ��ձ���ֵ
		if (SHGetSpecialFolderPath(HWND_DESKTOP, szPath, iIndex[i], FALSE) != 0)	// ��ȡ�����ļ���
			WriteLog("%s=%s", csIndex[i], szPath);			// ����ļ���·��
		else WriteLog("��ȡ%sʧ��", csIndex[i]);			// ���������Ϣ
	}
}

// 21.7.5(OK)
void CSystemInfoSampleDlg::OnButtonGetstartmode()	// ���ϵͳ����ģʽ
{
	int iMode = GetSystemMetrics(SM_CLEANBOOT);		// ��ȡϵͳ����ģʽ
	switch (iMode)									// �жϷ��ص�ģʽֵ
	{
	case 0:	// ����ģʽ
		WriteLog("ϵͳ����ģʽΪ--����ģʽ");break;
	case 1:	// ��ȫģʽ
		WriteLog("ϵͳ����ģʽΪ--��ȫģʽ");break;
	case 2:	// ���绷���°�ȫģʽ
		WriteLog("ϵͳ����ģʽΪ--���绷���°�ȫģʽ");break;
	default:// ����ģʽ
		WriteLog("ϵͳ����ģʽΪ--����");break;
	}
}

// 21.7.6(OK)
void CSystemInfoSampleDlg::OnButtonGetSysversion()	// �жϲ���ϵͳ����
{
	OSVERSIONINFO osvi;								// ����汾��Ϣ�ṹ
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);	// ���ð汾�ṹ��С
	if (GetVersionEx (&osvi))							// ��ȡ�汾��Ϣ
		WriteLog("��ȡ����ϵͳ�汾�ɹ������汾=%d;�ΰ汾=%d;\r\n���ɰ汾=%d;ƽ̨ID=%d;ϵͳ����=%s",
			osvi.dwMajorVersion, osvi.dwMinorVersion, 
			osvi.dwBuildNumber,	osvi.dwPlatformId, osvi.szCSDVersion);	// ����汾��Ϣ
	else WriteLog("��ȡ����ϵͳ�汾ʧ��");				// ���������Ϣ	
}

// 21.7.7(OK)
void CSystemInfoSampleDlg::OnButtonGetruntime()			// ��ȡ��ǰϵͳ������ʱ��
{	
	DWORD dwTicks = GetTickCount();						// ��ȡ���еĵ�λʱ����
	CTimeSpan timeSpan(dwTicks/1000);					// ����ת��ΪCTimeSpan����
	// �������ʱ����Ϣ
	WriteLog("ϵͳ�Ѿ�������%d�죬%dСʱ��%d���ӣ�%d��", timeSpan.GetDays(), timeSpan.GetHours(), timeSpan.GetMinutes(), timeSpan.GetSeconds());	
}

// 21.7.8(OK)
void CSystemInfoSampleDlg::OnButtonGetstarttime()		// ��ȡWindows 2000ϵͳ����ʱ��
{	
	DWORD dwTicks = GetTickCount();						// ��ȡ���еĵ�λʱ����
	CTime time = CTime::GetCurrentTime();				// ��ȡ��ǰʱ��
	CTimeSpan timeSpan(dwTicks/1000);					// ����ת��ΪCTimeSpan����
	time -= timeSpan;									// ��ǰʱ���ȥ�Ѿ����е�ʱ��
	WriteLog("ϵͳ����ʱ��Ϊ��%s", time.Format("%Y-%m-%d %H:%M:%S"));	// �������ʱ��
}

// 21.7.9(OK)
void CSystemInfoSampleDlg::OnButtonGetProcessor()		// ��ȡ��������Ϣ
{
	SYSTEM_INFO sysinfo;								// ����ϵͳ��Ϣ�ṹ
	GetSystemInfo(&sysinfo);							// ��ȡ��������Ϣ
	switch(sysinfo.wProcessorArchitecture)				// �жϴ���������
	{
	case PROCESSOR_ARCHITECTURE_INTEL:					// Intel������
		switch (sysinfo.wProcessorLevel)				// �жϴ������ͺ�
		{
		case 3:
			WriteLog("����������=PROCESSOR_ARCHITECTURE_INTEL--Intel 80386");	break; 
		case 4:
			WriteLog("����������=PROCESSOR_ARCHITECTURE_INTEL--Intel 80486");	break;
		case 5:
			WriteLog("����������=PROCESSOR_ARCHITECTURE_INTEL--Pentium"); break;
		default:
			WriteLog("����������=PROCESSOR_ARCHITECTURE_INTEL"); break;
		}
		break;
	case PROCESSOR_ARCHITECTURE_MIPS :					// MIPS
		WriteLog("����������=MIPS--R%d000", sysinfo.wProcessorLevel);
		break;
	case PROCESSOR_ARCHITECTURE_ALPHA:					// ALPHA
		WriteLog("����������=ALPHA--%d", sysinfo.wProcessorLevel);
		break;
	case PROCESSOR_ARCHITECTURE_PPC:					// PPC
		switch (sysinfo.wProcessorLevel)				// �жϴ������ͺ�
		{
		case 1:
			WriteLog("����������=PPC--PPC 601");break;
		case 3:
			WriteLog("����������=PPC--PPC 603");break;
		case 4:
			WriteLog("����������=PPC--PPC 604");break;
		case 6:
			WriteLog("����������=PPC--PPC 603+");break;
		case 9:
			WriteLog("����������=PPC--PPC 604+");break;
		case 20:
			WriteLog("����������=PPC--PPC 620");break;
		default:
			WriteLog("����������=PPC--PPC PPC");		
		}
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN :			// ������δ֪
		WriteLog("����������δ֪");break;
	default:										// ����δֵ֪
		WriteLog("����������δ֪");break;
	}
	WriteLog("ϵͳ�еĴ�������ĿΪ%d", sysinfo.dwNumberOfProcessors);	// �����������Ŀ
}

// 21.7.10(OK)
void CSystemInfoSampleDlg::OnButtonIsaudio()		// ����Ƿ�װ����
{	// ����Ƶ����
	MMRESULT mmResult = waveOutOpen(NULL, WAVE_MAPPER, NULL, NULL, NULL,WAVE_FORMAT_QUERY);
	if (GetLastError() == MMSYSERR_NODRIVER)	// ���������Ϊû������=û�а�װ����
		WriteLog("ϵͳ��û�а�װ����");			// �����ʾ��Ϣ
	else  WriteLog("ϵͳ�а�װ������");			// �����ʾ��Ϣ
}

// 21.7.11(OK)
void CSystemInfoSampleDlg::OnButtonGetUsername()	// ��ȡ��ǰ�û���
{	
	TCHAR szName[MAX_PATH];							// �����û�������
	DWORD dwLen = MAX_PATH;							// �����û�������
	if (GetUserName(szName, &dwLen))				// ��ȡ�û���
		WriteLog("��ȡ�û����ɹ�,����=%d;�û���=%s", dwLen, szName);// ����û���
	else WriteLog("��ȡ�û���ʧ��");				// ���������Ϣ
}

// 21.7.12(OK)
void CSystemInfoSampleDlg::OnButtonGetEnrovar()		// ��ȡϵͳ��������
{
	char szBuffer[1024] = {0};						// ���廷������ֵ����
	DWORD dwSize=1024;								// ���������С
	if (GetEnvironmentVariable("PATH",(LPTSTR)szBuffer, dwSize) > 0)	// ��ȡ��������ֵ
		WriteLog("��������PATH=%s", szBuffer);		// �����������ֵ
	else WriteLog("��ȡ��������ʧ��");				// ���������ʾ
}

// 21.7.13(OK)
void CSystemInfoSampleDlg::OnButtonSetComputeName() // �޸ļ��������
{
	if (SetComputerName("huge-lln"))			// �޸ļ��������
	{
		char szName[128] = "";	// ����������������
		DWORD dwLen = 128;		// �����������Ƴ���
		if (GetComputerName(szName, &dwLen))		// ��ȡ���������
			WriteLog("���ü�������Ƴɹ����޸ĺ�ļ��������=%s", szName);	// ������������	
	}
	else
        WriteLog("���ü��������ʧ��");			// ���������ʾ   
}

// 21.7.14(OK)
void CSystemInfoSampleDlg::OnButtonGetScreencolor()		// ��ȡ��ǰ��Ļ��ɫ����
{
	HDC hdc = GetDC()->m_hDC;							// ��ȡ�豸�����ľ��
	int iColors = GetDeviceCaps(hdc, BITSPIXEL);		// ��ȡ��Ļ��ɫ����
	WriteLog("��ǰ��Ļ��ɫ����Ϊ%d", iColors);			// �����Ļ��ɫ����
}

// 21.7.15(OK)
void CSystemInfoSampleDlg::OnButtonGetScreenxy()		// ��õ�ǰ��Ļ�ķֱ���
{
	int iScreenX = GetSystemMetrics(SM_CXSCREEN);		// X�ֱ���
	int iScreenY = GetSystemMetrics(SM_CYSCREEN);		// Y�ֱ���
	WriteLog("��ǰ��Ļ�ֱ���Ϊ%d*%d", iScreenX, iScreenY);	// �����Ļ�ֱ���
}










typedef HRESULT (WINAPI  *PFUNCTIONPATH)(HWND hwndOwner, int nFolder, LPITEMIDLIST *ppidl);     
	

