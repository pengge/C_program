// GDIBaseSample.h : main header file for the GDIBASESAMPLE application
//

#if !defined(AFX_GDIBASESAMPLE_H__A14E6AD1_748F_4471_B4A1_1443273EF3E5__INCLUDED_)
#define AFX_GDIBASESAMPLE_H__A14E6AD1_748F_4471_B4A1_1443273EF3E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleApp:
// See GDIBaseSample.cpp for the implementation of this class
//

class CGDIBaseSampleApp : public CWinApp
{
public:
	CGDIBaseSampleApp();
	ULONG_PTR m_gdiplus;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIBaseSampleApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGDIBaseSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIBASESAMPLE_H__A14E6AD1_748F_4471_B4A1_1443273EF3E5__INCLUDED_)
