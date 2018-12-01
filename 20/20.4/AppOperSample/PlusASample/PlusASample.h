// PlusASample.h : main header file for the PLUSASAMPLE DLL
//

#if !defined(AFX_PLUSASAMPLE_H__E5D4455E_B61D_4FD4_AB74_E08AEFDB1882__INCLUDED_)
#define AFX_PLUSASAMPLE_H__E5D4455E_B61D_4FD4_AB74_E08AEFDB1882__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlusASampleApp
// See PlusASample.cpp for the implementation of this class
//

class CPlusASampleApp : public CWinApp
{
public:
	CPlusASampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlusASampleApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPlusASampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUSASAMPLE_H__E5D4455E_B61D_4FD4_AB74_E08AEFDB1882__INCLUDED_)
