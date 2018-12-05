// GDIControlDoc.cpp : implementation of the CGDIControlDoc class
//

#include "stdafx.h"
#include "GDIControl.h"

#include "GDIControlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIControlDoc

IMPLEMENT_DYNCREATE(CGDIControlDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDIControlDoc, CDocument)
	//{{AFX_MSG_MAP(CGDIControlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIControlDoc construction/destruction

CGDIControlDoc::CGDIControlDoc()
{
	// TODO: add one-time construction code here

}

CGDIControlDoc::~CGDIControlDoc()
{
}

BOOL CGDIControlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGDIControlDoc serialization

void CGDIControlDoc::Serialize(CArchive& ar)
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
// CGDIControlDoc diagnostics

#ifdef _DEBUG
void CGDIControlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDIControlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIControlDoc commands
