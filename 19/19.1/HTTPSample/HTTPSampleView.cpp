// HTTPSampleView.cpp : implementation of the CHTTPSampleView class
//

#include "stdafx.h"
#include "HTTPSample.h"

#include "HTTPSampleDoc.h"
#include "HTTPSampleView.h"
#include <afxinet.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleView

IMPLEMENT_DYNCREATE(CHTTPSampleView, CFormView)

BEGIN_MESSAGE_MAP(CHTTPSampleView, CFormView)
	//{{AFX_MSG_MAP(CHTTPSampleView)
	ON_BN_CLICKED(IDC_BUTTON_DOWNLOAD, OnButtonDownload)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleView construction/destruction

CHTTPSampleView::CHTTPSampleView()
	: CFormView(CHTTPSampleView::IDD)
{
	//{{AFX_DATA_INIT(CHTTPSampleView)
	m_Address = _T("http://www.baidu.com");
	m_Content = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_pHttpConnection = NULL;
}

CHTTPSampleView::~CHTTPSampleView()
{
}

void CHTTPSampleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHTTPSampleView)
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_Content);
	//}}AFX_DATA_MAP
}

BOOL CHTTPSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CHTTPSampleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleView printing

BOOL CHTTPSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHTTPSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHTTPSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHTTPSampleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleView diagnostics

#ifdef _DEBUG
void CHTTPSampleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHTTPSampleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHTTPSampleDoc* CHTTPSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHTTPSampleDoc)));
	return (CHTTPSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHTTPSampleView message handlers

// 下载HTTP页面
void CHTTPSampleView::OnButtonDownload() 
{
	UpdateData(TRUE);
	CString strServerName;
	CString strObject;
	INTERNET_PORT nPort;
	DWORD dwServiceType;	


	if (!AfxParseURL(m_Address, dwServiceType, strServerName, strObject, nPort))
	{
		// 如果失败，可能是没有加http://		
		m_Address = _T("http://") + m_Address;
	
		if (!AfxParseURL(m_Address, dwServiceType, strServerName, strObject, nPort))
		{
			AfxMessageBox("无效的URL", MB_OK);
			return;
		}
	}

	CWaitCursor cursor; // 显示等待光标

	CInternetSession session("HTTP Session");
	if (m_pHttpConnection != NULL)
		m_pHttpConnection->Close();
	delete m_pHttpConnection;
	m_pHttpConnection = NULL;

	CHttpFile* pFile = NULL;
	CString strHeader;
	DWORD dwReturn;
	try
	{
	   m_pHttpConnection = session.GetHttpConnection(strServerName, nPort);
	   pFile = m_pHttpConnection->OpenRequest(CHttpConnection::HTTP_VERB_GET, strObject);
	   pFile->AddRequestHeaders(strHeader);
	   pFile->SendRequest();
	   pFile->QueryInfoStatusCode(dwReturn);

	   if (dwReturn == HTTP_STATUS_OK)
	   {
		   char szBuff[1024];
		   UINT nRead = pFile->Read(szBuff, 1023);
		   while (nRead > 0)
		   {	
			   m_Content += szBuff;			   
			   nRead = pFile->Read(szBuff, 1023);
		   }
	   }
	   delete pFile;
	   delete m_pHttpConnection;
	   AfxMessageBox("下载HTTP页面成功");
	}
	catch (CInternetException* pEx)
	{
		// 从WinINet中检查错误
		TCHAR szErr[1024];
		if (pEx->GetErrorMessage(szErr, 1024))
			AfxMessageBox(szErr, MB_OK);
		else
			AfxMessageBox("下载HTTP页面失败", MB_OK);
		pEx->Delete();

		m_pHttpConnection = NULL;
	}
	session.Close();
	UpdateData(FALSE);
}
