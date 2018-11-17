// PageTeacher.cpp : implementation file
//

#include "stdafx.h"
#include "dialogExample.h"
#include "PageTeacher.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageTeacher property page

IMPLEMENT_DYNCREATE(CPageTeacher, CPropertyPage)

CPageTeacher::CPageTeacher() : CPropertyPage(CPageTeacher::IDD)
{
	//{{AFX_DATA_INIT(CPageTeacher)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPageTeacher::~CPageTeacher()
{
}

void CPageTeacher::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageTeacher)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageTeacher, CPropertyPage)
	//{{AFX_MSG_MAP(CPageTeacher)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageTeacher message handlers
