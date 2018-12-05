// PlayMultiMedia.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PlayMultiMedia.h"
#include "PlayMultiMediaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayMultiMediaApp

BEGIN_MESSAGE_MAP(CPlayMultiMediaApp, CWinApp)
	//{{AFX_MSG_MAP(CPlayMultiMediaApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayMultiMediaApp construction

CPlayMultiMediaApp::CPlayMultiMediaApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPlayMultiMediaApp object

CPlayMultiMediaApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPlayMultiMediaApp initialization

BOOL CPlayMultiMediaApp::InitInstance()
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

	//初始化gdiplus的环境
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	// 初始化GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	CPlayMultiMediaDlg dlg;
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


	//关闭gdiplus的环境
	GdiplusShutdown(gdiplusToken);

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
