// toolbarSample.h : main header file for the TOOLBARSAMPLE application
//

#if !defined(AFX_TOOLBARSAMPLE_H__08EA25DA_6C76_4348_A5EA_A6A2FF25E7D7__INCLUDED_)
#define AFX_TOOLBARSAMPLE_H__08EA25DA_6C76_4348_A5EA_A6A2FF25E7D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleApp:
// See toolbarSample.cpp for the implementation of this class
//

class CToolbarSampleApp : public CWinApp
{
public:
	CToolbarSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CToolbarSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARSAMPLE_H__08EA25DA_6C76_4348_A5EA_A6A2FF25E7D7__INCLUDED_)
