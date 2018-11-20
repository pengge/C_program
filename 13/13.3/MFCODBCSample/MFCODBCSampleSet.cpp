// MFCODBCSampleSet.cpp : implementation of the CMFCODBCSampleSet class
//

#include "stdafx.h"
#include "MFCODBCSample.h"
#include "MFCODBCSampleSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleSet implementation

IMPLEMENT_DYNAMIC(CMFCODBCSampleSet, CRecordset)

CMFCODBCSampleSet::CMFCODBCSampleSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMFCODBCSampleSet)
	m_Address = _T("");
	m_City = _T("");
	m_CompanyName = _T("");
	m_ContactName = _T("");
	m_ContactTitle = _T("");
	m_Country = _T("");
	m_CustomerID = _T("");
	m_Fax = _T("");
	m_Phone = _T("");
	m_PostalCode = _T("");
	m_Region = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CMFCODBCSampleSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Test;uid=sa;pass=sa");
}

CString CMFCODBCSampleSet::GetDefaultSQL()
{
	return _T("[dbo].[Customers]");
}

void CMFCODBCSampleSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMFCODBCSampleSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	RFX_Text(pFX, _T("[City]"), m_City);
	RFX_Text(pFX, _T("[CompanyName]"), m_CompanyName);
	RFX_Text(pFX, _T("[ContactName]"), m_ContactName);
	RFX_Text(pFX, _T("[ContactTitle]"), m_ContactTitle);
	RFX_Text(pFX, _T("[Country]"), m_Country);
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	RFX_Text(pFX, _T("[Fax]"), m_Fax);
	RFX_Text(pFX, _T("[Phone]"), m_Phone);
	RFX_Text(pFX, _T("[PostalCode]"), m_PostalCode);
	RFX_Text(pFX, _T("[Region]"), m_Region);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleSet diagnostics

#ifdef _DEBUG
void CMFCODBCSampleSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCODBCSampleSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
