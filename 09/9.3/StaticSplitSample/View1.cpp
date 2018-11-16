// View1.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitSample.h"
#include "View1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView1

IMPLEMENT_DYNCREATE(CView1, CEditView)

CView1::CView1()
{
}

CView1::~CView1()
{
}


BEGIN_MESSAGE_MAP(CView1, CEditView)
	//{{AFX_MSG_MAP(CView1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView1 drawing

void CView1::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
}

/////////////////////////////////////////////////////////////////////////////
// CView1 diagnostics

#ifdef _DEBUG
void CView1::AssertValid() const
{
	CEditView::AssertValid();
}

void CView1::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView1 message handlers

void CView1::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();	
	this->GetEditCtrl().SetWindowText("这里是EditView类型的View1");
}
