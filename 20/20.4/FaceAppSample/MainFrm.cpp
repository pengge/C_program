// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "FaceAppSample.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENUITEM_FACE_BLUE, OnMenuitemFaceBlue)
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
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this,TBSTYLE_FLAT|TBSTYLE_TRANSPARENT,WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP,
		CRect(0,0,0,0),AFX_IDW_TOOLBAR) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar,NULL,NULL,RBBS_GRIPPERALWAYS|RBBS_FIXEDBMP|RBBS_BREAK))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	LoadFace("back.bmp");	
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


void CMainFrame::OnMenuitemFaceBlue() 
{
	LoadFace("FACE1.bmp");
}

void CMainFrame::LoadFace(CString bkPath)
{
	HBITMAP m_bmpBack=(HBITMAP)LoadImage(AfxGetInstanceHandle(), bkPath,
		IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION); 

	CReBarCtrl& rc=m_wndReBar.GetReBarCtrl(); 
	REBARBANDINFO ri;
	memset(&ri,0,sizeof(REBARBANDINFO)); 
	ri.cbSize=sizeof(ri);
	ri.fMask=RBBIM_BACKGROUND; 
	
	if (m_bmpBack != INVALID_HANDLE_VALUE)	ri.hbmBack=m_bmpBack;
	else ri.hbmBack = NULL;
	rc.SetBandInfo(0,&ri);	
	rc.UpdateWindow();
}
