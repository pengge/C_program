// CavsSample.h : main header file for the CAVSSAMPLE application
//

#if !defined(AFX_CAVSSAMPLE_H__C71355FA_D655_4A56_8F8C_16C7DCCD23D1__INCLUDED_)
#define AFX_CAVSSAMPLE_H__C71355FA_D655_4A56_8F8C_16C7DCCD23D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


/////////////////////////////////////////////////////////////////////////////
// CCavsSampleApp:
// See CavsSample.cpp for the implementation of this class
//

class CCavsSampleApp : public CWinApp
{
public:
	CCavsSampleApp();
	ULONG_PTR m_gdiplus;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCavsSampleApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCavsSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAVSSAMPLE_H__C71355FA_D655_4A56_8F8C_16C7DCCD23D1__INCLUDED_)
