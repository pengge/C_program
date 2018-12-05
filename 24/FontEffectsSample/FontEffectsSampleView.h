// FontEffectsSampleView.h : interface of the CFontEffectsSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FONTEFFECTSSAMPLEVIEW_H__DCD79414_76DF_406C_9D04_D36D16284F46__INCLUDED_)
#define AFX_FONTEFFECTSSAMPLEVIEW_H__DCD79414_76DF_406C_9D04_D36D16284F46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFontEffectsSampleView : public CView
{
protected: // create from serialization only
	CFontEffectsSampleView();
	DECLARE_DYNCREATE(CFontEffectsSampleView)

// Attributes
public:
	CFontEffectsSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontEffectsSampleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFontEffectsSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint mousePoint;
	int   m_iXExtend;
	int   m_iYExtend;


// Generated message map functions
protected:
	//{{AFX_MSG(CFontEffectsSampleView)
	afx_msg void OnMenuitemRotateFont();
	afx_msg void OnPaint();
	afx_msg void OnMenuKongxinFont();
	afx_msg void OnMenuitemJianbianFont();
	afx_msg void OnMenuitem3dFont();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FontEffectsSampleView.cpp
inline CFontEffectsSampleDoc* CFontEffectsSampleView::GetDocument()
   { return (CFontEffectsSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTEFFECTSSAMPLEVIEW_H__DCD79414_76DF_406C_9D04_D36D16284F46__INCLUDED_)
