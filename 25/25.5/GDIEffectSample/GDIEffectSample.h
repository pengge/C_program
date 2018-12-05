// GDIEffectSample.h : main header file for the GDIEFFECTSAMPLE application
//

#if !defined(AFX_GDIEFFECTSAMPLE_H__FA5E9FB5_0694_4644_97DB_72EC48C7490F__INCLUDED_)
#define AFX_GDIEFFECTSAMPLE_H__FA5E9FB5_0694_4644_97DB_72EC48C7490F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleApp:
// See GDIEffectSample.cpp for the implementation of this class
//

class CGDIEffectSampleApp : public CWinApp
{
public:
	ULONG_PTR m_gdiplus;
	CGDIEffectSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIEffectSampleApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGDIEffectSampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIEFFECTSAMPLE_H__FA5E9FB5_0694_4644_97DB_72EC48C7490F__INCLUDED_)
