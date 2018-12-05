// GDIBaseSampleDoc.cpp : implementation of the CGDIBaseSampleDoc class
//

#include "stdafx.h"
#include "GDIBaseSample.h"

#include "GDIBaseSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleDoc

IMPLEMENT_DYNCREATE(CGDIBaseSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDIBaseSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CGDIBaseSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleDoc construction/destruction

CGDIBaseSampleDoc::CGDIBaseSampleDoc()
{
	// TODO: add one-time construction code here

}

CGDIBaseSampleDoc::~CGDIBaseSampleDoc()
{
}

BOOL CGDIBaseSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleDoc serialization

void CGDIBaseSampleDoc::Serialize(CArchive& ar)
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
// CGDIBaseSampleDoc diagnostics

#ifdef _DEBUG
void CGDIBaseSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDIBaseSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIBaseSampleDoc commands
