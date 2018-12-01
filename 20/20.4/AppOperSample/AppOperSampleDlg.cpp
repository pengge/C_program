// AppOperSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AppOperSample.h"
#include "AppOperSampleDlg.h"
#include "imagehlp.h"
#include "tlhelp32.h"
#include "winbase.h"
#include <windows.h>
#include <stdio.h>
//#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "strmiids.lib")

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
// CAppOperSampleDlg dialog

CAppOperSampleDlg::CAppOperSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAppOperSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAppOperSampleDlg)
	m_Log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAppOperSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAppOperSampleDlg)
	DDX_Control(pDX, IDC_BUTTON_ICON, m_Icon);
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_Log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAppOperSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CAppOperSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_IF_RUNNING, OnButtonIfRunning)
	ON_BN_CLICKED(IDC_BUTTON_RUN_COPYDOS, OnButtonRunCopydos)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_TITLE, OnButtonUpdateTitle)
	ON_BN_CLICKED(IDC_BUTTON_IS_RESPONSE, OnButtonIsResponse)
	ON_BN_CLICKED(IDC_BUTTON_REPLACEICON, OnButtonReplaceicon)
	ON_BN_CLICKED(IDC_BUTTON_EXEC_COMMAND, OnButtonExecCommand)
	ON_BN_CLICKED(IDC_BUTTON_SAVEICON, OnButtonSaveicon)
	ON_BN_CLICKED(IDC_BUTTON_LISTTASK, OnButtonListtask)
	ON_BN_CLICKED(IDC_BUTTON_PEPARSER, OnButtonPeparser)
	ON_BN_CLICKED(IDC_BUTTON_EXEUSEDLLS, OnButtonExeusedlls)
	ON_BN_CLICKED(IDC_BUTTON_WAITPROCESS, OnButtonWaitprocess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppOperSampleDlg message handlers

BOOL CAppOperSampleDlg::OnInitDialog()
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

void CAppOperSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAppOperSampleDlg::OnPaint() 
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
HCURSOR CAppOperSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// ��¼��־
void CAppOperSampleDlg::WriteLog(LPCTSTR format,...)	// ��¼��־
{
	char log[1024]={0};
	va_list arg_ptr;			// ��ȡ�����б�
	va_start(arg_ptr, format);	// �������б�ָ���һ������	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}


// 21.4.2(OK)
typedef BOOL  (WINAPI *PROCISHUNGAPPWINDOW)   (HWND); 
void CAppOperSampleDlg::OnButtonIsResponse()		// ȷ��Ӧ�ó���û����Ӧ
{    
	PROCISHUNGAPPWINDOW  IsHungAppWindow;  	
	HMODULE hUser32=GetModuleHandle("user32");   
	IsHungAppWindow = (PROCISHUNGAPPWINDOW)GetProcAddress(hUser32,"IsHungAppWindow"); 
	CString szAppName = "Notepad";
	HWND hWnd = ::FindWindow(szAppName, NULL);
	if (hWnd)
	{
		if (IsHungAppWindow(hWnd))
            WriteLog("%s����û����Ӧ", szAppName);
		else
            WriteLog("%s��������Ӧ", szAppName);
	}
	else
        WriteLog("%s����û������", szAppName);	
}

// 21.4.3(OK)
void CAppOperSampleDlg::OnButtonListtask()	// ��������������е������б�
{
	::EnumWindows((WNDENUMPROC)enumProcFunc,(LPARAM)this);
}

BOOL CALLBACK CAppOperSampleDlg::enumProcFunc(HWND hWnd, LPARAM lParam)
{
	CAppOperSampleDlg * pDlg = (CAppOperSampleDlg*)lParam;
	TCHAR szTitle[MAX_PATH] = {0};

	if (hWnd == NULL)  return FALSE;
	if (hWnd == pDlg->m_hWnd) return TRUE;
	if (::IsWindow(hWnd) && ::IsWindowVisible(hWnd) && 
		((GetWindowLong(hWnd, GWL_EXSTYLE)&WS_EX_TOOLWINDOW)!=WS_EX_TOOLWINDOW) &&
		(GetWindowLong(hWnd, GWL_HWNDPARENT)==0))
	{
		memset(szTitle, 0x00, sizeof(szTitle));
		::GetWindowText(hWnd, szTitle, sizeof(szTitle));
		if (strlen(szTitle) == 0)    return TRUE;
		DWORD dwProcessID = 0;
		::GetWindowThreadProcessId(hWnd,&dwProcessID);		
		pDlg->WriteLog("%s \t\t����ID=%X", szTitle, dwProcessID);	
	}    
	return TRUE;
}

// 21.4.4(OK)
void CAppOperSampleDlg::OnButtonIfRunning()		// �ж�ĳ�������Ƿ�����
{
	BOOL bRunning = FALSE;						// ���������ʶ�����Ƿ�����������
	CString szAppName="C:\\Windows\\Notepad.exe";
	HANDLE   hPS;											// ���̿��վ��
	PROCESSENTRY32   pe;									// ������Ŀ����
	hPS = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	// �������̿���  
    if (hPS==INVALID_HANDLE_VALUE)   return;				// ����ʧ�ܣ�����
	memset(&pe,0,sizeof(pe));								// ��ʼ��PROCESSENTRY32�ṹ
    pe.dwSize=sizeof(PROCESSENTRY32);						// ΪdwSize��ֵ
	if (Process32First(hPS, &pe))							// ������һ������
	{
		do   
		{
			if (szAppName.CompareNoCase(pe.szExeFile))		// �Ƚ��Ƿ���Ҫ�жϵ�Ӧ�ó���
			{
				bRunning = TRUE;							// ����ǣ���ֵ����			
				break;										// �˳�ѭ��
			} 
		}   
		while(Process32Next(hPS,&pe));						// ������һ������ 
	} 
    CloseHandle(hPS);										// �رտ��վ��               

	if (bRunning)
        WriteLog("����%s��������......", szAppName);// ����ɹ���Ϣ
	else
        WriteLog("����%sû�����С�", szAppName);	// ���ʧ����Ϣ
}

// 21.4.5(OK)
void CAppOperSampleDlg::OnButtonRunCopydos()		// �ڳ�����ִ��DOS����
{
	system("copy C:\\1.txt D:\\");	
}

// 21.4.7(OK)
void CAppOperSampleDlg::OnButtonUpdateTitle()		// �޸����������жԻ���ı���
{
	HWND hWnd = ::FindWindow("Notepad", NULL);
	if (hWnd)
        ::SetWindowText(hWnd, "���Ǵ�AppOperSampleDlg�������޸ĺ�ı���");	
}

// 21.4.9(OK)
void CAppOperSampleDlg::OnButtonPeparser()	// PE������ʽ����
{	
	char szFile[MAX_PATH]={0};				// Ҫ������PE�ļ���
	strcpy(szFile, "user32.dll");			// ����user32.dll�ļ�

	LOADED_IMAGE li;						// ��Ϣ�ṹ����
	if (!MapAndLoad(szFile, 0, &li, FALSE, TRUE))	// װ��PE�ļ�
	{
		WriteLog("PE������ʽ����--MapAndLoad����");	// װ��ʧ�ܣ���ʾ������Ϣ
		return;										// ������
	}	

	// ����װ�ص�PEӳ��Ļ�����Ϣ
	WriteLog("ģ������=%s\r\n�ļ����=%d\r\nӳ���ַ=%08X\r\n�ַ���=%08X\r\n������С=%d\r\nӳ��%s���ں�ģʽ�µĿ�ִ��ӳ��\r\nӳ��%s��16λ��ִ��ӳ��\r\nLinks=%08X-%08X\r\nӳ���С=%u\r\n", 
		li.ModuleName, li.hFile,li.MappedAddress, li.Characteristics, li.SizeOfImage,
		li.fSystemImage ? "" : "��", li.fDOSImage ? "" : "��", li.Links.Blink, li.Links.Flink, li.SizeOfImage);
	
	PIMAGE_NT_HEADERS ntHeader = li.FileHeader;		// ��ȡNTͷ�ṹ����
	WriteLog("NTͷ��ϢFileHeader=%08X\r\n", ntHeader->FileHeader);	// ���NTͷ��Ϣ
	
    WriteLog("����%d��COFF����ͷ", li.NumberOfSections);	// ���COFF������    
    for (int i = 0;i < (int)li.NumberOfSections;i++)		// ѭ�����ÿ����Ϣ    
	{
		PIMAGE_SECTION_HEADER psHeader = (PIMAGE_SECTION_HEADER)&li.Sections[i];// ��ȡ��i����
		WriteLog("��%d��COFF����ͷ��Ϣ	����=%s", i, psHeader->Name);	// ���������
	}
    
	if (UnMapAndLoad(&li))	WriteLog("�ɹ�ж��%s�����ļ�", szFile);	// ж�ص����ļ�		
	else WriteLog("ж��%s�����ļ�ʧ��", szFile);			// ���������Ϣ
}

// 21.4.10(OK)
void CAppOperSampleDlg::OnButtonReplaceicon()	// �޸�Ӧ�ó���ͼ��
{
	HICON hIconNew=AfxGetApp()->LoadIcon(IDI_ICON_TEST);
	if(hIconNew != NULL)
	{
		HWND hWnd = ::FindWindow("Notepad", NULL);
		if (hWnd != NULL)
            ::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconNew);
	}
}

// 21.4.11(OK)
void CAppOperSampleDlg::OnButtonExeusedlls()	// �о�Ӧ�ó���ʹ�õ�dll�ļ�
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);// ��������ʹ�õ�ģ�����
	if (hModule == NULL)									// �������ʧ�ܣ���
	{
		WriteLog( "���ú���CreateToolhelp32Snapshotʧ��" );	// ��ʾ������Ϣ
		return;												// ������
	}

	WriteLog( "��ǰ���̵��õ�dll�ļ���:" );					// ��ʾ��ʾ��Ϣ
	MODULEENTRY32 me;										// ����ģ����Ϣ����							
	BOOL bResult = Module32First( hModule,  &me );			// ��ȡ�����еĵ�һ��ģ��
	while (bResult)											// ѭ������ģ��
	{
		WriteLog( me.szExePath );								// ���ģ���ļ���
		bResult = Module32Next( hModule,  &me );			// ��ȡ��һ��ģ��
	}
	CloseHandle( hModule );									// �ر�ģ����վ��
}

