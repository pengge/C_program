// XFileSample.h : main header file for the XFILESAMPLE application
//

#if !defined(AFX_XFILESAMPLE_H__E4E2561D_3E53_40E7_BE11_9EEA88347E45__INCLUDED_)
#define AFX_XFILESAMPLE_H__E4E2561D_3E53_40E7_BE11_9EEA88347E45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXFileSampleApp:
// See XFileSample.cpp for the implementation of this class
//

class CXFileSampleApp : public CWinApp
{
public:
	CXFileSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXFileSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXFileSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XFILESAMPLE_H__E4E2561D_3E53_40E7_BE11_9EEA88347E45__INCLUDED_)
