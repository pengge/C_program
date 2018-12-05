// GDIBaseSampleView.h : interface of the CGDIBaseSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIBASESAMPLEVIEW_H__DA50B1FC_CA86_46E3_9E3C_F7BABC48A237__INCLUDED_)
#define AFX_GDIBASESAMPLEVIEW_H__DA50B1FC_CA86_46E3_9E3C_F7BABC48A237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIBaseSampleView : public CView
{
protected: // create from serialization only
	CGDIBaseSampleView();
	DECLARE_DYNCREATE(CGDIBaseSampleView)

// Attributes
public:
	CGDIBaseSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIBaseSampleView)
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
	int savedDC;
	virtual ~CGDIBaseSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIBaseSampleView)
	afx_msg void OnMenuitemBmpbrush();
	afx_msg void OnMenuitemFillRect();
	afx_msg void OnMenuitemGeometricpen();
	afx_msg void OnMenuitemDrawCrossline();
	afx_msg void OnMenuitemColorchange();
	afx_msg void OnMenuitemDrawColorchange();
	afx_msg void OnMenuitemSavedc();
	afx_msg void OnMenuitemRestoredc();
	afx_msg void OnMenuitemMultibrush();
	afx_msg void OnMenuitemShowpiccenter();
	afx_msg void OnMenuitemSavemetafile();
	afx_msg void OnMenuitemOpenmetafile();
	afx_msg void OnMenuitemChekdigit();
	afx_msg void OnMenuitemClock();
	afx_msg void OnMenuitemCopydc();
	afx_msg void OnMenuitemDesignfont();
	afx_msg void OnMenuitemDraw3d();
	afx_msg void OnMenuitemMemdc();
	afx_msg void OnMenuitemPicturecomb();
	afx_msg void OnMenuitemSavescreentofile();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GDIBaseSampleView.cpp
inline CGDIBaseSampleDoc* CGDIBaseSampleView::GetDocument()
   { return (CGDIBaseSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIBASESAMPLEVIEW_H__DA50B1FC_CA86_46E3_9E3C_F7BABC48A237__INCLUDED_)
