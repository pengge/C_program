// SystemInfoSample.h : main header file for the SYSTEMINFOSAMPLE application
//

#if !defined(AFX_SYSTEMINFOSAMPLE_H__64BD572D_D839_429B_B017_450E40013F6E__INCLUDED_)
#define AFX_SYSTEMINFOSAMPLE_H__64BD572D_D839_429B_B017_450E40013F6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSystemInfoSampleApp:
// See SystemInfoSample.cpp for the implementation of this class
//

class CSystemInfoSampleApp : public CWinApp
{
public:
	CSystemInfoSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemInfoSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSystemInfoSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMINFOSAMPLE_H__64BD572D_D839_429B_B017_450E40013F6E__INCLUDED_)
