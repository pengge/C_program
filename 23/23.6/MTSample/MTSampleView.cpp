// MTSampleView.cpp : implementation of the CMTSampleView class
//

#include "stdafx.h"
#include "MTSample.h"

#include "MTSampleDoc.h"
#include "MTSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMTSampleView

IMPLEMENT_DYNCREATE(CMTSampleView, CView)

BEGIN_MESSAGE_MAP(CMTSampleView, CView)
	//{{AFX_MSG_MAP(CMTSampleView)
	ON_COMMAND(ID_MENUITEM_STARTRECVTHREAD, OnMenuitemStartrecvthread)
	ON_COMMAND(ID_MENUITEM_STARTSENDTHREAD, OnMenuitemStartsendthread)
	ON_COMMAND(ID_MENUITEM_STOPTHREAD, OnMenuitemStopthread)
	ON_WM_CREATE()
	ON_MESSAGE(WM_RECEIVE_MESSAGE, OnRecvMsg)
	ON_WM_COPYDATA()
	ON_WM_CANCELMODE()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMTSampleView construction/destruction

CMTSampleView::CMTSampleView()
{
	// TODO: add construction code here
	pThreadRecv = NULL;
	pThreadSend = NULL;
	y=0;
}

CMTSampleView::~CMTSampleView()
{
}

BOOL CMTSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMTSampleView drawing

void CMTSampleView::OnDraw(CDC* pDC)
{
	CMTSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMTSampleView printing

BOOL CMTSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMTSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMTSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMTSampleView diagnostics

#ifdef _DEBUG
void CMTSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMTSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMTSampleDoc* CMTSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMTSampleDoc)));
	return (CMTSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMTSampleView message handlers

void CMTSampleView::OnMenuitemStartrecvthread() 
{
	if (pThreadRecv) 
		if (pThreadRecv->bRun==TRUE) return;
	pThreadRecv = (CThreadRecv*)AfxBeginThread(RUNTIME_CLASS(CThreadRecv), NULL);
	pThreadRecv->hParent = GetSafeHwnd();
	pThreadRecv->m_bAutoDelete = FALSE;
	if (pThreadRecv) WriteLog("启动接收线程成功");
}

void CMTSampleView::OnMenuitemStartsendthread() 
{
	if (pThreadSend) 
		if (pThreadSend->bRun==TRUE) return;
	pThreadSend = (CThreadSend*)AfxBeginThread(RUNTIME_CLASS(CThreadSend), NULL);
	pThreadSend->m_bAutoDelete = FALSE;
	if (pThreadSend) WriteLog("启动发送线程成功");
}

void CMTSampleView::OnMenuitemStopthread() 
{
	if (pThreadRecv) pThreadRecv->bRun=FALSE;
	if (pThreadSend) pThreadSend->bRun=FALSE;
	WriteLog("停止线程成功");
}

BOOL CMTSampleView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

int CMTSampleView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pDC = new CClientDC(this);	
	return 0;
}

void CMTSampleView::WriteLog(CString log)
{
	m_pDC->TextOut(0,y,log);
	y+=20;
}

LRESULT CMTSampleView::OnRecvMsg(WPARAM wParam, LPARAM lParam)
{
    CString log;
    log.Format("接收到消息=%s", wParam);
    WriteLog(log);
    return 1;
}

BOOL CMTSampleView::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnCopyData(pWnd, pCopyDataStruct);
}

void CMTSampleView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CMTSampleView::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CView::OnCaptureChanged(pWnd);
}
