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
// 记录日志
void CClicpBoardSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.9.1(OK)
void CClicpBoardSampleDlg::OnButtonEnumClformat()	// 列举剪贴板中数据类型
{
	if(!OpenClipboard())							// 打开剪切板
	{
		WriteLog("打开剪切板时发生错误");			// 输出错误信息，并
		return;										// 返回
	}	
	WriteLog("剪切板中支持的数据类型有：");			// 输出提示信息
	UINT uiFormat = EnumClipboardFormats(0);		// 开始枚举剪切板数据类型
	TCHAR	szName[MAX_PATH];						// 定义剪切板名称变量
	while(uiFormat)									// 依次循环处理剪切板数据格式
	{	
		if (uiFormat < 0xc000)						// 如果数据类型小于0xc000，则调用GlobalGetAtomName
			GlobalGetAtomName((ATOM)uiFormat, szName, MAX_PATH);
		else
            GetClipboardFormatName(uiFormat, szName, MAX_PATH);	// 否则，调用GetClipboardFormatName
		WriteLog("%d=%s", uiFormat, szName);		// 输出剪切板格式
		uiFormat = EnumClipboardFormats(uiFormat);	// 枚举下一个格式
	}
    CloseClipboard();								// 关闭剪切板
}


// 21.9.2(OK)
void CClicpBoardSampleDlg::OnButtonMonitor()		// 启动监视剪贴板
{
	hNextWnd = SetClipboardViewer();				// 将对话框句柄加入剪切板监视列表
	if( hNextWnd!= NULL) WriteLog("开始监视剪切板复制的内容");	// 输出提示信息
	
}

void CClicpBoardSampleDlg::OnButtonCancelMonitor()	// 停止监视剪贴板
{
	if( ChangeClipboardChain(hNextWnd))				// 将对话框句柄从剪切板监视列表中移除
	{
		hNextWnd = NULL;							// 重置监视句柄
		WriteLog("结束监视剪切板复制的内容");		// 输出提示信息
	}
}

LRESULT CClicpBoardSampleDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) // 消息处理函数
{	
	if(message == WM_DRAWCLIPBOARD)					// 如果是剪切板复制消息
		WriteLog("剪切板内容发生变化了");			// 输出提示信息
	return CDialog::WindowProc(message, wParam, lParam);	// 调用基类处理函数
}

// 21.9.3(OK)
void CClicpBoardSampleDlg::OnButtonSetClicp()		// 设置剪切板数据		
{
	LPSTR pBuf = NULL;								// 定义数据区
	if (!(pBuf = (LPSTR)GlobalAlloc(GMEM_DDESHARE, 50 * sizeof(TCHAR))))   return; // 初始化数据区
    if (!OpenClipboard())							// 打开剪切板
	{
		WriteLog("打开剪切板时发生错误");			// 输出错误信息，并
		return;										// 返回
	}
	EmptyClipboard();								// 清空剪切板
	CString info;
	info.Format("通过剪切板传递全局数据iIndex=%d", iIndex);	// 输出提示信息
	iIndex++;										// 计数值自增一
	strcpy(pBuf, info);
	if (SetClipboardData(CF_TEXT, pBuf))			// 设置剪切板内容
		WriteLog("设置剪切板内容=%s", info);	// 输出成功提示信息
	else
        WriteLog("设置剪切板内容是失败");		// 输出错误提示信息
	CloseClipboard();								// 关闭剪切板
}

void CClicpBoardSampleDlg::OnButtonGetClicp()		// 获取剪切板数据
{
	LPSTR pBuf; 
    if (!OpenClipboard())							// 打开剪切板
	{
		WriteLog("打开剪切板时发生错误");			// 输出错误信息，并
		return;										// 返回
	}	
	HGLOBAL hGlobal = GetClipboardData(CF_TEXT);	// 获取剪切板中CF_TEXT数据
    pBuf = (LPSTR)GlobalLock(hGlobal);				// 锁定数据区
	WriteLog("获取剪切板内容=%s", pBuf);			// 输出获取的剪切板内容
	GlobalUnlock(hGlobal);							// 解锁数据区
	CloseClipboard();								// 关闭剪切板
}
