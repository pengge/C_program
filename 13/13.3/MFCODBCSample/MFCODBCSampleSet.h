// MFCODBCSampleSet.h : interface of the CMFCODBCSampleSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCODBCSAMPLESET_H__3871DE9C_6779_468D_978C_1A118FA330F2__INCLUDED_)
#define AFX_MFCODBCSAMPLESET_H__3871DE9C_6779_468D_978C_1A118FA330F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFCODBCSampleSet : public CRecordset
{
public:
	CMFCODBCSampleSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMFCODBCSampleSet)

// Field/Param Data
	//{{AFX_FIELD(CMFCODBCSampleSet, CRecordset)
	CString	m_Address;
	CString	m_City;
	CString	m_CompanyName;
	CString	m_ContactName;
	CString	m_ContactTitle;
	CString	m_Country;
	CString	m_CustomerID;
	CString	m_Fax;
	CString	m_Phone;
	CString	m_PostalCode;
	CString	m_Region;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCODBCSampleSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCODBCSAMPLESET_H__3871DE9C_6779_468D_978C_1A118FA330F2__INCLUDED_)

