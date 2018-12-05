// FontEffectsSampleDoc.cpp : implementation of the CFontEffectsSampleDoc class
//

#include "stdafx.h"
#include "FontEffectsSample.h"

#include "FontEffectsSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleDoc

IMPLEMENT_DYNCREATE(CFontEffectsSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CFontEffectsSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CFontEffectsSampleDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleDoc construction/destruction

CFontEffectsSampleDoc::CFontEffectsSampleDoc()
{
	// TODO: add one-time construction code here

}

CFontEffectsSampleDoc::~CFontEffectsSampleDoc()
{
}

BOOL CFontEffectsSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleDoc serialization

void CFontEffectsSampleDoc::Serialize(CArchive& ar)
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
// CFontEffectsSampleDoc diagnostics

#ifdef _DEBUG
void CFontEffectsSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFontEffectsSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFontEffectsSampleDoc commands


CString CFontEffectsSampleDoc::GetData()
{
	return m_data;
}
