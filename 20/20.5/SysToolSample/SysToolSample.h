// SysToolSample.h : main header file for the SYSTOOLSAMPLE application
//

#if !defined(AFX_SYSTOOLSAMPLE_H__E4B1BCB8_4DFF_43A9_B083_AE00A357A2AF__INCLUDED_)
#define AFX_SYSTOOLSAMPLE_H__E4B1BCB8_4DFF_43A9_B083_AE00A357A2AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSysToolSampleApp:
// See SysToolSample.cpp for the implementation of this class
//

class CSysToolSampleApp : public CWinApp
{
public:
	CSysToolSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysToolSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSysToolSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTOOLSAMPLE_H__E4B1BCB8_4DFF_43A9_B083_AE00A357A2AF__INCLUDED_)
