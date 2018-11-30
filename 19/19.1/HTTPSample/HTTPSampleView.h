// HTTPSampleView.h : interface of the CHTTPSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTTPSAMPLEVIEW_H__10C753C2_7635_415B_921B_0365BF080DA3__INCLUDED_)
#define AFX_HTTPSAMPLEVIEW_H__10C753C2_7635_415B_921B_0365BF080DA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxinet.h"

class CHTTPSampleView : public CFormView
{
protected: // create from serialization only
	CHTTPSampleView();
	
	CHttpConnection* m_pHttpConnection;		// HTTP¡¨Ω”¿‡

	DECLARE_DYNCREATE(CHTTPSampleView)

public:
	//{{AFX_DATA(CHTTPSampleView)
	enum { IDD = IDD_HTTPSAMPLE_FORM };
	CString	m_Address;
	CString	m_Content;
	//}}AFX_DATA

// Attributes
public:
	CHTTPSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTTPSampleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHTTPSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHTTPSampleView)
	afx_msg void OnButtonDownload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HTTPSampleView.cpp
inline CHTTPSampleDoc* CHTTPSampleView::GetDocument()
   { return (CHTTPSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPSAMPLEVIEW_H__10C753C2_7635_415B_921B_0365BF080DA3__INCLUDED_)
