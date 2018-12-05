// GDIControlView.cpp : implementation of the CGDIControlView class
//
#define UNICODE
#include "stdafx.h"
#include "GDIControl.h"

#include "GDIControlDoc.h"
#include "GDIControlView.h"
#include "winuser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIControlView

IMPLEMENT_DYNCREATE(CGDIControlView, CView)

BEGIN_MESSAGE_MAP(CGDIControlView, CView)
	//{{AFX_MSG_MAP(CGDIControlView)
	ON_COMMAND(ID_MENUITEM_DRAWLINEONIMAGE, OnMenuitemDrawlineonimage)
	ON_COMMAND(ID_MENUITEM_DRAWNETLINEONIMAGE, OnMenuitemDrawnetlineonimage)
	ON_COMMAND(ID_MENUITEM_OPENHIGHIMAGE, OnMenuitemOpenhighimage)
	ON_COMMAND(ID_MENUITEM_SCREENCOPY, OnMenuitemScreencopy)
	ON_COMMAND(ID_MENUITEM_SCREENCUT, OnMenuitemScreencut)
	ON_COMMAND(ID_MENUITEM_SHOWWORD, OnMenuitemShowword)
	ON_COMMAND(ID_MENUITEM_GETRGB, OnMenuitemGetrgb)
	ON_COMMAND(ID_MENUITEM_DRAG, OnMenuitemDrag)
	ON_COMMAND(ID_MENUITEM_CUTELLIPCONTENT, OnMenuitemCutellipcontent)
	ON_COMMAND(ID_MENUITEM_SAVEELLIPCONTENT, OnMenuitemSaveellipcontent)
	ON_COMMAND(ID_MENUITEM_SHIMAGE, OnMenuitemShimage)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIControlView construction/destruction

CGDIControlView::CGDIControlView()
{
	// TODO: add construction code here
	hThread = 0;
	bSelectedImage = FALSE;
}

CGDIControlView::~CGDIControlView()
{
	if (hThread)	
	{
		TerminateThread(hThread, NULL);
		CloseHandle(hThread);
	}
}

BOOL CGDIControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGDIControlView drawing

