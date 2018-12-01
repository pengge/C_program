// FaceAppSample.h : main header file for the FACEAPPSAMPLE application
//

#if !defined(AFX_FACEAPPSAMPLE_H__7681860F_C08B_48F3_90FA_F011B6DFF833__INCLUDED_)
#define AFX_FACEAPPSAMPLE_H__7681860F_C08B_48F3_90FA_F011B6DFF833__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleApp:
// See FaceAppSample.cpp for the implementation of this class
//

class CFaceAppSampleApp : public CWinApp
{
public:
	CFaceAppSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceAppSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFaceAppSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FACEAPPSAMPLE_H__7681860F_C08B_48F3_90FA_F011B6DFF833__INCLUDED_)
