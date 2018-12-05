// GDIBaseSampleView.cpp : implementation of the CGDIBaseSampleView class
//
#define UNICODE
#include "stdafx.h"
#include "GDIBaseSample.h"
#include "GDIBaseSampleDoc.h"
#include "GDIBaseSampleView.h"
#include "wingdi.h"
#include <math.h>
#include <windows.h>
#include "gdiplus.h"
#include <stdio.h>
using namespace Gdiplus;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleView

IMPLEMENT_DYNCREATE(CGDIBaseSampleView, CView)

BEGIN_MESSAGE_MAP(CGDIBaseSampleView, CView)
	//{{AFX_MSG_MAP(CGDIBaseSampleView)
	ON_COMMAND(ID_MENUITEM_BMPBRUSH, OnMenuitemBmpbrush)
	ON_COMMAND(ID_MENUITEM_FILL_RECT, OnMenuitemFillRect)
	ON_COMMAND(ID_MENUITEM_GEOMETRICPEN, OnMenuitemGeometricpen)
	ON_COMMAND(ID_MENUITEM_DRAW_CROSSLINE, OnMenuitemDrawCrossline)
	ON_COMMAND(ID_MENUITEM_COLORCHANGE, OnMenuitemColorchange)
	ON_COMMAND(ID_MENUITEM_DRAW_COLORCHANGE, OnMenuitemDrawColorchange)
	ON_COMMAND(ID_MENUITEM_SAVEDC, OnMenuitemSavedc)
	ON_COMMAND(ID_MENUITEM_RESTOREDC, OnMenuitemRestoredc)
	ON_COMMAND(ID_MENUITEM_MULTIBRUSH, OnMenuitemMultibrush)
	ON_COMMAND(ID_MENUITEM_SHOWPICCENTER, OnMenuitemShowpiccenter)
	ON_COMMAND(ID_MENUITEM_SAVEMETAFILE, OnMenuitemSavemetafile)
	ON_COMMAND(ID_MENUITEM_OPENMETAFILE, OnMenuitemOpenmetafile)
	ON_COMMAND(ID_MENUITEM_CHEKDIGIT, OnMenuitemChekdigit)
	ON_COMMAND(ID_MENUITEM_CLOCK, OnMenuitemClock)
	ON_COMMAND(ID_MENUITEM_COPYDC, OnMenuitemCopydc)
	ON_COMMAND(ID_MENUITEM_DESIGNFONT, OnMenuitemDesignfont)
	ON_COMMAND(ID_MENUITEM_DRAW3D, OnMenuitemDraw3d)
	ON_COMMAND(ID_MENUITEM_MEMDC, OnMenuitemMemdc)
	ON_COMMAND(ID_MENUITEM_PICTURECOMB, OnMenuitemPicturecomb)
	ON_COMMAND(ID_MENUITEM_SAVESCREENTOFILE, OnMenuitemSavescreentofile)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleView construction/destruction

CGDIBaseSampleView::CGDIBaseSampleView()
{
	// TODO: add construction code here

}

CGDIBaseSampleView::~CGDIBaseSampleView()
{
}

BOOL CGDIBaseSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleView drawing

void CGDIBaseSampleView::OnDraw(CDC* pDC)
{
	CGDIBaseSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleView printing

BOOL CGDIBaseSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIBaseSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIBaseSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleView diagnostics

#ifdef _DEBUG
void CGDIBaseSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIBaseSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIBaseSampleDoc* CGDIBaseSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIBaseSampleDoc)));
	return (CGDIBaseSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleView message handlers
//位图画刷
void CGDIBaseSampleView::OnMenuitemBmpbrush() 
{
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);		
	rect.top = rect.Height()/4;
	rect.bottom = rect.top*3;
	rect.left = rect.Width()/4;
	rect.right = rect.left*3;

	CBitmap bitmap;	
	if (!bitmap.LoadBitmap(IDB_BITMAP_BABY))
        return;//只能载入项目中的位图，要载入外部的使用LoadImage
	CBrush newBrush;
	if (newBrush.CreatePatternBrush(&bitmap))
		pDC->FillRect(&rect, &newBrush);		

}

int   GetEncoderClsid(const   WCHAR*   format,   CLSID*   pClsid)   
{   
	UINT num = 0;
	UINT size = 0;
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);   
	if(size == 0)   return   -1; 
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));   
	if(pImageCodecInfo == NULL)   return -1; 
	GetImageEncoders(num,   size,   pImageCodecInfo);
	for(UINT j=0; j < num; ++j)   
	{   
		if(wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )   
		{   
			*pClsid   =   pImageCodecInfo[j].Clsid;   
			free(pImageCodecInfo);   
			return   j;
		}           
	}
	free(pImageCodecInfo);   
	return   -1; 
}  

