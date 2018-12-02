// CRegKeySampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CRegKeySample.h"
#include "CRegKeySampleDlg.h"

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
// CCRegKeySampleDlg dialog

CCRegKeySampleDlg::CCRegKeySampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCRegKeySampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCRegKeySampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCRegKeySampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCRegKeySampleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCRegKeySampleDlg, CDialog)
	//{{AFX_MSG_MAP(CCRegKeySampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_WRITENEWKEY, OnButtonWritenewkey)
	ON_BN_CLICKED(IDC_BUTTON_QUERYKEY, OnButtonQuerykey)
	ON_BN_CLICKED(IDC_BUTTON_WRITEDEFAULTKEY, OnButtonWritedefaultkey)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCRegKeySampleDlg message handlers

BOOL CCRegKeySampleDlg::OnInitDialog()
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

void CCRegKeySampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCRegKeySampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CCRegKeySampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// 22.3.1(OK)
void CCRegKeySampleDlg::OnButtonWritedefaultkey()	// 写入默认值
{
	CRegKey key;
	long result = key.Create(HKEY_CURRENT_USER, "MyTestKey\\Animals\\Pig");
	if (result != ERROR_SUCCESS)	
	{
		MessageBox("创建注册表键失败", "错误");	
		return;
	}
	result = key.SetValue("体态肥胖，好吃懒做，但是活泼可爱");
	if (result != ERROR_SUCCESS)
        MessageBox("写入注册表默认键值失败", "错误");
	else
        MessageBox("写入注册表默认键值成功", "提示");
}

// 22.3.2(OK)
void CCRegKeySampleDlg::OnButtonWritenewkey()	// 写入新键值
{
	
	CRegKey key;
	long result1;
	long result = key.Create(HKEY_CURRENT_USER, "MyTestKey\\Animals\\");
	if (result != ERROR_SUCCESS)	
	{
		MessageBox("创建注册表键失败", "错误");	
		return;
	}
	result1 = key.SetKeyValue("Pig", "好吃懒做，但是活泼可爱", "特点");
	result = key.SetKeyValue("Pig", "肥胖", "体态");
	if ((result != ERROR_SUCCESS) || (result1 != ERROR_SUCCESS))
        MessageBox("写入注册表新键值失败", "错误");
	else
        MessageBox("写入注册表新键值成功", "提示");
}

// 22.3.3(OK)
void CCRegKeySampleDlg::OnButtonQuerykey()	// 查询键值
{	
	CRegKey key;
	long result = key.Create(HKEY_CURRENT_USER, "MyTestKey\\Animals\\Pig");
	if (result != ERROR_SUCCESS)	
	{
		MessageBox("打开注册表键失败", "错误");	
		return;
	}
	char chat[256];
	DWORD iLen = 256;
	result = key.QueryValue(chat, "体态", &iLen);
	if (result != ERROR_SUCCESS)
        MessageBox("查询注册表键失败", "错误");	
	else
        MessageBox(chat, "Pig的体态是");
}


