// GDIEffectSampleDoc.cpp : implementation of the CGDIEffectSampleDoc class
//

#include "stdafx.h"
#include "GDIEffectSample.h"

#include "GDIEffectSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleDoc

IMPLEMENT_DYNCREATE(CGDIEffectSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDIEffectSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CGDIEffectSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleDoc construction/destruction

CGDIEffectSampleDoc::CGDIEffectSampleDoc()
{
	// TODO: add one-time construction code here

}

CGDIEffectSampleDoc::~CGDIEffectSampleDoc()
{
}

BOOL CGDIEffectSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleDoc serialization

void CGDIEffectSampleDoc::Serialize(CArchive& ar)
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
// CGDIEffectSampleDoc diagnostics

#ifdef _DEBUG
void CGDIEffectSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDIEffectSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIEffectSampleDoc commands
