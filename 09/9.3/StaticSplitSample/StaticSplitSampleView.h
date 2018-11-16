// StaticSplitSampleView.h : interface of the CStaticSplitSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATICSPLITSAMPLEVIEW_H__08D8B085_BCB7_4E7E_AA16_F0DBA5A09D7F__INCLUDED_)
#define AFX_STATICSPLITSAMPLEVIEW_H__08D8B085_BCB7_4E7E_AA16_F0DBA5A09D7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStaticSplitSampleView : public CView
{
protected: // create from serialization only
	CStaticSplitSampleView();
	DECLARE_DYNCREATE(CStaticSplitSampleView)

// Attributes
public:
	CStaticSplitSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticSplitSampleView)
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
	virtual ~CStaticSplitSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStaticSplitSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StaticSplitSampleView.cpp
inline CStaticSplitSampleDoc* CStaticSplitSampleView::GetDocument()
   { return (CStaticSplitSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICSPLITSAMPLEVIEW_H__08D8B085_BCB7_4E7E_AA16_F0DBA5A09D7F__INCLUDED_)
