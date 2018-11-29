// CommSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CommSample.h"
#include "CommSampleDlg.h"
#include "ThreadCom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_USER_COMSENDMESSAGE	WM_USER+200
#define WM_USER_COMRECVMESSAGE	WM_USER+201

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
// CCommSampleDlg dialog

CCommSampleDlg::CCommSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommSampleDlg)
	m_editRecv = _T("");
	m_editSend = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_RECV, m_editRecv);
	DDX_Text(pDX, IDC_EDIT_SEND, m_editSend);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCommSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CCommSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_MESSAGE(WM_USER_COMSENDMESSAGE, OnSendMsg)
	ON_MESSAGE(WM_USER_COMRECVMESSAGE, OnRecvMsg)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommSampleDlg message handlers

BOOL CCommSampleDlg::OnInitDialog()
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
	pThreadCom = NULL;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCommSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCommSampleDlg::OnPaint() 
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
HCURSOR CCommSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 停止线程
DWORD CCommSampleDlg::StopWinThread(CWinThread *pThread, DWORD dwTimeout)
{
	if (pThread==NULL) return NULL;
 	pThread->PostThreadMessage(WM_QUIT,0,0);
	::WaitForSingleObject(pThread->m_hThread,dwTimeout);
	DWORD nExitCode=0;
	BOOL bFlag=::GetExitCodeThread(pThread->m_hThread,&nExitCode);
	if (bFlag)
	{
		delete pThread;
	}	
	return nExitCode;
}

// 打开串口
void CCommSampleDlg::OnButtonOpen() 
{
    if (pThreadCom != NULL)  return;
    CString str;
    CString com = "COM4";

    pThreadCom = (CThreadCom*)AfxBeginThread(RUNTIME_CLASS(CThreadCom));				
    pThreadCom->SetComStr(com);

    /*	try
    {
    pThreadCom = (CThreadCom*)AfxBeginThread(RUNTIME_CLASS(CThreadCom));				
    pThreadCom->SetComStr(com);
    }
    catch(CException e)
    {
    e.ReportError();
    pThreadCom->m_bDone=TRUE;
    StopWinThread((CWinThread*)pThreadCom,INFINITE);
    pThreadCom=NULL;		
    str.Format("创建串口%s线程错误!", com);
    WriteLog(str);	
    }   */


    if (pThreadCom->OpenCom(com, (CWnd*)this->GetSafeOwner(), 
        WM_USER_COMSENDMESSAGE, WM_USER_COMRECVMESSAGE))
    {		
        str.Format("打开串口%s成功", pThreadCom->GetComStr());
        WriteLog(str);
    }
    else
    {
        str.Format(pThreadCom->m_sError+",请重新配置串口!");
        WriteLog(str);
        pThreadCom->m_bInit=FALSE;		
        return ;		
    }
    m_bCom=TRUE;	
    return ;	
}

void CCommSampleDlg::WriteLog(CString log)
{
	m_editLog.SetWindowText(log);
}

//发送数据通知
LRESULT CCommSampleDlg::OnSendMsg(WPARAM dwEvent,LPARAM dwLen)
{
	if(!dwLen)	return 0;
	BYTE* temp = new BYTE[dwLen+1];
	memset(temp, 0x00, dwLen+1);
	memcpy(temp, (const void*)dwEvent, dwLen);
	CString log;
	log.Format("\r\n发送数据=%s", (LPCTSTR)temp);
	
	if (m_editLog)
	{	
		CEdit* editLog=(CEdit*)FromHandle(m_editLog);
		if (editLog->GetWindowTextLength()>50000)		
		{
			editLog->SetSel(0,-1);
			editLog->Clear();
			editLog->SetSel(0,0);
			editLog->ReplaceSel(log);
		}
		else
		{
			editLog->SetSel(editLog->GetWindowTextLength(),editLog->GetWindowTextLength());
			editLog->ReplaceSel(log );
		}
	}	
	return 0;
}

// 接收消息通知
LRESULT CCommSampleDlg::OnRecvMsg(WPARAM dwEvent,LPARAM dwLen)
{
	if(!dwLen)	return 0;
	BYTE* temp = new BYTE[dwLen+1];
	memset(temp, 0x00, dwLen+1);
	memcpy(temp, (const void*)dwEvent, dwLen);
	CString log;
	log.Format("\r\n接收数据=%s", (LPCTSTR)temp);

	if (m_editRecv.GetLength() > 50000)	m_editRecv = "";
	m_editRecv += log;	
	UpdateData(FALSE);
	return 0;
}

// 发送串口数据
void CCommSampleDlg::OnButtonSend() 
{
	UpdateData(TRUE);
	int iLen = m_editSend.GetLength();
	BYTE* s= new BYTE[iLen];
	memset(s, 0x00, iLen);
	memcpy(s, (LPCTSTR)m_editSend, iLen);
	pThreadCom->SendData((unsigned char*)s, iLen);
}
