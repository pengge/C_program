// DrawPictureSampleView.h : interface of the CDrawPictureSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWPICTURESAMPLEVIEW_H__BF3FFC50_ED02_4DD1_B377_19F5655C3866__INCLUDED_)
#define AFX_DRAWPICTURESAMPLEVIEW_H__BF3FFC50_ED02_4DD1_B377_19F5655C3866__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawPictureSampleView : public CView
{
protected: // create from serialization only
	int type;
	POINT ptBegin,ptEnd;
	HPEN hPen;
	HBRUSH hBrush;
	CDrawPictureSampleView();
	DECLARE_DYNCREATE(CDrawPictureSampleView)

// Attributes
public:
	CDrawPictureSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawPictureSampleView)
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
	virtual ~CDrawPictureSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawPictureSampleView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMenuitemDrawLine();
	afx_msg void OnMenuitemDrawRect();
	afx_msg void OnMenuitemArrow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawPictureSampleView.cpp
inline CDrawPictureSampleDoc* CDrawPictureSampleView::GetDocument()
   { return (CDrawPictureSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWPICTURESAMPLEVIEW_H__BF3FFC50_ED02_4DD1_B377_19F5655C3866__INCLUDED_)
