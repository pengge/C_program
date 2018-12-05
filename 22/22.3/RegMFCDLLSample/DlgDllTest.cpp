// DlgDllTest.cpp : implementation file
//

#include "stdafx.h"
#include "RegMFCDLLSample.h"
#include "DlgDllTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDllTest dialog


CDlgDllTest::CDlgDllTest(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDllTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDllTest)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgDllTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDllTest)
	DDX_Control(pDX, IDC_STATIC_COLOR, m_static);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDllTest, CDialog)
	//{{AFX_MSG_MAP(CDlgDllTest)
	ON_BN_CLICKED(IDC_BUTTON_HELLO, OnButtonHello)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDllTest message handlers

void CDlgDllTest::OnButtonHello() 
{
	m_static.SetWindowText("Hello World");	
}
