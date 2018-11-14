// SpinSliderProgressSample.h : main header file for the SPINSLIDERPROGRESSSAMPLE application
//

#if !defined(AFX_SPINSLIDERPROGRESSSAMPLE_H__FA7AF40D_17DF_4A33_B95C_39483A139622__INCLUDED_)
#define AFX_SPINSLIDERPROGRESSSAMPLE_H__FA7AF40D_17DF_4A33_B95C_39483A139622__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpinSliderProgressSampleApp:
// See SpinSliderProgressSample.cpp for the implementation of this class
//

class CSpinSliderProgressSampleApp : public CWinApp
{
public:
	CSpinSliderProgressSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinSliderProgressSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpinSliderProgressSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINSLIDERPROGRESSSAMPLE_H__FA7AF40D_17DF_4A33_B95C_39483A139622__INCLUDED_)
