// OLEDBSampleView.h : interface of the COLEDBSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBSAMPLEVIEW_H__1AFC0230_57D2_4FE5_9BFB_892D0C82CFA5__INCLUDED_)
#define AFX_OLEDBSAMPLEVIEW_H__1AFC0230_57D2_4FE5_9BFB_892D0C82CFA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COLEDBSampleView : public CFormView
{
protected: // create from serialization only
	COLEDBSampleView();
	DECLARE_DYNCREATE(COLEDBSampleView)

public:
	//{{AFX_DATA(COLEDBSampleView)
	enum { IDD = IDD_OLEDBSAMPLE_FORM };
	CListCtrl	m_DataCtrl;
	CListCtrl	m_TablesCtrl;
	CListCtrl	m_ColumesCtrl;
	//}}AFX_DATA

// Attributes
public:
	COLEDBSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBSampleView)
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
	void ShowData();
	void ShowTitle();
	void ShowColumes();
	void ShowTable();
	virtual ~COLEDBSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDBSampleView)
	afx_msg void OnFileOpen();
	afx_msg void OnDblclkTreeDb(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListTables(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLvnItemchangedListTables(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // debug version in OLEDBSampleView.cpp
inline COLEDBSampleDoc* COLEDBSampleView::GetDocument()
   { return (COLEDBSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBSAMPLEVIEW_H__1AFC0230_57D2_4FE5_9BFB_892D0C82CFA5__INCLUDED_)
