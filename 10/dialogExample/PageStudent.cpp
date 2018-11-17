// PageStudent.cpp : implementation file
//

#include "stdafx.h"
#include "dialogExample.h"
#include "PageStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageStudent property page

IMPLEMENT_DYNCREATE(CPageStudent, CPropertyPage)

CPageStudent::CPageStudent() : CPropertyPage(CPageStudent::IDD)
{
	//{{AFX_DATA_INIT(CPageStudent)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPageStudent::~CPageStudent()
{
}

void CPageStudent::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageStudent)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageStudent, CPropertyPage)
	//{{AFX_MSG_MAP(CPageStudent)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageStudent message handlers
