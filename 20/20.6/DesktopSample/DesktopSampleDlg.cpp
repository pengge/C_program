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
// ��¼��־
void CDesktopSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.6.2(OK)
void CDesktopSampleDlg::OnButtonGetBar()	// ��ȡ�������Ի�����
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// ��ȡ�������Ի���
	if(hWinBar != NULL)	WriteLog("��ȡ���������ھ���ɹ�=0x%08X", hWinBar);	// �����Ϣ
	else WriteLog("��ȡ���������ھ��ʧ��");			// ���������Ϣ
}

// 21.6.3(OK)
void CDesktopSampleDlg::OnButtonGetDesklist()		// ��ȡ�����б���ͼ���
{
	HWND hDeskWnd = ::FindWindow("Progman",NULL);	// ��ȡ����������
	if(hDeskWnd == NULL)							// �����ȡʧ��
	{
		WriteLog("��ȡ������ʧ�ܡ�");	return;		// ��ʾ������Ϣ������		
	}	
	HWND  hSubDeskWnd=::GetDlgItem(hDeskWnd, 0L);	// ��ȡ��������еĵ�һ������
	if(hSubDeskWnd == NULL)								// �����ȡʧ��
	{
		WriteLog("��ȡ���洰���еĶ���ʧ�ܡ�");	return;	// ��ʾ������Ϣ������
	}  
	HWND  hDeskList=::GetDlgItem(hSubDeskWnd, 1L);		// ��ȡ��������еĵ�һ������ĵڶ�������
	if(hDeskList == NULL)								// �����ȡʧ��
	{	
		WriteLog("��ȡ���洰���еĶ���ʧ�ܡ�");	return;	// ��ʾ������Ϣ������
	}
	WriteLog("��ȡ�����б���ͼ����ɹ�=0x%08X", hDeskList);	// �����ȡ����Ϣ
}

// 21.6.4(OK)
void CDesktopSampleDlg::OnButtonGettoolbarpro()			// ��ȡ����������
{	   
	if(FAILED(CoInitialize(NULL)))						// ��ʼ��COM��������
	{
		WriteLog("��ʼ��COM��������ʧ��");	return;		// ��ʾ������Ϣ������
	}
	IShellDispatch* pShellDispatch=NULL;				// ����IShellDispatch�ӿڱ���
	if(SUCCEEDED(CoCreateInstance(CLSID_Shell,NULL,CLSCTX_INPROC_SERVER, IID_IDispatch,(LPVOID*)&pShellDispatch)))   
	{	// ����IShellDispatchʵ��
		if(SUCCEEDED(pShellDispatch->TrayProperties())) WriteLog("��ʾ���������Դ��ڳɹ�");	// ��ʾ�ɹ���Ϣ
		else WriteLog("��ʾ���������Դ���ʧ��");		// ��ʾ������Ϣ
	}
	else WriteLog("����IShellDispatch�ӿ�ʵ��ʧ��");	// ��ʾ������Ϣ
	CoUninitialize();									// �ͷ�COM��������
}

// 21.6.5(OK)	
void CDesktopSampleDlg::OnButtonHideDesktop()			// ���������ļ�
{	
	HWND hDeskWnd = ::FindWindow("Progman",NULL);		// ��ȡ�����ļ����	
	if(hDeskWnd!=NULL)	::ShowWindow(hDeskWnd, SW_HIDE);// ���������ļ�
}
void CDesktopSampleDlg::OnButtonShowDesktop()			// ��ʾ�����ļ�
{	
	HWND hDeskWnd = ::FindWindow("Progman",NULL);		// ��ȡ�����ļ����	
	if(hDeskWnd!=NULL)	::ShowWindow(hDeskWnd, SW_SHOW);// ��ʾ����
}

// 21.6.6(OK)
void CDesktopSampleDlg::OnButtonHideBar()				// ����������
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// ��ȡ���������
	if(hWinBar!=NULL)	::ShowWindow(hWinBar, SW_HIDE);	// ����������
}
void CDesktopSampleDlg::OnButtonShowBar()				// ��ʾ������
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// ��ȡ���������	
	if(hWinBar!=NULL)	::ShowWindow(hWinBar, SW_SHOW);	// ��ʾ������
}

// 21.6.7(OK)
void CDesktopSampleDlg::OnButtonShowStart()				// ��ʾ��ʼ��ť
{
    HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// ��ȡ���������
    if(hWinBar!=NULL)
    {
        HWND hMenu = ::FindWindowEx(hWinBar, 0, "Button", NULL);	// ��ȡ��ʼ��ť���
        if(hMenu!=NULL)	::ShowWindow(hMenu, SW_SHOW);	// ��ʾ��ʼ��ť
        else WriteLog("��ȡ��ʼ��ť�Ի�����ʧ��");	// ���������Ϣ
    }
    else WriteLog("��ȡWindows���������ʧ��");			// ���������Ϣ
}
void CDesktopSampleDlg::OnButtonHideStart()				// ���ؿ�ʼ��ť
{
    HWND hWinBar = ::FindWindow("Shell_TrayWnd","");	// ��ȡ���������
    if(hWinBar!=NULL)
    {
        HWND hMenu = ::FindWindowEx(hWinBar, 0, "Button", NULL);	// ��ȡ��ʼ��ť���
        if(hMenu!=NULL)	::ShowWindow(hMenu, SW_HIDE);	// ���ؿ�ʼ��ť
        else WriteLog("��ȡ��ʼ��ť�Ի�����ʧ��");	// ���������Ϣ
    }
    else WriteLog("��ȡWindows���������ʧ��");			// ���������Ϣ
}

