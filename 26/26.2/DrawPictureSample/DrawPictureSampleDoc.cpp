// DrawPictureSampleDoc.cpp : implementation of the CDrawPictureSampleDoc class
//

#include "stdafx.h"
#include "DrawPictureSample.h"

#include "DrawPictureSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleDoc

IMPLEMENT_DYNCREATE(CDrawPictureSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawPictureSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawPictureSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleDoc construction/destruction

CDrawPictureSampleDoc::CDrawPictureSampleDoc()
{
	// TODO: add one-time construction code here

}

CDrawPictureSampleDoc::~CDrawPictureSampleDoc()
{
}

BOOL CDrawPictureSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleDoc serialization

void CDrawPictureSampleDoc::Serialize(CArchive& ar)
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
// CDrawPictureSampleDoc diagnostics

#ifdef _DEBUG
void CDrawPictureSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawPictureSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawPictureSampleDoc commands
