// ExecNoteSample.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ExecNoteSample.h"
#include "ExecNoteSampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExecNoteSampleApp

BEGIN_MESSAGE_MAP(CExecNoteSampleApp, CWinApp)
	//{{AFX_MSG_MAP(CExecNoteSampleApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExecNoteSampleApp construction

CExecNoteSampleApp::CExecNoteSampleApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CExecNoteSampleApp object

CExecNoteSampleApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CExecNoteSampleApp initialization

BOOL CExecNoteSampleApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CExecNoteSampleDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


UINT StartAndWaitThreadProc( LPVOID pParam )
{// 启动记事本程序并等待其结束
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);	
	if( !CreateProcess(NULL,"notepad.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)) 
		AfxMessageBox("启动记事本进程失败.");
	
	WaitForSingleObject( pi.hProcess, INFINITE );// 无限期等待进程结束	
	CloseHandle( pi.hProcess );	// 关闭进程
	CloseHandle( pi.hThread );	// 关闭线程
	AfxMessageBox("启动的记事本已经关闭");
	return 0;
}

int bRunning = 0;
UINT StartAndCloseThreadProc( LPVOID pParam )
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);	
	if( !CreateProcess(NULL,"notepad.exe",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi)) 
		AfxMessageBox("启动记事本进程失败.");
	while(bRunning) 
	{
		if (bRunning == 2)	SuspendThread(pi.hThread);	// 挂起
		else if (bRunning == 3) ResumeThread(pi.hThread); // 恢复
		Sleep(1000);
	}
	EnumWindows((WNDENUMPROC)CloseNoteApp, (LPARAM)pi.dwProcessId);	
	if (pi.hProcess) CloseHandle( pi.hProcess );	// 关闭进程
	if (pi.hThread) CloseHandle( pi.hThread );	// 关闭线程
	AfxMessageBox("启动的记事本已经关闭");	
	return 0;
}
   
BOOL CALLBACK CloseNoteApp(HWND hwnd,LPARAM lParam)   
{   
	DWORD dwID;
	GetWindowThreadProcessId(hwnd, &dwID);
	if(dwID == (DWORD)lParam)   PostMessage(hwnd,WM_CLOSE,0, 0);   
	return TRUE;
}  


