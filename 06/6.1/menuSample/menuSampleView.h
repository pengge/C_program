// menuSampleView.h : interface of the CMenuSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUSAMPLEVIEW_H__5936017E_B42C_4248_883F_CB75B9616EF0__INCLUDED_)
#define AFX_MENUSAMPLEVIEW_H__5936017E_B42C_4248_883F_CB75B9616EF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuSampleView : public CView
{
protected: // create from serialization only
	CMenuSampleView();
	DECLARE_DYNCREATE(CMenuSampleView)

// Attributes
public:
	CMenuSampleDoc* GetDocument();
	BOOL bToosCheck;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuSampleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenuSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuSampleView)
	afx_msg void OnMenuitemStatu();
	afx_msg void OnUpdateMenuitemStatu(CCmdUI* pCmdUI);
	afx_msg void OnMenuitemPopItem1();
	afx_msg void OnMenuitemPopItem2();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in menuSampleView.cpp
inline CMenuSampleDoc* CMenuSampleView::GetDocument()
   { return (CMenuSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUSAMPLEVIEW_H__5936017E_B42C_4248_883F_CB75B9616EF0__INCLUDED_)
