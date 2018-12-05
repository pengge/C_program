// AnimateIconSampleView.cpp : implementation of the CAnimateIconSampleView class
//

#include "stdafx.h"
#include "AnimateIconSample.h"

#include "AnimateIconSampleDoc.h"
#include "AnimateIconSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleView

IMPLEMENT_DYNCREATE(CAnimateIconSampleView, CView)

BEGIN_MESSAGE_MAP(CAnimateIconSampleView, CView)
	//{{AFX_MSG_MAP(CAnimateIconSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleView construction/destruction

CAnimateIconSampleView::CAnimateIconSampleView()
{
	// TODO: add construction code here

}

CAnimateIconSampleView::~CAnimateIconSampleView()
{
}

BOOL CAnimateIconSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleView drawing

void CAnimateIconSampleView::OnDraw(CDC* pDC)
{
	CAnimateIconSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleView printing

BOOL CAnimateIconSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAnimateIconSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAnimateIconSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleView diagnostics

#ifdef _DEBUG
void CAnimateIconSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CAnimateIconSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnimateIconSampleDoc* CAnimateIconSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnimateIconSampleDoc)));
	return (CAnimateIconSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleView message handlers
