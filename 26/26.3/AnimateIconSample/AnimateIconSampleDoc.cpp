// AnimateIconSampleDoc.cpp : implementation of the CAnimateIconSampleDoc class
//

#include "stdafx.h"
#include "AnimateIconSample.h"

#include "AnimateIconSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleDoc

IMPLEMENT_DYNCREATE(CAnimateIconSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CAnimateIconSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CAnimateIconSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleDoc construction/destruction

CAnimateIconSampleDoc::CAnimateIconSampleDoc()
{
	// TODO: add one-time construction code here

}

CAnimateIconSampleDoc::~CAnimateIconSampleDoc()
{
}

BOOL CAnimateIconSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleDoc serialization

void CAnimateIconSampleDoc::Serialize(CArchive& ar)
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
// CAnimateIconSampleDoc diagnostics

#ifdef _DEBUG
void CAnimateIconSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAnimateIconSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnimateIconSampleDoc commands
