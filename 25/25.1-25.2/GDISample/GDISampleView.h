// GDISampleView.h : interface of the CGDISampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDISAMPLEVIEW_H__A1C228FF_87D2_4B0C_B06C_0FE6D358E6D7__INCLUDED_)
#define AFX_GDISAMPLEVIEW_H__A1C228FF_87D2_4B0C_B06C_0FE6D358E6D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDISampleView : public CView
{
protected: // create from serialization only
	CGDISampleView();
	DECLARE_DYNCREATE(CGDISampleView)

// Attributes
public:
	CGDISampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDISampleView)
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
	virtual ~CGDISampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDISampleView)
	afx_msg void OnMenuitemBrush();
	afx_msg void OnMenuitemPen();
	afx_msg void OnMenuitemBitmap();
	afx_msg void OnMenuitemRegion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GDISampleView.cpp
inline CGDISampleDoc* CGDISampleView::GetDocument()
   { return (CGDISampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDISAMPLEVIEW_H__A1C228FF_87D2_4B0C_B06C_0FE6D358E6D7__INCLUDED_)
