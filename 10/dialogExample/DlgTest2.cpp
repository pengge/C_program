// DlgTest2.cpp : implementation file
//

#include "stdafx.h"
#include "dialogExample.h"
#include "DlgTest2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTest2 dialog


CDlgTest2::CDlgTest2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTest2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTest2)
	m_szLog = _T("Hello World");
	//}}AFX_DATA_INIT
}


void CDlgTest2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTest2)
	DDX_Control(pDX, IDC_EDIT_LOG, m_editLog);
	DDX_Text(pDX, IDC_EDIT_LOG, m_szLog);
	DDV_MaxChars(pDX, m_szLog, 1024);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTest2, CDialog)
	//{{AFX_MSG_MAP(CDlgTest2)
	ON_BN_CLICKED(IDC_BUTTON_TEST, OnButtonTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTest2 message handlers

void CDlgTest2::OnButtonTest() 
{
	AfxMessageBox("Hello World!");	
}
