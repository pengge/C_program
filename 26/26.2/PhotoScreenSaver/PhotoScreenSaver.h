// PhotoScreenSaver.h : main header file for the PHOTOSCREENSAVER application
//

#if !defined(AFX_PHOTOSCREENSAVER_H__2DE80E3E_F413_4A29_AD2B_3BEE0174F498__INCLUDED_)
#define AFX_PHOTOSCREENSAVER_H__2DE80E3E_F413_4A29_AD2B_3BEE0174F498__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "PhotoScreenWnd.h"

/////////////////////////////////////////////////////////////////////////////
// CPhotoScreenSaverApp:
// See PhotoScreenSaver.cpp for the implementation of this class
//

class CPhotoScreenSaverApp : public CWinApp
{
public:
	CPhotoScreenSaverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoScreenSaverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPhotoScreenSaverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTOSCREENSAVER_H__2DE80E3E_F413_4A29_AD2B_3BEE0174F498__INCLUDED_)
