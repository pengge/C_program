// StaticSplitSampleView.cpp : implementation of the CStaticSplitSampleView class
//

#include "stdafx.h"
#include "StaticSplitSample.h"

#include "StaticSplitSampleDoc.h"
#include "StaticSplitSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleView

IMPLEMENT_DYNCREATE(CStaticSplitSampleView, CView)

BEGIN_MESSAGE_MAP(CStaticSplitSampleView, CView)
	//{{AFX_MSG_MAP(CStaticSplitSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleView construction/destruction

CStaticSplitSampleView::CStaticSplitSampleView()
{
	// TODO: add construction code here

}

CStaticSplitSampleView::~CStaticSplitSampleView()
{
}

BOOL CStaticSplitSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleView drawing

void CStaticSplitSampleView::OnDraw(CDC* pDC)
{
	CStaticSplitSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleView printing

BOOL CStaticSplitSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticSplitSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticSplitSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleView diagnostics

#ifdef _DEBUG
void CStaticSplitSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CStaticSplitSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStaticSplitSampleDoc* CStaticSplitSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticSplitSampleDoc)));
	return (CStaticSplitSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleView message handlers
