// DLLAppSample.h : main header file for the DLLAPPSAMPLE application
//

#if !defined(AFX_DLLAPPSAMPLE_H__10D70400_95FD_44F6_9CD2_B912758C4A84__INCLUDED_)
#define AFX_DLLAPPSAMPLE_H__10D70400_95FD_44F6_9CD2_B912758C4A84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDLLAppSampleApp:
// See DLLAppSample.cpp for the implementation of this class
//

static HHOOK hOldHook;
class CDLLAppSampleApp : public CWinApp
{
public:
	CDLLAppSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLLAppSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDLLAppSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLAPPSAMPLE_H__10D70400_95FD_44F6_9CD2_B912758C4A84__INCLUDED_)
