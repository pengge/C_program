// RSCustomer.cpp : implementation file
//

#include "stdafx.h"
#include "MFCODBCSample.h"
#include "RSCustomer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRSCustomer

IMPLEMENT_DYNAMIC(CRSCustomer, CRecordset)

CRSCustomer::CRSCustomer(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRSCustomer)
	m_CustomerID = _T("");
	m_CompanyName = _T("");
	m_ContactName = _T("");
	m_ContactTitle = _T("");
	m_Address = _T("");
	m_City = _T("");
	m_Region = _T("");
	m_PostalCode = _T("");
	m_Country = _T("");
	m_Phone = _T("");
	m_Fax = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CRSCustomer::GetDefaultConnect()
{
	return _T("ODBC;DSN=Test;UID=sa;PWD=sa");
}

CString CRSCustomer::GetDefaultSQL()
{
	return _T("[dbo].[Customer]");
}

void CRSCustomer::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRSCustomer)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[CustomerID]"), m_CustomerID);
	RFX_Text(pFX, _T("[CompanyName]"), m_CompanyName);
	RFX_Text(pFX, _T("[ContactName]"), m_ContactName);
	RFX_Text(pFX, _T("[ContactTitle]"), m_ContactTitle);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	RFX_Text(pFX, _T("[City]"), m_City);
	RFX_Text(pFX, _T("[Region]"), m_Region);
	RFX_Text(pFX, _T("[PostalCode]"), m_PostalCode);
	RFX_Text(pFX, _T("[Country]"), m_Country);
	RFX_Text(pFX, _T("[Phone]"), m_Phone);
	RFX_Text(pFX, _T("[Fax]"), m_Fax);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRSCustomer diagnostics

#ifdef _DEBUG
void CRSCustomer::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRSCustomer::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
