// CavsSampleView.h : interface of the CCavsSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAVSSAMPLEVIEW_H__5AD0E473_C9E4_44B8_89ED_C523399FA2E5__INCLUDED_)
#define AFX_CAVSSAMPLEVIEW_H__5AD0E473_C9E4_44B8_89ED_C523399FA2E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCavsSampleView : public CView
{
protected: // create from serialization only
	CCavsSampleView();
	DECLARE_DYNCREATE(CCavsSampleView)

// Attributes
public:
	CCavsSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCavsSampleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCavsSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCavsSampleView)
	afx_msg void OnMenuitemDrawbezier();
	afx_msg void OnMenuitemWoniuline();
	afx_msg void OnMenuitemSinline();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CavsSampleView.cpp
inline CCavsSampleDoc* CCavsSampleView::GetDocument()
   { return (CCavsSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAVSSAMPLEVIEW_H__5AD0E473_C9E4_44B8_89ED_C523399FA2E5__INCLUDED_)
