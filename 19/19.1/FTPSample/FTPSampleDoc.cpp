// FTPSampleDoc.cpp : implementation of the CFTPSampleDoc class
//

#include "stdafx.h"
#include "FTPSample.h"

#include "FTPSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleDoc

IMPLEMENT_DYNCREATE(CFTPSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CFTPSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CFTPSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleDoc construction/destruction

CFTPSampleDoc::CFTPSampleDoc()
{
	// TODO: add one-time construction code here

}

CFTPSampleDoc::~CFTPSampleDoc()
{
}

BOOL CFTPSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFTPSampleDoc serialization

void CFTPSampleDoc::Serialize(CArchive& ar)
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
// CFTPSampleDoc diagnostics

#ifdef _DEBUG
void CFTPSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFTPSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleDoc commands
