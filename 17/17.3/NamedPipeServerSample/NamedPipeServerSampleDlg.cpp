// NamedPipeServerSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NamedPipeServerSample.h"
#include "NamedPipeServerSampleDlg.h"

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
// CNamedPipeServerSampleDlg dialog

CNamedPipeServerSampleDlg::CNamedPipeServerSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNamedPipeServerSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNamedPipeServerSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNamedPipeServerSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNamedPipeServerSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNamedPipeServerSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CNamedPipeServerSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamedPipeServerSampleDlg message handlers

BOOL CNamedPipeServerSampleDlg::OnInitDialog()
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

void CNamedPipeServerSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNamedPipeServerSampleDlg::OnPaint() 
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
HCURSOR CNamedPipeServerSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNamedPipeServerSampleDlg::OnButtonListen() 
{
    m_hPipe = CreateNamedPipe("\\\\.\\Pipe\\NamedPipeSample", 
        PIPE_ACCESS_DUPLEX,  PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
        1, 0, 0, 1000, NULL); // 创建命名管道
    if (m_hPipe == INVALID_HANDLE_VALUE)	// 判断命名管道是否成功
    {
        m_Log = "创建命名管道失败!\r\n";	// 记录日志信息
        UpdateData(FALSE);				// 显示日志
        return;
    }
    else
    {
        m_Log = "创建命名管道成功!\r\n";	// 记录日志信息
        UpdateData(FALSE);				// 显示日志
        AfxBeginThread(ListenProc, this); // 开启监听线程
    }	
}

UINT ListenProc(LPVOID lpVoid)			// 监听线程函数
{
    char buffer[1024];					// 数据缓存　
    DWORD dwReadBytes;					// 定义读取数据的字节个数的变量
    CNamedPipeServerSampleDlg* pDlg = (CNamedPipeServerSampleDlg*)lpVoid; // 获取对话框句柄　
    if (ConnectNamedPipe(pDlg->m_hPipe, NULL) == FALSE)
    {// 等待客户端连接
        CloseHandle(pDlg->m_hPipe);		// 关闭管道句柄
        pDlg->m_Log += "与命名管道客户端建立连接失败!\r\n"; // 记录日志信息
        pDlg->m_editLog.SetWindowText(pDlg->m_Log);				// 显示日志
        return 0;
    }
    else
    {
        pDlg->m_Log += "与客户端建立连接!\r\n";	// 记录日志信息
        pDlg->m_editLog.SetWindowText(pDlg->m_Log);				// 显示日志
    }
    if (ReadFile(pDlg->m_hPipe, buffer, sizeof(buffer), &dwReadBytes, NULL) == FALSE)
    {// 从管道读取数据
        CloseHandle(pDlg->m_hPipe);				// 关闭管道句柄
        pDlg->m_Log +=  "从管道读取数据失败!\r\n";	// 记录日志信息		
    } 
    else 
    {
        buffer[dwReadBytes] = '\0';				// 显示接收到的信息
        pDlg->m_Log += "接收到客户端命名管道发送的数据=\r\n";
        pDlg->m_Log += CString(buffer);			// 记录日志信息		
    }

    if (DisconnectNamedPipe(pDlg->m_hPipe) == FALSE)	// 终止连接
    {
        pDlg->m_Log += "终止连接失败!\r\n";		// 记录日志信息		
    }
    else
    {
        CloseHandle(pDlg->m_hPipe);					// 关闭管道句柄
        pDlg->m_Log += "成功终止连接!\r\n";			// 记录日志信息	
    } 

    pDlg->m_editLog.SetWindowText(pDlg->m_Log);				// 显示日志
    return 1;
}
