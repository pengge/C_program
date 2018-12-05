// DLLAppSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DLLAppSample.h"
#include "DLLAppSampleDlg.h"
#include "winuser.h"
#include "ShieldKeyBordSample.h"

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
// CDLLAppSampleDlg dialog

CDLLAppSampleDlg::CDLLAppSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDLLAppSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLLAppSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDLLAppSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLLAppSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Control(pDX, IDC_LIST_ICON, m_iconList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDLLAppSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CDLLAppSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GETALLICON, OnButtonGetallicon)
	ON_MESSAGE(WM_ICON_MESSAGE, OnIconMessage)
	ON_BN_CLICKED(IDC_BUTTON_GETBITMAP, OnButtonGetbitmap)
	ON_MESSAGE(WM_BITMAP_MESSAGE, OnBitmapMessage)
	ON_BN_CLICKED(IDC_BUTTON_GETDIALOG, OnButtonGetdialog)		
	ON_BN_CLICKED(IDC_BUTTON_REPLACEDIALOG, OnButtonReplacedialog)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE_POWER, OnButtonDisablePower)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE_WIN, OnButtonDisableWin)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE_ALTF4, OnButtonDisableAltf4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLLAppSampleDlg message handlers

BOOL CDLLAppSampleDlg::OnInitDialog()
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

void CDLLAppSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDLLAppSampleDlg::OnPaint() 
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
HCURSOR CDLLAppSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDLLAppSampleDlg::WriteLog(CString log)
{
	m_editLog.SetWindowText(log);
}

void CDLLAppSampleDlg::ResetContent()
{
	m_iconList.ShowWindow(SW_SHOW);
	if (imagelist.m_hImageList == NULL)
	{
		imagelist.Create(32, 32, ILC_COLOR32, 8, 8); 
	}
	m_iconList.DeleteAllItems();
}


// 枚举图标
void CDLLAppSampleDlg::OnButtonGetallicon() 
{
	ResetContent();	
	HINSTANCE  hLibrary;
	if( (hLibrary = LoadLibraryEx( "MORICONS.DLL", NULL, LOAD_LIBRARY_AS_DATAFILE )) == NULL )
	{
		WriteLog("文件载入错误!");
		return;
	}

	if(!EnumResourceNames(hLibrary,RT_GROUP_ICON,(ENUMRESNAMEPROC)EnumIconProcedure,(LPARAM)GetSafeHwnd()))
		WriteLog("列举图标资源停止!");

	FreeLibrary(hLibrary);

	CString log;
	log.Format("DLL中共包含%d个图标资源！", m_iconList.GetItemCount());
	WriteLog(log);
}

// 显示图标
LRESULT CDLLAppSampleDlg::OnIconMessage(WPARAM wParam,LPARAM lParam)
{
	int iIconRet = imagelist.Add((HICON)wParam); 
	if (iIconRet!=-1)
	{
		m_iconList.SetImageList (&imagelist,LVSIL_SMALL);
		int iIndex = m_iconList.GetItemCount();
		m_iconList.InsertItem(iIndex, (const char*)&lParam, iIndex);
	}
    return 1;
}

// 枚举位图
void CDLLAppSampleDlg::OnButtonGetbitmap() 
{
	m_iconList.ShowWindow(SW_HIDE);
	if( (hLibrary = LoadLibraryEx( "MORICONS.DLL", NULL, LOAD_LIBRARY_AS_DATAFILE )) == NULL )
	{
		WriteLog("文件载入错误!");
		return;
	}

	if(!EnumResourceNames(hLibrary,RT_BITMAP,(ENUMRESNAMEPROC)EnumBitmapProcedure,(LPARAM)GetSafeHwnd()))
		WriteLog("列举位图资源停止!");
	FreeLibrary(hLibrary);
}

//显示位图
LRESULT CDLLAppSampleDlg::OnBitmapMessage(WPARAM wParam,LPARAM lParam)
{	
	CStatic* m_Bitmap = (CStatic*)GetDlgItem(IDC_STATIC_BITMAP);
	m_Bitmap->SetBitmap((HBITMAP)wParam);
	WriteLog((const char*)&lParam);
    return 1;
}

