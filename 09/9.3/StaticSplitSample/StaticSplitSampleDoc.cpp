// StaticSplitSampleDoc.cpp : implementation of the CStaticSplitSampleDoc class
//

#include "stdafx.h"
#include "StaticSplitSample.h"

#include "StaticSplitSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleDoc

IMPLEMENT_DYNCREATE(CStaticSplitSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CStaticSplitSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CStaticSplitSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleDoc construction/destruction

CStaticSplitSampleDoc::CStaticSplitSampleDoc()
{
	// TODO: add one-time construction code here

}

CStaticSplitSampleDoc::~CStaticSplitSampleDoc()
{
}

BOOL CStaticSplitSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleDoc serialization

void CStaticSplitSampleDoc::Serialize(CArchive& ar)
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
// CStaticSplitSampleDoc diagnostics

#ifdef _DEBUG
void CStaticSplitSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticSplitSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitSampleDoc commands