void CGDIControlView::OnDraw(CDC* pDC)
{
	CGDIControlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGDIControlView printing

BOOL CGDIControlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIControlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIControlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGDIControlView diagnostics

#ifdef _DEBUG
void CGDIControlView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIControlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIControlDoc* CGDIControlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIControlDoc)));
	return (CGDIControlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIControlView message handlers

//在图片上绘制线条
void CGDIControlView::OnMenuitemDrawlineonimage() 
{
	Graphics graphics(m_hWnd);	
	Image image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	Rect destRect(width+20, 10, width, height);	
	graphics.DrawImage(&image, 10, 10, width, height);
	graphics.DrawImage(&image, destRect, 0, 0, width, height, UnitPixel);
	Pen pen(Color(255, 255, 0, 0), 3);
	int nLineCount = 18;
	int h = height/(nLineCount-1);
	for (int i = 0;i <nLineCount; i++)
	{		
		graphics.DrawLine(&pen, width+20, h*i+10, width*2 + 20, h*i+10);
	}
}

//在图片上绘制网格
void CGDIControlView::OnMenuitemDrawnetlineonimage() 
{	
	Graphics graphics(m_hWnd);	
	Image image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	Rect destRect(width+20, 10, width, height);	
	graphics.DrawImage(&image, 10, 10, width, height);
	graphics.DrawImage(&image, destRect, 0, 0, width, height, UnitPixel);
	Pen pen(Color(255, 255, 0, 0), 3);
	int nXCount = 18;
	int nYCount  = 18;
	int h = height/(nXCount-1);
	for (int i = 0;i <nXCount; i++)
	{		
		graphics.DrawLine(&pen, width+20, h*i+10, width*2 + 20, h*i+10);
	}
	int w = width/(nYCount-1);
	for ( int i = 0;i <nYCount; i++)
	{		
		graphics.DrawLine(&pen, w*i+20+width, 10, w*i+20+width, 10+height);
	}
}

//打开高颜色质量图像
void CGDIControlView::OnMenuitemOpenhighimage() 
{
	Graphics graphics(m_hWnd);	
	Image image(L"baby.JPG");
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();

	graphics.SetInterpolationMode(InterpolationModeHighQualityBicubic);
	graphics.DrawImage(&image, 10, 10, width, height);

	graphics.SetInterpolationMode(InterpolationModeNearestNeighbor);
	graphics.DrawImage(&image, width + 20, 10, width, height);	
}

//在视图中拖动图片
void CGDIControlView::OnMenuitemDrag() 
{
	OperType = 3;
	Graphics graphics(m_hWnd);
	graphics.Clear(Color::White);
	graphics.SetSmoothingMode(SmoothingModeAntiAlias);
	Bitmap image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	graphics.DrawImage(&image, 0, 0, width, height);
	rect.left = 0;
	rect.top = 0;
	rect.right = width;
	rect.bottom = height;
}

//屏幕截图
void CGDIControlView::OnMenuitemScreencut() 
{
	int cx = GetSystemMetrics(SM_CXSCREEN);   
    int cy = GetSystemMetrics(SM_CYSCREEN);   
	HDC hScrDC = CreateDC("DISPLAY",   NULL,   NULL,   NULL); 
	Graphics graphics1(hScrDC);
	Bitmap  bitmap(cx, cy, &graphics1);   
	Graphics graphics2(&bitmap);

	HDC dc1 = graphics1.GetHDC();
	HDC dc2 = graphics2.GetHDC();
   
	BitBlt(dc2, 0, 0, cx, cy, dc1, 0, 0, 13369376);
	graphics1.ReleaseHDC(dc1);
	graphics2.ReleaseHDC(dc2);

	Graphics graphics(m_hWnd);	
	UINT width = bitmap.GetWidth();
	UINT height = bitmap.GetHeight();
	graphics.DrawImage(&bitmap, 0, 0, width, height);	
}

//保存屏幕图像到剪贴板
void CGDIControlView::OnMenuitemScreencopy() 
{
	CDC* pDC = GetDC();
	int cx = GetSystemMetrics(SM_CXSCREEN);   
    int cy = GetSystemMetrics(SM_CYSCREEN);   
	HDC hScrDC = CreateDC("DISPLAY",   NULL,   NULL,   NULL); 
	HBITMAP hBitmap = CreateCompatibleBitmap(hScrDC, cx, cy);  
	HGLOBAL hGlobal =(HGLOBAL)(UINT)hBitmap;
	OpenClipboard();
	SetClipboardData(MF_BITMAP, (HANDLE)hGlobal);
	CloseClipboard();
}

//获取图像RGB值
void CGDIControlView::OnMenuitemGetrgb() 
{
	Graphics graphics(m_hWnd);	
	Bitmap image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	graphics.DrawImage(&image, 0, 30, width, height);
	Color color;
	image.GetPixel(width/2, height/2, &color);
	CString log;
	log.Format("图像中心点的颜色值为：Alpha=%d;Red=%d;Green=%d;Blue=%d", 
		color.GetAlpha(), color.GetRed(), color.GetGreen(), color.GetBlue());
	CDC* pDC = GetDC();
	pDC->TextOut(0, 0, log);
}

//显示Word艺术字
void CGDIControlView::OnMenuitemShowword() 
{
	Graphics graphics(m_hWnd);	
	SolidBrush backBrush(Color(255, 255, 255, 0));
	SolidBrush foreBrush(Color(255, 255, 0, 0));

	FontFamily fontFamily(L"幼圆");
	Font font(&fontFamily, 40, FontStyleRegular, UnitPixel);

	PointF point1(42, 2);
	PointF point2(40, 0);

	graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);
	graphics.RotateTransform(30.0f);
	graphics.DrawString(L"艺术字", -1, &font, point1, &foreBrush);
	graphics.DrawString(L"艺术字", -1, &font, point2, &backBrush);
}

//渐隐渐显的图像
DWORD WINAPI ThreadShimageFunc( LPVOID lpParam ) 
{	
    Graphics graphics((HWND)lpParam);	
	graphics.SetSmoothingMode(SmoothingModeAntiAlias);
	Bitmap image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	
	TextureBrush brush(&image);
	graphics.FillRectangle(&brush, Rect(0,0,width,height));
	for (int i = 0; i < 255; i++)
	{//渐隐
		SolidBrush solidBrush(Color(i,0xA9,0xA9, 0xA9));
		graphics.FillRectangle(&solidBrush, Rect(0,0,width,height));
		Sleep(100);
	} 
	
	graphics.Clear(Color::White);	
	for (int i = 0; i <255; i++)
	{//渐现		
		
		Color color, colorTemp;
		for(INT iRow = 0; iRow < (INT)height; iRow++)
		{
			for(INT iColumn = 0; iColumn < (INT)width; iColumn++)
			{
				image.GetPixel(iColumn, iRow, &color);	
				colorTemp.SetValue(color.MakeARGB(i, color.GetRed(),color.GetGreen(), color.GetBlue()));
				image.SetPixel(iColumn, iRow, colorTemp);			
			}
		}
		graphics.DrawImage(&image, 0, 0, width, height);	
		Sleep(100);
	} 	
    return 0; 
}  

