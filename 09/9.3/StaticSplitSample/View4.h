#if !defined(AFX_VIEW4_H__D5C26540_7A9A_4F8D_8A90_F85D7AFBD114__INCLUDED_)
#define AFX_VIEW4_H__D5C26540_7A9A_4F8D_8A90_F85D7AFBD114__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// View4.h : header file
//
#include <Afxcview.h>

/////////////////////////////////////////////////////////////////////////////
// CView4 view

class CView4 : public CListView
{
protected:
	CView4();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CView4)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CView4)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CView4();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CView4)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW4_H__D5C26540_7A9A_4F8D_8A90_F85D7AFBD114__INCLUDED_)
