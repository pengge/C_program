// LBAndCBSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LBAndCBSample.h"
#include "LBAndCBSampleDlg.h"

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
// CLBAndCBSampleDlg dialog

CLBAndCBSampleDlg::CLBAndCBSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLBAndCBSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLBAndCBSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLBAndCBSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLBAndCBSampleDlg)
	DDX_Control(pDX, IDC_LIST_TEST, m_listTest);
	DDX_Control(pDX, IDC_COMBO_TEST, m_comboTest);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLBAndCBSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CLBAndCBSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST_TEST, OnSelchangeListTest)
	ON_CBN_SELCHANGE(IDC_COMBO_TEST, OnSelchangeComboTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLBAndCBSampleDlg message handlers

BOOL CLBAndCBSampleDlg::OnInitDialog()
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
	InitListBoxData();
	InitComboBoxData();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLBAndCBSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLBAndCBSampleDlg::OnPaint() 
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
HCURSOR CLBAndCBSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLBAndCBSampleDlg::InitListBoxData()
{
	CString items[3]= {"北京", "上海", "广州"};
	for (int i =0;i < 3;i++)
	{
		m_listTest.AddString(items[i]);
	}	
}

void CLBAndCBSampleDlg::OnSelchangeListTest() 
{
	// TODO: Add your control notification handler code here
	int index = m_listTest.GetCurSel();
	CString result;
	m_listTest.GetText(index, result);
	MessageBox(result, "当前列表框选择的内容");
}

void CLBAndCBSampleDlg::InitComboBoxData()
{
	CString items[5]= {"汉族", "回族", "满族", "白族", "其他"};
	for (int i =0;i < 5;i++)
	{
		m_comboTest.AddString(items[i]);
	}
}

void CLBAndCBSampleDlg::OnSelchangeComboTest() 
{
	// TODO: Add your control notification handler code here
	CString result; 
	m_comboTest.GetWindowText(result);	
	MessageBox(result, "当前组合框选择的内容");
}
