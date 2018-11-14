// statusbarSampleView.h : interface of the CStatusbarSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSBARSAMPLEVIEW_H__7D7F2134_5E1F_415D_85F9_46C19ECC21A9__INCLUDED_)
#define AFX_STATUSBARSAMPLEVIEW_H__7D7F2134_5E1F_415D_85F9_46C19ECC21A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusbarSampleView : public CView
{
protected: // create from serialization only
	CStatusbarSampleView();
	DECLARE_DYNCREATE(CStatusbarSampleView)

// Attributes
public:
	CStatusbarSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusbarSampleView)
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
	virtual ~CStatusbarSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusbarSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in statusbarSampleView.cpp
inline CStatusbarSampleDoc* CStatusbarSampleView::GetDocument()
   { return (CStatusbarSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSBARSAMPLEVIEW_H__7D7F2134_5E1F_415D_85F9_46C19ECC21A9__INCLUDED_)
