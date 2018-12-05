// RegMFCDLLSample.h : main header file for the REGMFCDLLSAMPLE DLL
//

#if !defined(AFX_REGMFCDLLSAMPLE_H__730B6B40_6BD2_4580_A98B_BCD6CF168370__INCLUDED_)
#define AFX_REGMFCDLLSAMPLE_H__730B6B40_6BD2_4580_A98B_BCD6CF168370__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegMFCDLLSampleApp
// See RegMFCDLLSample.cpp for the implementation of this class
//

class CRegMFCDLLSampleApp : public CWinApp
{
public:
	CRegMFCDLLSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegMFCDLLSampleApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CRegMFCDLLSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGMFCDLLSAMPLE_H__730B6B40_6BD2_4580_A98B_BCD6CF168370__INCLUDED_)
