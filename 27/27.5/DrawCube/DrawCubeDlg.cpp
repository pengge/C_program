// DrawCubeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DrawCube.h"
#include "DrawCubeDlg.h"

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
// CDrawCubeDlg dialog

CDrawCubeDlg::CDrawCubeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawCubeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDrawCubeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bCameraReset	= TRUE; 
    bFirstRender	= TRUE;
}

void CDrawCubeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawCubeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDrawCubeDlg, CDialog)
	//{{AFX_MSG_MAP(CDrawCubeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawCubeDlg message handlers

BOOL CDrawCubeDlg::OnInitDialog()
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
	if(! cube.CreateD3DDevice(m_hWnd, FALSE))
        return FALSE;
  
    if(! cube.InitVertexBuffer())
        return FALSE;


	cube.Render();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDrawCubeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawCubeDlg::OnPaint() 
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
HCURSOR CDrawCubeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDrawCubeDlg::OnDestroy() 
{	
	CDialog::OnDestroy();
	cube.ReleaseD3D();	
}

void CDrawCubeDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	bCameraReset = FALSE;
	switch (nChar)
	{	
	case 'a':	//左
	case 'A':
		bCameraReset = TRUE;
		bFirstRender = FALSE;
		cube.m_curX -= 0.2f;
		break;
	case 'd':	//右
	case 'D':
		bCameraReset = TRUE;
		bFirstRender = FALSE;
		cube.m_curX += 0.2f;
		break;
	case 'w':	//上
	case 'W':
		bCameraReset = TRUE;
		bFirstRender = FALSE;
		cube.m_curY += 0.2f;
		break;
	case 'z':	//下
	case 'Z':
		bCameraReset = TRUE;
		bFirstRender = FALSE;
		cube.m_curY -= 0.2f;
		break;
	default:
		break;	
	}

	// 如果需要重置摄影机或第一次渲染
	if(bCameraReset || bFirstRender)
    {
        // 设置世界坐标系
        cube.SetWorldPosition(cube.m_curX, cube.m_curY, cube.m_curZ);
        // 设置摄影机位置
        cube.SetCamera();
    }

	// 渲染基本立体面
    cube.Render();

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
