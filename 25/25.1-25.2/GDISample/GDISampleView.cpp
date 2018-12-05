// GDISampleView.cpp : implementation of the CGDISampleView class
//

#include "stdafx.h"
#include "GDISample.h"
#include "GDISampleDoc.h"
#include "GDISampleView.h"
#include "DlgEllip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDISampleView

IMPLEMENT_DYNCREATE(CGDISampleView, CView)

BEGIN_MESSAGE_MAP(CGDISampleView, CView)
	//{{AFX_MSG_MAP(CGDISampleView)
	ON_COMMAND(ID_MENUITEM_BRUSH, OnMenuitemBrush)
	ON_COMMAND(ID_MENUITEM_PEN, OnMenuitemPen)
	ON_COMMAND(ID_MENUITEM_BITMAP, OnMenuitemBitmap)
	ON_COMMAND(ID_MENUITEM_REGION, OnMenuitemRegion)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDISampleView construction/destruction

CGDISampleView::CGDISampleView()
{
	// TODO: add construction code here

}

CGDISampleView::~CGDISampleView()
{
}

BOOL CGDISampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGDISampleView drawing

void CGDISampleView::OnDraw(CDC* pDC)
{
	CGDISampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGDISampleView printing

BOOL CGDISampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDISampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDISampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGDISampleView diagnostics

#ifdef _DEBUG
void CGDISampleView::AssertValid() const
{
	CView::AssertValid();
}

void CGDISampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDISampleDoc* CGDISampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDISampleDoc)));
	return (CGDISampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDISampleView message handlers
// »­Ë¢»æÍ¼ÊµÀý
void CGDISampleView::OnMenuitemBrush() 
{
	CDC* pDC = GetDC();	
	CBrush newBrush; 
    if( newBrush.CreateSolidBrush(RGB(0,255,0)))
    {        
		RECT rect;
		GetClientRect(&rect);		
		CRgn rgn;
		rgn.CreateEllipticRgn(rect.left+10,rect.top, rect.right-10,rect.bottom); 
		pDC->FillRgn(&rgn, &newBrush);			
    }
    else
        MessageBox("´´½¨»­Ë¢Ê§°Ü£¡"); 
}

// »­±Ê»æÍ¼ÊµÀý
void CGDISampleView::OnMenuitemPen() 
{
	CDC* pDC = GetDC();	
	CPen newPen; 
    if( newPen.CreatePen( PS_SOLID, 2, RGB(255,0,0) ) )
    {
        CPen* pOldPen = pDC->SelectObject( &newPen );
		RECT rect;
		GetClientRect(&rect);		
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.right, rect.bottom);        
		pDC->SelectObject( pOldPen );		
    }
    else
        MessageBox("´´½¨»­±ÊÊ§°Ü£¡"); 
}

// Î»Í¼ÊµÀý
void CGDISampleView::OnMenuitemBitmap() 
{
	CBitmap bitmap;
	CDC *pDC = GetDC();
	bitmap.LoadBitmap(IDB_BITMAP_FACE);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bitmap);

	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CRect rect;
	GetClientRect(&rect);
    pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 
		0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY); 
    memDC.DeleteDC();  
    ::DeleteObject(&bitmap); 
}

// ÇøÓòÊµÀý
void CGDISampleView::OnMenuitemRegion() 
{
	CDlgEllip dlg;
	dlg.DoModal();
}
