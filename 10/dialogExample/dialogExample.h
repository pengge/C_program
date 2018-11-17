// dialogExample.h : main header file for the DIALOGEXAMPLE application
//

#if !defined(AFX_DIALOGEXAMPLE_H__283241EB_002F_44D8_8655_872E75EC9F51__INCLUDED_)
#define AFX_DIALOGEXAMPLE_H__283241EB_002F_44D8_8655_872E75EC9F51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogExampleApp:
// See dialogExample.cpp for the implementation of this class
//

class CDialogExampleApp : public CWinApp
{
public:
	CDialogExampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogExampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogExampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEXAMPLE_H__283241EB_002F_44D8_8655_872E75EC9F51__INCLUDED_)
