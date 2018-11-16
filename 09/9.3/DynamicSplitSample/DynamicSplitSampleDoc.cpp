// DynamicSplitSampleDoc.cpp : implementation of the CDynamicSplitSampleDoc class
//

#include "stdafx.h"
#include "DynamicSplitSample.h"

#include "DynamicSplitSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleDoc

IMPLEMENT_DYNCREATE(CDynamicSplitSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynamicSplitSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CDynamicSplitSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleDoc construction/destruction

CDynamicSplitSampleDoc::CDynamicSplitSampleDoc()
{
	// TODO: add one-time construction code here

}

CDynamicSplitSampleDoc::~CDynamicSplitSampleDoc()
{
}

BOOL CDynamicSplitSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleDoc serialization

void CDynamicSplitSampleDoc::Serialize(CArchive& ar)
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
// CDynamicSplitSampleDoc diagnostics

#ifdef _DEBUG
void CDynamicSplitSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynamicSplitSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicSplitSampleDoc commands
