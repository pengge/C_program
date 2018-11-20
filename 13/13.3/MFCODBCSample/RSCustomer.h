#if !defined(AFX_RSCUSTOMER_H__BFF5A480_1647_4E57_9B67_C9D203777216__INCLUDED_)
#define AFX_RSCUSTOMER_H__BFF5A480_1647_4E57_9B67_C9D203777216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCustomer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRSCustomer recordset

class CRSCustomer : public CRecordset
{
public:
	CRSCustomer(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRSCustomer)

// Field/Param Data
	//{{AFX_FIELD(CRSCustomer, CRecordset)
	CString	m_CustomerID;
	CString	m_CompanyName;
	CString	m_ContactName;
	CString	m_ContactTitle;
	CString	m_Address;
	CString	m_City;
	CString	m_Region;
	CString	m_PostalCode;
	CString	m_Country;
	CString	m_Phone;
	CString	m_Fax;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSCustomer)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSCUSTOMER_H__BFF5A480_1647_4E57_9B67_C9D203777216__INCLUDED_)
