// StaticAndEditSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StaticAndEditSample.h"
#include "StaticAndEditSampleDlg.h"

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
// CStaticAndEditSampleDlg dialog

CStaticAndEditSampleDlg::CStaticAndEditSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticAndEditSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStaticAndEditSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStaticAndEditSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStaticAndEditSampleDlg)
	DDX_Control(pDX, IDC_EDIT_TEST_SCROLL, m_editTestScroll);
	DDX_Control(pDX, IDC_EDIT_TEST, m_editTest);
	DDX_Control(pDX, IDC_STATIC_LOG, m_staticLog);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStaticAndEditSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CStaticAndEditSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_TEST, OnChangeEditTest)
	ON_EN_ERRSPACE(IDC_EDIT_TEST, OnErrspaceEditTest)
	ON_EN_KILLFOCUS(IDC_EDIT_TEST, OnKillfocusEditTest)
	ON_EN_MAXTEXT(IDC_EDIT_TEST, OnMaxtextEditTest)
	ON_EN_SETFOCUS(IDC_EDIT_TEST, OnSetfocusEditTest)
	ON_EN_UPDATE(IDC_EDIT_TEST, OnUpdateEditTest)
	ON_EN_HSCROLL(IDC_EDIT_TEST_SCROLL, OnHscrollEditTestScroll)
	ON_EN_VSCROLL(IDC_EDIT_TEST_SCROLL, OnVscrollEditTestScroll)
	ON_BN_CLICKED(IDC_BUTTON_GETEDITTEXT, OnButtonGetedittext)
	ON_BN_CLICKED(IDC_BUTTON_SETEDITTEXT, OnButtonSetedittext)
	ON_BN_CLICKED(IDC_BUTTON_GETLINE, OnButtonGetline)
	ON_BN_CLICKED(IDC_BUTTON_GETSEL, OnButtonGetsel)
	ON_BN_CLICKED(IDC_BUTTON_SETSEL, OnButtonSetsel)
	ON_BN_CLICKED(IDC_BUTTON_REPLACESEL, OnButtonReplacesel)
	ON_BN_CLICKED(IDC_STATIC_TEST, OnStaticTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticAndEditSampleDlg message handlers

BOOL CStaticAndEditSampleDlg::OnInitDialog()
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

void CStaticAndEditSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStaticAndEditSampleDlg::OnPaint() 
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
HCURSOR CStaticAndEditSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStaticAndEditSampleDlg::OnChangeEditTest() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_CHANGE消息", "左边的编辑控件");
}

void CStaticAndEditSampleDlg::OnErrspaceEditTest() 
{
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_ERRSPACE消息", "左边的编辑控件");
}

void CStaticAndEditSampleDlg::OnKillfocusEditTest() 
{
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_KILLFOCUS消息", "左边的编辑控件");	
}

void CStaticAndEditSampleDlg::OnMaxtextEditTest() 
{
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_MAXTEXT消息", "左边的编辑控件");
}

void CStaticAndEditSampleDlg::OnSetfocusEditTest() 
{
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_SETFOCUS消息", "左边的编辑控件");
}

void CStaticAndEditSampleDlg::OnUpdateEditTest() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_UPDATE消息", "左边的编辑控件");	
}

void CStaticAndEditSampleDlg::OnHscrollEditTestScroll() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_SCROLL flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_HSCROLL消息", "右边的编辑控件");
}

void CStaticAndEditSampleDlg::OnVscrollEditTestScroll() 
{
	// TODO: Add your control notification handler code here
	WriteLog("接收到ON_EN_VSCROLL消息", "右边的编辑控件");
}

void CStaticAndEditSampleDlg::WriteLog(CString message, CString title)
{
	m_staticLog.SetWindowText(title + "--" + message);
}

void CStaticAndEditSampleDlg::OnButtonGetedittext() 
{
	// TODO: Add your control notification handler code here
	CString content;
	m_editTest.GetWindowText(content);
	MessageBox(content, "获取左边编辑框内容");
}

void CStaticAndEditSampleDlg::OnButtonSetedittext() 
{
	// TODO: Add your control notification handler code here
	m_editTest.SetWindowText("您好!这是测试");	
}

void CStaticAndEditSampleDlg::OnButtonGetline() 
{
	// TODO: Add your control notification handler code here
	TCHAR content[256];
	memset(content, 0x00, sizeof(content));
	int iCount = m_editTest.GetLine(1, content, sizeof(content));
	if (iCount > 0)
	{
		MessageBox(content, "GETLINE获取第2行的内容");
	}
	else
	{
		MessageBox("失败", "GETLINE获取第2行的内容");
	}
}

void CStaticAndEditSampleDlg::OnButtonGetsel() 
{
	// TODO: Add your control notification handler code here
	int iStart= 0,iEnd = 0;
	m_editTest.GetSel(iStart, iEnd);
	CString log;
	log.Format("选择的内容从第%d个字符到第%d个字符", iStart, iEnd);	
	MessageBox(log, "GetSel");
}

void CStaticAndEditSampleDlg::OnButtonSetsel() 
{
	// TODO: Add your control notification handler code here
	m_editTest.SetSel(5, 10, TRUE);
	MessageBox("选择编辑控件中的第6个字符到第11个字符", "SetSel");
}

void CStaticAndEditSampleDlg::OnButtonReplacesel() 
{
	// TODO: Add your control notification handler code here
	m_editTest.ReplaceSel("此处是新替换的内容");
}

void CStaticAndEditSampleDlg::OnStaticTest() 
{
	// TODO: Add your control notification handler code here
	MessageBox("如果使用SS_NOTIFY创建静态控件，\n则可以接收其单击事件，\n此处就是例子。", "静态控件");
}
