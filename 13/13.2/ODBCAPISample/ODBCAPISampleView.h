// ODBCAPISampleView.h : interface of the CODBCAPISampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCAPISAMPLEVIEW_H__91344FE3_CA0E_41C0_97DE_170D17AB55C5__INCLUDED_)
#define AFX_ODBCAPISAMPLEVIEW_H__91344FE3_CA0E_41C0_97DE_170D17AB55C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CODBCAPISampleView : public CFormView
{
protected: // create from serialization only
	CODBCAPISampleView();
	DECLARE_DYNCREATE(CODBCAPISampleView)

public:
	//{{AFX_DATA(CODBCAPISampleView)
	enum { IDD = IDD_ODBCAPISAMPLE_FORM };
	CEdit	m_editLog;
	CString	m_company;
	CString	m_customerID;
	//}}AFX_DATA

// Attributes
public:
	CODBCAPISampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCAPISampleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBCAPISampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBCAPISampleView)
	afx_msg void OnMenuitemDeletecustomer();
	afx_msg void OnMenuitemInsertcustomer();
	afx_msg void OnMenuitemQuerycustomer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnMenuitemConnect();
};

#ifndef _DEBUG  // debug version in ODBCAPISampleView.cpp
inline CODBCAPISampleDoc* CODBCAPISampleView::GetDocument()
   { return (CODBCAPISampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCAPISAMPLEVIEW_H__91344FE3_CA0E_41C0_97DE_170D17AB55C5__INCLUDED_)
