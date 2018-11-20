// MFCODBCSampleDoc.cpp : implementation of the CMFCODBCSampleDoc class
//

#include "stdafx.h"
#include "MFCODBCSample.h"

#include "MFCODBCSampleSet.h"
#include "MFCODBCSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleDoc

IMPLEMENT_DYNCREATE(CMFCODBCSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCODBCSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCODBCSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCODBCSampleDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CMFCODBCSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMFCODBCSample to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {6E0CFE89-9B0F-4015-9241-64E0AD96F215}
static const IID IID_IMFCODBCSample =
{ 0x6e0cfe89, 0x9b0f, 0x4015, { 0x92, 0x41, 0x64, 0xe0, 0xad, 0x96, 0xf2, 0x15 } };

BEGIN_INTERFACE_MAP(CMFCODBCSampleDoc, CDocument)
	INTERFACE_PART(CMFCODBCSampleDoc, IID_IMFCODBCSample, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleDoc construction/destruction

CMFCODBCSampleDoc::CMFCODBCSampleDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CMFCODBCSampleDoc::~CMFCODBCSampleDoc()
{
	AfxOleUnlockApp();
}

BOOL CMFCODBCSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleDoc diagnostics

#ifdef _DEBUG
void CMFCODBCSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCODBCSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleDoc commands
