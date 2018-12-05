// MultiThreadFuncSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThreadFuncSample.h"
#include "MultiThreadFuncSampleDlg.h"
#include "Maths.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern int globalCounter;
extern bool bThreadRunning;
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
// CMultiThreadFuncSampleDlg dialog

CMultiThreadFuncSampleDlg::CMultiThreadFuncSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThreadFuncSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThreadFuncSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThreadFuncSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThreadFuncSampleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThreadFuncSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThreadFuncSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START_THREAD, OnButtonStartThread)
	ON_BN_CLICKED(IDC_BUTTON_SUSPEND_THREAD, OnButtonSuspendThread)
	ON_BN_CLICKED(IDC_BUTTON_STOP_THREAD, OnButtonStopThread)
	ON_BN_CLICKED(IDC_BUTTON_RESUME_THREAD, OnButtonResumeThread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFuncSampleDlg message handlers

BOOL CMultiThreadFuncSampleDlg::OnInitDialog()
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

void CMultiThreadFuncSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiThreadFuncSampleDlg::OnPaint() 
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
HCURSOR CMultiThreadFuncSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiThreadFuncSampleDlg::OnButtonStartThread() 
{	
	CMaths* pMathObject = new CMaths();
	pThread = new CWinThread();
	pThread->m_bAutoDelete = FALSE;
	pThread = AfxBeginThread(MyThreadProc, pMathObject);
	if (pThread != NULL) MessageBox("启动线程成功");
}

void CMultiThreadFuncSampleDlg::OnButtonSuspendThread() 
{
	// TODO: Add your control notification handler code here
	pThread->SuspendThread();
	CString info;
	info.Format("挂起后globalCounter=%d", globalCounter);
	MessageBox(info, "提示");
}

void CMultiThreadFuncSampleDlg::OnButtonStopThread() 
{
	// TODO: Add your control notification handler code here
	bThreadRunning = FALSE;	
	DWORD exitCode;
	CString info;
	if (GetExitCodeThread(pThread->m_hThread, &exitCode))
	{
		info.Format("线程退出码=%u", exitCode);
		MessageBox(info, "提示");
	}
	else	MessageBox("获取线程退出码时发生错误", "提示");
}

void CMultiThreadFuncSampleDlg::OnButtonResumeThread() 
{
	// TODO: Add your control notification handler code here
	CString info;
	info.Format("重新启动前globalCounter=%d", globalCounter);
	MessageBox(info, "提示");
	pThread->ResumeThread();	
}
