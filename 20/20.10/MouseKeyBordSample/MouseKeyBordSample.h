// MouseKeyBordSample.h : main header file for the MOUSEKEYBORDSAMPLE application
//

#if !defined(AFX_MOUSEKEYBORDSAMPLE_H__41D0B7BB_80F4_4205_B594_2A0E799B5C0E__INCLUDED_)
#define AFX_MOUSEKEYBORDSAMPLE_H__41D0B7BB_80F4_4205_B594_2A0E799B5C0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBordSampleApp:
// See MouseKeyBordSample.cpp for the implementation of this class
//

class CMouseKeyBordSampleApp : public CWinApp
{
public:
	CMouseKeyBordSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseKeyBordSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMouseKeyBordSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEKEYBORDSAMPLE_H__41D0B7BB_80F4_4205_B594_2A0E799B5C0E__INCLUDED_)
