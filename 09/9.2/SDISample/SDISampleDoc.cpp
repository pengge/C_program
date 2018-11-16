// SDISampleDoc.cpp : implementation of the CSDISampleDoc class
//

#include "stdafx.h"
#include "SDISample.h"

#include "SDISampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSDISampleDoc

IMPLEMENT_DYNCREATE(CSDISampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDISampleDoc, CDocument)
	//{{AFX_MSG_MAP(CSDISampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSDISampleDoc construction/destruction

CSDISampleDoc::CSDISampleDoc()
{
	// TODO: add one-time construction code here
	m_data = "Hello World!haha...";
}

CSDISampleDoc::~CSDISampleDoc()
{
}

BOOL CSDISampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSDISampleDoc serialization

void CSDISampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_data;
	}
	else
	{
		ar >> m_data;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSDISampleDoc diagnostics

#ifdef _DEBUG
void CSDISampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDISampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSDISampleDoc commands

/*CString CSDISampleDoc::GetData()
{
	return m_data;
}*/
