// MFCSOCKClientSample.h : main header file for the MFCSOCKCLIENTSAMPLE application
//

#if !defined(AFX_MFCSOCKCLIENTSAMPLE_H__AC08FC23_EB3A_4C96_8486_78C9229EC68E__INCLUDED_)
#define AFX_MFCSOCKCLIENTSAMPLE_H__AC08FC23_EB3A_4C96_8486_78C9229EC68E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCSOCKClientSampleApp:
// See MFCSOCKClientSample.cpp for the implementation of this class
//

class CMFCSOCKClientSampleApp : public CWinApp
{
public:
	CMFCSOCKClientSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSOCKClientSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCSOCKClientSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSOCKCLIENTSAMPLE_H__AC08FC23_EB3A_4C96_8486_78C9229EC68E__INCLUDED_)
