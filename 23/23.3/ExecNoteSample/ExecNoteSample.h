// ExecNoteSample.h : main header file for the EXECNOTESAMPLE application
//

#if !defined(AFX_EXECNOTESAMPLE_H__08052FDE_978A_4642_B7EF_5593E36CC3A6__INCLUDED_)
#define AFX_EXECNOTESAMPLE_H__08052FDE_978A_4642_B7EF_5593E36CC3A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExecNoteSampleApp:
// See ExecNoteSample.cpp for the implementation of this class
//

UINT StartAndCloseThreadProc( LPVOID pParam );
UINT StartAndWaitThreadProc( LPVOID pParam );
BOOL CALLBACK CloseNoteApp(HWND hwnd, LPARAM lParam); 

class CExecNoteSampleApp : public CWinApp
{
public:
	CExecNoteSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExecNoteSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExecNoteSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXECNOTESAMPLE_H__08052FDE_978A_4642_B7EF_5593E36CC3A6__INCLUDED_)
