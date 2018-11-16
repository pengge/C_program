#if !defined(AFX_VIEW2_H__27104322_8D28_40E4_BEC9_AFCE4EDCACDD__INCLUDED_)
#define AFX_VIEW2_H__27104322_8D28_40E4_BEC9_AFCE4EDCACDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// View2.h : header file
//
#include "MDISampleDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CView2 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CView2 : public CFormView
{
protected:
	CView2();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CView2)

// Form Data
public:
	//{{AFX_DATA(CView2)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CView2)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CView2();
	CMDISampleDoc* GetDocument(); // non-debug version is inline
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CView2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW2_H__27104322_8D28_40E4_BEC9_AFCE4EDCACDD__INCLUDED_)
