// MSCOMMSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MSCOMMSample.h"
#include "MSCOMMSampleDlg.h"

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
// CMSCOMMSampleDlg dialog

CMSCOMMSampleDlg::CMSCOMMSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMSCOMMSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMSCOMMSampleDlg)
	m_editReceive = _T("");
	m_editSend = _T("");
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSCOMMSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMSCOMMSampleDlg)
	DDX_Text(pDX, IDC_EDIT_RECEIVE, m_editReceive);
	DDX_Text(pDX, IDC_EDIT_SEND, m_editSend);
	DDX_Control(pDX, IDC_MSCOMM1, m_Comm);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMSCOMMSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMSCOMMSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSCOMMSampleDlg message handlers

BOOL CMSCOMMSampleDlg::OnInitDialog()
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

void CMSCOMMSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMSCOMMSampleDlg::OnPaint() 
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
HCURSOR CMSCOMMSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CMSCOMMSampleDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMSCOMMSampleDlg)
	ON_EVENT(CMSCOMMSampleDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

//事件处理函数
void CMSCOMMSampleDlg::OnOnCommMscomm1() 
{
    VARIANT vInput; 
    COleSafeArray arrInput; 
    LONG len,k; 
    BYTE rxdata[2048]; //设置BYTE数组
    CString strtemp; 
    switch(m_Comm.GetCommEvent()) 
    { 
    case EV_CTS:		//发送数据 
        WriteLog("发送数据");
        break; 
    case EV_RXCHAR:		//读取数据 
        vInput=m_Comm.GetInput(); //读缓冲区 
        arrInput=vInput; 
        len=arrInput.GetOneDimSize(); //得到有效数据长度 
        // 读取数据 
        for(k=0; k < len; k++)
        { 
            arrInput.GetElement(&k,rxdata+k); //转换为BYTE型数组 
            BYTE bt=*(char*)(rxdata+k); //字符型 
            strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
            m_editReceive+=strtemp; 
        } 
        WriteLog("接收数据");
        break; 
    default:	// 出错 
        m_Comm.SetOutBufferCount(0); 
        break; 
    } 
    UpdateData(FALSE); //更新图象内容 
    return ; 
}

void CMSCOMMSampleDlg::OnButtonSend() 
{
    UpdateData(TRUE);
    unsigned char  uiSum=0; 
    int iLen = m_editSend.GetLength();
    CByteArray  array; 

    for(int i=0; i<iLen-1; i++) 
        uiSum+=m_editSend[i];  //计算校验和 
    //TxData[uiCount-1]=uiSum; //存储校验和 
    array.RemoveAll();  //清空数组 
    array.SetSize(iLen+1);  //设置数组大小为帧长度 
    for(int i=0; i<iLen; i++)  //把待发送数据存入数组 
        array.SetAt(i,m_editSend[i]); 
    array.Add(uiSum);

    if (!m_Comm.GetPortOpen())
        m_Comm.SetPortOpen(TRUE); 

    m_Comm.SetOutput(COleVariant(array));    
}

// 打开串口
void CMSCOMMSampleDlg::OnButtonOpen() 
{
    if(m_Comm.GetPortOpen()) //如果串口是打开的，则关闭串口 
        m_Comm.SetPortOpen(FALSE); 

    m_Comm.SetCommPort(1); //选择COM1 
    m_Comm.SetInBufferSize(1024); //接收缓冲区 
    m_Comm.SetOutBufferSize(1024);//发送缓冲区 
    m_Comm.SetInputLen(0);//设置当前接收区数据长度为0,表示全部读取 
    m_Comm.SetInputMode(0);//以文本方式读写数据 
    m_Comm.SetRThreshold(1);//接收缓冲区有1个及1个以上字符时，触发OnComm事件 
    m_Comm.SetSettings("9600,n,8,1");//波特率9600无检验位，8个数据位，1个停止位 

    if(!m_Comm.GetPortOpen())//如果串口没有打开则打开 
        m_Comm.SetPortOpen(TRUE);//打开串口 
    else m_Comm.SetOutBufferCount(0); 
    WriteLog("打开串口成功");
}

void CMSCOMMSampleDlg::WriteLog(CString log)
{
	m_Log += log;
	UpdateData(FALSE);
}
