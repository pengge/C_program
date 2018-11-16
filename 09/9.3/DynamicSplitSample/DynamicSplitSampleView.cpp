// DynamicSplitSampleView.cpp : implementation of the CDynamicSplitSampleView class
//

#include "stdafx.h"
#include "DynamicSplitSample.h"

#include "DynamicSplitSampleDoc.h"
#include "DynamicSplitSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleView

IMPLEMENT_DYNCREATE(CDynamicSplitSampleView, CView)

BEGIN_MESSAGE_MAP(CDynamicSplitSampleView, CView)
	//{{AFX_MSG_MAP(CDynamicSplitSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleView construction/destruction

CDynamicSplitSampleView::CDynamicSplitSampleView()
{
	// TODO: add construction code here

}

CDynamicSplitSampleView::~CDynamicSplitSampleView()
{
}

BOOL CDynamicSplitSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleView drawing

void CDynamicSplitSampleView::OnDraw(CDC* pDC)
{
	CDynamicSplitSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(0, 0, "这是被分割的对话框-_-");
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleView printing

BOOL CDynamicSplitSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDynamicSplitSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDynamicSplitSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleView diagnostics

#ifdef _DEBUG
void CDynamicSplitSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CDynamicSplitSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDynamicSplitSampleDoc* CDynamicSplitSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynamicSplitSampleDoc)));
	return (CDynamicSplitSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleView message handlers
