// BroadConvert.h : main header file for the BROADCONVERT application
//

#if !defined(AFX_BROADCONVERT_H__B008E949_2391_4C3F_8352_6B79F00E84D4__INCLUDED_)
#define AFX_BROADCONVERT_H__B008E949_2391_4C3F_8352_6B79F00E84D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBroadConvertApp:
// See BroadConvert.cpp for the implementation of this class
//

class CBroadConvertApp : public CWinApp
{
public:
	CBroadConvertApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBroadConvertApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBroadConvertApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROADCONVERT_H__B008E949_2391_4C3F_8352_6B79F00E84D4__INCLUDED_)
