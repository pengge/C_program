// MessageSendSample.h : main header file for the MESSAGESENDSAMPLE application
//

#if !defined(AFX_MESSAGESENDSAMPLE_H__A6C22735_F858_4A8F_B337_A45FDCC06DC4__INCLUDED_)
#define AFX_MESSAGESENDSAMPLE_H__A6C22735_F858_4A8F_B337_A45FDCC06DC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMessageSendSampleApp:
// See MessageSendSample.cpp for the implementation of this class
//

class CMessageSendSampleApp : public CWinApp
{
public:
	CMessageSendSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageSendSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMessageSendSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGESENDSAMPLE_H__A6C22735_F858_4A8F_B337_A45FDCC06DC4__INCLUDED_)
