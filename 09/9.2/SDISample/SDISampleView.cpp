// SDISampleView.cpp : implementation of the CSDISampleView class
//

#include "stdafx.h"
#include "SDISample.h"

#include "SDISampleDoc.h"
#include "SDISampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSDISampleView

IMPLEMENT_DYNCREATE(CSDISampleView, CView)

BEGIN_MESSAGE_MAP(CSDISampleView, CView)
	//{{AFX_MSG_MAP(CSDISampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSDISampleView construction/destruction

CSDISampleView::CSDISampleView()
{
	// TODO: add construction code here

}

CSDISampleView::~CSDISampleView()
{
}

BOOL CSDISampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSDISampleView drawing

void CSDISampleView::OnDraw(CDC* pDC)
{
	CSDISampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString data = pDoc->GetData();
	CRect rect;
    GetClientRect( &rect );
    pDC->SetTextAlign( TA_BASELINE | TA_CENTER );
    pDC->TextOut( rect.right / 2, rect.bottom / 2, data, data.GetLength());
}

/////////////////////////////////////////////////////////////////////////////
// CSDISampleView printing

BOOL CSDISampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDISampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDISampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSDISampleView diagnostics

#ifdef _DEBUG
void CSDISampleView::AssertValid() const
{
	CView::AssertValid();
}

void CSDISampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDISampleDoc* CSDISampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDISampleDoc)));
	return (CSDISampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSDISampleView message handlers

void CSDISampleView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class		
}
