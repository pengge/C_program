// DrawCube.h : main header file for the DRAWCUBE application
//

#if !defined(AFX_DRAWCUBE_H__63C438A8_F998_4921_B54C_D30BB9DA3CCB__INCLUDED_)
#define AFX_DRAWCUBE_H__63C438A8_F998_4921_B54C_D30BB9DA3CCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawCubeApp:
// See DrawCube.cpp for the implementation of this class
//

class CDrawCubeApp : public CWinApp
{
public:
	CDrawCubeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawCubeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawCubeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCUBE_H__63C438A8_F998_4921_B54C_D30BB9DA3CCB__INCLUDED_)
