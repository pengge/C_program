// menuSampleView.cpp : implementation of the CMenuSampleView class
//

#include "stdafx.h"
#include "menuSample.h"

#include "menuSampleDoc.h"
#include "menuSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleView

IMPLEMENT_DYNCREATE(CMenuSampleView, CView)

BEGIN_MESSAGE_MAP(CMenuSampleView, CView)
	//{{AFX_MSG_MAP(CMenuSampleView)
	ON_COMMAND(ID_MENUITEM_STATU, OnMenuitemStatu)
	ON_COMMAND(ID_MENUITEM_POPITEM1, OnMenuitemPopItem1)
	ON_COMMAND(ID_MENUITEM_POPITEM2, OnMenuitemPopItem2)
	ON_UPDATE_COMMAND_UI(ID_MENUITEM_STATU, OnUpdateMenuitemStatu)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleView construction/destruction

CMenuSampleView::CMenuSampleView()
{
	// TODO: add construction code here
	bToosCheck = TRUE;
}

CMenuSampleView::~CMenuSampleView()
{
}

BOOL CMenuSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleView drawing

void CMenuSampleView::OnDraw(CDC* pDC)
{
	CMenuSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleView printing

BOOL CMenuSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleView diagnostics

#ifdef _DEBUG
void CMenuSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuSampleDoc* CMenuSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuSampleDoc)));
	return (CMenuSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleView message handlers

void CMenuSampleView::OnMenuitemStatu()			// 状态测试命令消息处理函数
{	
	if (bToosCheck) bToosCheck = FALSE;
	else bToosCheck = TRUE;	
}

void CMenuSampleView::OnUpdateMenuitemStatu(CCmdUI* pCmdUI) // 状态测试命令更新消息处理函数
{	
	if (bToosCheck) 
	{
		pCmdUI->SetCheck(1);
		pCmdUI->SetText("选择，单击取消");
	}
	else 
	{
		pCmdUI->SetCheck(0);
		pCmdUI->SetText("未选择，单击选择");
	}	
}

void CMenuSampleView::OnRButtonDown(UINT nFlags, CPoint point) // 单击右键时，打开弹出式菜单
{
	POINT screenPoint = point;				// 定义窗体坐标
    ClientToScreen(&screenPoint);			// 将传入的客户区域坐标转换为屏幕坐标

	CMenu menu;								// 定义菜单对象
	VERIFY(menu.LoadMenu(IDR_MENU_POPTEST));// 验证装载的菜单项
	CMenu* pPopup = menu.GetSubMenu(0);		// 获取弹出菜单
	ASSERT(pPopup != NULL); 				// 验证获取的弹出菜单

	// 弹出菜单
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, screenPoint.x,
        screenPoint.y, AfxGetMainWnd());
	CView::OnRButtonDown(nFlags, point);
}

BOOL CMenuSampleView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	return CView::OnCommand(wParam, lParam);
}

void CMenuSampleView::OnMenuitemPopItem1()
{
	CDC* pDC = GetDC();
	pDC->TextOut(0, 0, "单击弹出菜单中的菜单项1");
}

void CMenuSampleView::OnMenuitemPopItem2()
{
	CDC* pDC = GetDC();
	pDC->TextOut(0, 0, "单击弹出菜单中的菜单项2");
}