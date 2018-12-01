// FaceAppSampleView.cpp : implementation of the CFaceAppSampleView class
//

#include "stdafx.h"
#include "FaceAppSample.h"

#include "FaceAppSampleDoc.h"
#include "FaceAppSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleView

IMPLEMENT_DYNCREATE(CFaceAppSampleView, CView)

BEGIN_MESSAGE_MAP(CFaceAppSampleView, CView)
	//{{AFX_MSG_MAP(CFaceAppSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleView construction/destruction

CFaceAppSampleView::CFaceAppSampleView()
{
	// TODO: add construction code here

}

CFaceAppSampleView::~CFaceAppSampleView()
{
}

BOOL CFaceAppSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleView drawing

void CFaceAppSampleView::OnDraw(CDC* pDC)
{
	CFaceAppSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleView printing

BOOL CFaceAppSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFaceAppSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFaceAppSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleView diagnostics

#ifdef _DEBUG
void CFaceAppSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CFaceAppSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceAppSampleDoc* CFaceAppSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceAppSampleDoc)));
	return (CFaceAppSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleView message handlers
