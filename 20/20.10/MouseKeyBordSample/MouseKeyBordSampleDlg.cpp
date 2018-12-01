// MouseKeyBordSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MouseKeyBordSample.h"
#include "MouseKeyBordSampleDlg.h"

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
// CMouseKeyBordSampleDlg dialog

CMouseKeyBordSampleDlg::CMouseKeyBordSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMouseKeyBordSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMouseKeyBordSampleDlg)
	m_DoubleClickTime = 0;
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseKeyBordSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMouseKeyBordSampleDlg)
	DDX_Control(pDX, IDC_BUT_HWND, m_ButHWND);
	DDX_Text(pDX, IDC_EDIT_DOUBLECLICKTIME, m_DoubleClickTime);
	DDV_MinMaxInt(pDX, m_DoubleClickTime, 0, 999999);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMouseKeyBordSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMouseKeyBordSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_SETDOUBLETIME, OnButSetdoubletime)
	ON_BN_CLICKED(IDC_BUT_SWAP, OnButSwap)
	ON_BN_CLICKED(IDC_BUT_RESTORESWAP, OnButRestoreswap)
	ON_BN_CLICKED(IDC_BUT_HWND, OnButHwnd)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_GETBUTTONS, OnButtonGetbuttons)
	ON_BN_CLICKED(IDC_BUT_SENDMOUSE, OnButSendmouse)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON_GETKEYBOARD, OnButtonGetkeyboard)
	ON_BN_CLICKED(IDC_BUT_CONTROLKEY, OnButControlkey)
	ON_BN_CLICKED(IDC_BUT_REGISTHOTKEY, OnButRegisthotkey)	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBordSampleDlg message handlers

BOOL CMouseKeyBordSampleDlg::OnInitDialog()
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

void CMouseKeyBordSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMouseKeyBordSampleDlg::OnPaint() 
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
HCURSOR CMouseKeyBordSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


#define	MAX_LOG_LENGTH	1024
// ��¼��־
void CMouseKeyBordSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.10.1(OK)
void CMouseKeyBordSampleDlg::OnButSwap()	// ����������Ҽ�
{	
	if (SwapMouseButton(TRUE))				// ����������Ҽ�
		WriteLog("������Ҽ��Ѿ�����");		// ���������ʾ��Ϣ
	else
        WriteLog("����������Ҽ��ɹ�");	// �����ʾ��Ϣ
}

void CMouseKeyBordSampleDlg::OnButRestoreswap()		// �ָ�������Ҽ�
{	
	if (SwapMouseButton(FALSE))				// �ָ�������Ҽ�
		WriteLog("�ָ�������Ҽ��ɹ�");		// �����ʾ��Ϣ
	else
        WriteLog("����������Ҽ��ɹ�");	// ���������ʾ��Ϣ
}

// 21.10.2(OK)
void CMouseKeyBordSampleDlg::OnButSetdoubletime()	// �������˫��ʱ����
{
	UpdateData(TRUE);						// ��ȡҪ���õ����˫��ʱ����
	BOOL bResult = SetDoubleClickTime(m_DoubleClickTime);	// ����˫��ʱ����ֵ
	UINT dcTime = GetDoubleClickTime();						// ��ȡ˫��ʱ����ֵ
	WriteLog("�������˫��ʱ����%s����ǰֵΪ%d", bResult ? "�ɹ�": "ʧ��", dcTime);		
}

// 21.10.3(OK)
void CMouseKeyBordSampleDlg::OnButtonGetbuttons()	// ���������
{
	int iButtons = GetSystemMetrics(SM_CMOUSEBUTTONS);	// ����GetSystemMetrics������ȡ������
	if (iButtons > 0)									// �������0�����������
		WriteLog("��ǰϵͳ�й���%d����갴��", iButtons);
	else
        WriteLog("��ǰϵͳ��û�а�װ���");			// ����ϵͳ��û�а�װ���
}

