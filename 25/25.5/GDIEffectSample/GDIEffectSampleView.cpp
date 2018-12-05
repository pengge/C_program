// GDIEffectSampleView.cpp : implementation of the CGDIEffectSampleView class
//

#include "stdafx.h"
#include "GDIEffectSample.h"

#include "GDIEffectSampleDoc.h"
#include "GDIEffectSampleView.h"
#include "Afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleView

IMPLEMENT_DYNCREATE(CGDIEffectSampleView, CView)

BEGIN_MESSAGE_MAP(CGDIEffectSampleView, CView)
	//{{AFX_MSG_MAP(CGDIEffectSampleView)
	ON_COMMAND(ID_MENUITEM_RESERVE, OnMenuitemReserve)
	ON_COMMAND(ID_MENUITEM_RESIZE, OnMenuitemResize)
	ON_COMMAND(ID_MENUITEM_CUT, OnMenuitemCut)
	ON_COMMAND(ID_MENUITEM_HUIDU, OnMenuitemHuidu)
	ON_COMMAND(ID_MENUITEM_ROUHUA, OnMenuitemRouhua)
	ON_COMMAND(ID_MENUITEM_RUIHUA, OnMenuitemRuihua)
	ON_COMMAND(ID_MENUITEM_FANSE, OnMenuitemFanse)
	ON_COMMAND(ID_MENUITEM_FUDIAO, OnMenuitemFudiao)
	ON_COMMAND(ID_MENUITEM_3DHUI, OnMenuitem3dhui)
	ON_COMMAND(ID_MENUITEM_HBAIYE, OnMenuitemHbaiye)
	ON_COMMAND(ID_MENUITEM_MASAIKE, OnMenuitemMasaike)
	ON_COMMAND(ID_MENUITEM_VBAIYE, OnMenuitemVbaiye)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleView construction/destruction

CGDIEffectSampleView::CGDIEffectSampleView()
{
	// TODO: add construction code here

}

CGDIEffectSampleView::~CGDIEffectSampleView()
{
}

BOOL CGDIEffectSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleView drawing

void CGDIEffectSampleView::OnDraw(CDC* pDC)
{
	CGDIEffectSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleView printing

BOOL CGDIEffectSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIEffectSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIEffectSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleView diagnostics

#ifdef _DEBUG
void CGDIEffectSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIEffectSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIEffectSampleDoc* CGDIEffectSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIEffectSampleDoc)));
	return (CGDIEffectSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleView message handlers

//图像翻转
void CGDIEffectSampleView::OnMenuitemReserve() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	graphics.DrawImage(&image, 10, 0, width, height);
	image.RotateFlip(Rotate180FlipX);
	width = image.GetWidth();
	height = image.GetHeight();
	graphics.DrawImage(&image, 20 + width, 0, width, height);	
}

//图像缩放
void CGDIEffectSampleView::OnMenuitemResize() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	graphics.DrawImage(&image, 0, 0, width, height);
	graphics.DrawImage(&image, width, 0, (int)0.75 * width, (int)0.75 * height);
}

//图片剪切
void CGDIEffectSampleView::OnMenuitemCut() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();	
	Rect destRect1(width+20, 20, 30, 30);	//小范围
	Rect destRect2(width+20, 100, 120, 120); //大范围
	graphics.DrawImage(&image, 0, 0, width, height);//原始图像
	graphics.DrawImage(&image, destRect1, 87, 123, 35, 35, UnitPixel);//缩小剪切
	graphics.SetInterpolationMode(InterpolationModeHighQualityBilinear);
	graphics.DrawImage(&image, destRect2, 87, 123, 35, 35, UnitPixel);//放大剪切
}