//保存屏幕抓图文件
void CGDIBaseSampleView::OnMenuitemSavescreentofile() 
{
	int cx = GetSystemMetrics(SM_CXSCREEN);   
    int cy = GetSystemMetrics(SM_CYSCREEN);   
	HDC hScrDC = CreateDC("DISPLAY",   NULL,   NULL,   NULL); 
	Graphics graphics1(hScrDC);
	Bitmap  bitmap(cx, cy, &graphics1);   
	Graphics graphics2(&bitmap);

	HDC dc1 = graphics1.GetHDC();
	HDC dc2 = graphics2.GetHDC();
   
	BitBlt(dc2,0,0,cx,cy,dc1,0,0,13369376);
	graphics1.ReleaseHDC(dc1);
	graphics2.ReleaseHDC(dc2);

	CLSID clsid;
	char propertyValue[] = "屏幕截图";
	PropertyItem* propertyItem = new PropertyItem;

	GetEncoderClsid(L"image/jpeg", &clsid);
	propertyItem->id = PropertyTagImageTitle;
	propertyItem->length = 16; 
	propertyItem->type = PropertyTagTypeASCII;
	propertyItem->value = propertyValue;
	bitmap.SetPropertyItem(propertyItem);
	bitmap.Save(L"screen.jpg", &clsid, NULL);
	CDC* pDC = GetDC();
	pDC->TextOut(0,0,"保存屏幕抓图到screen.jpg文件");
}

//利用内存画布防止绘图时出现屏幕闪烁
void CGDIBaseSampleView::OnMenuitemMemdc() 
{	
	Bitmap bmp(300, 300);
	Graphics g(&bmp);

	Rect rect(0, 0, 300, 300);
	LinearGradientBrush brush(rect, Color::Green, Color::Blue,LinearGradientModeHorizontal);
		
	
	for(int j = 0; j < 60; j ++)
	{
		for(int i = 0; i < 60; i++)
		{
			g.FillEllipse(&brush, i*5, j*5, 5, 5);
		}
	}
	Graphics graphics(m_hWnd);
	graphics.DrawImage(&bmp, 0, 0);

}

// 几何画笔
void CGDIBaseSampleView::OnMenuitemGeometricpen() 
{
	CDC* pDC= GetDC();	
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID; 
    lb.lbColor = RGB(0,0,255); 
    lb.lbHatch = HS_CROSS; 

	HPEN hPen = ExtCreatePen(PS_GEOMETRIC|PS_ENDCAP_SQUARE|PS_JOIN_ROUND, 10, &lb, 0, NULL); 
	if (hPen == NULL) return;
	CPen newPen;	
    if(newPen.Attach(hPen))
    {        
        CPen* pOldPen = pDC->SelectObject( &newPen );     

		CRect rect;
		GetClientRect(&rect);		
		rect.top = rect.Height()/4;
		rect.bottom = rect.top*3;
		rect.left = rect.Width()/4;
		rect.right = rect.left*3;
		
		pDC->Rectangle(&rect);      
    }
}

//绘制网格
void CGDIBaseSampleView::OnMenuitemDrawCrossline() 
{
	CDC* pDC= GetDC();
	CPen newPen;  
    if( newPen.CreatePen( PS_SOLID, 2, RGB(125,125,125) ) )
    {        
		const int HC = 9;
		const int VC = 9;
        CPen* pOldPen = pDC->SelectObject( &newPen );
		CRect rect;
		GetClientRect(&rect);
		int dx = rect.Width()/(HC-1);   
		int dy = rect.Height()/(VC-1); 		

		CPoint (*Point)[VC] = new CPoint[HC][VC];	
    
		for(int i=0;i<HC;i++)   
		{   
			for(int   j=0;j<VC;j++)   
			{   
				Point[i][j].x =  i*dx;   
				Point[i][j].y =  j*dy;   
			}   
		}   
		for(int i=0;i<HC;i++)   
		{   
			pDC->MoveTo(Point[i][0]);   
			pDC->LineTo(Point[i][VC-1]);   
		}   
		for(int j=0;j<VC;j++)   
		{   
			pDC->MoveTo(Point[0][j]);   
			pDC->LineTo(Point[HC-1][j]);   
		} 		
        pDC->SelectObject( pOldPen );
    }	
}

