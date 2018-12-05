// PhotoScreenSaver.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PhotoScreenSaver.h"
#include "PhotoScreenSaverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhotoScreenSaverApp

BEGIN_MESSAGE_MAP(CPhotoScreenSaverApp, CWinApp)
	//{{AFX_MSG_MAP(CPhotoScreenSaverApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhotoScreenSaverApp construction

CPhotoScreenSaverApp::CPhotoScreenSaverApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPhotoScreenSaverApp object

CPhotoScreenSaverApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPhotoScreenSaverApp initialization

BOOL CPhotoScreenSaverApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to redUCe the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need.

	#ifdef _AFXDLL
	Enable3dControls(); // Call this when using MFC in a shared DLL
	#else
	Enable3dControlsStatic(); // Call this when linking to MFC statically
	#endif
	CPhotoScreenWnd* pWnd=new CPhotoScreenWnd;
	pWnd->Create();
	m_pMainWnd=pWnd;
	return TRUE;
}