//图像锐化处理
void CGDIEffectSampleView::OnMenuitemRuihua() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
        return;
	Bitmap oldBitmap(L"girl.JPG");
	status = oldBitmap.GetLastStatus();
	if (status != Ok)
        return;	
	
	UINT width = oldBitmap.GetWidth();
	UINT height = oldBitmap.GetHeight();
	Bitmap newBitmap(width, height);
	Color pixel1, pixel2, pixel;
	graphics.DrawImage(&oldBitmap, 10, 0, width, height);
	
	int Laplacian[] ={ -1, -1, -1, -1, 9, -1, -1, -1, -1 };//拉普拉斯模板
	for (int x = 1; x < (int)width - 1; x++)
	{
		for (int y = 1; y < (int)height - 1; y++)
		{
			int r = 0, g = 0, b = 0;
			int Index = 0;
			for (int col = -1; col <= 1; col++)
			for (int row = -1; row <= 1; row++)
			{
				oldBitmap.GetPixel(x + row, y + col, &pixel); 
				r += pixel.GetRed() * Laplacian[Index];
				g += pixel.GetGreen() * Laplacian[Index];
				b += pixel.GetBlue() * Laplacian[Index];
				Index++;
			}
		
			if ( r > 255 ) r = 255;
			else if ( r < 0 ) r = -r;
			if ( g > 255 ) g = 255;
			else if ( g < 0 ) g = -g;
			if ( b > 255 ) b = 255;
			else if ( b < 0 ) b = -b;

			pixel.SetFromCOLORREF(RGB(r, g, b));
			newBitmap.SetPixel(x - 1, y - 1, pixel);
		}
	}
	graphics.DrawImage(&newBitmap, width+20, 0, width, height);
}


//图像柔化处理
void CGDIEffectSampleView::OnMenuitemRouhua() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Bitmap oldBitmap(L"girl.JPG");
	status = oldBitmap.GetLastStatus();
	if (status != Ok) return;	
	
	UINT width = oldBitmap.GetWidth();
	UINT height = oldBitmap.GetHeight();
	Bitmap newBitmap(width, height);
	Color pixel1, pixel2, pixel;
	graphics.DrawImage(&oldBitmap, 10, 0, width, height);

	int smoothGauss[9] = {1,2,1,2,4,2,1,2,1}; // 高斯模板
	for (int x = 1; x < (int)width - 1; x++)
	{
		for (int y = 1; y < (int)height - 1; y++)
		{
			int r = 0, g = 0, b = 0;
			int Index = 0;
			for (int col = -1; col <= 1; col++)
			for (int row = -1; row <= 1; row++)
			{
				oldBitmap.GetPixel(x + row, y + col, &pixel); 
				r += pixel.GetRed() * smoothGauss[Index];
				g += pixel.GetGreen() * smoothGauss[Index];
				b += pixel.GetBlue() * smoothGauss[Index];
				Index++;
			}

			r = (r/16);
			g = (g/16);
			b = (b/16);
		
			if ( r > 255 ) r = 255;
			else if ( r < 0 ) r = -r;
			if ( g > 255 ) g = 255;
			else if ( g < 0 ) g = -g;
			if ( b > 255 ) b = 255;
			else if ( b < 0 ) b = -b;

			pixel.SetFromCOLORREF(RGB(r, g, b));
			newBitmap.SetPixel(x - 1, y - 1, pixel);
		}
	}
	graphics.DrawImage(&newBitmap, width+20, 0, width, height);	   
}

