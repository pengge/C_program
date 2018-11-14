// statusbarSample.h : main header file for the STATUSBARSAMPLE application
//

#if !defined(AFX_STATUSBARSAMPLE_H__3DD2695B_C07E_49BC_9118_038DDC4A4A17__INCLUDED_)
#define AFX_STATUSBARSAMPLE_H__3DD2695B_C07E_49BC_9118_038DDC4A4A17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleApp:
// See statusbarSample.cpp for the implementation of this class
//

class CStatusbarSampleApp : public CWinApp
{
public:
	CStatusbarSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusbarSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStatusbarSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSBARSAMPLE_H__3DD2695B_C07E_49BC_9118_038DDC4A4A17__INCLUDED_)
