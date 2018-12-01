// AppOperSample.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "AppOperSample.h"
#include "AppOperSampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppOperSampleApp

BEGIN_MESSAGE_MAP(CAppOperSampleApp, CWinApp)
	//{{AFX_MSG_MAP(CAppOperSampleApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppOperSampleApp construction

CAppOperSampleApp::CAppOperSampleApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAppOperSampleApp object

CAppOperSampleApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAppOperSampleApp initialization
const char* MyClassName = "CAppOperSampleDlg";
BOOL CAppOperSampleApp::InitInstance()
{
	AfxEnableControlContainer();
	HANDLE hMutex = CreateMutex(NULL, TRUE, MyClassName);
	if(GetLastError() == ERROR_ALREADY_EXISTS) 
	{
		AfxMessageBox("�����Ѿ������У��˳���");
		return FALSE;	
	}
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CAppOperSampleDlg dlg;
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

	CloseHandle(hMutex);
	
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


BOOL CAppOperSampleApp::InitApplication() 
{	
	return CWinApp::InitApplication();
}
