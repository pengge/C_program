// FontEffectsSample.h : main header file for the FONTEFFECTSSAMPLE application
//

#if !defined(AFX_FONTEFFECTSSAMPLE_H__DD4719BB_7B30_4BE6_B9E8_455B0794A18D__INCLUDED_)
#define AFX_FONTEFFECTSSAMPLE_H__DD4719BB_7B30_4BE6_B9E8_455B0794A18D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleApp:
// See FontEffectsSample.cpp for the implementation of this class
//

class CFontEffectsSampleApp : public CWinApp
{
public:
	CFontEffectsSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontEffectsSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFontEffectsSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTEFFECTSSAMPLE_H__DD4719BB_7B30_4BE6_B9E8_455B0794A18D__INCLUDED_)
