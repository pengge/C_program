// ODBCAPISampleView.cpp : implementation of the CODBCAPISampleView class
//

#include "stdafx.h"
#include "ODBCAPISample.h"
#include "ODBCAPISampleDoc.h"
#include "ODBCAPISampleView.h"
#include "MyODBCAPI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleView

IMPLEMENT_DYNCREATE(CODBCAPISampleView, CFormView)

BEGIN_MESSAGE_MAP(CODBCAPISampleView, CFormView)
	//{{AFX_MSG_MAP(CODBCAPISampleView)
	ON_COMMAND(ID_MENUITEM_DELETECUSTOMER, OnMenuitemDeletecustomer)
	ON_COMMAND(ID_MENUITEM_INSERTCUSTOMER, OnMenuitemInsertcustomer)
	ON_COMMAND(ID_MENUITEM_QUERYCUSTOMER, OnMenuitemQuerycustomer)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
    ON_COMMAND(ID_MENUITEM_CONNECT, &CODBCAPISampleView::OnMenuitemConnect)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleView construction/destruction

CODBCAPISampleView::CODBCAPISampleView()
	: CFormView(CODBCAPISampleView::IDD)
{
	//{{AFX_DATA_INIT(CODBCAPISampleView)
	m_company = _T("");
	m_customerID = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CODBCAPISampleView::~CODBCAPISampleView()
{
}

void CODBCAPISampleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCAPISampleView)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_COMPANY, m_company);
	DDX_Text(pDX, IDC_EDIT_CUSTOMERID, m_customerID);
	//}}AFX_DATA_MAP
}

BOOL CODBCAPISampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CODBCAPISampleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleView printing

BOOL CODBCAPISampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CODBCAPISampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CODBCAPISampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CODBCAPISampleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleView diagnostics

#ifdef _DEBUG
void CODBCAPISampleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CODBCAPISampleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CODBCAPISampleDoc* CODBCAPISampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCAPISampleDoc)));
	return (CODBCAPISampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleView message handlers

void CODBCAPISampleView::OnMenuitemDeletecustomer() 
{
	// 删除客户
	UpdateData(TRUE);
	MyODBCAPI myODBC;
	myODBC.DeleteCustomer(m_customerID);
	m_editLog.SetWindowText(myODBC.msg);	
}

void CODBCAPISampleView::OnMenuitemInsertcustomer() 
{
	// 增加客户
	UpdateData(TRUE);
	MyODBCAPI myODBC;
	myODBC.InsertCustomer(m_customerID, m_company);
	m_editLog.SetWindowText(myODBC.msg);
}

void CODBCAPISampleView::OnMenuitemQuerycustomer() 
{		
	// 查询客户
	MyODBCAPI myODBC;
	myODBC.QueryCustomer();
	m_editLog.SetWindowText(myODBC.msg);
}


void CODBCAPISampleView::OnMenuitemConnect()
{
    // TODO: 在此添加命令处理程序代码
    MyODBCAPI myODBC;			// 定义自定义类MyODBCAPI的变量
    myODBC.QueryCustomer();

    m_editLog.SetWindowText(myODBC.msg);
}
