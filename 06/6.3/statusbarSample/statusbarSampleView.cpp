// statusbarSampleView.cpp : implementation of the CStatusbarSampleView class
//

#include "stdafx.h"
#include "statusbarSample.h"

#include "statusbarSampleDoc.h"
#include "statusbarSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleView

IMPLEMENT_DYNCREATE(CStatusbarSampleView, CView)

BEGIN_MESSAGE_MAP(CStatusbarSampleView, CView)
	//{{AFX_MSG_MAP(CStatusbarSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleView construction/destruction

CStatusbarSampleView::CStatusbarSampleView()
{
	// TODO: add construction code here

}

CStatusbarSampleView::~CStatusbarSampleView()
{
}

BOOL CStatusbarSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleView drawing

void CStatusbarSampleView::OnDraw(CDC* pDC)
{
	CStatusbarSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleView printing

BOOL CStatusbarSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatusbarSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatusbarSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleView diagnostics

#ifdef _DEBUG
void CStatusbarSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CStatusbarSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatusbarSampleDoc* CStatusbarSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatusbarSampleDoc)));
	return (CStatusbarSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleView message handlers