// 21.6.8(OK)
void CDesktopSampleDlg::OnButtonHideClock()					// ����������ʱ��
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd",NULL);		// ��ȡ���������
	if (hWinBar != NULL)									// ����ɹ�����
	{
		HWND hNotifyWnd = ::FindWindowEx(hWinBar, 0, "TrayNotifyWnd",NULL);	// ��ȡ֪ͨ���̾��
		if (hNotifyWnd != NULL)								// ����ɹ�����
		{
			HWND hClockWnd = ::FindWindowEx(hNotifyWnd, 0, "TrayClockWClass", NULL);	// ��ȡʱ�Ӿ��
			if(hClockWnd!=NULL)	::ShowWindow(hClockWnd, SW_HIDE);	// ����ɹ���������ʱ��
			else  WriteLog("��ȡʱ�Ӿ��ʧ��");				// ��ʾ������Ϣ
		}
		else WriteLog("��ȡ֪ͨ���̾��ʧ��");				// ��ʾ������Ϣ
	}
	else WriteLog("��ȡ���������ʧ��");					// ��ʾ������Ϣ
}
void CDesktopSampleDlg::OnButtonShowClock()					// ��ʾ������ʱ��
{
	HWND hWinBar = ::FindWindow("Shell_TrayWnd",NULL);		// ��ȡ���������
	if (hWinBar != NULL)									// ����ɹ�����
	{
		HWND hNotifyWnd = ::FindWindowEx(hWinBar, 0, "TrayNotifyWnd",NULL);	// ��ȡ֪ͨ���̾��
		if (hNotifyWnd != NULL)								// ����ɹ�����
		{
			HWND hClockWnd = ::FindWindowEx(hNotifyWnd, 0, "TrayClockWClass", NULL);	// ��ȡʱ�Ӿ��
			if(hClockWnd!=NULL)	::ShowWindow(hClockWnd, SW_SHOW);	// ����ɹ�������ʾʱ��
			else  WriteLog("��ȡʱ�Ӿ��ʧ��");				// ��ʾ������Ϣ
		}
		else WriteLog("��ȡ֪ͨ���̾��ʧ��");				// ��ʾ������Ϣ
	}
	else WriteLog("��ȡ���������ʧ��");					// ��ʾ������Ϣ	
}

// 21.6.9(OK)
void CDesktopSampleDlg::OnButtonSaverscreenRunning()	// �ж���Ļ���������Ƿ�������
{
	HDESK hDesktop;										// ����������
    hDesktop = OpenDesktop(TEXT("screen-saver"), 0, FALSE, MAXIMUM_ALLOWED );	// ��������������
    if(hDesktop == NULL)								// ������صľ����Ч����
	{
		if(GetLastError() == ERROR_ACCESS_DENIED)		// �������ERROR_ACCESS_DENIED����=������������
			WriteLog("������������");					// �����Ϣ��ʾ
		else WriteLog("û����������");					// ����=����û������
	}
	else												// ������صľ����Ч=������������
	{
		WriteLog("������������");						// �����Ϣ��ʾ
		CloseDesktop(hDesktop);							// �ر�����
	}
}

// 21.6.10(OK)
void CDesktopSampleDlg::OnButtonGetFont()				// �ж�ϵͳ�Ƿ�ʹ�ô�����
{
	HWND hWnd = ::GetDesktopWindow();					// ��ȡ������
	if (hWnd != NULL)									// ����ɹ�����
	{
		HDC	hDC = ::GetWindowDC(hWnd);					// ��ȡ����������
		if (hDC != NULL)								// ����ɹ�����
		{
			int	iOldMode = SetMapMode(hDC, MM_TEXT);	// ����������ӳ��ģʽ 
			TEXTMETRIC   tm;							// ��������ṹ����
			if (GetTextMetrics(hDC,&tm))				// ��ȡ����������������Ϣ
			{
				SetMapMode(hDC,iOldMode);				// �ָ����������ĵ�ӳ��ģʽ
				::ReleaseDC(hWnd,hDC);					// �ͷ���������Դ
				if (tm.tmHeight > 16)					// ʹ�ô�����
					WriteLog("ϵͳʹ�õ��Ǵ����壬��С=%d", tm.tmHeight);	
				else WriteLog("ϵͳʹ�õĲ��Ǵ����壬��С=%d", tm.tmHeight);   // û��ʹ�ô�����
			}
			else WriteLog("��ȡ������Ϣʧ��");			// ���������Ϣ
		}
		else WriteLog("��ȡ����������ʧ��");			// ���������Ϣ
	}
	else WriteLog("��ȡ������ʧ��");					// ���������Ϣ
}

// 21.6.11(OK)
void CDesktopSampleDlg::OnButtonSetBackgroud()			// �ı����汳����ɫ
{
	if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "River Sumida.jpg", 0))	// �޸����汳��
		WriteLog("�������汳���ɹ�");					// �����ʾ��Ϣ
	else WriteLog("�������汳��ʧ��");					// ���������Ϣ
}




