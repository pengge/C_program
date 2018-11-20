// RVCustomer.cpp : implementation file
//

#include "stdafx.h"
#include "MFCODBCSample.h"
#include "RVCustomer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRVCustomer

IMPLEMENT_DYNCREATE(CRVCustomer, CRecordView)

CRVCustomer::CRVCustomer()
	: CRecordView(CRVCustomer::IDD)
{
	//{{AFX_DATA_INIT(CRVCustomer)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
}

CRVCustomer::~CRVCustomer()
{
	if (m_pSet)
		delete m_pSet;
}

void CRVCustomer::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRVCustomer)
	DDX_FieldText(pDX, IDC_EDIT_CUSTOMERID, m_pSet->m_CustomerID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_ADDRESS, m_pSet->m_Address, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_CITY, m_pSet->m_City, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_COMPANYNAME, m_pSet->m_CompanyName, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_CONTACTNAME, m_pSet->m_ContactName, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_CONTACTTITLE, m_pSet->m_ContactTitle, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_COUNTRY, m_pSet->m_Country, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_FAX, m_pSet->m_Fax, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_POSTALCODE, m_pSet->m_PostalCode, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_REGION, m_pSet->m_Region, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_TELE, m_pSet->m_Phone, m_pSet);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRVCustomer, CRecordView)
	//{{AFX_MSG_MAP(CRVCustomer)
	ON_COMMAND(ID_MENUITEM_ADDRECORD, OnMenuitemAddrecord)
	ON_COMMAND(ID_MENUITEM_DELETERECORD, OnMenuitemDeleterecord)
	ON_COMMAND(ID_MENUITEM_UPDATERECORD, OnMenuitemUpdaterecord)
	ON_COMMAND(ID_MENUITEM_COMMIT, OnMenuitemCommit)
	ON_COMMAND(ID_MENUITEM_REFRESH, OnMenuitemRefresh)	
	ON_COMMAND(ID_MENUITEM_CANCELRECORD, OnMenuitemCancelrecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRVCustomer diagnostics

#ifdef _DEBUG
void CRVCustomer::AssertValid() const
{
	CRecordView::AssertValid();
}

void CRVCustomer::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRVCustomer message handlers

CRecordset* CRVCustomer::OnGetRecordset()
{
	if (m_pSet != NULL)
		return m_pSet;

	m_pSet = new CRSCustomer(NULL);
	m_pSet->Open();

	return m_pSet;
}

CRSCustomer* CRVCustomer::GetRecordset()
{
	CRSCustomer* pData = (CRSCustomer*) OnGetRecordset();
	ASSERT(pData == NULL || pData->IsKindOf(RUNTIME_CLASS(CRSCustomer)));
	return pData;
}

void CRVCustomer::OnInitialUpdate()
{
	BeginWaitCursor();
	GetRecordset();
	CRecordView::OnInitialUpdate();
	if (m_pSet->IsOpen())
	{
		CString strTitle = m_pSet->m_pDatabase->GetDatabaseName();
		CString strTable = m_pSet->GetTableName();
		if (!strTable.IsEmpty())
			strTitle += _T(":") + strTable;
		GetDocument()->SetTitle(strTitle);
	}
	EndWaitCursor();
}

// 增加记录
void CRVCustomer::OnMenuitemAddrecord() 
{
	if (m_pSet->IsOpen())
	{
		m_pSet->AddNew();
		UpdateData(FALSE);
	}	
}

// 删除记录
void CRVCustomer::OnMenuitemDeleterecord() 
{
	if (m_pSet->IsOpen())
	{		
		m_pSet->Delete();		
	}
}

// 修改记录
void CRVCustomer::OnMenuitemUpdaterecord() 
{
	if (m_pSet->IsOpen())
	{
		m_pSet->Edit();
	}
}

// 增加或修改提交
void CRVCustomer::OnMenuitemCommit() 
{
	if (m_pSet->IsOpen())
	{
		UpdateData(TRUE);
		m_pSet->Update();
		m_pSet->MoveFirst();
		UpdateData(FALSE);
	}
}

// 刷新记录
void CRVCustomer::OnMenuitemRefresh() 
{
	if (m_pSet != NULL)
	{
		m_pSet->Requery();
	}
	else
	{
		m_pSet = new CRSCustomer(NULL);
		m_pSet->Open();
	}
}


//取消修改记录
void CRVCustomer::OnMenuitemCancelrecord() 
{
	if (m_pSet->IsOpen())
	{
		m_pSet->CancelUpdate();
		m_pSet->MoveFirst();
		UpdateData(FALSE);
	}
}
