// SysToolSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SysToolSample.h"
#include "SysToolSampleDlg.h"
#include <shlguid.h> 
#include <shlobj.h>
#include <mmsystem.h>
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>


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
// CSysToolSampleDlg dialog

CSysToolSampleDlg::CSysToolSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSysToolSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysToolSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSysToolSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysToolSampleDlg)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSysToolSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSysToolSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATELINK, OnButtonCreatelink)
	ON_BN_CLICKED(IDC_BUTTON_CLEARBIN, OnButtonClearbin)
	ON_BN_CLICKED(IDC_BUTTON_GETMILLSECOND, OnButtonGetmillsecond)
	ON_BN_CLICKED(IDC_BUTTON_REGISTCOM, OnButtonRegistcom)
	ON_BN_CLICKED(IDC_BUTTON_UNREGISTCOM, OnButtonUnregistcom)
	ON_BN_CLICKED(IDC_BUTTON_SHOWPRODIG, OnButtonShowprodig)
	ON_BN_CLICKED(IDC_BUTTON_GETPROCLIST, OnButtonGetproclist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysToolSampleDlg message handlers

BOOL CSysToolSampleDlg::OnInitDialog()
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

void CSysToolSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSysToolSampleDlg::OnPaint() 
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
HCURSOR CSysToolSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define MAX_LOG_LENGTH	1024
// ��¼��־
void CSysToolSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[MAX_LOG_LENGTH]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}

// 21.5.1(OK)
void CSysToolSampleDlg::OnButtonCreatelink()	// Ϊ������ӿ�ݷ�ʽ
{
	if (!SUCCEEDED(CoInitialize(NULL)))			// ��ʼ��COM���
	{
		WriteLog("��ʼ��Shellʧ��");			// ��ʼ��ʧ����ʾ��Ϣ
		return;									// ����
	}
	IShellLink *pisl;							// �����ݷ�ʽ�ӿڱ���
	if (SUCCEEDED(CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkA, (void**)&pisl))) 
	{	// ������ݷ�ʽʵ��
		IPersistFile* pIPF;						// �����ļ��ӿڱ���
		CString szPath;							// �����ļ�������
		GetModuleFileName(GetModuleHandle(NULL), szPath.GetBuffer(MAX_PATH), MAX_PATH); // ��ȡ����·��
		pisl->SetPath(szPath);					// �����ļ��ӿڵ�·��Ϊ��ǰ����·��
		szPath.ReleaseBuffer();					// �ͷ�·������
		if (SUCCEEDED(pisl->QueryInterface(IID_IPersistFile, (void**)&pIPF))) 
		{	// �����ļ�ʵ��		
			CString szLinkPath;					// ���崴���Ŀ�ݷ�ʽ��·��			
			SHGetSpecialFolderPath(0, szLinkPath.GetBuffer(MAX_PATH), CSIDL_DESKTOPDIRECTORY, 0);// ��ȡ�����Ӧ��·��
			szLinkPath.ReleaseBuffer();			// �ͷſ�ݷ�ʽ·������
			szLinkPath += szPath.Mid(szPath.ReverseFind('\\'));	// ���ÿ�ݷ�ʽ���ļ���
			szLinkPath += ".lnk";								// ���ÿ�ݷ�ʽ����չ��
			WCHAR wpath[MAX_PATH] = { 0 };						// ����Unicode�ַ���
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szLinkPath, -1, wpath, MAX_PATH);	// ����ݷ�ʽ�������ļ���ת��ΪUnicode
			pIPF->Save(wpath, FALSE);			// ���ÿ�ݷ�ʽ��Ӧ���ļ���
			pIPF->Release();					// �ͷ��ļ��ӿ�
			WriteLog("������ݷ�ʽ�ɹ�����ݷ�ʽ·��=%s", szLinkPath);	// ��ʾ�����Ŀ�ݷ�ʽ��Ϣ
		}
		else
            WriteLog("�����ļ��ӿ�IID_IPersistFileʧ��");		// ��ʾ������Ϣ			
		pisl->Release();						// �ͷ��ļ��ӿ�
	} 
	else WriteLog("����CLSID_ShellLinkʵ��ʧ��");				// ��ʾ������Ϣ	
	CoUninitialize();							// �ͷ�COM�����������
}

// 21.5.2(OK)
void CSysToolSampleDlg::OnButtonGetproclist()	// ��ʾϵͳ�������еĳ���
{
	HANDLE hPS=NULL;				// ������̿��վ��
    PROCESSENTRY32 pe32={0};		// ������̽ṹ����
    hPS = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);				// �������̿���
    if (hPS == (HANDLE)-1) 
	{
		WriteLog("����CreateToolhelp32Snapshot�����������̿���ʧ��");	// ��ʾ������Ϣ
		return;						// ����
	}
    pe32.dwSize = sizeof(PROCESSENTRY32);		// Ϊ���̽ṹ�Ĵ�С������ֵ
    if (Process32First(hPS, &pe32))				// ���������еĵ�һ������
    {
        do 
        {									// ��ʾ�������ý�����Ϣ
			WriteLog("\n���ȼ�=%d\t����ID=%d\t�߳���Ŀ=%d\tģ������=%s",pe32.pcPriClassBase, pe32.th32ProcessID, pe32.cntThreads, pe32.szExeFile);     
        } 
        while (Process32Next(hPS, &pe32));		// ���������е���һ������
    } 
    else
        WriteLog("����Process32First����ö�����г���ʧ��");	// ��ʾ������Ϣ
    CloseHandle (hPS);				// �رս��̿��վ��
}

