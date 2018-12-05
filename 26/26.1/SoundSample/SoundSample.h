// SoundSample.h : main header file for the SOUNDSAMPLE application
//

#if !defined(AFX_SOUNDSAMPLE_H__6826C021_A651_4C71_B075_186E3A95B16A__INCLUDED_)
#define AFX_SOUNDSAMPLE_H__6826C021_A651_4C71_B075_186E3A95B16A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSoundSampleApp:
// See SoundSample.cpp for the implementation of this class
//

class CSoundSampleApp : public CWinApp
{
public:
	CSoundSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSoundSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDSAMPLE_H__6826C021_A651_4C71_B075_186E3A95B16A__INCLUDED_)
