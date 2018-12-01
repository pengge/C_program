// DiskOper.h : main header file for the DISKOPER application
//

#if !defined(AFX_DISKOPER_H__66C390E6_B6F4_4858_BEC7_3CCAE08FA549__INCLUDED_)
#define AFX_DISKOPER_H__66C390E6_B6F4_4858_BEC7_3CCAE08FA549__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiskOperApp:
// See DiskOper.cpp for the implementation of this class
//

class CDiskOperApp : public CWinApp
{
public:
	CDiskOperApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskOperApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDiskOperApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKOPER_H__66C390E6_B6F4_4858_BEC7_3CCAE08FA549__INCLUDED_)
