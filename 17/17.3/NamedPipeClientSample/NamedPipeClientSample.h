// NamedPipeClientSample.h : main header file for the NAMEDPIPECLIENTSAMPLE application
//

#if !defined(AFX_NAMEDPIPECLIENTSAMPLE_H__7AD30FC3_96F2_4B9C_91D0_C517D6FDF371__INCLUDED_)
#define AFX_NAMEDPIPECLIENTSAMPLE_H__7AD30FC3_96F2_4B9C_91D0_C517D6FDF371__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNamedPipeClientSampleApp:
// See NamedPipeClientSample.cpp for the implementation of this class
//

class CNamedPipeClientSampleApp : public CWinApp
{
public:
	CNamedPipeClientSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedPipeClientSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNamedPipeClientSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPIPECLIENTSAMPLE_H__7AD30FC3_96F2_4B9C_91D0_C517D6FDF371__INCLUDED_)
