// PlayMultiMedia.h : main header file for the PLAYMULTIMEDIA application
//

#if !defined(AFX_PLAYMULTIMEDIA_H__E88E1587_0EF9_4C08_B4C1_014302D0376C__INCLUDED_)
#define AFX_PLAYMULTIMEDIA_H__E88E1587_0EF9_4C08_B4C1_014302D0376C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlayMultiMediaApp:
// See PlayMultiMedia.cpp for the implementation of this class
//

class CPlayMultiMediaApp : public CWinApp
{
public:
	CPlayMultiMediaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayMultiMediaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlayMultiMediaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYMULTIMEDIA_H__E88E1587_0EF9_4C08_B4C1_014302D0376C__INCLUDED_)
