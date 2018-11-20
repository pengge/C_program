// MFCODBCSampleView.cpp : implementation of the CMFCODBCSampleView class
//

#include "stdafx.h"
#include "MFCODBCSample.h"

#include "MFCODBCSampleSet.h"
#include "MFCODBCSampleDoc.h"
#include "MFCODBCSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleView

IMPLEMENT_DYNCREATE(CMFCODBCSampleView, CRecordView)

BEGIN_MESSAGE_MAP(CMFCODBCSampleView, CRecordView)
	//{{AFX_MSG_MAP(CMFCODBCSampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleView construction/destruction

CMFCODBCSampleView::CMFCODBCSampleView()
	: CRecordView(CMFCODBCSampleView::IDD)
{
	//{{AFX_DATA_INIT(CMFCODBCSampleView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMFCODBCSampleView::~CMFCODBCSampleView()
{
}

void CMFCODBCSampleView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCODBCSampleView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMFCODBCSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CMFCODBCSampleView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_mFCODBCSampleSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleView printing

BOOL CMFCODBCSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCODBCSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCODBCSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleView diagnostics

#ifdef _DEBUG
void CMFCODBCSampleView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCODBCSampleView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCODBCSampleDoc* CMFCODBCSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCODBCSampleDoc)));
	return (CMFCODBCSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleView database support
CRecordset* CMFCODBCSampleView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CMFCODBCSampleView message handlers
