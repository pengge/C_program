// HTTPSample.h : main header file for the HTTPSAMPLE application
//

#if !defined(AFX_HTTPSAMPLE_H__DB18E809_8BD7_4E16_8D11_0938DC828E9E__INCLUDED_)
#define AFX_HTTPSAMPLE_H__DB18E809_8BD7_4E16_8D11_0938DC828E9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleApp:
// See HTTPSample.cpp for the implementation of this class
//

class CHTTPSampleApp : public CWinApp
{
public:
	CHTTPSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTTPSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHTTPSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPSAMPLE_H__DB18E809_8BD7_4E16_8D11_0938DC828E9E__INCLUDED_)
