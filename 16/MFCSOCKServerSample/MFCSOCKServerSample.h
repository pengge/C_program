// MFCSOCKServerSample.h : main header file for the MFCSOCKSERVERSAMPLE application
//

#if !defined(AFX_MFCSOCKSERVERSAMPLE_H__ECB238AF_97E1_4953_A441_965BB1DCA778__INCLUDED_)
#define AFX_MFCSOCKSERVERSAMPLE_H__ECB238AF_97E1_4953_A441_965BB1DCA778__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCSOCKServerSampleApp:
// See MFCSOCKServerSample.cpp for the implementation of this class
//

class CMFCSOCKServerSampleApp : public CWinApp
{
public:
	CMFCSOCKServerSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSOCKServerSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCSOCKServerSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSOCKSERVERSAMPLE_H__ECB238AF_97E1_4953_A441_965BB1DCA778__INCLUDED_)
