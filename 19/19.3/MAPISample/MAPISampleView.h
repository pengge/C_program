// MAPISampleView.h : interface of the CMAPISampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPISAMPLEVIEW_H__9DB9658E_F020_474F_9D8A_C65E8DECF636__INCLUDED_)
#define AFX_MAPISAMPLEVIEW_H__9DB9658E_F020_474F_9D8A_C65E8DECF636__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMAPISampleView : public CEditView
{
protected: // create from serialization only
	CMAPISampleView();
	DECLARE_DYNCREATE(CMAPISampleView)

// Attributes
public:
	CMAPISampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMAPISampleView)
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
	virtual ~CMAPISampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMAPISampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MAPISampleView.cpp
inline CMAPISampleDoc* CMAPISampleView::GetDocument()
   { return (CMAPISampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPISAMPLEVIEW_H__9DB9658E_F020_474F_9D8A_C65E8DECF636__INCLUDED_)
