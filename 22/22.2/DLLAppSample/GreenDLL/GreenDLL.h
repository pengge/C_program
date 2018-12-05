// GreenDLL.h : main header file for the GREENDLL application
//

#if !defined(AFX_GREENDLL_H__41BB2322_B86B_4C73_B37E_BBF38A717D49__INCLUDED_)
#define AFX_GREENDLL_H__41BB2322_B86B_4C73_B37E_BBF38A717D49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLApp:
// See GreenDLL.cpp for the implementation of this class
//

class CGreenDLLApp : public CWinApp
{
public:
	CGreenDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreenDLLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGreenDLLApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREENDLL_H__41BB2322_B86B_4C73_B37E_BBF38A717D49__INCLUDED_)
