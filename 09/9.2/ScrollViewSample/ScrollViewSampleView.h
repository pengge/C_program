// ScrollViewSampleView.h : interface of the CScrollViewSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCROLLVIEWSAMPLEVIEW_H__4D672E35_9DEC_4DB4_84C7_072569C1BFE6__INCLUDED_)
#define AFX_SCROLLVIEWSAMPLEVIEW_H__4D672E35_9DEC_4DB4_84C7_072569C1BFE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CScrollViewSampleView : public CScrollView
{
protected: // create from serialization only
	CScrollViewSampleView();
	DECLARE_DYNCREATE(CScrollViewSampleView)

// Attributes
public:
	CScrollViewSampleDoc* GetDocument();
	CRect m_rect;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollViewSampleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScrollViewSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScrollViewSampleView)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ScrollViewSampleView.cpp
inline CScrollViewSampleDoc* CScrollViewSampleView::GetDocument()
   { return (CScrollViewSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLVIEWSAMPLEVIEW_H__4D672E35_9DEC_4DB4_84C7_072569C1BFE6__INCLUDED_)
