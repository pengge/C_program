// View3.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitSample.h"
#include "View3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView3

IMPLEMENT_DYNCREATE(CView3, CScrollView)

CView3::CView3()
{
}

CView3::~CView3()
{
}


BEGIN_MESSAGE_MAP(CView3, CScrollView)
	//{{AFX_MSG_MAP(CView3)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView3 drawing

void CView3::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	
}

void CView3::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOut(0,0,"这里是ScrollView类型的View3");
}

/////////////////////////////////////////////////////////////////////////////
// CView3 diagnostics

#ifdef _DEBUG
void CView3::AssertValid() const
{
	CScrollView::AssertValid();
}

void CView3::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView3 message handlers
