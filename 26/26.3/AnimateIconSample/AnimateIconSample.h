// AnimateIconSample.h : main header file for the ANIMATEICONSAMPLE application
//

#if !defined(AFX_ANIMATEICONSAMPLE_H__883FCBC9_9536_4BA6_95E0_3671663706FC__INCLUDED_)
#define AFX_ANIMATEICONSAMPLE_H__883FCBC9_9536_4BA6_95E0_3671663706FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleApp:
// See AnimateIconSample.cpp for the implementation of this class
//

class CAnimateIconSampleApp : public CWinApp
{
public:
	CAnimateIconSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateIconSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAnimateIconSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATEICONSAMPLE_H__883FCBC9_9536_4BA6_95E0_3671663706FC__INCLUDED_)
