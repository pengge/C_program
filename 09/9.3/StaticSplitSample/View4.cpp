// View4.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitSample.h"
#include "View4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView4

IMPLEMENT_DYNCREATE(CView4, CListView)

CView4::CView4()
{
}

CView4::~CView4()
{
}


BEGIN_MESSAGE_MAP(CView4, CListView)
	//{{AFX_MSG_MAP(CView4)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView4 drawing

void CView4::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CView4 diagnostics

#ifdef _DEBUG
void CView4::AssertValid() const
{
	CListView::AssertValid();
}

void CView4::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView4 message handlers

void CView4::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	this->GetListCtrl().InsertItem(0, "这里是ListView的View4");
}
