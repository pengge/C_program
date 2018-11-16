// ScrollViewSampleView.cpp : implementation of the CScrollViewSampleView class
//

#include "stdafx.h"
#include "ScrollViewSample.h"

#include "ScrollViewSampleDoc.h"
#include "ScrollViewSampleView.h"
#include "wingdi.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleView

IMPLEMENT_DYNCREATE(CScrollViewSampleView, CScrollView)

BEGIN_MESSAGE_MAP(CScrollViewSampleView, CScrollView)
	//{{AFX_MSG_MAP(CScrollViewSampleView)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleView construction/destruction

CScrollViewSampleView::CScrollViewSampleView()
{
	// TODO: add construction code here
	m_rect = CRect(0, 0, 1024*3, -1024*3 );	 
}

CScrollViewSampleView::~CScrollViewSampleView()
{
}

BOOL CScrollViewSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleView drawing

void CScrollViewSampleView::OnDraw(CDC* pDC)
{
	CScrollViewSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->Ellipse( m_rect );
}

void CScrollViewSampleView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal( 40000, 30000); //逻辑窗口大小
	CSize sizePage( sizeTotal.cx/4, sizeTotal.cy/3 ); 
	CSize sizeLine( sizeTotal.cx/100, sizeTotal.cy/100 );
	SetScrollSizes( MM_HIMETRIC, sizeTotal, sizePage, sizeLine );	
}

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleView printing

BOOL CScrollViewSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CScrollViewSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CScrollViewSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleView diagnostics

#ifdef _DEBUG
void CScrollViewSampleView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CScrollViewSampleView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CScrollViewSampleDoc* CScrollViewSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollViewSampleDoc)));
	return (CScrollViewSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleView message handlers

void CScrollViewSampleView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CScrollViewSampleView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CScrollViewSampleView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    switch( nChar )
    {	
    case VK_UP:			// 向上按键
        OnVScroll( SB_LINEUP, 0, NULL );
        break;
    case VK_DOWN:		// 向下按键
        OnVScroll( SB_LINEDOWN, 0, NULL );
        break;
    case VK_LEFT:		// 向左按键
        OnHScroll( SB_LINELEFT, 0, NULL );
        break;
    case VK_RIGHT:		// 向右按键
        OnHScroll( SB_LINERIGHT, 0, NULL );
        break;
    case VK_PRIOR:		// 上页按键
        OnVScroll( SB_PAGEUP, 0, NULL );
        break;
    case VK_NEXT:		// 下页按键
        OnVScroll( SB_PAGEDOWN, 0, NULL );
        break;	
    case VK_HOME:		// 开始按键
        OnVScroll( SB_TOP, 0, NULL );
        OnHScroll( SB_LEFT, 0, NULL );
        break;
    case VK_END:		// 结束按键
        OnVScroll( SB_BOTTOM, 0, NULL );
        OnHScroll( SB_RIGHT, 0, NULL );
        break;
    default:
        break;
    }	
    CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CScrollViewSampleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc( this );
	OnPrepareDC( &dc );
	CRect rectDevice = m_rect;
	dc.LPtoDP( rectDevice );
	rectDevice.PtInRect( point );	
	InvalidateRect( rectDevice );	
	CScrollView::OnLButtonDown(nFlags, point);
}
