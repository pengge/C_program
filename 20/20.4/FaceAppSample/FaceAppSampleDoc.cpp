// FaceAppSampleDoc.cpp : implementation of the CFaceAppSampleDoc class
//

#include "stdafx.h"
#include "FaceAppSample.h"

#include "FaceAppSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleDoc

IMPLEMENT_DYNCREATE(CFaceAppSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CFaceAppSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CFaceAppSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleDoc construction/destruction

CFaceAppSampleDoc::CFaceAppSampleDoc()
{
	// TODO: add one-time construction code here

}

CFaceAppSampleDoc::~CFaceAppSampleDoc()
{
}

BOOL CFaceAppSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleDoc serialization

void CFaceAppSampleDoc::Serialize(CArchive& ar)
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
// CFaceAppSampleDoc diagnostics

#ifdef _DEBUG
void CFaceAppSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFaceAppSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceAppSampleDoc commands
