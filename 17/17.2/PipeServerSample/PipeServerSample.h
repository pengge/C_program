// PipeServerSample.h : main header file for the PIPESERVERSAMPLE application
//

#if !defined(AFX_PIPESERVERSAMPLE_H__092DAB93_457F_41D0_B561_2799951164CF__INCLUDED_)
#define AFX_PIPESERVERSAMPLE_H__092DAB93_457F_41D0_B561_2799951164CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPipeServerSampleApp:
// See PipeServerSample.cpp for the implementation of this class
//

class CPipeServerSampleApp : public CWinApp
{
public:
	CPipeServerSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPipeServerSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPipeServerSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIPESERVERSAMPLE_H__092DAB93_457F_41D0_B561_2799951164CF__INCLUDED_)
