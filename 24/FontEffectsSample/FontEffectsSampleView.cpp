// FontEffectsSampleView.cpp : implementation of the CFontEffectsSampleView class
//

#include "stdafx.h"
#include "FontEffectsSample.h"

#include "FontEffectsSampleDoc.h"
#include "FontEffectsSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleView

IMPLEMENT_DYNCREATE(CFontEffectsSampleView, CView)

BEGIN_MESSAGE_MAP(CFontEffectsSampleView, CView)
	//{{AFX_MSG_MAP(CFontEffectsSampleView)
	ON_COMMAND(ID_MENUITEM_ROTATE_FONT, OnMenuitemRotateFont)
	ON_WM_PAINT()
	ON_COMMAND(ID_MENU_KONGXIN_FONT, OnMenuKongxinFont)
	ON_COMMAND(ID_MENUITEM_JIANBIAN_FONT, OnMenuitemJianbianFont)
	ON_COMMAND(ID_MENUITEM_3D_FONT, OnMenuitem3dFont)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleView construction/destruction

CFontEffectsSampleView::CFontEffectsSampleView()
{
	// TODO: add construction code here
	m_iXExtend = 0;  
	m_iYExtend = 0;
}

CFontEffectsSampleView::~CFontEffectsSampleView()
{
}

BOOL CFontEffectsSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleView drawing

void CFontEffectsSampleView::OnDraw(CDC* pDC)
{
	CFontEffectsSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//pDC->TextOut(mousePoint.x, mousePoint.y, "我是鼠标位置");
/*	CRect rc;
	GetClientRect(&rc);
    
    TEXTMETRIC tm;
    pDC->GetTextMetrics(&tm);
    pDC->SetTextAlign(TA_CENTER | TA_TOP);

	CString strText;
	strText.Format("字体高度=%d   字体宽度=%d   斜体=%d   下划线=%d   删除线=%d",
		tm.tmHeight, tm.tmWeight, tm.tmItalic, tm.tmUnderlined, tm.tmStruckOut);
	pDC->TextOut((rc.left + rc.right) / 2, 0, strText); */
}

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleView printing

BOOL CFontEffectsSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFontEffectsSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFontEffectsSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleView diagnostics

#ifdef _DEBUG
void CFontEffectsSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CFontEffectsSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFontEffectsSampleDoc* CFontEffectsSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFontEffectsSampleDoc)));
	return (CFontEffectsSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleView message handlers
// 实现旋转字体
void CFontEffectsSampleView::OnMenuitemRotateFont() 
{
	// TODO: Add your command handler code here	      
	CClientDC dc(this);	// 获得窗口的客户区设备上下文句柄 
	//定义字体属性
	LOGFONT lf;
	lf.lfHeight = 50; 
	lf.lfWidth = 0; 
	lf.lfEscapement = 400; //倾斜40度，十分之一度为单位
	lf.lfOrientation = 0;
	lf.lfItalic = FALSE; 
	lf.lfUnderline = FALSE;
	lf.lfStrikeOut = FALSE;
	lf.lfCharSet = GB2312_CHARSET; 
	strcpy(lf.lfFaceName,"楷书");
	//创建字体
	CFont font;
	font.CreateFontIndirect(&lf);
	//更改当前字体
	CFont *pOldFont  = dc.SelectObject(&font);
	//绘制字体
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,255,0));
	dc.TextOut(10,300,"这里是旋转字体示例");
	//恢复设备上下文的原有设置
	dc.SelectObject(pOldFont);
}

void CFontEffectsSampleView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	//dc.TextOut(mousePoint.x+3, mousePoint.y+3, "欢迎");
	//dc.TextOut(m_iXExtend,m_iYExtend,"水平文字滚动测试");
/*	CRect rc(m_iXExtend, m_iYExtend, m_iXExtend+15, m_iYExtend+150);   
	dc.DrawText("垂直文字滚动测试", &rc, DT_EDITCONTROL|DT_WORDBREAK|DT_CENTER);    */
    CView::OnPaint();
}


// 绘制空心字
void CFontEffectsSampleView::OnMenuKongxinFont() 
{
	// 获得窗口的客户区设备上下文句柄
	CClientDC dc(this);
	// 更改当前字体
	LOGFONT lf;
	dc.GetCurrentFont()->GetLogFont(&lf);
	CFont font;
	CFont *pOldFont; // 保存设备上下文最初使用的字体对象
	lf.lfCharSet=134;
	lf.lfHeight=-80;
	lf.lfWidth=0;
	strcpy(lf.lfFaceName, "宋体");
	font.CreateFontIndirect(&lf);
	pOldFont=dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	// 更改当前画笔
	CPen pen(PS_SOLID, 2, RGB(255, 50, 0));
	CPen *pOldPen;
	pOldPen=dc.SelectObject(&pen);
	// 开始一个路径
	dc.BeginPath();
	dc.TextOut(10, 10, "这里是空心字效果示例");
	dc.EndPath();
	// 绘制路径
	dc.StrokePath();
	// 恢复设备上下文的原有设置
	dc.SelectObject(pOldFont);
	dc.SelectObject(pOldPen);	
}

