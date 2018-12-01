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


// 记录日志
void CAppOperSampleDlg::WriteLog(LPCTSTR format,...)	// 记录日志
{
	char log[1024]={0};
	va_list arg_ptr;			// 获取参数列表
	va_start(arg_ptr, format);	// 将参数列表指向第一个参数	
	_vsnprintf(log, sizeof(log)-1, format, arg_ptr);
	m_Log += log;
	m_Log += "\r\n";
	UpdateData(FALSE);	
}


// 21.4.2(OK)
typedef BOOL  (WINAPI *PROCISHUNGAPPWINDOW)   (HWND); 
void CAppOperSampleDlg::OnButtonIsResponse()		// 确定应用程序没有响应
{    
	PROCISHUNGAPPWINDOW  IsHungAppWindow;  	
	HMODULE hUser32=GetModuleHandle("user32");   
	IsHungAppWindow = (PROCISHUNGAPPWINDOW)GetProcAddress(hUser32,"IsHungAppWindow"); 
	CString szAppName = "Notepad";
	HWND hWnd = ::FindWindow(szAppName, NULL);
	if (hWnd)
	{
		if (IsHungAppWindow(hWnd))
            WriteLog("%s程序没有响应", szAppName);
		else
            WriteLog("%s程序有响应", szAppName);
	}
	else
        WriteLog("%s程序没有运行", szAppName);	
}

// 21.4.3(OK)
void CAppOperSampleDlg::OnButtonListtask()	// 检索任务管理器中的任务列表
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
		pDlg->WriteLog("%s \t\t进程ID=%X", szTitle, dwProcessID);	
	}    
	return TRUE;
}

// 21.4.4(OK)
void CAppOperSampleDlg::OnButtonIfRunning()		// 判断某个程序是否运行
{
	BOOL bRunning = FALSE;						// 定义变量标识程序是否正在运行中
	CString szAppName="C:\\Windows\\Notepad.exe";
	HANDLE   hPS;											// 进程快照句柄
	PROCESSENTRY32   pe;									// 进程条目变量
	hPS = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	// 创建进程快照  
    if (hPS==INVALID_HANDLE_VALUE)   return;				// 创建失败，返回
	memset(&pe,0,sizeof(pe));								// 初始化PROCESSENTRY32结构
    pe.dwSize=sizeof(PROCESSENTRY32);						// 为dwSize赋值
	if (Process32First(hPS, &pe))							// 检索第一个进程
	{
		do   
		{
			if (szAppName.CompareNoCase(pe.szExeFile))		// 比较是否是要判断的应用程序
			{
				bRunning = TRUE;							// 如果是，赋值变量			
				break;										// 退出循环
			} 
		}   
		while(Process32Next(hPS,&pe));						// 检索下一个进程 
	} 
    CloseHandle(hPS);										// 关闭快照句柄               

	if (bRunning)
        WriteLog("程序%s正在运行......", szAppName);// 输出成功信息
	else
        WriteLog("程序%s没有运行。", szAppName);	// 输出失败信息
}

// 21.4.5(OK)
void CAppOperSampleDlg::OnButtonRunCopydos()		// 在程序中执行DOS命令
{
	system("copy C:\\1.txt D:\\");	
}

// 21.4.7(OK)
void CAppOperSampleDlg::OnButtonUpdateTitle()		// 修改其他进程中对话框的标题
{
	HWND hWnd = ::FindWindow("Notepad", NULL);
	if (hWnd)
        ::SetWindowText(hWnd, "这是从AppOperSampleDlg程序中修改后的标题");	
}

