// DlgEllip.cpp : implementation file
//

#include "stdafx.h"
#include "GDISample.h"
#include "DlgEllip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEllip dialog


CDlgEllip::CDlgEllip(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEllip::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEllip)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgEllip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEllip)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEllip, CDialog)
	//{{AFX_MSG_MAP(CDlgEllip)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEllip message handlers

BOOL CDlgEllip::OnInitDialog() 
{
	CDialog::OnInitDialog(); 
	SetWindowText(_T("椭圆窗口测试"));	
	CWnd* hParent = this->GetParent();
	CenterWindow(hParent);
	CRect rect;
	this->GetClientRect(&rect);
	int nEllipseWidth = rect.Width(); 
	int nEllipseHeight = rect.Height(); 
	m_rgnWnd.CreateEllipticRgn(0, 0, nEllipseWidth, nEllipseHeight);	 
	SetWindowRgn((HRGN)m_rgnWnd, TRUE);	// 将m_rgnWnd设置为窗口区域
	return TRUE; 
}
