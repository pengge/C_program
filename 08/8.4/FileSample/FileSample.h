// FileSample.h : main header file for the FILESAMPLE application
//

#if !defined(AFX_FILESAMPLE_H__C077D8DA_014D_45DB_B1C0_1E8D86A8C29E__INCLUDED_)
#define AFX_FILESAMPLE_H__C077D8DA_014D_45DB_B1C0_1E8D86A8C29E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileSampleApp:
// See FileSample.cpp for the implementation of this class
//

class CFileSampleApp : public CWinApp
{
public:
	CFileSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESAMPLE_H__C077D8DA_014D_45DB_B1C0_1E8D86A8C29E__INCLUDED_)
