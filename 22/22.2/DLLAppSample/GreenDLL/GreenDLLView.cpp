// GreenDLLView.cpp : implementation of the CGreenDLLView class
//

#include "stdafx.h"
#include "GreenDLL.h"

#include "GreenDLLDoc.h"
#include "GreenDLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLView

IMPLEMENT_DYNCREATE(CGreenDLLView, CView)

BEGIN_MESSAGE_MAP(CGreenDLLView, CView)
	//{{AFX_MSG_MAP(CGreenDLLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLView construction/destruction

CGreenDLLView::CGreenDLLView()
{
	// TODO: add construction code here

}

CGreenDLLView::~CGreenDLLView()
{
}

BOOL CGreenDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLView drawing

void CGreenDLLView::OnDraw(CDC* pDC)
{
	CGreenDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLView printing

BOOL CGreenDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGreenDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGreenDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLView diagnostics

#ifdef _DEBUG
void CGreenDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CGreenDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGreenDLLDoc* CGreenDLLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGreenDLLDoc)));
	return (CGreenDLLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLView message handlers
