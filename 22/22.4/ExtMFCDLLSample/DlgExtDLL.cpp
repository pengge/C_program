// DlgExtDLL.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "DlgExtDLL.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgExtDLL dialog

CDlgExtDLL::CDlgExtDLL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExtDLL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExtDLL)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgExtDLL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExtDLL)
	DDX_Control(pDX, IDC_STATIC_HELLO, m_static);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgExtDLL, CDialog)
	//{{AFX_MSG_MAP(CDlgExtDLL)
	ON_BN_CLICKED(IDC_BUTTON_HELLO, OnButtonHello)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgExtDLL message handlers

void CDlgExtDLL::OnButtonHello() 
{
	m_static.SetWindowText("我是扩展DLL中的对话框！");	
}

int CDlgExtDLL::DoModal() 
{	
	return CDialog::DoModal();
}
