// ThreadCommSample.h : main header file for the THREADCOMMSAMPLE application
//

#if !defined(AFX_THREADCOMMSAMPLE_H__95A0DD68_FD93_4AA5_9050_3DC5F6EC071A__INCLUDED_)
#define AFX_THREADCOMMSAMPLE_H__95A0DD68_FD93_4AA5_9050_3DC5F6EC071A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadCommSampleApp:
// See ThreadCommSample.cpp for the implementation of this class
//
UINT MyThreadProc( LPVOID pParam );
class CThreadCommSampleApp : public CWinApp
{
public:
	CThreadCommSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadCommSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadCommSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADCOMMSAMPLE_H__95A0DD68_FD93_4AA5_9050_3DC5F6EC071A__INCLUDED_)
