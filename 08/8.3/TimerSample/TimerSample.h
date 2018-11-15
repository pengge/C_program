// TimerSample.h : main header file for the TIMERSAMPLE application
//

#if !defined(AFX_TIMERSAMPLE_H__7EA082A8_64B1_439B_B6BC_FBDCD315737D__INCLUDED_)
#define AFX_TIMERSAMPLE_H__7EA082A8_64B1_439B_B6BC_FBDCD315737D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimerSampleApp:
// See TimerSample.cpp for the implementation of this class
//

class CTimerSampleApp : public CWinApp
{
public:
	CTimerSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimerSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSAMPLE_H__7EA082A8_64B1_439B_B6BC_FBDCD315737D__INCLUDED_)
