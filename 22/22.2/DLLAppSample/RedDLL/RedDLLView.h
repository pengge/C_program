// RedDLLView.h : interface of the CRedDLLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REDDLLVIEW_H__2553009D_3477_43A7_8DC4_7F4433CB21D6__INCLUDED_)
#define AFX_REDDLLVIEW_H__2553009D_3477_43A7_8DC4_7F4433CB21D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRedDLLView : public CView
{
protected: // create from serialization only
	CRedDLLView();
	DECLARE_DYNCREATE(CRedDLLView)

// Attributes
public:
	CRedDLLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRedDLLView)
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
	virtual ~CRedDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRedDLLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RedDLLView.cpp
inline CRedDLLDoc* CRedDLLView::GetDocument()
   { return (CRedDLLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDDLLVIEW_H__2553009D_3477_43A7_8DC4_7F4433CB21D6__INCLUDED_)
