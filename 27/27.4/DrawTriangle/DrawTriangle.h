// DrawTriangle.h : main header file for the DRAWTRIANGLE application
//

#if !defined(AFX_DRAWTRIANGLE_H__F970F1F1_2A55_445A_BDEA_AD3969D9A3E2__INCLUDED_)
#define AFX_DRAWTRIANGLE_H__F970F1F1_2A55_445A_BDEA_AD3969D9A3E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawTriangleApp:
// See DrawTriangle.cpp for the implementation of this class
//

class CDrawTriangleApp : public CWinApp
{
public:
	CDrawTriangleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTriangleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawTriangleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTRIANGLE_H__F970F1F1_2A55_445A_BDEA_AD3969D9A3E2__INCLUDED_)
