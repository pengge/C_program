// HTTPSampleDoc.cpp : implementation of the CHTTPSampleDoc class
//

#include "stdafx.h"
#include "HTTPSample.h"

#include "HTTPSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleDoc

IMPLEMENT_DYNCREATE(CHTTPSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CHTTPSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CHTTPSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleDoc construction/destruction

CHTTPSampleDoc::CHTTPSampleDoc()
{
	// TODO: add one-time construction code here

}

CHTTPSampleDoc::~CHTTPSampleDoc()
{
}

BOOL CHTTPSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleDoc serialization

void CHTTPSampleDoc::Serialize(CArchive& ar)
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
// CHTTPSampleDoc diagnostics

#ifdef _DEBUG
void CHTTPSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHTTPSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleDoc commands
