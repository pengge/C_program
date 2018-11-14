// RadioAndCheckBoxSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RadioAndCheckBoxSample.h"
#include "RadioAndCheckBoxSampleDlg.h"

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
// CRadioAndCheckBoxSampleDlg dialog

CRadioAndCheckBoxSampleDlg::CRadioAndCheckBoxSampleDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CRadioAndCheckBoxSampleDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CRadioAndCheckBoxSampleDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRadioAndCheckBoxSampleDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CRadioAndCheckBoxSampleDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRadioAndCheckBoxSampleDlg, CDialog)
    //{{AFX_MSG_MAP(CRadioAndCheckBoxSampleDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_GETSTATE, OnButtonGetstate)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRadioAndCheckBoxSampleDlg message handlers

BOOL CRadioAndCheckBoxSampleDlg::OnInitDialog()
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

void CRadioAndCheckBoxSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRadioAndCheckBoxSampleDlg::OnPaint() 
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
HCURSOR CRadioAndCheckBoxSampleDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CRadioAndCheckBoxSampleDlg::OnButtonGetstate() 
{
    // TODO: Add your control notification handler code here
    UINT iColor[] = {IDC_RADIO_COLOR_RED, IDC_RADIO_COLOR_GREEN,
        IDC_RADIO_COLOR_BLUE};
    CString sColor[] = {"红色", "绿色", "蓝色"};
    CString sResultColor;

    CButton *pBtn=NULL;
    for(int i=0; i<3; i++)
    {
        pBtn = (CButton*)GetDlgItem(iColor[i]);
        if(!pBtn)
            continue;

        if(pBtn->GetCheck() == 1)
            sResultColor = "颜色选择：" + sColor[i];		
    }

    UINT iSex[] = {IDC_RADIO_SEX_MALE, IDC_RADIO_SEX_FEMALE};
    CString sSex[] = {"男", "女"};
    CString sResultSex;

    for(int i=0; i<2; i++)
    {
        pBtn = (CButton*)GetDlgItem(iSex[i]);
        if(!pBtn)
            continue;

        if(pBtn->GetCheck() == 1)
            sResultSex = "\n性别选择：" + sSex[i];		
    }

    UINT iLike[] = {IDC_CHECK_LIKE_BOOK, IDC_CHECK_LIKE_MUSIC,
        IDC_CHECK_LIKE_SPORT,IDC_CHECK_LIKE_DANCE};
    CString sLike[] = {"读书", "听音乐", "运动", "跳舞"};
    CString sResultLike = "\n喜欢：";

    for(int i=0; i<4; i++)
    {
        pBtn = (CButton*)GetDlgItem(iLike[i]);
        if(!pBtn)
            continue;

        if(pBtn->GetCheck() == 1)
            sResultLike =  sResultLike + sLike[i] + "、";		
    }

    MessageBox(sResultColor +  sResultSex + sResultLike, "选择结果");
}
