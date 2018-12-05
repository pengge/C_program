// MTSampleDoc.cpp : implementation of the CMTSampleDoc class
//

#include "stdafx.h"
#include "MTSample.h"

#include "MTSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMTSampleDoc

IMPLEMENT_DYNCREATE(CMTSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMTSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CMTSampleDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMTSampleDoc construction/destruction

CMTSampleDoc::CMTSampleDoc()
{
	// TODO: add one-time construction code here	
}

CMTSampleDoc::~CMTSampleDoc()
{
}

BOOL CMTSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMTSampleDoc serialization

void CMTSampleDoc::Serialize(CArchive& ar)
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
// CMTSampleDoc diagnostics

#ifdef _DEBUG
void CMTSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMTSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMTSampleDoc commands



