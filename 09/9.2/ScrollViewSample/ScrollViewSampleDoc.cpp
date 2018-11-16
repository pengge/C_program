// ScrollViewSampleDoc.cpp : implementation of the CScrollViewSampleDoc class
//

#include "stdafx.h"
#include "ScrollViewSample.h"

#include "ScrollViewSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleDoc

IMPLEMENT_DYNCREATE(CScrollViewSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CScrollViewSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CScrollViewSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleDoc construction/destruction

CScrollViewSampleDoc::CScrollViewSampleDoc()
{
	// TODO: add one-time construction code here

}

CScrollViewSampleDoc::~CScrollViewSampleDoc()
{
}

BOOL CScrollViewSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleDoc serialization

void CScrollViewSampleDoc::Serialize(CArchive& ar)
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
// CScrollViewSampleDoc diagnostics

#ifdef _DEBUG
void CScrollViewSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScrollViewSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScrollViewSampleDoc commands