void CGDIControlView::OnMenuitemShimage() 
{
	DWORD dwThreadId;    
    hThread = CreateThread(NULL,0, (LPTHREAD_START_ROUTINE)ThreadShimageFunc, (LPVOID)m_hWnd, 0, &dwThreadId); 	
}

//保留椭圆下图片内容
void CGDIControlView::OnMenuitemSaveellipcontent() 
{
	Graphics graphics(m_hWnd);	
	Image image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	graphics.DrawImage(&image, 0, 0, width, height);
	OperType = 1;
}

//去除椭圆下的图片内容
void CGDIControlView::OnMenuitemCutellipcontent() 
{
	Graphics graphics(m_hWnd);	
	Image image(L"baby.JPG");	
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	graphics.DrawImage(&image, 0, 0, width, height);
	OperType = 2;
}

void CGDIControlView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	beginPoint = point;	
	if(OperType == 3)
	{
		Graphics graphics(m_hWnd);
		Region region(Rect(rect.left, rect.top, rect.right, rect.bottom));
		PointF backPoint((float)point.x, (float)point.y);
		if(region.IsVisible(backPoint, &graphics))
		{
			bSelectedImage = TRUE;
			forePoint.x = point.x;
			forePoint.y = point.y;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}

//鼠标抬起事件
void CGDIControlView::OnLButtonUp(UINT nFlags, CPoint point) 
{	
	endPoint = point;
	if (OperType == 1)
	{//保留椭圆中的内容
		Graphics graphics(m_hWnd);
		graphics.Clear(Color::White);
		GraphicsPath path;
		path.AddEllipse(beginPoint.x, beginPoint.y, 
			(endPoint.x-beginPoint.x), (endPoint.y-beginPoint.y));
		Region region(&path);
		Pen pen(Color(255, 0, 0, 255));
		graphics.DrawPath(&pen, &path);
		graphics.SetClip(&region);
		Image image(L"baby.JPG");	
		UINT width = image.GetWidth();
		UINT height = image.GetHeight();
		graphics.DrawImage(&image, 0, 0, width, height);
		OperType = 0;
	}
	else if (OperType == 2)
	{//去除椭圆中的内容
		Graphics graphics(m_hWnd);
		graphics.Clear(Color::White);

		CRect rect;
		GetClientRect(&rect);
		Region region1(Rect(rect.left, rect.top, rect.right, rect.bottom));

		GraphicsPath path;
		path.AddEllipse(beginPoint.x, beginPoint.y, 
			(endPoint.x-beginPoint.x), (endPoint.y-beginPoint.y));
		Region region2(&path);
		
		region1.Exclude(&region2);
		Pen pen(Color(255, 0, 0, 255));
		graphics.DrawPath(&pen, &path);
		graphics.SetClip(&region1);
		Image image(L"baby.JPG");	
		UINT width = image.GetWidth();
		UINT height = image.GetHeight();
		graphics.DrawImage(&image, 0, 0, width, height);
		OperType = 0;
	}
	else if (OperType == 3)
	{//拖动图片
		if (bSelectedImage)
		{
			bSelectedImage = FALSE;
			Graphics graphics(m_hWnd);
			graphics.Clear(Color::White);
			Image image(L"baby.JPG");	
			UINT width = image.GetWidth();
			UINT height = image.GetHeight();
			int offX = point.x - forePoint.x;
			int offY = point.y - forePoint.y;
			rect.left += offX;
			rect.top += offY;
			graphics.DrawImage(&image, rect.left, rect.top, width, height);			
		}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CGDIControlView::OnMouseMove(UINT nFlags, CPoint point) 
{
	
	CView::OnMouseMove(nFlags, point);
}

void CGDIControlView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
}
