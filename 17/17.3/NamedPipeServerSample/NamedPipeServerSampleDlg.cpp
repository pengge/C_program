// NamedPipeServerSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NamedPipeServerSample.h"
#include "NamedPipeServerSampleDlg.h"

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
// CNamedPipeServerSampleDlg dialog

CNamedPipeServerSampleDlg::CNamedPipeServerSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNamedPipeServerSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNamedPipeServerSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNamedPipeServerSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNamedPipeServerSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNamedPipeServerSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CNamedPipeServerSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamedPipeServerSampleDlg message handlers

BOOL CNamedPipeServerSampleDlg::OnInitDialog()
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

void CNamedPipeServerSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNamedPipeServerSampleDlg::OnPaint() 
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
HCURSOR CNamedPipeServerSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNamedPipeServerSampleDlg::OnButtonListen() 
{
    m_hPipe = CreateNamedPipe("\\\\.\\Pipe\\NamedPipeSample", 
        PIPE_ACCESS_DUPLEX,  PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
        1, 0, 0, 1000, NULL); // ���������ܵ�
    if (m_hPipe == INVALID_HANDLE_VALUE)	// �ж������ܵ��Ƿ�ɹ�
    {
        m_Log = "���������ܵ�ʧ��!\r\n";	// ��¼��־��Ϣ
        UpdateData(FALSE);				// ��ʾ��־
        return;
    }
    else
    {
        m_Log = "���������ܵ��ɹ�!\r\n";	// ��¼��־��Ϣ
        UpdateData(FALSE);				// ��ʾ��־
        AfxBeginThread(ListenProc, this); // ���������߳�
    }	
}

UINT ListenProc(LPVOID lpVoid)			// �����̺߳���
{
    char buffer[1024];					// ���ݻ��桡
    DWORD dwReadBytes;					// �����ȡ���ݵ��ֽڸ����ı���
    CNamedPipeServerSampleDlg* pDlg = (CNamedPipeServerSampleDlg*)lpVoid; // ��ȡ�Ի�������
    if (ConnectNamedPipe(pDlg->m_hPipe, NULL) == FALSE)
    {// �ȴ��ͻ�������
        CloseHandle(pDlg->m_hPipe);		// �رչܵ����
        pDlg->m_Log += "�������ܵ��ͻ��˽�������ʧ��!\r\n"; // ��¼��־��Ϣ
        pDlg->m_editLog.SetWindowText(pDlg->m_Log);				// ��ʾ��־
        return 0;
    }
    else
    {
        pDlg->m_Log += "��ͻ��˽�������!\r\n";	// ��¼��־��Ϣ
        pDlg->m_editLog.SetWindowText(pDlg->m_Log);				// ��ʾ��־
    }
    if (ReadFile(pDlg->m_hPipe, buffer, sizeof(buffer), &dwReadBytes, NULL) == FALSE)
    {// �ӹܵ���ȡ����
        CloseHandle(pDlg->m_hPipe);				// �رչܵ����
        pDlg->m_Log +=  "�ӹܵ���ȡ����ʧ��!\r\n";	// ��¼��־��Ϣ		
    } 
    else 
    {
        buffer[dwReadBytes] = '\0';				// ��ʾ���յ�����Ϣ
        pDlg->m_Log += "���յ��ͻ��������ܵ����͵�����=\r\n";
        pDlg->m_Log += CString(buffer);			// ��¼��־��Ϣ		
    }

    if (DisconnectNamedPipe(pDlg->m_hPipe) == FALSE)	// ��ֹ����
    {
        pDlg->m_Log += "��ֹ����ʧ��!\r\n";		// ��¼��־��Ϣ		
    }
    else
    {
        CloseHandle(pDlg->m_hPipe);					// �رչܵ����
        pDlg->m_Log += "�ɹ���ֹ����!\r\n";			// ��¼��־��Ϣ	
    } 

    pDlg->m_editLog.SetWindowText(pDlg->m_Log);				// ��ʾ��־
    return 1;
}
