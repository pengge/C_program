// GopherSampleDoc.cpp : implementation of the CGopherSampleDoc class
//

#include "stdafx.h"
#include "GopherSample.h"

#include "GopherSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleDoc

IMPLEMENT_DYNCREATE(CGopherSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CGopherSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CGopherSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleDoc construction/destruction

CGopherSampleDoc::CGopherSampleDoc()
{
	// TODO: add one-time construction code here

}

CGopherSampleDoc::~CGopherSampleDoc()
{
}

BOOL CGopherSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGopherSampleDoc serialization

void CGopherSampleDoc::Serialize(CArchive& ar)
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
// CGopherSampleDoc diagnostics

#ifdef _DEBUG
void CGopherSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGopherSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGopherSampleDoc commands
