// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "StaticSplitSample.h"

#include "ChildFrm.h"
#include "View1.h"
#include "View2.h"
#include "View3.h"
#include "View4.h"
#include "View5.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
    CCreateContext* pContext)
{
    // 创建一个静态分栏窗口，分为三行一列 
    if(m_wndSplitter1.CreateStatic(this, 3, 1)==NULL)
        return FALSE;
    // 将CView1连接到0行0列窗格上
    m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CView1),CSize(10,10), pContext); 
    // 将CView2连接到1行0列窗格上
    m_wndSplitter1.CreateView(1,0,RUNTIME_CLASS(CView2),CSize(10,10),pContext); 
    // 将第2行再分开1行3列
    if(m_wndSplitter2.CreateStatic(&m_wndSplitter1, 1,3,WS_CHILD|WS_VISIBLE, 
        m_wndSplitter1.IdFromRowCol(2, 0))==NULL)
        return FALSE;  
    //将CView3类连接到第3行的第1列
    m_wndSplitter2.CreateView(0,0,RUNTIME_CLASS(CView3),CSize(300,200),pContext); 
    //将CView4类连接到第3行的第2列
    m_wndSplitter2.CreateView(0,1,RUNTIME_CLASS(CView4),CSize(300,200),pContext); 
    //将CView5类连接到第3行的第3列
    m_wndSplitter2.CreateView(0,2,RUNTIME_CLASS(CView5),CSize(300,200),pContext); 
    return TRUE; 
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
