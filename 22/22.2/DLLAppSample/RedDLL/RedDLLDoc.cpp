// RedDLLDoc.cpp : implementation of the CRedDLLDoc class
//

#include "stdafx.h"
#include "RedDLL.h"

#include "RedDLLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRedDLLDoc

IMPLEMENT_DYNCREATE(CRedDLLDoc, CDocument)

BEGIN_MESSAGE_MAP(CRedDLLDoc, CDocument)
	//{{AFX_MSG_MAP(CRedDLLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRedDLLDoc construction/destruction

CRedDLLDoc::CRedDLLDoc()
{
	// TODO: add one-time construction code here

}

CRedDLLDoc::~CRedDLLDoc()
{
}

BOOL CRedDLLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRedDLLDoc serialization

void CRedDLLDoc::Serialize(CArchive& ar)
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
// CRedDLLDoc diagnostics

#ifdef _DEBUG
void CRedDLLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRedDLLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRedDLLDoc commands