// 21.5.3(OK)
void CSysToolSampleDlg::OnButtonGetmillsecond()		// ��λ�ú��뼶ʱ��
{	
	DWORD t1 = timeGetTime();						// ��ȡ��ϵͳ���������ھ����ĺ�����
	Sleep(10);										// ��������10����
	DWORD t2 = timeGetTime();						// ��ȡ��ϵͳ���������ھ����ĺ�����
	WriteLog("��ʼʱ��=%u", t1);					// �����ʼʱ��
	WriteLog("����ʱ��=%u", t2);					// �������ʱ��
	WriteLog("��ʱ��10���������ʱ��=%u", (t2- t1));// ���10���뾭����ʱ����
}

// 21.5.4(OK)
void CSysToolSampleDlg::OnButtonRegistcom()			// ע�����
{
	CString szPath= "COMSample.dll";				// �������·������
	HINSTANCE hLib=LoadLibrary(szPath);				// װ�����
	if (hLib == NULL)								// ���װ��ʧ�ܣ�
	{
		WriteLog("װ��%s����ļ�ʧ��!", szPath);	// ���������Ϣ
		return;										// ������
	} 	
	FARPROC lpEntryPoint = GetProcAddress(hLib,_T("DllRegisterServer")); // ��ȡDllRegisterServer����ָ��
	if (lpEntryPoint != NULL)						// �����ں�����ΪNULL����
	{	// ���ú���ע�����
		if(FAILED((*lpEntryPoint)()))	WriteLog("�������%s��DllRegisterServer����ʧ��!", szPath);// ���������Ϣ
		else WriteLog("ע��%s����ɹ�!", szPath);	// ����ɹ���Ϣ
	}
	else WriteLog("û���ҵ����%s����ں���DllRegisterServer,�޷�ע��!", szPath);	// ���������Ϣ
	FreeLibrary(hLib);								// �ͷŶ����������
}

void CSysToolSampleDlg::OnButtonUnregistcom()		// ж�����
{
	CString szPath= "COMSample.dll";				// �������·������
	HINSTANCE hLib=LoadLibrary(szPath);				// װ�����
	if (hLib == NULL)								// ���װ��ʧ�ܣ�
	{
		WriteLog("װ��%s����ļ�ʧ��!", szPath);	// ���������Ϣ
		return;										// ������
	}	
	FARPROC lpEntryPoint = GetProcAddress(hLib,_T("DllUnregisterServer"));	// ��ȡDllUnregisterServer����ָ��
	if (lpEntryPoint != NULL)						// �����ں�����ΪNULL����
	{	// ���ú���ж�����
		if(FAILED((*lpEntryPoint)()))	WriteLog("�������%s��DllUnregisterServerʧ��!", szPath);	// ���������Ϣ
		else WriteLog("ж��%s����ɹ�!", szPath);	// ����ɹ���Ϣ
	}
	else WriteLog("û���ҵ����%s����ں���DllUnregisterServer,�޷�ж��!", szPath);					// ���������Ϣ
	FreeLibrary(hLib);								// �ͷŶ����������
}

// 21.5.5(OK)
void CSysToolSampleDlg::OnButtonClearbin()			// ��ջ���վ
{
	if( SHEmptyRecycleBin(this->m_hWnd, NULL, NULL) == S_OK)	// ��ջ���վ
		WriteLog("��ջ���վ���");					// ����ɹ���Ϣ
	else WriteLog("��ջ���վʧ��");				// ���������Ϣ
}

// 21.5.6(OK)
void CSysToolSampleDlg::OnButtonShowprodig()		// �ڳ�������ʾ�ļ����ԶԻ���
{	
	CString szPath;									// ����·��
	GetCurrentDirectory(MAX_PATH, szPath.GetBuffer(MAX_PATH));	// ��ȡ��ǰ����·��
	szPath.ReleaseBuffer();							// �ͷ�·������
	SHELLEXECUTEINFO   seci;						// �����ִ����Ϣ
	ZeroMemory(&seci,sizeof(seci));					// ��ʼ����������Ϣ����
	seci.cbSize = sizeof(SHELLEXECUTEINFO);			// ��ֵ��ִ�б����Ĵ�С
	seci.hwnd = this->m_hWnd;						// ��ֵ������
	seci.lpParameters = NULL;						// ��ֵ����ΪNULL
	seci.lpDirectory = szPath;						// ��ֵ�ļ���
	seci.nShow = 0;									// ����ʾ�ļ�	
	seci.hInstApp = 0;								// ��ֵӦ��ʵ��
	szPath += "\\ReadMe.txt";						// �ļ���
	seci.lpFile = szPath;							// ��ֵ�ļ���	
	seci.lpVerb = "properties";						// ��ֵ���ð汾Ϊ����
	seci.fMask = SEE_MASK_NOCLOSEPROCESS|SEE_MASK_INVOKEIDLIST|SEE_MASK_FLAG_NO_UI;  // ����ѡ�� 
	ShellExecuteEx(&seci);							// �����ļ����ԶԻ���
}

