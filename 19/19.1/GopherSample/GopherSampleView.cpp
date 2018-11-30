// GopherSampleView.cpp : implementation of the CGopherSampleView class
//

#include "stdafx.h"
#include "GopherSample.h"
#include "GopherSampleDoc.h"
#include "GopherSampleView.h"
#include <afxinet.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleView

IMPLEMENT_DYNCREATE(CGopherSampleView, CFormView)

BEGIN_MESSAGE_MAP(CGopherSampleView, CFormView)
	//{{AFX_MSG_MAP(CGopherSampleView)
	ON_BN_CLICKED(IDC_BUTTON_GOTO, OnButtonGoto)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleView construction/destruction

CGopherSampleView::CGopherSampleView()
	: CFormView(CGopherSampleView::IDD)
{
	//{{AFX_DATA_INIT(CGopherSampleView)
	m_Address = _T("gopher://gopher.harvard.edu");
	m_Content = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CGopherSampleView::~CGopherSampleView()
{
}

void CGopherSampleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGopherSampleView)
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_Content);
	//}}AFX_DATA_MAP
}

BOOL CGopherSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CGopherSampleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleView printing

BOOL CGopherSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGopherSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGopherSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGopherSampleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleView diagnostics

#ifdef _DEBUG
void CGopherSampleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGopherSampleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGopherSampleDoc* CGopherSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGopherSampleDoc)));
	return (CGopherSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleView message handlers

void CGopherSampleView::OnButtonGoto() 
{  
	UpdateData(TRUE);
	ConnectGopher(m_Address);
//	ConnectGopher("gopher." + m_Address);
}

void CGopherSampleView::ConnectGopher(CString m_host) 
{ 
	UpdateData(TRUE);
	m_Content = "==========================================================\r\n";
	CWaitCursor cursor; // 显示等待光标

	CInternetSession session;//(NULL, 1, PRE_CONFIG_INTERNET_ACCESS); 
	CGopherConnection* pConn = NULL;
	CGopherFileFind* pFile = NULL;
	CString fileName;

	try
	{
		pConn = session.GetGopherConnection(m_host);
	}
	catch (CInternetException* pEx)
	{
		pEx->ReportError();
		pConn = NULL;
		pEx->Delete();
	}

	if (pConn)
	{
		m_Content += "已建立链接。 \r\n";
		CString line;
		CGopherLocator locator = pConn->CreateLocator(NULL, NULL, GOPHER_TYPE_DIRECTORY);
		line = locator;
		m_Content += "第一个Gopher位置是" + line + "\r\n";
		pConn->Close();
		delete pConn;
	}
	else
	{
		m_Content += "本地址没有发现gopher主机 。 \r\n";
	}
	m_Content += "==========================================================\r\n";

	UpdateData(FALSE);
} 

