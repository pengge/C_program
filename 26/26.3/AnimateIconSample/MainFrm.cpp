// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "AnimateIconSample.h"

#include "MainFrm.h"
#include <winuser.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_TIMER_TITLEBAR_ANTI 200
#define WM_TIMER_STATUBAR_ANTI 201
#define WM_TIMER_DRAWICON_ANTI 202

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_TBImgList.m_hImageList = NULL;
	m_SBImgList.m_hImageList = NULL;

	m_iTBIconCounter = -1;
	m_iMaxTBIcon = -99;

	m_iSBIconCounter = -1;
	m_iMaxSBIcon = -99;

	m_iIconCounter = 0;
}

CMainFrame::~CMainFrame()
{
	if (hSBPrevIcon) DestroyIcon(hSBPrevIcon);
	if (hTBPrevIcon) DestroyIcon(hTBPrevIcon);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	SetTBImageList(IDB_TITLEBAR_IMAGELIST, 4, RGB(0,0,0));	
	SetTimer(WM_TIMER_TITLEBAR_ANTI,500,NULL);

	SetSBImageList(IDB_STATUBAR_IMAGELIST, 4, RGB(255,0,0));	
	SetTimer(WM_TIMER_STATUBAR_ANTI,500,NULL); 

	SetTimer(WM_TIMER_DRAWICON_ANTI,500,NULL); 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::SetTBImageList(int imageListID,int iMaxIcons, COLORREF tc)
{
	if(iMaxIcons <= 0) return FALSE;
	m_iMaxTBIcon = iMaxIcons;
	VERIFY(m_TBImgList.Create(imageListID, 16, 1, tc));
	return TRUE;
}

BOOL CMainFrame::ShowTBNextIcon()
{
	if(m_TBImgList.m_hImageList == NULL) return FALSE;
	m_iTBIconCounter++;
	if(m_iTBIconCounter >= m_iMaxTBIcon)	m_iTBIconCounter =0;
	hTBIcon = m_TBImgList.ExtractIcon(m_iTBIconCounter);
	HICON hPrevIcon = (HICON) AfxGetMainWnd()->SendMessage(WM_SETICON,TRUE,(LPARAM)hTBIcon);
	if (hPrevIcon) DestroyIcon(hPrevIcon);
	return TRUE;
}

BOOL CMainFrame::SetSBImageList(int imageListID,int iMaxIcons, COLORREF tc)
{
	if(iMaxIcons <= 0) return FALSE;
	m_iMaxSBIcon = iMaxIcons;
	VERIFY(m_SBImgList.Create(imageListID, 16, 1, tc));	

	hSBIcon = m_SBImgList.ExtractIcon(0);
	//HICON hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON_APP));
	NOTIFYICONDATA nid;
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = m_hWnd;
	nid.uID = IDI_ICON_APP;
	nid.uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE;
	nid.uCallbackMessage = NULL;
	nid.hIcon = hSBIcon;
	lstrcpyn(nid.szTip, __TEXT("ÍÐÅÌÍ¼±ê²âÊÔ!"), 64);
	Shell_NotifyIcon(NIM_ADD, &nid);

	return TRUE;
}
BOOL CMainFrame::ShowSBNextIcon()
{
	if(m_SBImgList.m_hImageList == NULL) return FALSE;
	m_iSBIconCounter++;
	if(m_iSBIconCounter >= m_iMaxSBIcon)	m_iSBIconCounter =0;
	hSBIcon = m_SBImgList.ExtractIcon(m_iSBIconCounter);
	NOTIFYICONDATA nid;
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = m_hWnd;
	nid.uID = IDI_ICON_APP;
	nid.uFlags =  NIF_ICON;	
	nid.hIcon = hSBIcon;	
	Shell_NotifyIcon(NIM_MODIFY, &nid);
	if (hSBPrevIcon) DestroyIcon(hSBPrevIcon);
	hSBPrevIcon = hSBIcon;
	return TRUE;
}

BOOL CMainFrame::DrawNextIcon()
{
	CDC* pDC = GetDC();
	char* dwIcons[] = {IDI_APPLICATION,IDI_ASTERISK,IDI_ERROR,IDI_EXCLAMATION,
			IDI_HAND,IDI_INFORMATION,IDI_QUESTION,IDI_WARNING,IDI_WINLOGO};

	m_iIconCounter++;
	if(m_iIconCounter >= 9)	m_iIconCounter =0;
	HICON hIcon = LoadIcon(NULL, MAKEINTRESOURCE(dwIcons[m_iIconCounter]));

	if (hIcon == NULL) return FALSE;
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawIcon(rect.Width()/2, rect.Height()/2, hIcon);
	return TRUE;
}


void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	KillTimer(WM_TIMER_TITLEBAR_ANTI);	
	KillTimer(WM_TIMER_STATUBAR_ANTI);	
	KillTimer(WM_TIMER_DRAWICON_ANTI);
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == WM_TIMER_TITLEBAR_ANTI)	ShowTBNextIcon();	
	else if (nIDEvent == WM_TIMER_STATUBAR_ANTI) ShowSBNextIcon();
	else if (nIDEvent == WM_TIMER_DRAWICON_ANTI) DrawNextIcon();
	CFrameWnd::OnTimer(nIDEvent);
}
