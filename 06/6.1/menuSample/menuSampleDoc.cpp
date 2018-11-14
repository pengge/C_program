// menuSampleDoc.cpp : implementation of the CMenuSampleDoc class
//

#include "stdafx.h"
#include "menuSample.h"

#include "menuSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleDoc

IMPLEMENT_DYNCREATE(CMenuSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMenuSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CMenuSampleDoc)	
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_MENUITEMSETTITLE, &CMenuSampleDoc::OnMenuitemsettitle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleDoc construction/destruction

CMenuSampleDoc::CMenuSampleDoc()
{
	// TODO: add one-time construction code here
	
}

CMenuSampleDoc::~CMenuSampleDoc()
{
}

BOOL CMenuSampleDoc::OnNewDocument()		// 新建命令消息处理函数
{
	if (!CDocument::OnNewDocument())	return FALSE;	// 调用基类新建处理函数

	

	return TRUE;							// 函数完成返回
}



/////////////////////////////////////////////////////////////////////////////
// CMenuSampleDoc serialization

void CMenuSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleDoc diagnostics

#ifdef _DEBUG
void CMenuSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenuSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuSampleDoc commands




void CMenuSampleDoc::OnMenuitemsettitle()
{
	// TODO: 在此添加命令处理程序代码
	SetTitle(CTime::GetCurrentTime().Format("log %Y-%m-%d %H:%M:%S"));
}