// 21.4.9(OK)
void CAppOperSampleDlg::OnButtonPeparser()	// PE档案格式分析
{	
	char szFile[MAX_PATH]={0};				// 要解析的PE文件名
	strcpy(szFile, "user32.dll");			// 解析user32.dll文件

	LOADED_IMAGE li;						// 信息结构变量
	if (!MapAndLoad(szFile, 0, &li, FALSE, TRUE))	// 装载PE文件
	{
		WriteLog("PE档案格式分析--MapAndLoad错误");	// 装载失败，显示错误信息
		return;										// 并返回
	}	

	// 分析装载的PE映射的基本信息
	WriteLog("模块名称=%s\r\n文件句柄=%d\r\n映射地址=%08X\r\n字符集=%08X\r\n档案大小=%d\r\n映射%s是内核模式下的可执行映射\r\n映射%s是16位可执行映射\r\nLinks=%08X-%08X\r\n映射大小=%u\r\n", 
		li.ModuleName, li.hFile,li.MappedAddress, li.Characteristics, li.SizeOfImage,
		li.fSystemImage ? "" : "不", li.fDOSImage ? "" : "不", li.Links.Blink, li.Links.Flink, li.SizeOfImage);
	
	PIMAGE_NT_HEADERS ntHeader = li.FileHeader;		// 获取NT头结构变量
	WriteLog("NT头信息FileHeader=%08X\r\n", ntHeader->FileHeader);	// 输出NT头信息
	
    WriteLog("共有%d个COFF个段头", li.NumberOfSections);	// 输出COFF段数量    
    for (int i = 0;i < (int)li.NumberOfSections;i++)		// 循环输出每段信息    
	{
		PIMAGE_SECTION_HEADER psHeader = (PIMAGE_SECTION_HEADER)&li.Sections[i];// 获取第i个段
		WriteLog("第%d个COFF个段头信息	名称=%s", i, psHeader->Name);	// 输出段名称
	}
    
	if (UnMapAndLoad(&li))	WriteLog("成功卸载%s档案文件", szFile);	// 卸载档案文件		
	else WriteLog("卸载%s档案文件失败", szFile);			// 输出错误信息
}

// 21.4.10(OK)
void CAppOperSampleDlg::OnButtonReplaceicon()	// 修改应用程序图标
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
void CAppOperSampleDlg::OnButtonExeusedlls()	// 列举应用程序使用的dll文件
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);// 创建进程使用的模块快照
	if (hModule == NULL)									// 如果创建失败，则
	{
		WriteLog( "调用函数CreateToolhelp32Snapshot失败" );	// 显示错误信息
		return;												// 并返回
	}

	WriteLog( "当前进程调用的dll文件有:" );					// 显示提示信息
	MODULEENTRY32 me;										// 定义模块信息变量							
	BOOL bResult = Module32First( hModule,  &me );			// 获取快照中的第一个模块
	while (bResult)											// 循环处理模块
	{
		WriteLog( me.szExePath );								// 输出模块文件名
		bResult = Module32Next( hModule,  &me );			// 获取下一个模块
	}
	CloseHandle( hModule );									// 关闭模块快照句柄
}

// 21.4.12(OK)
void CAppOperSampleDlg::OnButtonExecCommand()			// 调用具有命令行参数的应用程序
{
	WinExec("AddSample.exe 4 6", SW_SHOWNORMAL);		// 执行自定义程序AddSample
}

// 21.4.13(OK)
void CAppOperSampleDlg::OnButtonWaitprocess()			// 在程序中调用一个子进程直到其结束
{
	WriteLog("调用计算器程序......");					// 显示提示信息
	STARTUPINFO si={0};									// 定义启动信息变量
	PROCESS_INFORMATION pi;								// 定义进程信息变量
	si.cb = sizeof(si);									// 赋值进程结构大小	
	if(CreateProcess(NULL,"calc.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)) // 启动程序
	{		
		WaitForSingleObject(pi.hProcess,INFINITE);		// 等待程序返回
		WriteLog("计算器程序正常结束.");				// 显示结果信息
	}	
}

void CAppOperSampleDlg::OnButtonSaveicon() 
{
	
	SHFILEINFO  fi;
	
	LPVOID lpGMem= GlobalLock(fi.hIcon);
	if(!::SHGetFileInfo("c:\\Windows\\System32\\calc.exe",0, &fi,sizeof(SHFILEINFO),SHGFI_ICON | SHGFI_SMALLICON))
	{
		WriteLog("获取应用程序图标失败。");
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
		WriteLog("保存应用程序图标到SavedAppIcon.ico文件成功。文件大小=%d", dwSize);
	}
	
	if (!SUCCEEDED(CoInitialize(NULL))) 
	{
		WriteLog("初始化OLE组件失败。");
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
					WriteLog("保存应用程序图标成功");
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
