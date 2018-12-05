// DrawPictureSampleView.cpp : implementation of the CDrawPictureSampleView class
//

#include "stdafx.h"
#include "DrawPictureSample.h"

#include "DrawPictureSampleDoc.h"
#include "DrawPictureSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleView

IMPLEMENT_DYNCREATE(CDrawPictureSampleView, CView)

BEGIN_MESSAGE_MAP(CDrawPictureSampleView, CView)
	//{{AFX_MSG_MAP(CDrawPictureSampleView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MENUITEM_DRAW_LINE, OnMenuitemDrawLine)
	ON_COMMAND(ID_MENUITEM_DRAW_RECT, OnMenuitemDrawRect)
	ON_COMMAND(ID_MENUITEM_ARROW, OnMenuitemArrow)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleView construction/destruction

CDrawPictureSampleView::CDrawPictureSampleView()
{
	// TODO: add construction code here
		
}

CDrawPictureSampleView::~CDrawPictureSampleView()
{
	
}

BOOL CDrawPictureSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleView drawing

void CDrawPictureSampleView::OnDraw(CDC* pDC)
{
	CDrawPictureSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleView printing

BOOL CDrawPictureSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawPictureSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawPictureSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleView diagnostics

#ifdef _DEBUG
void CDrawPictureSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawPictureSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawPictureSampleDoc* CDrawPictureSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawPictureSampleDoc)));
	return (CDrawPictureSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleView message handlers

void CDrawPictureSampleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	ptBegin.x = point.x;
	ptBegin.y = point.y;	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawPictureSampleView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CDC* pDC = GetDC();	
	if (type == 1)
	{
		hPen = CreatePen(PS_SOLID,8, RGB(255,0,255));		
		pDC->SelectObject(hPen);		
		ptEnd.x = point.x;
		ptEnd.y = point.y;
		pDC->MoveTo(ptBegin.x, ptBegin.y);
		pDC->LineTo(ptEnd.x, ptEnd.y);
		DeleteObject(hPen);
		DeleteDC(pDC->m_hDC);
	}
	else if (type == 2)
	{
		hPen = CreatePen(PS_SOLID,5,RGB(0,255,0));
		hBrush = CreateSolidBrush(RGB(125, 125, 0)); 
		pDC->SelectObject(hPen);
		pDC->SelectObject(hBrush);
		ptEnd.x = point.x;
		ptEnd.y = point.y;	
		Rectangle(pDC->m_hDC,ptBegin.x, ptBegin.y, ptEnd.x, ptEnd.y);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		DeleteDC(pDC->m_hDC);
	}
	CView::OnLButtonUp(nFlags, point);
}


//绘制直线
void CDrawPictureSampleView::OnMenuitemDrawLine() 
{
	type = 1;	
}

//绘制矩形
void CDrawPictureSampleView::OnMenuitemDrawRect() 
{
	type = 2;
}

//箭头
void CDrawPictureSampleView::OnMenuitemArrow() 
{
	type = 0;
}
