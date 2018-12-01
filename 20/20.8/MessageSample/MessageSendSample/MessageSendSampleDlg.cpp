// MessageSendSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MessageSendSample.h"
#include "MessageSendSampleDlg.h"

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
// CMessageSendSampleDlg dialog

CMessageSendSampleDlg::CMessageSendSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageSendSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessageSendSampleDlg)
	m_content = _T("WM_COPYDATA����");
	m_sender = _T("LLN");
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMessageSendSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessageSendSampleDlg)
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_content);
	DDX_Text(pDX, IDC_EDIT_SENDER, m_sender);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMessageSendSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMessageSendSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND_COPYDATA, OnButtonSendCopydata)
	ON_BN_CLICKED(IDC_BUTTON_SEND_MYMESSAGE, OnButtonSendMymessage)
	ON_BN_CLICKED(IDC_BUTTON_REGMESSAGE, OnButtonRegmessage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessageSendSampleDlg message handlers

BOOL CMessageSendSampleDlg::OnInitDialog()
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

void CMessageSendSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMessageSendSampleDlg::OnPaint() 
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
HCURSOR CMessageSendSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define MAX_LOG_LENGTH	1024
// ��¼��־
void CMessageSendSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.8.1(OK)
#define WM_MY_MESSAGE	WM_USER + 66			// �Զ�����Ϣ

void CMessageSendSampleDlg::OnButtonSendMymessage()		// �����Զ�����Ϣ����
{
	SendMessage(WM_MY_MESSAGE, NULL, NULL);		// �����Զ�����Ϣ
}

LRESULT CMessageSendSampleDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) // ��������
{
	switch (message)			// �ж���Ϣ����
	{
	case WM_MY_MESSAGE:
		WriteLog("���յ�WM_MY_MESSAGE��Ϣ");	// ���յ��û��Զ�����Ϣ�����
		break;
	default:
		break;
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

// 21.8.2(OK)
void CMessageSendSampleDlg::OnButtonRegmessage()			// ע����Ϣ����	
{
	UINT myMsg = RegisterWindowMessage("LLN's Message Test");	// ע����Ϣ
	::SendMessage(HWND_BROADCAST, myMsg, NULL, NULL);		// ���͹㲥��Ϣ
}


// 21.8.4(OK)
struct MESCONTENT				// ��Ϣ���ݽṹ
{
	char	sender[50];			// ��Ϣ������
	char	content[500];		// ��Ϣ����
};

void CMessageSendSampleDlg::OnButtonSendCopydata()	// ͨ��WM_COPYDATA��Ϣ��������
{
	UpdateData(TRUE);								// ��ȡ��������
	CWnd *pWnd=CWnd::FindWindow(NULL, _T("����WM_COPYDATA��Ϣ����"));	// ��ȡ���նԻ���
    if(pWnd==NULL)									// ���û�м��������նԻ�����
	{
        WriteLog("������Ϣ���ݵĽ���δ����");		// ���������Ϣ����
        return;										// ����
    }

	MESCONTENT msData={0};								// ������Ϣ�ṹ����
	strcpy(msData.sender, m_sender.GetBuffer(50));		// ��ֵ��Ϣ������
	strcpy(msData.content,m_content.GetBuffer(500));	// ��ֵ��Ϣ����

	COPYDATASTRUCT cpd;									// ���巢�ͽṹ����
    cpd.dwData = 0;										// ��������ֵΪ0
	cpd.cbData = sizeof(msData);							// �������ݵĳ���
	cpd.lpData = &msData;									// ������������
    
    pWnd->SendMessage(WM_COPYDATA, NULL, (LPARAM)&cpd);		// ����WM_COPYDATA��Ϣ
}