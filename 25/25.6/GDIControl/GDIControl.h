// GDIControl.h : main header file for the GDICONTROL application
//

#if !defined(AFX_GDICONTROL_H__D6CC18FE_5D7F_423A_B90B_0CA8194383B0__INCLUDED_)
#define AFX_GDICONTROL_H__D6CC18FE_5D7F_423A_B90B_0CA8194383B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGDIControlApp:
// See GDIControl.cpp for the implementation of this class
//

class CGDIControlApp : public CWinApp
{
public:
	CGDIControlApp();
	ULONG_PTR m_gdiplus;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIControlApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGDIControlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDICONTROL_H__D6CC18FE_5D7F_423A_B90B_0CA8194383B0__INCLUDED_)
