// AppOperSample.h : main header file for the APPOPERSAMPLE application
//

#if !defined(AFX_APPOPERSAMPLE_H__3E163DC4_F09D_4DBD_BDEF_29323339B7C1__INCLUDED_)
#define AFX_APPOPERSAMPLE_H__3E163DC4_F09D_4DBD_BDEF_29323339B7C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAppOperSampleApp:
// See AppOperSample.cpp for the implementation of this class
//

class CAppOperSampleApp : public CWinApp
{
public:
	CAppOperSampleApp();
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppOperSampleApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAppOperSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPOPERSAMPLE_H__3E163DC4_F09D_4DBD_BDEF_29323339B7C1__INCLUDED_)
