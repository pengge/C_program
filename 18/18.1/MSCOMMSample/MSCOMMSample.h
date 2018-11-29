// MSCOMMSample.h : main header file for the MSCOMMSAMPLE application
//

#if !defined(AFX_MSCOMMSAMPLE_H__1FF6C699_D3B4_4B7A_A237_ABD2EBA5FA04__INCLUDED_)
#define AFX_MSCOMMSAMPLE_H__1FF6C699_D3B4_4B7A_A237_ABD2EBA5FA04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMSCOMMSampleApp:
// See MSCOMMSample.cpp for the implementation of this class
//

class CMSCOMMSampleApp : public CWinApp
{
public:
	CMSCOMMSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSCOMMSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMSCOMMSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSCOMMSAMPLE_H__1FF6C699_D3B4_4B7A_A237_ABD2EBA5FA04__INCLUDED_)
