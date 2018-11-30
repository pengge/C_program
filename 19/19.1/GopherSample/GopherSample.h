// GopherSample.h : main header file for the GOPHERSAMPLE application
//

#if !defined(AFX_GOPHERSAMPLE_H__EF7BE5C3_B13D_4DB8_830F_EB3A36FBA54C__INCLUDED_)
#define AFX_GOPHERSAMPLE_H__EF7BE5C3_B13D_4DB8_830F_EB3A36FBA54C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleApp:
// See GopherSample.cpp for the implementation of this class
//

class CGopherSampleApp : public CWinApp
{
public:
	CGopherSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGopherSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGopherSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOPHERSAMPLE_H__EF7BE5C3_B13D_4DB8_830F_EB3A36FBA54C__INCLUDED_)
