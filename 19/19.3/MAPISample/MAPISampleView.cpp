// MAPISampleView.cpp : implementation of the CMAPISampleView class
//

#include "stdafx.h"
#include "MAPISample.h"

#include "MAPISampleDoc.h"
#include "MAPISampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleView

IMPLEMENT_DYNCREATE(CMAPISampleView, CEditView)

BEGIN_MESSAGE_MAP(CMAPISampleView, CEditView)
	//{{AFX_MSG_MAP(CMAPISampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleView construction/destruction

CMAPISampleView::CMAPISampleView()
{
	// TODO: add construction code here

}

CMAPISampleView::~CMAPISampleView()
{
}

BOOL CMAPISampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleView drawing

void CMAPISampleView::OnDraw(CDC* pDC)
{
	CMAPISampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleView printing

BOOL CMAPISampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CMAPISampleView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMAPISampleView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleView diagnostics

#ifdef _DEBUG
void CMAPISampleView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMAPISampleView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMAPISampleDoc* CMAPISampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMAPISampleDoc)));
	return (CMAPISampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMAPISampleView message handlers
