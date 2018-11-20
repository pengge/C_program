// ODBCAPISampleDoc.cpp : implementation of the CODBCAPISampleDoc class
//

#include "stdafx.h"
#include "ODBCAPISample.h"

#include "ODBCAPISampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleDoc

IMPLEMENT_DYNCREATE(CODBCAPISampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CODBCAPISampleDoc, CDocument)
	//{{AFX_MSG_MAP(CODBCAPISampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleDoc construction/destruction

CODBCAPISampleDoc::CODBCAPISampleDoc()
{
	// TODO: add one-time construction code here

}

CODBCAPISampleDoc::~CODBCAPISampleDoc()
{
}

BOOL CODBCAPISampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleDoc serialization

void CODBCAPISampleDoc::Serialize(CArchive& ar)
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
// CODBCAPISampleDoc diagnostics

#ifdef _DEBUG
void CODBCAPISampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CODBCAPISampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCAPISampleDoc commands
