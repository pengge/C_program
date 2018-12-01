// DiskInfo.h : main header file for the DISKINFO application
//

#if !defined(AFX_DISKINFO_H__B019F1FF_FA3C_47B7_BAC6_2BA54318CF07__INCLUDED_)
#define AFX_DISKINFO_H__B019F1FF_FA3C_47B7_BAC6_2BA54318CF07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiskInfoApp:
// See DiskInfo.cpp for the implementation of this class
//

class CDiskInfoApp : public CWinApp
{
public:
	CDiskInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDiskInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKINFO_H__B019F1FF_FA3C_47B7_BAC6_2BA54318CF07__INCLUDED_)
