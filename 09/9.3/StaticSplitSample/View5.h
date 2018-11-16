#if !defined(AFX_VIEW5_H__52211FEC_E853_4D1D_886B_56A68A4C92C6__INCLUDED_)
#define AFX_VIEW5_H__52211FEC_E853_4D1D_886B_56A68A4C92C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// View5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CView5 view

class CView5 : public CScrollView
{
protected:
	CView5();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CView5)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CView5)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CView5();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CView5)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW5_H__52211FEC_E853_4D1D_886B_56A68A4C92C6__INCLUDED_)
