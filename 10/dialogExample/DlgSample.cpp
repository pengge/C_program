// DlgSample.cpp : implementation file
//

#include "stdafx.h"
#include "dialogExample.h"
#include "DlgSample.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSample dialog


CDlgSample::CDlgSample(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSample::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSample)
	m_editName = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSample::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSample)
	DDX_Text(pDX, IDC_EDIT1, m_editName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSample, CDialog)
	//{{AFX_MSG_MAP(CDlgSample)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSample message handlers

void CDlgSample::OnChangeEdit1() 
{
	// 这里是文本框内容改变消息的处理函数	
}
