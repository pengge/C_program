// statusbarSampleDoc.cpp : implementation of the CStatusbarSampleDoc class
//

#include "stdafx.h"
#include "statusbarSample.h"

#include "statusbarSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleDoc

IMPLEMENT_DYNCREATE(CStatusbarSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CStatusbarSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CStatusbarSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleDoc construction/destruction

CStatusbarSampleDoc::CStatusbarSampleDoc()
{
	// TODO: add one-time construction code here

}

CStatusbarSampleDoc::~CStatusbarSampleDoc()
{
}

BOOL CStatusbarSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleDoc serialization

void CStatusbarSampleDoc::Serialize(CArchive& ar)
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
// CStatusbarSampleDoc diagnostics

#ifdef _DEBUG
void CStatusbarSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStatusbarSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusbarSampleDoc commands
