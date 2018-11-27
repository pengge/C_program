// NamedPipeServerSample.h : main header file for the NAMEDPIPESERVERSAMPLE application
//

#if !defined(AFX_NAMEDPIPESERVERSAMPLE_H__6E888D0B_7ECE_4B6E_9072_AD01A942070A__INCLUDED_)
#define AFX_NAMEDPIPESERVERSAMPLE_H__6E888D0B_7ECE_4B6E_9072_AD01A942070A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNamedPipeServerSampleApp:
// See NamedPipeServerSample.cpp for the implementation of this class
//

class CNamedPipeServerSampleApp : public CWinApp
{
public:
	CNamedPipeServerSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedPipeServerSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNamedPipeServerSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPIPESERVERSAMPLE_H__6E888D0B_7ECE_4B6E_9072_AD01A942070A__INCLUDED_)
