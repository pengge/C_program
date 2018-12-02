// XMLParserSample.h : main header file for the XMLPARSERSAMPLE application
//

#if !defined(AFX_XMLPARSERSAMPLE_H__F4316722_EC8C_4FD2_AA19_B221584191C4__INCLUDED_)
#define AFX_XMLPARSERSAMPLE_H__F4316722_EC8C_4FD2_AA19_B221584191C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXMLParserSampleApp:
// See XMLParserSample.cpp for the implementation of this class
//

class CXMLParserSampleApp : public CWinApp
{
public:
	CXMLParserSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLParserSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXMLParserSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLPARSERSAMPLE_H__F4316722_EC8C_4FD2_AA19_B221584191C4__INCLUDED_)