//创建不同的画刷
void CGDIBaseSampleView::OnMenuitemMultibrush() 
{
	CDC* pDC = GetDC();
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(255, 255, 0));
	CRect rect;
	GetClientRect(&rect);
	int width = rect.Width()/4;
	rect.right = width;
	pDC->FillRect(&rect, &newBrush);
	::DeleteObject((HGDIOBJ)newBrush);

	CBrush newBrush1;
	newBrush1.CreateHatchBrush(HS_CROSS, RGB(0,255,255));//创建纹理画笔
	rect.left += width;
	rect.right += width;
	pDC->FillRect(&rect, &newBrush1);
	::DeleteObject((HGDIOBJ)newBrush1);

	LOGBRUSH logBrush;
	logBrush.lbColor = RGB(255, 0, 255);
	logBrush.lbHatch = HS_HORIZONTAL;
	logBrush.lbStyle = BS_HATCHED;
	CBrush newBrush2;
	newBrush2.CreateBrushIndirect(&logBrush);//创建纹理画笔
	rect.left += width;
	rect.right += width;
	pDC->FillRect(&rect, &newBrush2);
	::DeleteObject((HGDIOBJ)newBrush2);

	CBrush newBrush3;
	newBrush3.CreateSysColorBrush(HS_VERTICAL);
	rect.left += width;
	rect.right += width;
	pDC->FillRect(&rect, &newBrush3);
	::DeleteObject((HGDIOBJ)newBrush3);
}

//填充矩形
void CGDIBaseSampleView::OnMenuitemFillRect() 
{
	CDC* pDC= GetDC();	    
	CBrush backBrush(RGB(255, 128, 128));        
	CRect rect;
	GetClientRect(&rect);		
	rect.top = rect.Height()/4;
	rect.bottom = rect.top*3;
	rect.left = rect.Width()/4;
	rect.right = rect.left*3;	
	pDC->FillRect(&rect, &backBrush);   
}

//模拟时钟
void CGDIBaseSampleView::OnMenuitemClock() 
{
	SetTimer(200, 1000, NULL);
}

// 颜色渐变算法
void CGDIBaseSampleView::OnMenuitemColorchange() 
{
	CDC* pDC= GetDC();
	int  i=0,j=0;   
	for(i=0;i<255;i++)   
	{   
		for(j=0;j<255;j++)   
		{   
			DWORD dwColor = (unsigned long)(0x00000000|0|j<<8|i);
			pDC->SetPixel(i,j,dwColor);			
		}   
	}
}

//绘制渐变颜色
void CGDIBaseSampleView::OnMenuitemDrawColorchange() 
{
	CDC* pDC=GetDC();
	CRect rect;
	GetClientRect(&rect);
	TRIVERTEX vert[2];   
	GRADIENT_RECT gRect; 
	vert[0].x = rect.left;   
	vert[0].y = rect.top;   
	vert[0].Red = 0xff00;   
	vert[0].Green = 0x0000;   
	vert[0].Blue = 0x0000;   
	vert[0].Alpha = 0; 
	vert[1].x = rect.right;   
	vert[1].y = rect.bottom;     
	vert[1].Red = 0x0000;   
	vert[1].Green = 0xff00;   
	vert[1].Blue = 0x0000;   
	vert[1].Alpha = 0;
	gRect.UpperLeft=0;   
	gRect.LowerRight=1;   
	GradientFill(pDC->GetSafeHdc(),vert,2,&gRect,1,GRADIENT_FILL_RECT_H);
}

//绘制立体模型
void CGDIBaseSampleView::OnMenuitemDraw3d() 
{
	Graphics graphics(m_hWnd);   
	

	/*System.Drawing.Drawing2D.GraphicsContainer gCon;
gCon = g.BeginContainer();
Rectangle bound=new Rectangle(50,50,50,50);
GraphicsPath gp = new GraphicsPath();
g.SmoothingMode = SmoothingMode.AntiAlias;
gp.AddRectangle(bound);
g.FillPath(new SolidBrush(Color.Violet),gp);
FillCylinderShadow(g,gp,0.5f,Color.FromArgb(100, 0, 0, 0),Color.FromArgb(100, Color.White));    
gp.Dispose();
g.EndContainer(gCon);
}
public void FillCylinderShadow(Graphics g,GraphicsPath gp,float focus,Color BeginColor,Color EndColor)
{
 
LinearGradientBrush linGrBrush = new LinearGradientBrush(
gp.PathPoints[0],gp.PathPoints[1],
BeginColor,      
EndColor
);   
linGrBrush.SetSigmaBellShape(focus);
g.FillPath(linGrBrush, gp);

linGrBrush.Dispose();
}*/



	Rect rect(50, 50, 300, 300); 
    GraphicsPath   gp;
	graphics.SetSmoothingMode(SmoothingModeAntiAlias);   
	gp.AddEllipse(rect);
	PointF PointCenter((rect.X + rect.Width)/2.0f, (rect.Y + rect.Height)/2.0f); 
	PathGradientBrush brush2(&gp);
	brush2.SetCenterColor(Color(255,255, 0,0)); 
	int count = 1; 
	Color color(255, 255,255,255);
	brush2.SetSurroundColors(&color, &count); 
	brush2.SetCenterPoint(PointCenter); 
	REAL pos[4] = {0.0f, 0.15f, 0.20f, 1.0f}; 
	REAL fac[4] = {0.0f, 0.70f, 1.0f, 1.0f}; 
	brush2.SetBlend(fac, pos, 4);   
	graphics.FillPath(&brush2, &gp);   
		
	
}

