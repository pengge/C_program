// ScrollViewSample.h : main header file for the SCROLLVIEWSAMPLE application
//

#if !defined(AFX_SCROLLVIEWSAMPLE_H__BF09E063_B30B_4B9E_9D51_3DB05173B885__INCLUDED_)
#define AFX_SCROLLVIEWSAMPLE_H__BF09E063_B30B_4B9E_9D51_3DB05173B885__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleApp:
// See ScrollViewSample.cpp for the implementation of this class
//

class CScrollViewSampleApp : public CWinApp
{
public:
	CScrollViewSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollViewSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CScrollViewSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLVIEWSAMPLE_H__BF09E063_B30B_4B9E_9D51_3DB05173B885__INCLUDED_)
