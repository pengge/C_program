// MFCODBCSampleView.h : interface of the CMFCODBCSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCODBCSAMPLEVIEW_H__20F696A3_E47B_4B50_92D5_0CF739EA3F0E__INCLUDED_)
#define AFX_MFCODBCSAMPLEVIEW_H__20F696A3_E47B_4B50_92D5_0CF739EA3F0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFCODBCSampleSet;

class CMFCODBCSampleView : public CRecordView
{
protected: // create from serialization only
	CMFCODBCSampleView();
	DECLARE_DYNCREATE(CMFCODBCSampleView)

public:
	//{{AFX_DATA(CMFCODBCSampleView)
	enum{ IDD = IDD_MFCODBCSAMPLE_FORM };
	CMFCODBCSampleSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMFCODBCSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCODBCSampleView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCODBCSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCODBCSampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCODBCSampleView.cpp
inline CMFCODBCSampleDoc* CMFCODBCSampleView::GetDocument()
   { return (CMFCODBCSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCODBCSAMPLEVIEW_H__20F696A3_E47B_4B50_92D5_0CF739EA3F0E__INCLUDED_)
