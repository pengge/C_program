// dialogExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialogExample.h"
#include "dialogExampleDlg.h"
#include "DlgTest.h"
#include "DlgNonModal.h"
#include "PageStudent.h"
#include "PageTeacher.h"
#include "DlgTest2.h"

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
// CDialogExampleDlg dialog

CDialogExampleDlg::CDialogExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogExampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogExampleDlg)
	m_bPass = FALSE;
	m_strSex = _T("");
	m_strName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogExampleDlg)
	DDX_Check(pDX, IDC_CHECK_PASS, m_bPass);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
	DDV_MaxChars(pDX, m_strSex, 20);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 50);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogExampleDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogExampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DIALOG_MESSAGE, OnButtonDialogMessage)
	ON_BN_CLICKED(IDC_BUTTON_DIALOG_COLOR, OnButtonDialogColor)
	ON_BN_CLICKED(IDC_BUTTON_DIALOG_FILE, OnButtonDialogFile)
	ON_BN_CLICKED(IDC_BUTTON_DIALOG_FONT, OnButtonDialogFont)
	ON_BN_CLICKED(IDC_BUTTON_DIALOG_FIND, OnButtonDialogFind)
	ON_BN_CLICKED(IDC_BUTTON_DIALOG_PRINT, OnButtonDialogPrint)
	ON_BN_CLICKED(IDC_BUTTON_MODAL, OnButtonModal)
	ON_BN_CLICKED(IDC_BUTTON_NONMODAL, OnButtonNonmodal)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SHEET, OnButtonOpenSheet)
	ON_BN_CLICKED(IDC_BUTTON_TEST2, OnButtonTest2)
	//}}AFX_MSG_MAP
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogExampleDlg message handlers

BOOL CDialogExampleDlg::OnInitDialog()
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

void CDialogExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogExampleDlg::OnPaint() 
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
HCURSOR CDialogExampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CButton* CDialogExampleDlg::GetPassCheckBox()
{
	return (CButton*)GetDlgItem(IDC_CHECK_PASS);
}

void CDialogExampleDlg::OnButtonSetcheck() 
{
	// TODO: Add your control notification handler code here
	GetPassCheckBox()->SetState(TRUE);
}



void CDialogExampleDlg::OnButtonDialogMessage() 
{
	// TODO: Add your control notification handler code here
	MessageBox("Hello World!", "提示", MB_OK);
}

void CDialogExampleDlg::OnButtonDialogColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlgColor;
	if (dlgColor.DoModal() == IDOK)
	{
		COLORREF m_ctrlCustome = dlgColor.GetColor();		
	}
}

void CDialogExampleDlg::OnButtonDialogFile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg( TRUE, "EXE", "*.EXE", OFN_FILEMUSTEXIST, 0, this );
    if ( IDOK != dlg.DoModal() )
        return;
    ((CWnd*)GetDlgItem(IDC_EDIT_NAME))->SetWindowText(dlg.GetPathName());
}

void CDialogExampleDlg::OnButtonDialogFont() 
{
	// TODO: Add your control notification handler code here
	CFontDialog fontDlg; 
	if ( IDOK != fontDlg.DoModal() )
        return;    
}

void CDialogExampleDlg::OnButtonDialogFind() 
{
	// TODO: Add your control notification handler code here
	CFindReplaceDialog* dlg;
	dlg = new CFindReplaceDialog();
	dlg->m_fr.lStructSize   =   sizeof(FINDREPLACE);
	dlg->Create(false, "查找的内容", "替换的内容", FR_DOWN | FR_WHOLEWORD, this);
}

void CDialogExampleDlg::OnButtonDialogPrint() 
{
	// TODO: Add your control notification handler code here
	char   pbuf[100] = "Hello World.";
    HDC    hdcPrn ;
    CPrintDialog *printDlg =new CPrintDialog(FALSE, 
        PD_ALLPAGES | PD_RETURNDC, NULL);
    printDlg->m_pd.nMinPage = printDlg->m_pd.nMaxPage = 1;
    printDlg->m_pd.nFromPage = printDlg->m_pd.nToPage = 1;
    printDlg->DoModal();
    hdcPrn = printDlg->GetPrinterDC();
    if (hdcPrn != NULL)
    {
           
    }
    delete printDlg;
}

void CDialogExampleDlg::OnButtonModal() 
{
	// TODO: Add your control notification handler code here
	CDlgTest dlg;
	if (dlg.DoModal() == IDOK)
	{
		// 用户单击【OK】命令
	}
	else
	{
		// 用户单击【Cancel】命令
	}
}

void CDialogExampleDlg::OnButtonNonmodal() 
{
	// TODO: Add your control notification handler code here
	CDlgNonModal* dlg = new CDlgNonModal();
	dlg->Create(IDD_DIALOG_NONMODAL);
}

void CDialogExampleDlg::OnButtonOpenSheet() 
{
	// TODO: Add your control notification handler code here
	CPropertySheet Sheet;
	Sheet.SetTitle("信息管理");
	CPageStudent page1;
	CPageTeacher page2;
	Sheet.AddPage(&page1);
	Sheet.AddPage(&page2);
	Sheet.DoModal();
}

void CDialogExampleDlg::OnButtonTest2() 
{
	CDlgTest2 dlg;
	dlg.DoModal();
}


HBRUSH CDialogExampleDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  在此更改 DC 的任何特性
/*    if(nCtlColor == CTLCOLOR_DLG)
    {
        CBrush *brush = new CBrush(RGB(0,192,192));
        return (HBRUSH)(brush->m_hObject);
    }   */
    // TODO:  如果默认的不是所需画笔，则返回另一个画笔
    return hbr;
}
