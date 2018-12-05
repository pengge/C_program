// MultiThreadFuncSample.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MultiThreadFuncSample.h"
#include "MultiThreadFuncSampleDlg.h"
#include "Maths.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFuncSampleApp

BEGIN_MESSAGE_MAP(CMultiThreadFuncSampleApp, CWinApp)
	//{{AFX_MSG_MAP(CMultiThreadFuncSampleApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFuncSampleApp construction

CMultiThreadFuncSampleApp::CMultiThreadFuncSampleApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMultiThreadFuncSampleApp object

CMultiThreadFuncSampleApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFuncSampleApp initialization

BOOL CMultiThreadFuncSampleApp::InitInstance()
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

	CMultiThreadFuncSampleDlg dlg;
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

int globalCounter = 0;
bool bThreadRunning = true;
UINT MyThreadProc( LPVOID pParam )
{
    CMaths* pObject = (CMaths*)pParam;
    if ((pObject == NULL) || (!pObject->IsKindOf(RUNTIME_CLASS(CMaths))))
	{
		AfxMessageBox("参数传入失败。Prepare Exit Thread");
		return 1; 
	}
	while (bThreadRunning)
	{
		globalCounter++;
		if (globalCounter > 99999999)	globalCounter=0;	
		Sleep(1000);
	}
	return 0;
}