// 21.10.4(OK)
void CMouseKeyBordSampleDlg::OnButHwnd()	// ����������괰��Ķ�ʱ��
{
	SetTimer(100, 1000, NULL);	
}

void CMouseKeyBordSampleDlg::OnTimer(UINT nIDEvent)		// ��ʱ��������
{	
	HWND m_hWnd  = ::GetCapture();						// ������괰��
	WriteLog("��ǰ�������Ĵ����HWND=0x%08X", m_hWnd);// ������
	CDialog::OnTimer(nIDEvent);							// ���û��ദ����
}

// 21.10.5(OK)
void CMouseKeyBordSampleDlg::OnButSendmouse()			// ģ��������
{
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP , 0, 0, NULL, NULL);	// ģ��������
}

// 21.10.6��21.10.9(OK)
BOOL CMouseKeyBordSampleDlg::PreTranslateMessage(MSG* pMsg)		// ��ϢԤ����
{	
	if (pMsg->message == WM_KEYDOWN)	// �ж��Ƿ��ǰ�������
	{
		char szName[MAX_PATH]={0};		// ���尴����������
		UINT uVirtKey = MapVirtualKey(pMsg->wParam, 0)<<16;	// ��ȡ����ֵ	
		if (GetKeyNameText(uVirtKey, (LPTSTR)szName, sizeof(szName)))	// ��ȡ��������
			WriteLog("���¼���=%s����", szName);		// �����������
	}
	if(GetAsyncKeyState(VK_F5))		// �ж��Ƿ���Ҫ���õĿ�ݼ�
	{   
		OnButtonGetbuttons();		// ִ�п�ݼ�Ҫ����ĺ���
		return  TRUE;				// ����
	}	
	return CDialog::PreTranslateMessage(pMsg);
}

// 21.10.7(OK)
void CMouseKeyBordSampleDlg::OnButRegisthotkey()	// �ڶԻ�����ʹ�ü��ټ�
{
	if(RegisterHotKey(this->m_hWnd, VK_F1+1, MOD_CONTROL, VK_F1+1))	// ע����ټ�
		WriteLog("ע����ټ��ɹ�");					// �����ʾ��Ϣ
	else WriteLog("ע����ټ�ʧ��");				// ���������Ϣ	
}


LRESULT CMouseKeyBordSampleDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) // ������Ϣ������
{
	char szName[MAX_PATH]={0};				// �������Ʊ���
	UINT fuModifiers,uVirtKey;				// ���尴������
	switch(message)							// �ж���Ϣ
	{
	case WM_LBUTTONDOWN:
		WriteLog("����������");	
		break;
	case WM_LBUTTONUP:
		WriteLog("̧��������");
		break;
	case WM_KEYDOWN:		
		TCHAR szName[200];
		GetKeyNameText(wParam, szName, sizeof(szName));
		WriteLog("����%s����", szName);
		break;
	case WM_HOTKEY:							// ���յ����ټ�
		uVirtKey = MapVirtualKey((UINT)HIWORD(lParam), 0)<<16;		// ��ȡ���ܰ���
		if (GetKeyNameText(uVirtKey, (LPTSTR)szName, sizeof(szName)))	// ��ȡ��������
			WriteLog("���ټ�=%s", szName);							// �����������
		fuModifiers = (UINT) LOWORD(lParam);						// ȡ��Ϲ��ܼ�		
		switch(fuModifiers)		// �ж���ϼ�
		{
		case MOD_ALT:			// ALT��
			WriteLog("������ALT��ϼ���");	break;
		case MOD_CONTROL:		// CTRL��
			WriteLog("������CTRL��ϼ���");	break;
		case MOD_SHIFT:			// SHIFT��
			WriteLog("������SHIFT��ϼ���");break;
		case MOD_WIN:			// WIN��
			WriteLog("������WIN��ϼ���");	break;
		}		
		break;
	default:
		break;
	}	
	return CDialog::WindowProc(message, wParam, lParam);
}

