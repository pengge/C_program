// ODBCAPISample.h : main header file for the ODBCAPISAMPLE application
//

#if !defined(AFX_ODBCAPISAMPLE_H__EB9FDC20_E7E1_4C07_B885_5B6A89C7396A__INCLUDED_)
#define AFX_ODBCAPISAMPLE_H__EB9FDC20_E7E1_4C07_B885_5B6A89C7396A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleApp:
// See ODBCAPISample.cpp for the implementation of this class
//

class CODBCAPISampleApp : public CWinApp
{
public:
	CODBCAPISampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCAPISampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CODBCAPISampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCAPISAMPLE_H__EB9FDC20_E7E1_4C07_B885_5B6A89C7396A__INCLUDED_)
