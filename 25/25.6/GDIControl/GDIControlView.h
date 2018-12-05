// GDIControlView.h : interface of the CGDIControlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDICONTROLVIEW_H__C3B5195A_FDEA_4A84_B295_D40AFCA620EE__INCLUDED_)
#define AFX_GDICONTROLVIEW_H__C3B5195A_FDEA_4A84_B295_D40AFCA620EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIControlView : public CView
{
protected: // create from serialization only
	CGDIControlView();
	BOOL bSelectedImage;
	CRect rect;
	CPoint forePoint;
	DECLARE_DYNCREATE(CGDIControlView)

// Attributes
public:
	CGDIControlDoc* GetDocument();
	HANDLE hThread; 
	CPoint beginPoint;
	CPoint endPoint;
	int OperType;//1--±£¡ÙÕ÷‘≤÷–ƒ⁄»›

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIControlView)
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
	virtual ~CGDIControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIControlView)
	afx_msg void OnMenuitemDrawlineonimage();
	afx_msg void OnMenuitemDrawnetlineonimage();
	afx_msg void OnMenuitemOpenhighimage();
	afx_msg void OnMenuitemScreencopy();
	afx_msg void OnMenuitemScreencut();
	afx_msg void OnMenuitemShowword();
	afx_msg void OnMenuitemGetrgb();
	afx_msg void OnMenuitemDrag();
	afx_msg void OnMenuitemCutellipcontent();
	afx_msg void OnMenuitemSaveellipcontent();
	afx_msg void OnMenuitemShimage();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GDIControlView.cpp
inline CGDIControlDoc* CGDIControlView::GetDocument()
   { return (CGDIControlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDICONTROLVIEW_H__C3B5195A_FDEA_4A84_B295_D40AFCA620EE__INCLUDED_)
