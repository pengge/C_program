// FaceAppSampleView.h : interface of the CFaceAppSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACEAPPSAMPLEVIEW_H__75C4E8CB_48D6_4C5C_85A6_0B3289399F13__INCLUDED_)
#define AFX_FACEAPPSAMPLEVIEW_H__75C4E8CB_48D6_4C5C_85A6_0B3289399F13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceAppSampleView : public CView
{
protected: // create from serialization only
	CFaceAppSampleView();
	DECLARE_DYNCREATE(CFaceAppSampleView)

// Attributes
public:
	CFaceAppSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceAppSampleView)
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
	virtual ~CFaceAppSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFaceAppSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FaceAppSampleView.cpp
inline CFaceAppSampleDoc* CFaceAppSampleView::GetDocument()
   { return (CFaceAppSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FACEAPPSAMPLEVIEW_H__75C4E8CB_48D6_4C5C_85A6_0B3289399F13__INCLUDED_)
