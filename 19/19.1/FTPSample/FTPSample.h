// FTPSample.h : main header file for the FTPSAMPLE application
//

#if !defined(AFX_FTPSAMPLE_H__46F78F28_B4A0_483F_92BA_4759A368E1BD__INCLUDED_)
#define AFX_FTPSAMPLE_H__46F78F28_B4A0_483F_92BA_4759A368E1BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleApp:
// See FTPSample.cpp for the implementation of this class
//

class CFTPSampleApp : public CWinApp
{
public:
	CFTPSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFTPSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPSAMPLE_H__46F78F28_B4A0_483F_92BA_4759A368E1BD__INCLUDED_)