//使用模块对话框资源
void CDLLAppSampleDlg::OnButtonGetdialog() 
{
	HINSTANCE m_hInstOld=AfxGetInstanceHandle();
	HINSTANCE m_hInstNew = LoadLibrary("RedDLL.exe"); 
	if (m_hInstNew == NULL)  WriteLog("装载可执行文件失败！");	 
	AfxSetResourceHandle(m_hInstNew);
	CDialog* dlg = new CDialog();
	if (dlg->Create(IDD_ABOUTBOX))	dlg->ShowWindow(SW_SHOW);
	AfxSetResourceHandle(m_hInstOld);
}

void CDLLAppSampleDlg::OnButtonReplacedialog() 
{
	HRSRC hRes, hResLoad; 
	HANDLE hExe, hUpdateExe; 
	char *lpResLock;    
	BOOL bResult; 
 
	hExe = LoadLibrary("RedDLL.exe"); 
	if (hExe == NULL)  WriteLog("装载可执行文件失败！");		
 
	hRes = FindResource((HINSTANCE)hExe, MAKEINTRESOURCE(IDD_ABOUTBOX), RT_DIALOG); 
	if (hRes == NULL) WriteLog("无法查找要替换的资源！");
	 
	hResLoad = (HRSRC)LoadResource((HINSTANCE)hExe, hRes);  
	if (hResLoad == NULL)	WriteLog("无法装载对话框！"); 	

	lpResLock = (char*)LockResource(hResLoad); 
	if (lpResLock == NULL)  WriteLog("无法锁定对话框！"); 

 
	hUpdateExe = (HRSRC)BeginUpdateResource("GreenDLL.exe", FALSE); 
	if (hUpdateExe == NULL)  WriteLog("无法打开要写入资源的文件！"); 

	bResult = UpdateResource((HINSTANCE)hUpdateExe, RT_DIALOG, MAKEINTRESOURCE(IDD_ABOUTBOX),  
     MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), lpResLock, 
     SizeofResource((HINSTANCE)hExe, hRes));  
	if (bResult == FALSE)  WriteLog("替换资源失败！"); 
	
	if (!EndUpdateResource(hUpdateExe, FALSE)) WriteLog("不能写入对文件的修改！");	
 
	if (!FreeLibrary((HINSTANCE)hExe)) 	WriteLog("释放文件失败！"); 	
}

//屏蔽键盘POWER键
void CDLLAppSampleDlg::OnButtonDisablePower() 
{
	DWORD dwVerKey[] = {0x00000001};
	DWORD dwConKey[] = {0};
    int nLength = sizeof(dwVerKey) / sizeof(DWORD);
    if (StartShieldKey(dwVerKey, dwConKey, nLength)) WriteLog("已经屏蔽POWER键");
	else WriteLog("屏蔽POWER键失败");
}

//屏蔽键盘WIN键
void CDLLAppSampleDlg::OnButtonDisableWin() 
{
	DWORD dwVerKey[] = {VK_LWIN, VK_RWIN};
	DWORD dwConKey[] = {0, 0};
    int nLength = sizeof(dwVerKey) / sizeof(DWORD);
    if (StartShieldKey(dwVerKey, dwConKey, nLength)) WriteLog("已经屏蔽了WIN按键");
	else WriteLog("屏蔽WIN按键失败");	
}

//禁止使用<Alt＋F4>键来关闭窗体
void CDLLAppSampleDlg::OnButtonDisableAltf4() 
{
	DWORD dwVerKey[] = {VK_F4};
	DWORD dwConKey[] = {1};
    int nLength = sizeof(dwVerKey) / sizeof(DWORD);
    if (StartShieldKey(dwVerKey, dwConKey, nLength)) WriteLog("已经屏蔽了Alt＋F4按键");
	else WriteLog("屏蔽Alt＋F4按键失败");
}
