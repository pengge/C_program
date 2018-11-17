// DlgNonModal.cpp : implementation file
//

#include "stdafx.h"
#include "dialogExample.h"
#include "DlgNonModal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgNonModal dialog


CDlgNonModal::CDlgNonModal(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNonModal::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNonModal)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgNonModal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNonModal)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgNonModal, CDialog)
	//{{AFX_MSG_MAP(CDlgNonModal)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgNonModal message handlers