// 21.10.8(OK)
BOOL CMouseKeyBordSampleDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) // ������������Ϣ
{
	WriteLog("�����������¼�--");		// �����ʾ��Ϣ
	switch(nFlags)						// �ж���û�а�����ϼ��������
	{
	case MK_CONTROL:
		WriteLog("CTRL�������¡�");	break;
	case MK_LBUTTON:
		WriteLog("���������¡�");	break;
	case MK_MBUTTON:
		WriteLog("����м����¡�");	break;
	case MK_RBUTTON:
		WriteLog("����Ҽ����¡�");	break;
	case MK_SHIFT:
		WriteLog("SHIFT�������¡�");break;
	default:
		WriteLog("û�й��ܼ����¡�");break;
	}
	if (zDelta > 0)						// ��������ƶ��ķ���ʹ�С
		WriteLog("������ǰ�ƶ�%d", abs(zDelta));
	else
        WriteLog("��������ƶ�%d", abs(zDelta));
	WriteLog("��굱ǰλ��(�������Ļ���Ͻ�)��X=%d;Y=%d", pt.x, pt.y);	// �����굱ǰλ��
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);		// ���ദ����
}

// 21.10.10(OK)
void CMouseKeyBordSampleDlg::OnButtonGetkeyboard()	// ��ȡ��������
{
	CString type[8]={"��ȡ��������ʧ��", "IBM PC/XT or compatible (83-key) keyboard",
	"Olivetti 'ICO' (102-key) keyboard", "IBM PC/AT (84-key) or similar keyboard",
	"IBM enhanced (101- or 102-key) keyboard", "Nokia 1050 and similar keyboards",
	"Nokia 9140 and similar keyboards", "Japanese keyboard"};	// ���������������
	CString funKeys[8]={"��ȡ���̹��ܼ���Ŀʧ��", "10", "12,��ʱ��18","10", "12",
	"10", "24","����OEM���̶���"};				// ������̹��ܰ�����
	int keyboardType = GetKeyboardType(0);		// ��ȡ��������
	int keyboardSubType = GetKeyboardType(1);	// ��ȡ����������
	int functionsKeys = GetKeyboardType(2);		// ��ȡ���̹��ܰ�����	
	if (keyboardType < 8)	WriteLog("��������=%s", type[keyboardType]);	// �����������
	else WriteLog("��������δ֪");
	WriteLog("����������=%d(���庬�壬��Ҫ���ݼ������͵Ĳ�ͬ�����ж�)", keyboardSubType);	// �������������
	if (functionsKeys < 8)	WriteLog("���̹��ܼ���Ŀ=%s\r\n", type[functionsKeys]);	// ������̹��ܰ�����
	else WriteLog("���̹��ܼ���Ŀδ֪");	
}

// 21.10.11(OK)
void CMouseKeyBordSampleDlg::OnButControlkey()	// ���Ƽ���ָʾ��
{
	int keys[] = {VK_CAPITAL, VK_NUMLOCK,VK_SCROLL};	// ������Ƶ�ָʾ��
	CString keysName[] = {"VK_CAPITAL", "VK_NUMLOCK","VK_SCROLL"};	// ����ָʾ������
	for (int i = 0;i < sizeof(keys)/sizeof(int);i ++)	// ���ο��Ƹ���ָʾ��״̬
	{	
		keybd_event( keys[i], 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );  // �л�ָʾ��״̬
		keybd_event( keys[i], 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);// �л�ָʾ��״̬
	}
	BYTE keyState[MAX_PATH]={0};				// ָʾ��״̬����
	GetKeyboardState((LPBYTE)&keyState);		// ��ȡ����״̬
	for (int i = 0;i < sizeof(keys)/sizeof(int);i ++)		// ���λ�ȡָʾ��״̬
		WriteLog("%s��ǰ%s", keysName[i], keyState[keys[i]] == 1 ? "����" : "����");// ���ָʾ��״̬
}