//如何设计字型窗体
void CGDIBaseSampleView::OnMenuitemDesignfont() 
{
		
}

//打开图元文件
void CGDIBaseSampleView::OnMenuitemOpenmetafile() 
{	
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
        return;
	Image image(L"MFSample.emf");
	status = image.GetLastStatus();
	if (status != Ok)
        return;
	graphics.DrawImage(&image, 0, 0);
}

//保存图元文件
void CGDIBaseSampleView::OnMenuitemSavemetafile() 
{	
	CDC* pDC = GetDC();
	Status status = GenericError;
	Metafile metafile(L"MFSample.emf", pDC->m_hDC);
	{
		Graphics graphics(&metafile);
		status = graphics.GetLastStatus();
		if (status != Ok) return;

		Pen pen(Color(255, 0, 255, 0));
		status = pen.GetLastStatus();
		if (status != Ok) return;
		
		SolidBrush solidBrush(Color(255, 0, 255, 255));
		status = solidBrush.GetLastStatus();
		if (status != Ok) return;

		CRect rect;
		GetClientRect(&rect);
		int nLeft = (rect.Width())/2;
		int nTop = (rect.Height())/2;

		graphics.DrawRectangle(&pen, Rect(0, 0, nLeft, nTop));
		graphics.FillEllipse(&solidBrush, Rect(nLeft, nTop, nLeft/2, nTop/2));
		graphics.SetSmoothingMode(SmoothingModeHighQuality);	
	}
	Graphics graphics(pDC->m_hDC);
	graphics.DrawImage(&metafile, 0, 0);
}

//图像居中显示
void CGDIBaseSampleView::OnMenuitemShowpiccenter() 
{
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
        return;
	Image image(L"baby.JPG");
	status = image.GetLastStatus();
	if (status != Ok)
        return;

	CRect rect;
	GetClientRect(&rect);
	int nLeft = 10;
	int nTop = 20;

	graphics.DrawImage(&image, nLeft, nTop, rect.Width()-2*nLeft, rect.Height()-2*nTop);	
}

//图片融合效果
void CGDIBaseSampleView::OnMenuitemPicturecomb() 
{
	Graphics  graphics(m_hWnd);   
	Bitmap bg(L"girl1.jpg");   
	int bgWidth = bg.GetWidth();
	int bgHeight = bg.GetHeight();
	graphics.DrawImage(&bg, 0, 0, bgWidth, bgHeight);   
	Bitmap fg(L"girl2.jpg");   
	int   fgWidth = fg.GetWidth();   
	int   fgHeight = fg.GetHeight();   
	//分别设置前景图中的每一个像素的透明度   
	Color color, colorTemp;   
	for(int iRow =0; iRow < fgHeight; iRow++)   
	{   
		for(int iColumn =0; iColumn <fgWidth; iColumn++)   
		{   
			fg.GetPixel(iColumn, iRow, &color);   
			colorTemp.SetValue(color.MakeARGB(150, color.GetRed(),color.GetGreen(),color.GetBlue()));   
			fg.SetPixel(iColumn, iRow, colorTemp);   
		}   
	}   
	graphics.DrawImage(&fg, 0, 0, fgWidth, fgHeight);   
}

//保存设备上下文
void CGDIBaseSampleView::OnMenuitemSavedc() 
{
	CDC* pDC=GetDC();
	CPen newPen;  
    if( newPen.CreatePen( PS_SOLID, 2, RGB(255,0,255) ) )
    {
		int saved = pDC->SaveDC();
		pDC->SelectObject( &newPen );
		CRect rect;
		GetClientRect(&rect);
		pDC->MoveTo(0,0);   
		pDC->LineTo(rect.Width(),rect.Height());  
		pDC->RestoreDC(saved);
		pDC->MoveTo(rect.Width(),0);   
		pDC->LineTo(0,rect.Height());
	}
}

