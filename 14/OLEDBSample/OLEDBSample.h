// OLEDBSample.h : main header file for the OLEDBSAMPLE application
//

#if !defined(AFX_OLEDBSAMPLE_H__CF1BA5E4_4AD6_4EB3_A23F_0569BBA27DC6__INCLUDED_)
#define AFX_OLEDBSAMPLE_H__CF1BA5E4_4AD6_4EB3_A23F_0569BBA27DC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COLEDBSampleApp:
// See OLEDBSample.cpp for the implementation of this class
//

class COLEDBSampleApp : public CWinApp
{
public:
	COLEDBSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBSampleApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(COLEDBSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBSAMPLE_H__CF1BA5E4_4AD6_4EB3_A23F_0569BBA27DC6__INCLUDED_)
