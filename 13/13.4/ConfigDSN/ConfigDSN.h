// ConfigDSN.h : main header file for the CONFIGDSN application
//

#if !defined(AFX_CONFIGDSN_H__1CE80649_5AB8_4E75_82BA_6761F1A940A5__INCLUDED_)
#define AFX_CONFIGDSN_H__1CE80649_5AB8_4E75_82BA_6761F1A940A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConfigDSNApp:
// See ConfigDSN.cpp for the implementation of this class
//

class CConfigDSNApp : public CWinApp
{
public:
	CConfigDSNApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigDSNApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConfigDSNApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGDSN_H__1CE80649_5AB8_4E75_82BA_6761F1A940A5__INCLUDED_)
