// ClicpBoardSample.h : main header file for the CLICPBOARDSAMPLE application
//

#if !defined(AFX_CLICPBOARDSAMPLE_H__8ABF67A4_AC43_4A0F_A8D3_E59156AAC0B6__INCLUDED_)
#define AFX_CLICPBOARDSAMPLE_H__8ABF67A4_AC43_4A0F_A8D3_E59156AAC0B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClicpBoardSampleApp:
// See ClicpBoardSample.cpp for the implementation of this class
//

class CClicpBoardSampleApp : public CWinApp
{
public:
	CClicpBoardSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClicpBoardSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClicpBoardSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLICPBOARDSAMPLE_H__8ABF67A4_AC43_4A0F_A8D3_E59156AAC0B6__INCLUDED_)
