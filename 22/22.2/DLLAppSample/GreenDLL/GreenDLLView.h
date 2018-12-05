// GreenDLLView.h : interface of the CGreenDLLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GREENDLLVIEW_H__BB00946C_2E51_4F95_8BBC_461244D7CD5A__INCLUDED_)
#define AFX_GREENDLLVIEW_H__BB00946C_2E51_4F95_8BBC_461244D7CD5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGreenDLLView : public CView
{
protected: // create from serialization only
	CGreenDLLView();
	DECLARE_DYNCREATE(CGreenDLLView)

// Attributes
public:
	CGreenDLLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreenDLLView)
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
	virtual ~CGreenDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGreenDLLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GreenDLLView.cpp
inline CGreenDLLDoc* CGreenDLLView::GetDocument()
   { return (CGreenDLLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREENDLLVIEW_H__BB00946C_2E51_4F95_8BBC_461244D7CD5A__INCLUDED_)