// 21.4.12(OK)
void CAppOperSampleDlg::OnButtonExecCommand()			// ���þ��������в�����Ӧ�ó���
{
	WinExec("AddSample.exe 4 6", SW_SHOWNORMAL);		// ִ���Զ������AddSample
}

// 21.4.13(OK)
void CAppOperSampleDlg::OnButtonWaitprocess()			// �ڳ����е���һ���ӽ���ֱ�������
{
	WriteLog("���ü���������......");					// ��ʾ��ʾ��Ϣ
	STARTUPINFO si={0};									// ����������Ϣ����
	PROCESS_INFORMATION pi;								// ���������Ϣ����
	si.cb = sizeof(si);									// ��ֵ���̽ṹ��С	
	if(CreateProcess(NULL,"calc.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)) // ��������
	{		
		WaitForSingleObject(pi.hProcess,INFINITE);		// �ȴ����򷵻�
		WriteLog("������������������.");				// ��ʾ�����Ϣ
	}	
}

void CAppOperSampleDlg::OnButtonSaveicon() 
{
	
	SHFILEINFO  fi;
	
	LPVOID lpGMem= GlobalLock(fi.hIcon);
	if(!::SHGetFileInfo("c:\\Windows\\System32\\calc.exe",0, &fi,sizeof(SHFILEINFO),SHGFI_ICON | SHGFI_SMALLICON))
	{
		WriteLog("��ȡӦ�ó���ͼ��ʧ�ܡ�");
		return;
	}

	SendDlgItemMessage (IDC_BUTTON_ICON, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)(HICON)fi.hIcon);
	
	PICONINFO pi;
	BOOL bResult = GetIconInfo(fi.hIcon, pi);

	CDC dc;
	

	DWORD  dwSize= GlobalSize(fi.hIcon);
	UINT   uiSize;
	OFSTRUCT  of;
	
    int fh = OpenFile ("SavedAppIcon.ico", &of, OF_WRITE | OF_CREATE);
    if (fh != -1)  
    {
		uiSize = _lwrite(fh, (LPSTR)lpGMem, (UINT)dwSize);
		_lclose(fh);
		WriteLog("����Ӧ�ó���ͼ�굽SavedAppIcon.ico�ļ��ɹ����ļ���С=%d", dwSize);
	}
	
	if (!SUCCEEDED(CoInitialize(NULL))) 
	{
		WriteLog("��ʼ��OLE���ʧ�ܡ�");
		return;
	}
	//IUnknown*   pUnk;
	/*IFilterGraph *pfg=NULL;
	if (!SUCCEEDED(CoCreateInstance(CLSID_FilterGraph, NULL, 
		CLSCTX_INPROC, IID_IGraphBuilder,(void**)&pfg)))
	{*/
		/*IPicture* pPicture;
		if (SUCCEEDED(pUnk->QueryInterface(IID_IPicture, (void**)&pPicture)))
		{
			IStorage* pStorage=NULL;
			if (SUCCEEDED(::StgCreateDocfile(L"GetAppIcon", STGM_SHARE_EXCLUSIVE|STGM_CREATE|STGM_READWRITE,     
                              0,   &pStorage)))
			{
				IStream* pStream = NULL;              
                if(SUCCEEDED(pStorage->CreateStream(L"PICTURE",     
                   STGM_SHARE_EXCLUSIVE|STGM_CREATE|STGM_READWRITE, 0,0,&pStream)))
                {   
                    pPicture->SaveAsFile(pStream, TRUE, NULL);   
                    pStream->Release();  
					WriteLog("����Ӧ�ó���ͼ��ɹ�");
                }   
                pStorage->Release();   
			}
			pPicture->Release();
		}*/
	//}
}









void CAppOperSampleDlg::LoadPlugIns()
{
	CString strPlugPath;
	char szFileName[MAX_PATH];
	GetModuleFileName(NULL, szFileName, sizeof(szFileName)); 
	strPlugPath = CString(szFileName); 
	strPlugPath = strPlugPath.Left(strPlugPath.GetLength() - CString(AfxGetAppName()).GetLength() - 4) + CString("PLUGINS");
	CString findPath = strPlugPath + "\\*.dll";
	CFileFind fileFinder;
	BOOL bContinue  = fileFinder.FindFile(findPath, NULL);
	while (bContinue)
	{
		CreatePlugIns(strPlugPath + "\\" + fileFinder.GetFileName()); 
		bContinue = fileFinder.FindNextFile();
	}
	fileFinder.Close();
}

void CAppOperSampleDlg::CreatePlugIns(CString szPath)
{
	/*HMODULE hMoudle = LoadLibrary(szPath);
	PFN_CREATE_FLUG_OBJECT pFunc = (PFN_CREATE_FLUG_OBJECT)GetProcAddress(hMoudle, 
		_T("CreatePlusObject"));
	if (pFunc((void **)&stPs.pObj))
		m_arrPlugObj.Add(stPs);*/
}
