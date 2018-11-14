// toolbarSampleView.cpp : implementation of the CToolbarSampleView class
//

#include "stdafx.h"
#include "toolbarSample.h"

#include "toolbarSampleDoc.h"
#include "toolbarSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleView

IMPLEMENT_DYNCREATE(CToolbarSampleView, CView)

BEGIN_MESSAGE_MAP(CToolbarSampleView, CView)
	//{{AFX_MSG_MAP(CToolbarSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleView construction/destruction

CToolbarSampleView::CToolbarSampleView()
{
	// TODO: add construction code here

}

CToolbarSampleView::~CToolbarSampleView()
{
}

BOOL CToolbarSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleView drawing

void CToolbarSampleView::OnDraw(CDC* pDC)
{
	CToolbarSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleView printing

BOOL CToolbarSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CToolbarSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CToolbarSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleView diagnostics

#ifdef _DEBUG
void CToolbarSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CToolbarSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolbarSampleDoc* CToolbarSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolbarSampleDoc)));
	return (CToolbarSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleView message handlers
