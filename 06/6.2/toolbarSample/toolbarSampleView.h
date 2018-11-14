// toolbarSampleView.h : interface of the CToolbarSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARSAMPLEVIEW_H__1F7CD8CC_F70C_4F3D_8AA3_5C5A5F6F5E48__INCLUDED_)
#define AFX_TOOLBARSAMPLEVIEW_H__1F7CD8CC_F70C_4F3D_8AA3_5C5A5F6F5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolbarSampleView : public CView
{
protected: // create from serialization only
	CToolbarSampleView();
	DECLARE_DYNCREATE(CToolbarSampleView)

// Attributes
public:
	CToolbarSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarSampleView)
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
	virtual ~CToolbarSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolbarSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in toolbarSampleView.cpp
inline CToolbarSampleDoc* CToolbarSampleView::GetDocument()
   { return (CToolbarSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARSAMPLEVIEW_H__1F7CD8CC_F70C_4F3D_8AA3_5C5A5F6F5E48__INCLUDED_)
