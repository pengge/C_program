// ExtMFCDLLTest.h : main header file for the EXTMFCDLLTEST application
//

#if !defined(AFX_EXTMFCDLLTEST_H__0FE4AD01_F2B5_47C6_98FF_A617F34BE716__INCLUDED_)
#define AFX_EXTMFCDLLTEST_H__0FE4AD01_F2B5_47C6_98FF_A617F34BE716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExtMFCDLLTestApp:
// See ExtMFCDLLTest.cpp for the implementation of this class
//

class CExtMFCDLLTestApp : public CWinApp
{
public:
	CExtMFCDLLTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtMFCDLLTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExtMFCDLLTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTMFCDLLTEST_H__0FE4AD01_F2B5_47C6_98FF_A617F34BE716__INCLUDED_)
