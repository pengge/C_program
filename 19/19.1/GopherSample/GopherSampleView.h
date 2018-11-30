// GopherSampleView.h : interface of the CGopherSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOPHERSAMPLEVIEW_H__249205AC_69AE_484B_9E1F_261F03FA8EAD__INCLUDED_)
#define AFX_GOPHERSAMPLEVIEW_H__249205AC_69AE_484B_9E1F_261F03FA8EAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGopherSampleView : public CFormView
{
protected: // create from serialization only
	CGopherSampleView();
	DECLARE_DYNCREATE(CGopherSampleView)

public:
	//{{AFX_DATA(CGopherSampleView)
	enum { IDD = IDD_GOPHERSAMPLE_FORM };
	CString	m_Address;
	CString	m_Content;
	//}}AFX_DATA

// Attributes
public:
	CGopherSampleDoc* GetDocument();
	void ConnectGopher(CString m_host);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGopherSampleView)
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
	virtual ~CGopherSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGopherSampleView)
	afx_msg void OnButtonGoto();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GopherSampleView.cpp
inline CGopherSampleDoc* CGopherSampleView::GetDocument()
   { return (CGopherSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOPHERSAMPLEVIEW_H__249205AC_69AE_484B_9E1F_261F03FA8EAD__INCLUDED_)
