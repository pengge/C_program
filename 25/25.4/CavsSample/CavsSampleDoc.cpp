// CavsSampleDoc.cpp : implementation of the CCavsSampleDoc class
//

#include "stdafx.h"
#include "CavsSample.h"

#include "CavsSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleDoc

IMPLEMENT_DYNCREATE(CCavsSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CCavsSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CCavsSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleDoc construction/destruction

CCavsSampleDoc::CCavsSampleDoc()
{
	// TODO: add one-time construction code here

}

CCavsSampleDoc::~CCavsSampleDoc()
{
}

BOOL CCavsSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCavsSampleDoc serialization

void CCavsSampleDoc::Serialize(CArchive& ar)
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
// CCavsSampleDoc diagnostics

#ifdef _DEBUG
void CCavsSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCavsSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCavsSampleDoc commands
