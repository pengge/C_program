#if !defined(AFX_RVCUSTOMER_H__962BCC30_3E98_4890_B99D_0ACB1465B2A5__INCLUDED_)
#define AFX_RVCUSTOMER_H__962BCC30_3E98_4890_B99D_0ACB1465B2A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RVCustomer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRVCustomer record view

#include "RSCustomer.h"

class CRVCustomer : public CRecordView
{
protected:
	CRVCustomer();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRVCustomer)

// Form Data
public:
	//{{AFX_DATA(CRVCustomer)
	enum { IDD = IDD_DIALOG_CUSTOMER };
	CRSCustomer* m_pSet;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	CRSCustomer* GetRecordset();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRVCustomer)
		// NOTE - the ClassWizard will add and remove member functions here.
	public:
	virtual CRecordset* OnGetRecordset();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRVCustomer();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRVCustomer)
	afx_msg void OnMenuitemAddrecord();
	afx_msg void OnMenuitemDeleterecord();
	afx_msg void OnMenuitemUpdaterecord();
	afx_msg void OnMenuitemCommit();
	afx_msg void OnMenuitemRefresh();	
	afx_msg void OnMenuitemCancelrecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RVCUSTOMER_H__962BCC30_3E98_4890_B99D_0ACB1465B2A5__INCLUDED_)
