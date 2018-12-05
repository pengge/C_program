// RedDLLView.cpp : implementation of the CRedDLLView class
//

#include "stdafx.h"
#include "RedDLL.h"

#include "RedDLLDoc.h"
#include "RedDLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRedDLLView

IMPLEMENT_DYNCREATE(CRedDLLView, CView)

BEGIN_MESSAGE_MAP(CRedDLLView, CView)
	//{{AFX_MSG_MAP(CRedDLLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRedDLLView construction/destruction

CRedDLLView::CRedDLLView()
{
	// TODO: add construction code here

}

CRedDLLView::~CRedDLLView()
{
}

BOOL CRedDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRedDLLView drawing

void CRedDLLView::OnDraw(CDC* pDC)
{
	CRedDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRedDLLView printing

BOOL CRedDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRedDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRedDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRedDLLView diagnostics

#ifdef _DEBUG
void CRedDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CRedDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRedDLLDoc* CRedDLLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRedDLLDoc)));
	return (CRedDLLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRedDLLView message handlers
