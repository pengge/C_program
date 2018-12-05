// GDIEffectSampleView.h : interface of the CGDIEffectSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIEFFECTSAMPLEVIEW_H__BAD21549_FD15_4567_B45F_29D4058B4E0C__INCLUDED_)
#define AFX_GDIEFFECTSAMPLEVIEW_H__BAD21549_FD15_4567_B45F_29D4058B4E0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIEffectSampleView : public CView
{
protected: // create from serialization only
	CGDIEffectSampleView();
	DECLARE_DYNCREATE(CGDIEffectSampleView)

// Attributes
public:
	CGDIEffectSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIEffectSampleView)
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
	virtual ~CGDIEffectSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIEffectSampleView)
	afx_msg void OnMenuitemReserve();
	afx_msg void OnMenuitemResize();
	afx_msg void OnMenuitemCut();
	afx_msg void OnMenuitemHuidu();
	afx_msg void OnMenuitemRouhua();
	afx_msg void OnMenuitemRuihua();
	afx_msg void OnMenuitemFanse();
	afx_msg void OnMenuitemFudiao();
	afx_msg void OnMenuitem3dhui();
	afx_msg void OnMenuitemHbaiye();
	afx_msg void OnMenuitemMasaike();
	afx_msg void OnMenuitemVbaiye();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GDIEffectSampleView.cpp
inline CGDIEffectSampleDoc* CGDIEffectSampleView::GetDocument()
   { return (CGDIEffectSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIEFFECTSAMPLEVIEW_H__BAD21549_FD15_4567_B45F_29D4058B4E0C__INCLUDED_)
