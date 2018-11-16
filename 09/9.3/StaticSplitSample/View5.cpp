// View5.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitSample.h"
#include "View5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView5

IMPLEMENT_DYNCREATE(CView5, CScrollView)

CView5::CView5()
{
}

CView5::~CView5()
{
}


BEGIN_MESSAGE_MAP(CView5, CScrollView)
	//{{AFX_MSG_MAP(CView5)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView5 drawing

void CView5::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CView5::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOut(0,0, "这里是ScrollView类型的View5");
}

/////////////////////////////////////////////////////////////////////////////
// CView5 diagnostics

#ifdef _DEBUG
void CView5::AssertValid() const
{
	CScrollView::AssertValid();
}

void CView5::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView5 message handlers
