// RedDLL.h : main header file for the REDDLL application
//

#if !defined(AFX_REDDLL_H__2077FFDE_CA85_4BC6_83A5_53B6E04C337D__INCLUDED_)
#define AFX_REDDLL_H__2077FFDE_CA85_4BC6_83A5_53B6E04C337D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRedDLLApp:
// See RedDLL.cpp for the implementation of this class
//

class CRedDLLApp : public CWinApp
{
public:
	CRedDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRedDLLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRedDLLApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDDLL_H__2077FFDE_CA85_4BC6_83A5_53B6E04C337D__INCLUDED_)
