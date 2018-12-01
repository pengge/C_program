// DesktopSample.h : main header file for the DESKTOPSAMPLE application
//

#if !defined(AFX_DESKTOPSAMPLE_H__7F8A4591_4C1C_4CAA_A62E_932408B1B308__INCLUDED_)
#define AFX_DESKTOPSAMPLE_H__7F8A4591_4C1C_4CAA_A62E_932408B1B308__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDesktopSampleApp:
// See DesktopSample.cpp for the implementation of this class
//

class CDesktopSampleApp : public CWinApp
{
public:
	CDesktopSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesktopSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDesktopSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKTOPSAMPLE_H__7F8A4591_4C1C_4CAA_A62E_932408B1B308__INCLUDED_)