// 颜色渐变字体
void CFontEffectsSampleView::OnMenuitemJianbianFont() 
{
	// TODO: Add your command handler code here
	// 获得窗口的客户区设备上下文句柄
	CClientDC dc(this);
	// 更改当前字体
	LOGFONT lf;
    dc.GetCurrentFont()->GetLogFont(&lf);
    CFont font, *pOldFont;
    lf.lfCharSet=134;
    lf.lfHeight=-50;
    lf.lfWidth=0;
    strcpy(lf.lfFaceName, "宋体");
    font.CreateFontIndirect(&lf);
    pOldFont=dc.SelectObject(&font);
    dc.SetBkMode(TRANSPARENT);
    // 更改当前画笔为空
    CPen pen(PS_NULL, 1, RGB(0, 0, 255)), *pOldPen;
    pOldPen=dc.SelectObject(&pen);
    // 更改当前刷子
    CBrush br, *pOldBrush;
    pOldBrush=dc.SelectObject(&br);
    // 开始一个路径
    dc.BeginPath();
    dc.TextOut(10, 10, "这里是渐变颜色字体示例");
    dc.EndPath();
    // 绘制渐变效果
    dc.SelectClipPath(RGN_COPY);
    for (int i=255; i>0; i--)
    {
		int iRadius=(600*i)/255;
        dc.SelectObject(pOldBrush);
        br.DeleteObject();
        br.CreateSolidBrush(RGB(i, i, i));
        dc.SelectObject(&br);
        dc.Ellipse(-iRadius, -iRadius/3, iRadius, iRadius/3);
    }
    // 恢复设备上下文的原有设置
    dc.SelectObject(pOldFont);
    dc.SelectObject(pOldPen);
    dc.SelectObject(pOldBrush); 
}
//3D字体效果
void CFontEffectsSampleView::OnMenuitem3dFont() 
{
	// TODO: Add your command handler code here
	// 获得窗口的客户区设备上下文句柄
	CClientDC dc(this);
	//定义字体属性
	LOGFONT lf;
	lf.lfHeight = 50;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = FW_HEAVY;
	lf.lfItalic = FALSE;
	lf.lfUnderline = FALSE;
	lf.lfStrikeOut = FALSE; 
	lf.lfCharSet = GB2312_CHARSET;
	strcpy(lf.lfFaceName,"隶书");
	//创建字体
	CFont font;
	font.CreateFontIndirect(&lf);
	//更改当前字体
	CFont *pOldFont  = dc.SelectObject(&font);
	//绘制字体
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(::GetSysColor(COLOR_3DDKSHADOW));
	CString text = "这里是3D字体示例";
	CRect rc;
	GetClientRect(&rc);
	// 开始一个路径
	dc.BeginPath();
	dc.DrawText( text, rc, DT_SINGLELINE|DT_LEFT|DT_VCENTER|DT_CENTER);
	dc.SetTextColor(::GetSysColor( COLOR_3DHILIGHT) );
	dc.DrawText( text, rc+CPoint(2, 2), DT_SINGLELINE|DT_LEFT|DT_VCENTER|DT_CENTER);
	dc.EndPath();
	// 绘制路径
	dc.StrokePath();
	dc.SelectObject(pOldFont);
}

void CFontEffectsSampleView::OnMouseMove(UINT nFlags, CPoint point) 
{
	//mousePoint.x = point.x;
	//mousePoint.y = point.y;
	
	CView::OnMouseMove(nFlags, point);
	//Invalidate();   
	//UpdateWindow();
}

void CFontEffectsSampleView::OnTimer(UINT nIDEvent) 
{
	CRect   rect;   
	GetClientRect(rect);
	//int iWidth = rect.Width();
    int iHeight = rect.Height();
	Invalidate();   
	UpdateWindow();
	m_iYExtend+=2;   
	if (m_iYExtend > iHeight)   
	{
		m_iYExtend = 0;
	}
	CView::OnTimer(nIDEvent);
}

int CFontEffectsSampleView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;	
	//SetTimer(1,   100,   NULL);   
	return 0;
}




