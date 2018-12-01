// ClicpBoardSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClicpBoardSample.h"
#include "ClicpBoardSampleDlg.h"

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
// CClicpBoardSampleDlg dialog

CClicpBoardSampleDlg::CClicpBoardSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClicpBoardSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClicpBoardSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClicpBoardSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClicpBoardSampleDlg)
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClicpBoardSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CClicpBoardSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ENUM_CLFORMAT, OnButtonEnumClformat)
	ON_BN_CLICKED(IDC_BUTTON_MONITOR, OnButtonMonitor)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL_MONITOR, OnButtonCancelMonitor)
	ON_BN_CLICKED(IDC_BUTTON_SET_CLICP, OnButtonSetClicp)
	ON_BN_CLICKED(IDC_BUTTON_GET_CLICP, OnButtonGetClicp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClicpBoardSampleDlg message handlers

BOOL CClicpBoardSampleDlg::OnInitDialog()
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
	
	iIndex = 0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClicpBoardSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClicpBoardSampleDlg::OnPaint() 
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
HCURSOR CClicpBoardSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define	MAX_LOG_LENGTH	1024
// ��¼��־
void CClicpBoardSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.9.1(OK)
void CClicpBoardSampleDlg::OnButtonEnumClformat()	// �оټ���������������
{
	if(!OpenClipboard())							// �򿪼��а�
	{
		WriteLog("�򿪼��а�ʱ��������");			// ���������Ϣ����
		return;										// ����
	}	
	WriteLog("���а���֧�ֵ����������У�");			// �����ʾ��Ϣ
	UINT uiFormat = EnumClipboardFormats(0);		// ��ʼö�ټ��а���������
	TCHAR	szName[MAX_PATH];						// ������а����Ʊ���
	while(uiFormat)									// ����ѭ��������а����ݸ�ʽ
	{	
		if (uiFormat < 0xc000)						// �����������С��0xc000�������GlobalGetAtomName
			GlobalGetAtomName((ATOM)uiFormat, szName, MAX_PATH);
		else
            GetClipboardFormatName(uiFormat, szName, MAX_PATH);	// ���򣬵���GetClipboardFormatName
		WriteLog("%d=%s", uiFormat, szName);		// ������а��ʽ
		uiFormat = EnumClipboardFormats(uiFormat);	// ö����һ����ʽ
	}
    CloseClipboard();								// �رռ��а�
}


// 21.9.2(OK)
void CClicpBoardSampleDlg::OnButtonMonitor()		// �������Ӽ�����
{
	hNextWnd = SetClipboardViewer();				// ���Ի�����������а�����б�
	if( hNextWnd!= NULL) WriteLog("��ʼ���Ӽ��а帴�Ƶ�����");	// �����ʾ��Ϣ
	
}

void CClicpBoardSampleDlg::OnButtonCancelMonitor()	// ֹͣ���Ӽ�����
{
	if( ChangeClipboardChain(hNextWnd))				// ���Ի������Ӽ��а�����б����Ƴ�
	{
		hNextWnd = NULL;							// ���ü��Ӿ��
		WriteLog("�������Ӽ��а帴�Ƶ�����");		// �����ʾ��Ϣ
	}
}

LRESULT CClicpBoardSampleDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) // ��Ϣ������
{	
	if(message == WM_DRAWCLIPBOARD)					// ����Ǽ��а帴����Ϣ
		WriteLog("���а����ݷ����仯��");			// �����ʾ��Ϣ
	return CDialog::WindowProc(message, wParam, lParam);	// ���û��ദ����
}

// 21.9.3(OK)
void CClicpBoardSampleDlg::OnButtonSetClicp()		// ���ü��а�����		
{
	LPSTR pBuf = NULL;								// ����������
	if (!(pBuf = (LPSTR)GlobalAlloc(GMEM_DDESHARE, 50 * sizeof(TCHAR))))   return; // ��ʼ��������
    if (!OpenClipboard())							// �򿪼��а�
	{
		WriteLog("�򿪼��а�ʱ��������");			// ���������Ϣ����
		return;										// ����
	}
	EmptyClipboard();								// ��ռ��а�
	CString info;
	info.Format("ͨ�����а崫��ȫ������iIndex=%d", iIndex);	// �����ʾ��Ϣ
	iIndex++;										// ����ֵ����һ
	strcpy(pBuf, info);
	if (SetClipboardData(CF_TEXT, pBuf))			// ���ü��а�����
		WriteLog("���ü��а�����=%s", info);	// ����ɹ���ʾ��Ϣ
	else
        WriteLog("���ü��а�������ʧ��");		// ���������ʾ��Ϣ
	CloseClipboard();								// �رռ��а�
}

void CClicpBoardSampleDlg::OnButtonGetClicp()		// ��ȡ���а�����
{
	LPSTR pBuf; 
    if (!OpenClipboard())							// �򿪼��а�
	{
		WriteLog("�򿪼��а�ʱ��������");			// ���������Ϣ����
		return;										// ����
	}	
	HGLOBAL hGlobal = GetClipboardData(CF_TEXT);	// ��ȡ���а���CF_TEXT����
    pBuf = (LPSTR)GlobalLock(hGlobal);				// ����������
	WriteLog("��ȡ���а�����=%s", pBuf);			// �����ȡ�ļ��а�����
	GlobalUnlock(hGlobal);							// ����������
	CloseClipboard();								// �رռ��а�
}
