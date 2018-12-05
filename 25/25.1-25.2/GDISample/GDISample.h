// GDISample.h : main header file for the GDISAMPLE application
//

#if !defined(AFX_GDISAMPLE_H__22EA5C16_8DD1_4D53_83BC_5E951042D4B6__INCLUDED_)
#define AFX_GDISAMPLE_H__22EA5C16_8DD1_4D53_83BC_5E951042D4B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGDISampleApp:
// See GDISample.cpp for the implementation of this class
//

class CGDISampleApp : public CWinApp
{
public:
	CGDISampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDISampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGDISampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDISAMPLE_H__22EA5C16_8DD1_4D53_83BC_5E951042D4B6__INCLUDED_)
