// StaticSplitSample.h : main header file for the STATICSPLITSAMPLE application
//

#if !defined(AFX_STATICSPLITSAMPLE_H__4D221ECB_EC22_4BAA_AEAE_385B92B76B25__INCLUDED_)
#define AFX_STATICSPLITSAMPLE_H__4D221ECB_EC22_4BAA_AEAE_385B92B76B25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleApp:
// See StaticSplitSample.cpp for the implementation of this class
//

class CStaticSplitSampleApp : public CWinApp
{
public:
	CStaticSplitSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticSplitSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStaticSplitSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICSPLITSAMPLE_H__4D221ECB_EC22_4BAA_AEAE_385B92B76B25__INCLUDED_)
