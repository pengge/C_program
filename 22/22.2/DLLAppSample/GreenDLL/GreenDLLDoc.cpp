// GreenDLLDoc.cpp : implementation of the CGreenDLLDoc class
//

#include "stdafx.h"
#include "GreenDLL.h"

#include "GreenDLLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLDoc

IMPLEMENT_DYNCREATE(CGreenDLLDoc, CDocument)

BEGIN_MESSAGE_MAP(CGreenDLLDoc, CDocument)
	//{{AFX_MSG_MAP(CGreenDLLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLDoc construction/destruction

CGreenDLLDoc::CGreenDLLDoc()
{
	// TODO: add one-time construction code here

}

CGreenDLLDoc::~CGreenDLLDoc()
{
}

BOOL CGreenDLLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGreenDLLDoc serialization

void CGreenDLLDoc::Serialize(CArchive& ar)
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
// CGreenDLLDoc diagnostics

#ifdef _DEBUG
void CGreenDLLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGreenDLLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGreenDLLDoc commands
