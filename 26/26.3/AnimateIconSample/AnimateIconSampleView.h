// AnimateIconSampleView.h : interface of the CAnimateIconSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIMATEICONSAMPLEVIEW_H__5F663ACD_BCB7_4FDF_8252_C87D2269C207__INCLUDED_)
#define AFX_ANIMATEICONSAMPLEVIEW_H__5F663ACD_BCB7_4FDF_8252_C87D2269C207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAnimateIconSampleView : public CView
{
protected: // create from serialization only
	CAnimateIconSampleView();
	DECLARE_DYNCREATE(CAnimateIconSampleView)

// Attributes
public:
	CAnimateIconSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateIconSampleView)
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
	virtual ~CAnimateIconSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAnimateIconSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AnimateIconSampleView.cpp
inline CAnimateIconSampleDoc* CAnimateIconSampleView::GetDocument()
   { return (CAnimateIconSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATEICONSAMPLEVIEW_H__5F663ACD_BCB7_4FDF_8252_C87D2269C207__INCLUDED_)
