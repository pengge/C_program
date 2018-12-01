// SysControlSample.h : main header file for the SYSCONTROLSAMPLE application
//

#if !defined(AFX_SYSCONTROLSAMPLE_H__CE10ACF0_D0C4_4EDC_8AFD_4079C1BDDB10__INCLUDED_)
#define AFX_SYSCONTROLSAMPLE_H__CE10ACF0_D0C4_4EDC_8AFD_4079C1BDDB10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSysControlSampleApp:
// See SysControlSample.cpp for the implementation of this class
//

class CSysControlSampleApp : public CWinApp
{
public:
	CSysControlSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysControlSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSysControlSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSCONTROLSAMPLE_H__CE10ACF0_D0C4_4EDC_8AFD_4079C1BDDB10__INCLUDED_)
