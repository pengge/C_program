// PhotoScreenWnd.cpp: implementation of the CPhotoScreenWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PhotoScreenSaver.h"
#include "PhotoScreenWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CPhotoScreenWnd, CWnd)
	//{{AFX_MSG_MAP
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP() 


CPhotoScreenWnd::CPhotoScreenWnd()
{
	lpszClassName = NULL;
	m_nBitmapCount = 2;
	m_nTextCount = 10;
	m_idTimer=1;
	m_Point.x=-1;
	m_Point.y=-1;
	m_nIndex = 0;
	m_nTextIndex = 0;
	type = 1;
}

CPhotoScreenWnd::~CPhotoScreenWnd()
{
}

BOOL CPhotoScreenWnd::Create()
{
	if (lpszClassName==NULL)
	{
		lpszClassName=AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,::LoadCursor(AfxGetResourceHandle(),MAKEINTRESOURCE(IDC_NOCURSOR)));
	}
	CRect rect(0,0,::GetSystemMetrics(SM_CXSCREEN),::GetSystemMetrics(SM_CYSCREEN)); 
	CreateEx(WS_EX_TOPMOST,lpszClassName,_T(""),WS_VISIBLE|WS_POPUP, 
		rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,GetSafeHwnd(),NULL,NULL); 
	SetTimer(m_idTimer, 500, NULL); 
	return TRUE;
}

void CPhotoScreenWnd::DrawBitmap(CDC& dc, int nIndex)
{
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap m_Bitmap; 
	m_Bitmap.LoadBitmap(IDB_BITMAP1+nIndex); 
	dcMem.SelectObject(m_Bitmap);
	dc.BitBlt(0,0, 1276, 854,&dcMem,0,0,SRCCOPY);
}

void CPhotoScreenWnd::OnPaint()
{
	CPaintDC dc(this);
	CBrush brush(RGB(0,0,0));
	CRect rect;
	GetClientRect(rect);
	dc.FillRect(&rect,&brush);
}
void CPhotoScreenWnd::OnTimer(UINT nIDEvent)
{
	CClientDC dc(this);	
	if (type == 1)
	{
		DrawText(dc, m_nTextIndex);
		if (m_nTextIndex >= (m_nTextCount-1)) m_nTextIndex = 0;
		else m_nTextIndex++;
	}
	else
	{
		DrawBitmap(dc, m_nIndex);
		if (m_nIndex >= (m_nBitmapCount-1)) m_nIndex = 0;
		else m_nIndex++;
	}
	CWnd::OnTimer(nIDEvent);
}

void CPhotoScreenWnd::DrawText(CDC& dc, int nIndex)
{
	RedrawWindow();
	int width = ::GetSystemMetrics(SM_CXSCREEN);
	int height = ::GetSystemMetrics(SM_CYSCREEN);
	int colWidth = width/m_nTextCount;
	dc.TextOut(nIndex*colWidth, height/2, "ª∂”≠Ω¯»Î∆¡±£≤‚ ‘");	
}

void CPhotoScreenWnd::OnKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags)
{
	PostMessage(WM_CLOSE);
}
void CPhotoScreenWnd::OnLButtonDown(UINT nFlags,CPoint point)
{
	PostMessage(WM_CLOSE);
}
void CPhotoScreenWnd::OnRButtonDown(UINT nFlags,CPoint point)
{
	PostMessage(WM_CLOSE);
}
void CPhotoScreenWnd::OnSysKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags)
{
	PostMessage(WM_CLOSE);
}
void CPhotoScreenWnd::OnMouseMove(UINT nFlags,CPoint point)
{
	if (m_Point==CPoint(-1,-1))	m_Point=point;
	else if (m_Point!=point)  PostMessage(WM_CLOSE);
}

void CPhotoScreenWnd::OnDestroy()
{
	KillTimer(m_idTimer);
}
void CPhotoScreenWnd::PostNcDestroy()
{
	delete this;
}

void CPhotoScreenWnd::OnActivate(UINT nState,CWnd* pWndOther,BOOL bMinimized)
{
	CWnd::OnActivate(nState,pWndOther,bMinimized);
	if (nState == WA_INACTIVE)	PostMessage(WM_CLOSE);
}
void CPhotoScreenWnd::OnActivateApp(BOOL bActive,DWORD hTask)
{
	CWnd::OnActivateApp(bActive,hTask);
	if (!bActive) PostMessage(WM_CLOSE);
}



