// CRegKeySample.h : main header file for the CREGKEYSAMPLE application
//

#if !defined(AFX_CREGKEYSAMPLE_H__B50E1CA3_80CF_452E_87D9_3F7058C36FF7__INCLUDED_)
#define AFX_CREGKEYSAMPLE_H__B50E1CA3_80CF_452E_87D9_3F7058C36FF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCRegKeySampleApp:
// See CRegKeySample.cpp for the implementation of this class
//

class CCRegKeySampleApp : public CWinApp
{
public:
	CCRegKeySampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCRegKeySampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCRegKeySampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREGKEYSAMPLE_H__B50E1CA3_80CF_452E_87D9_3F7058C36FF7__INCLUDED_)
