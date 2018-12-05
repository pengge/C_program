// MultiThreadFuncSample.h : main header file for the MULTITHREADFUNCSAMPLE application
//

#if !defined(AFX_MULTITHREADFUNCSAMPLE_H__01F0E033_4E6D_4E88_BC59_9992DB032724__INCLUDED_)
#define AFX_MULTITHREADFUNCSAMPLE_H__01F0E033_4E6D_4E88_BC59_9992DB032724__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFuncSampleApp:
// See MultiThreadFuncSample.cpp for the implementation of this class
//

UINT MyThreadProc( LPVOID pParam );

class CMultiThreadFuncSampleApp : public CWinApp
{
public:
	CMultiThreadFuncSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadFuncSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThreadFuncSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREADFUNCSAMPLE_H__01F0E033_4E6D_4E88_BC59_9992DB032724__INCLUDED_)