//将设备上下文保存到剪贴板
void CGDIBaseSampleView::OnMenuitemCopydc() 
{
	//暂时删除
}

//恢复设备上下文
void CGDIBaseSampleView::OnMenuitemRestoredc() 
{
	//暂时删除
}

//手写数字识别程序
void CGDIBaseSampleView::OnMenuitemChekdigit() 
{
		
}

void CGDIBaseSampleView::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 200)
	{
		//绘制钟表盘
		Graphics graphics(m_hWnd);
		int width = 300;
		int height = 300;
		Rect outRect(0, 0, width, height); 
		Rect midRect(6, 6, 288, 288); 
		Rect inRect(9, 9, 282, 282); 

		LinearGradientBrush outBrush(outRect, Color(0, 125, 0), Color(0, 255, 0), LinearGradientModeBackwardDiagonal); 
		LinearGradientBrush midBrush(midRect, Color(0, 255, 0), Color(0, 125, 0), LinearGradientModeBackwardDiagonal); 
		LinearGradientBrush inBrush(inRect, Color(0, 125, 0), Color(0, 255, 0), LinearGradientModeBackwardDiagonal); 

		graphics.FillEllipse(&outBrush, outRect); 
		graphics.FillEllipse(&midBrush, midRect); 
		graphics.FillEllipse(&inBrush, inRect); 
		
		//绘制刻度	
		FontFamily fontFamily(L"Arial");
		Font font(&fontFamily, 20, FontStyleBold, UnitPixel); 
		SolidBrush whiteBrush(Color(255,255,255,255)); 
		graphics.DrawString(L"12", -1, &font, PointF(130, 10), &whiteBrush); 
		graphics.DrawString(L"6", -1, &font, PointF(140, 265), &whiteBrush); 
		graphics.DrawString(L"3", -1, &font, PointF(270, 140), &whiteBrush);  
		graphics.DrawString(L"9", -1, &font, PointF(10, 140), &whiteBrush);  
		graphics.DrawString(L"1", -1, &font, PointF(200, 30), &whiteBrush);  
		graphics.DrawString(L"2", -1, &font, PointF(250, 80), &whiteBrush);  
		graphics.DrawString(L"5", -1, &font, PointF(205, 245), &whiteBrush);  
		graphics.DrawString(L"4", -1, &font, PointF(250, 200), &whiteBrush);  
		graphics.DrawString(L"11", -1, &font, PointF(65, 30), &whiteBrush);  
		graphics.DrawString(L"10", -1, &font, PointF(20, 80), &whiteBrush);  
		graphics.DrawString(L"7", -1, &font, PointF(65, 245), &whiteBrush);  
		graphics.DrawString(L"8", -1, &font, PointF(25, 200), &whiteBrush);

		//绘制指针 
		graphics.TranslateTransform(150, 150, MatrixOrderAppend); 
		Pen hourPen(Color(255, 0, 255, 0), 7); //时针
		hourPen.SetLineCap(LineCapRoundAnchor, LineCapArrowAnchor, DashCapFlat); 
		Pen minutePen(Color(255, 0, 0,255), 4); //分针
		minutePen.SetLineCap(LineCapRoundAnchor, LineCapArrowAnchor, DashCapFlat); 
		Pen secondPen(Color(255, 255, 0, 0), 2); //秒针

		CTime time = CTime::GetCurrentTime();
		int sec = time.GetSecond();
		int min = time.GetMinute(); 
		int hour = time.GetHour();  

		const double pi = 3.1415926;
		double secondAngle = 2.0 * pi * sec / 60.0; 
		double minuteAngle = 2.0 * pi * (min + sec / 60.0) / 60.0; 
		double hourAngle = 2.0 * pi * (hour + min / 60.0) / 12.0; 

		Point centre(0, 0); 

		Point hourHand((int)(40 * sin(hourAngle)), (int)(-40 * cos(hourAngle))); 
		graphics.DrawLine(&hourPen, centre, hourHand); 

		Point minHand((int)(80 * sin(minuteAngle)), (int)(-80 * cos(minuteAngle))); 
		graphics.DrawLine(&minutePen, centre, minHand); 

		Point secHand((int)(80 * sin(secondAngle)), (int)(-80 * cos(secondAngle))); 
		graphics.DrawLine(&secondPen, centre, secHand);			
	}
	CView::OnTimer(nIDEvent);
}
