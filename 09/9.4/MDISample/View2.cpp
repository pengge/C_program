// View2.cpp : implementation file
//

#include "stdafx.h"
#include "MDISample.h"
#include "View2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView2

IMPLEMENT_DYNCREATE(CView2, CFormView)

CView2::CView2()
	: CFormView(CView2::IDD)
{
	//{{AFX_DATA_INIT(CView2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CView2::~CView2()
{
}

void CView2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CView2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CView2, CFormView)
	//{{AFX_MSG_MAP(CView2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView2 diagnostics

#ifdef _DEBUG
void CView2::AssertValid() const
{
	CFormView::AssertValid();
}

void CView2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView2 message handlers
CMDISampleDoc* CView2::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDISampleDoc)));
	return (CMDISampleDoc*)m_pDocument;
}

void CView2::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	CMDISampleDoc* pDoc = GetDocument();
	GetDlgItem(IDC_STATIC_1)->SetWindowText("这里是窗体视图CView2，文档内容=" + pDoc->m_Data);
}
