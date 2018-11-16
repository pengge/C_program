// SDISample.h : main header file for the SDISAMPLE application
//

#if !defined(AFX_SDISAMPLE_H__0B31D556_27A6_4D86_AB32_2C941255248E__INCLUDED_)
#define AFX_SDISAMPLE_H__0B31D556_27A6_4D86_AB32_2C941255248E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSDISampleApp:
// See SDISample.cpp for the implementation of this class
//

class CSDISampleApp : public CWinApp
{
public:
	CSDISampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDISampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSDISampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDISAMPLE_H__0B31D556_27A6_4D86_AB32_2C941255248E__INCLUDED_)
