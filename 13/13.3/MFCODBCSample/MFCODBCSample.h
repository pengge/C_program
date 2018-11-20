// MFCODBCSample.h : main header file for the MFCODBCSAMPLE application
//

#if !defined(AFX_MFCODBCSAMPLE_H__A7B97867_2EE8_4152_8085_B6DE697388DD__INCLUDED_)
#define AFX_MFCODBCSAMPLE_H__A7B97867_2EE8_4152_8085_B6DE697388DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleApp:
// See MFCODBCSample.cpp for the implementation of this class
//

class CMFCODBCSampleApp : public CWinApp
{
public:
	CMFCODBCSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCODBCSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CMFCODBCSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCODBCSAMPLE_H__A7B97867_2EE8_4152_8085_B6DE697388DD__INCLUDED_)
