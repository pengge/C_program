// MFCSOCKServerSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCSOCKServerSample.h"
#include "MFCSOCKServerSampleDlg.h"

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
// CMFCSOCKServerSampleDlg dialog

CMFCSOCKServerSampleDlg::CMFCSOCKServerSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCSOCKServerSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCSOCKServerSampleDlg)
	m_Port = _T("6666");
	m_editRecv = _T("");
	m_editSend = _T("");
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSOCKServerSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCSOCKServerSampleDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_IP);
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_PORT, m_Port);
	DDX_Text(pDX, IDC_EDIT_RECEIVE, m_editRecv);
	DDX_Text(pDX, IDC_EDIT_SEND, m_editSend);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCSOCKServerSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCSOCKServerSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_MESSAGE(WM_SOCKET_LOG, OnLogMsg)
	ON_MESSAGE(WM_SOCKET_RECEIVE, OnRecvMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCSOCKServerSampleDlg message handlers

BOOL CMFCSOCKServerSampleDlg::OnInitDialog()
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
	m_IP.SetWindowText("127.0.0.1");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCSOCKServerSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCSOCKServerSampleDlg::OnPaint() 
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
HCURSOR CMFCSOCKServerSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 监听
void CMFCSOCKServerSampleDlg::OnButtonListen() 
{
	pSocketServer = new CSocketServer();
	UpdateData(TRUE);
	pSocketServer->m_hMsgWnd = this->GetSafeHwnd();
	if (pSocketServer->Create(atoi(m_Port), SOCK_STREAM, FD_ACCEPT|FD_CLOSE))
		WriteLog("创建服务器SOCKET成功");
	else WriteLog("创建服务器SOCKET失败");

	if (pSocketServer->Listen())
		WriteLog("监听服务器成功");
	else WriteLog("监听服务器失败");
}

// 发送
void CMFCSOCKServerSampleDlg::OnButtonSend() 
{
	if (pSocketServer == NULL) 
	{
		WriteLog("SOCKET没有初始化");
		return;
	}
	if (pSocketServer->m_clientList.GetCount() <= 0)
	{
		WriteLog("没有客户端SOCKET");
		return;
	}
	UpdateData(TRUE);
	int iLen = m_editSend.GetLength();
	BYTE* s= new BYTE[iLen];
	memset(s, 0x00, iLen);
	memcpy(s, (LPCTSTR)m_editSend, iLen);	

	int iCount = pSocketServer->m_clientList.GetCount();
	for (int i = 0;i <iCount;i ++)
	{
		POSITION pos = pSocketServer->m_clientList.FindIndex(i);
		CSocketClient* pClient = (CSocketClient*)pSocketServer->m_clientList.GetAt(pos);
		if (pClient != NULL)	pClient->Send((unsigned char*)s, iLen);
	}
	
	WriteLog("发送数据中。。。。。。");
}

// 记录日志
void CMFCSOCKServerSampleDlg::WriteLog(CString log)
{
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);
}

// 接收消息通知
LRESULT CMFCSOCKServerSampleDlg::OnRecvMsg(WPARAM dwEvent, LPARAM dwLen)
{
	if(!dwLen)	return 0;
	BYTE* temp = new BYTE[dwLen+1];
	memset(temp, 0x00, dwLen+1);
	memcpy(temp, (const void*)dwEvent, dwLen);
	CString log; 
	log.Format("接收到客户端数据=%s\r\n", (LPCTSTR)temp);

	if (m_editRecv.GetLength() > 50000)	m_editRecv = "";
	m_editRecv += log;	
	UpdateData(FALSE);
	return 0;
}

// 接收到日志
LRESULT CMFCSOCKServerSampleDlg::OnLogMsg(WPARAM dwEvent, LPARAM dwLen)
{
	if(!dwLen)	return 0;
	BYTE* temp = new BYTE[dwLen+1];
	memset(temp, 0x00, dwLen+1);
	memcpy(temp, (const void*)dwEvent, dwLen);
	WriteLog((LPCTSTR)temp);
	return 0;
}
