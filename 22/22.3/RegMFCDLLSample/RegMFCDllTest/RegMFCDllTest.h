// RegMFCDllTest.h : main header file for the REGMFCDLLTEST application
//

#if !defined(AFX_REGMFCDLLTEST_H__FEDFD115_30E1_4B9A_AFC4_69E5E694B523__INCLUDED_)
#define AFX_REGMFCDLLTEST_H__FEDFD115_30E1_4B9A_AFC4_69E5E694B523__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegMFCDllTestApp:
// See RegMFCDllTest.cpp for the implementation of this class
//

class CRegMFCDllTestApp : public CWinApp
{
public:
	CRegMFCDllTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegMFCDllTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegMFCDllTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGMFCDLLTEST_H__FEDFD115_30E1_4B9A_AFC4_69E5E694B523__INCLUDED_)
