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

BOOL CMenuSampleDoc::OnNewDocument()		// �½�������Ϣ������
{
	if (!CDocument::OnNewDocument())	return FALSE;	// ���û����½�������

	

	return TRUE;							// ������ɷ���
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
	// TODO: �ڴ���������������
	SetTitle(CTime::GetCurrentTime().Format("log %Y-%m-%d %H:%M:%S"));
}
