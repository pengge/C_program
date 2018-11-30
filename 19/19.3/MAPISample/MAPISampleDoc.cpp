// MAPISampleDoc.cpp : implementation of the CMAPISampleDoc class
//

#include "stdafx.h"
#include "MAPISample.h"

#include "MAPISampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleDoc

IMPLEMENT_DYNCREATE(CMAPISampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMAPISampleDoc, CDocument)
	//{{AFX_MSG_MAP(CMAPISampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleDoc construction/destruction

CMAPISampleDoc::CMAPISampleDoc()
{
	// TODO: add one-time construction code here

}

CMAPISampleDoc::~CMAPISampleDoc()
{
}

BOOL CMAPISampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMAPISampleDoc serialization

void CMAPISampleDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleDoc diagnostics

#ifdef _DEBUG
void CMAPISampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMAPISampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleDoc commands
