// DrawPictureSample.h : main header file for the DRAWPICTURESAMPLE application
//

#if !defined(AFX_DRAWPICTURESAMPLE_H__062DBE84_A1AF_4267_B539_5B1C639E99B8__INCLUDED_)
#define AFX_DRAWPICTURESAMPLE_H__062DBE84_A1AF_4267_B539_5B1C639E99B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleApp:
// See DrawPictureSample.cpp for the implementation of this class
//

class CDrawPictureSampleApp : public CWinApp
{
public:
	CDrawPictureSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawPictureSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawPictureSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWPICTURESAMPLE_H__062DBE84_A1AF_4267_B539_5B1C639E99B8__INCLUDED_)
