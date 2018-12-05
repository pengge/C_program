// GDISampleDoc.cpp : implementation of the CGDISampleDoc class
//

#include "stdafx.h"
#include "GDISample.h"

#include "GDISampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDISampleDoc

IMPLEMENT_DYNCREATE(CGDISampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDISampleDoc, CDocument)
	//{{AFX_MSG_MAP(CGDISampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDISampleDoc construction/destruction

CGDISampleDoc::CGDISampleDoc()
{
	// TODO: add one-time construction code here

}

CGDISampleDoc::~CGDISampleDoc()
{
}

BOOL CGDISampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGDISampleDoc serialization

void CGDISampleDoc::Serialize(CArchive& ar)
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
// CGDISampleDoc diagnostics

#ifdef _DEBUG
void CGDISampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDISampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDISampleDoc commands
