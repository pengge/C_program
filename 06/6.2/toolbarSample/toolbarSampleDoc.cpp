// toolbarSampleDoc.cpp : implementation of the CToolbarSampleDoc class
//

#include "stdafx.h"
#include "toolbarSample.h"

#include "toolbarSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleDoc

IMPLEMENT_DYNCREATE(CToolbarSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CToolbarSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CToolbarSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleDoc construction/destruction

CToolbarSampleDoc::CToolbarSampleDoc()
{
	// TODO: add one-time construction code here

}

CToolbarSampleDoc::~CToolbarSampleDoc()
{
}

BOOL CToolbarSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleDoc serialization

void CToolbarSampleDoc::Serialize(CArchive& ar)
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
// CToolbarSampleDoc diagnostics

#ifdef _DEBUG
void CToolbarSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CToolbarSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolbarSampleDoc commands