//图像反色处理
void CGDIEffectSampleView::OnMenuitemFanse() 
{
	//创建反色图像的颜色矩阵
    ColorMatrix colorMatrix = {
			-1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	ImageAttributes imageAttributes;
	Rect destRect1(width+20, 10, width, height);
    imageAttributes.SetColorMatrix(&colorMatrix,ColorMatrixFlagsDefault,ColorAdjustTypeBitmap);
	graphics.DrawImage(&image, 10, 10, width, height);
	graphics.DrawImage(&image, destRect1, 0, 0, width, height, UnitPixel,&imageAttributes);
}

//图像灰度处理
void CGDIEffectSampleView::OnMenuitemHuidu() 
{
	//创建灰度图像的颜色矩阵
    ColorMatrix colorMatrix = {
			0.299f, 0.299f, 0.299f, 0.0f, 0.0f,
			0.587f, 0.587f, 0.587f, 0.0f, 0.0f,
			0.114f, 0.114f, 0.114f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	ImageAttributes imageAttributes;
	Rect destRect1(width+20, 10, width, height);
	imageAttributes.SetColorMatrix(&colorMatrix,ColorMatrixFlagsDefault,ColorAdjustTypeBitmap);
	graphics.DrawImage(&image, 10, 10, width, height);
	graphics.DrawImage(&image, destRect1, 0, 0, width, height, UnitPixel,	&imageAttributes);
}

//图像浮雕效果
void CGDIEffectSampleView::OnMenuitemFudiao() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Bitmap oldBitmap(L"girl.JPG");
	status = oldBitmap.GetLastStatus();
	if (status != Ok) return;	
	
	UINT width = oldBitmap.GetWidth();
	UINT height = oldBitmap.GetHeight();
	Bitmap newBitmap(width, height);
	Color pixel1, pixel2, pixel;

	graphics.DrawImage(&oldBitmap, 10, 0, width, height);

	for (int x = 0; x < (int)width-1; x++)
	{
		for (int y = 0; y < (int)height-1; y++)
		{
			int r = 0, g = 0, b = 0;
			oldBitmap.GetPixel(x, y, &pixel1);
			oldBitmap.GetPixel(x + 1, y + 1, &pixel2);
			r = abs(pixel1.GetRed() - pixel2.GetRed() + 128);
			g = abs(pixel1.GetGreen() - pixel2.GetGreen() + 128);
			b = abs(pixel1.GetBlue() - pixel2.GetBlue() + 128);
			if (r > 255) r = 255;
			if (r < 0) r = 0;
			if (g > 255) g = 255;
			if (g < 0) g = 0;
			if (b > 255) b = 255;
			if (b < 0) b = 0;

			pixel.SetFromCOLORREF(RGB(r, g, b));		
			newBitmap.SetPixel(x, y, pixel);
		}
	}
	graphics.DrawImage(&newBitmap, width+20, 0, width, height);
}

//显示3D灰色图像
void CGDIEffectSampleView::OnMenuitem3dhui() 
{
	//创建灰度图像的颜色矩阵
    /*ColorMatrix colorMatrix = {
			0.299f, 0.299f, 0.299f, 0.0f, 0.0f,
			0.587f, 0.587f, 0.587f, 0.0f, 0.0f,
			0.114f, 0.114f, 0.114f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	ImageAttributes imageAttributes;
	Rect destRect1(width+20, 10, width, height);
	imageAttributes.SetColorMatrix(&colorMatrix,ColorMatrixFlagsDefault,ColorAdjustTypeBitmap);
	graphics.DrawImage(&image, 10, 10, width, height);
	graphics.DrawImage(&image, destRect1, 0, 0, width, height, UnitPixel,	&imageAttributes);

	SolidBrush brush(::GetSysColor(COLOR_3DFACE));
	graphics.FillRectangle(&brush, width+20, 10, width, height);


	TextureBrush tBrush1(&image, WrapModeTileFlipXY, ::GetSysColor(COLOR_3DHILIGHT));
	graphics.FillRectangle(&tBrush1, width+21, 11, width, height);	

	SolidBrush solidBrush1(::GetSysColor(COLOR_3DSHADOW));
	graphics.DrawImage(&image, destRect1, 0, 0, width, height, UnitPixel,	&imageAttributes);*/
}

//水平百叶窗显示图片
void CGDIEffectSampleView::OnMenuitemHbaiye() 
{		
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	graphics.Clear(Color::White);
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	int nPixes = 30;
	int nNum = width/nPixes;
	for (int i = 0;i <nPixes; i++)
	{		
		for(int j=0;j<nNum;j++)
		{//分别扫描每条
			Rect destRect1(j*nPixes+i, 0, 1, height);
			graphics.DrawImage(&image, destRect1, j*nPixes+i, 0, 1, height, UnitPixel);
		}
		Sleep(10);	
	}
}

//垂直百叶窗显示图片
void CGDIEffectSampleView::OnMenuitemVbaiye() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	graphics.Clear(Color::White);
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	int nPixes = 15;
	int nNum = width/nPixes;
	for (int i = 0;i <nPixes; i++)
	{		
		for(int j=0;j<nNum;j++)
		{	//分别扫描每条
			Rect destRect1(0, j*nPixes+i, width, 1);
			graphics.DrawImage(&image, destRect1, 0, j*nPixes+i, width, 1, UnitPixel);
		}
		Sleep(50);	
	}
}

//图片马赛克效果
void CGDIEffectSampleView::OnMenuitemMasaike() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok) return;
	graphics.Clear(Color::White);
	Image image(L"girl.JPG");
	status = image.GetLastStatus();
	if (status != Ok) return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	int dw = width / 50;
	int dh = height / 50;

	int points[2500]={0};

	int nCount=0;
	while(nCount < 2500)
	{
		int index = rand()%2500;
		if (points[index] == 0)
		{
			nCount ++;
			points[index] = 1;
			int m = index/50;
			int n = index%50;
			Rect destRect(dw*m, dh*n, (m+1)*dw, (n+1)*dh);
			graphics.DrawImage(&image, destRect, dw*m, dh*n, (m+1)*dw, (n+1)*dh, UnitPixel);			
		}
		Sleep(10);
	}
}


