// CavsSampleView.cpp : implementation of the CCavsSampleView class
//

#include "stdafx.h"
#include "CavsSample.h"

#include "CavsSampleDoc.h"
#include "CavsSampleView.h"
#include "GdiPlus.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleView

IMPLEMENT_DYNCREATE(CCavsSampleView, CView)

BEGIN_MESSAGE_MAP(CCavsSampleView, CView)
	//{{AFX_MSG_MAP(CCavsSampleView)
	ON_COMMAND(ID_MENUITEM_DRAWBEZIER, OnMenuitemDrawbezier)
	ON_COMMAND(ID_MENUITEM_WONIULINE, OnMenuitemWoniuline)
	ON_COMMAND(ID_MENUITEM_SINLINE, OnMenuitemSinline)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleView construction/destruction

CCavsSampleView::CCavsSampleView()
{

}

CCavsSampleView::~CCavsSampleView()
{
}

BOOL CCavsSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleView drawing

void CCavsSampleView::OnDraw(CDC* pDC)
{
	CCavsSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here	

	/*Graphics graphics( pDC->m_hDC );

	GraphicsPath path; // 构造一个路径
	path.AddEllipse(50, 50, 200, 100);

	// 使用路径构造一个画刷
	PathGradientBrush pthGrBrush(&path);

	// 将路径中心颜色设为蓝色
	pthGrBrush.SetCenterColor(Color(255, 0, 0, 255));

	// 设置路径周围的颜色为蓝芭，但alpha值为0
	Color colors[] = {Color(0, 0, 0, 255)};
	INT count = 1;
	pthGrBrush.SetSurroundColors(colors, &count);

	graphics.FillRectangle(&pthGrBrush, 50, 50, 200, 100);

	LinearGradientBrush linGrBrush(
		Point(300, 50),
		Point(500, 150),
		Color(255, 255, 0, 0), // 红色
		Color(255, 0, 0, 255)); // 蓝色

	graphics.FillRectangle(&linGrBrush, 300, 50, 200, 100);*/

}

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleView printing

BOOL CCavsSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCavsSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCavsSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleView diagnostics

#ifdef _DEBUG
void CCavsSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CCavsSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCavsSampleDoc* CCavsSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCavsSampleDoc)));
	return (CCavsSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleView message handlers

//绘制蜗牛线
void CCavsSampleView::OnMenuitemWoniuline() 
{
	float pi = 3.1415926f;	
	CRect rect;
	GetClientRect(&rect);
	UINT width = rect.Width();
	UINT height = rect.Height();
	CDC* pDC = GetDC();
	for (float x = 0;x < 10*pi; x+= pi/width)
	{
		if (x == 0) pDC->SetPixel(width/2, 0, RGB(255,0,0));
		else pDC->SetPixel((int)(width*sin(x)/x*cos(x)+width/2), (int)(width*sin(x)/x*sin(x)),RGB(255,0,0));
	}
}

// 绘制贝塞尔曲线
void CCavsSampleView::OnMenuitemDrawbezier() 
{
	CDC* pDC = GetDC();	
	CPoint pt[] = { CPoint(40, 72),	CPoint(107, 302), 
		CPoint(329, 292),  
		CPoint(79, 148), 
		CPoint(498, 29),  
		CPoint(322, 201),  
		CPoint(176, 137) };
	pDC->PolyBezier(pt, sizeof(pt)/sizeof(pt[0]));
}

//绘制正弦曲线
void CCavsSampleView::OnMenuitemSinline() 
{
	float pi = 3.1415926f;
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
        return;	
	CRect rect;
	GetClientRect(&rect);
	UINT width = rect.Width();
	UINT height = rect.Height();

	Pen bluePen(Color(255, 0, 0, 255), 1);//绘制中心线
	graphics.DrawLine(&bluePen, 0, height/2, width, height/2);
	
	Pen redPen(Color(255, 255, 0, 0), 2);//绘制正弦曲线

	float oldX = 0.0f;
	float oldY=(float)(width/2);
	for (float x = 0;x < width;x++)
	{
		float radian = x/width*10*pi;
		float y = (float)sin(radian);		
		y = (1-y)*height/2;
		graphics.DrawLine(&redPen, oldX, oldY, x, y);
		oldX = x;
		oldY = y;
	}	
}
