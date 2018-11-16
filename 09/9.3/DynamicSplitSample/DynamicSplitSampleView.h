// DynamicSplitSampleView.h : interface of the CDynamicSplitSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMICSPLITSAMPLEVIEW_H__4F147228_A8F0_4939_ACB7_4D7450D601C3__INCLUDED_)
#define AFX_DYNAMICSPLITSAMPLEVIEW_H__4F147228_A8F0_4939_ACB7_4D7450D601C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynamicSplitSampleView : public CView
{
protected: // create from serialization only
	CDynamicSplitSampleView();
	DECLARE_DYNCREATE(CDynamicSplitSampleView)

// Attributes
public:
	CDynamicSplitSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicSplitSampleView)
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
	virtual ~CDynamicSplitSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynamicSplitSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DynamicSplitSampleView.cpp
inline CDynamicSplitSampleDoc* CDynamicSplitSampleView::GetDocument()
   { return (CDynamicSplitSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICSPLITSAMPLEVIEW_H__4F147228_A8F0_4939_ACB7_4D7450D601C3__INCLUDED_)
