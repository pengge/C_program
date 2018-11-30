// FTPSampleView.cpp : implementation of the CFTPSampleView class
//

#include "stdafx.h"
#include "FTPSample.h"

#include "FTPSampleDoc.h"
#include "FTPSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleView

IMPLEMENT_DYNCREATE(CFTPSampleView, CFormView)

BEGIN_MESSAGE_MAP(CFTPSampleView, CFormView)
	//{{AFX_MSG_MAP(CFTPSampleView)
	ON_BN_CLICKED(IDC_BUTTON_GOTO, OnButtonGoto)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleView construction/destruction

CFTPSampleView::CFTPSampleView()
	: CFormView(CFTPSampleView::IDD)
{
	//{{AFX_DATA_INIT(CFTPSampleView)
	m_Address = _T("ftp://ftp.trueice.net/");
	m_UserName = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_pFtpConnection = NULL;

}

CFTPSampleView::~CFTPSampleView()
{
}

void CFTPSampleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFTPSampleView)
	DDX_Control(pDX, IDC_LIST_FILES, m_fileCtrl);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_EDIT_PASS, m_Password);
	//}}AFX_DATA_MAP
}

BOOL CFTPSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFTPSampleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleView printing

BOOL CFTPSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFTPSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFTPSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFTPSampleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleView diagnostics

#ifdef _DEBUG
void CFTPSampleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFTPSampleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFTPSampleDoc* CFTPSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFTPSampleDoc)));
	return (CFTPSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFTPSampleView message handlers

void CFTPSampleView::OnButtonGoto() 
{
	m_fileCtrl.ResetContent();
	CString strServerName;
	CString strObject;
	INTERNET_PORT nPort;
	DWORD dwServiceType;

	UpdateData(TRUE);
	CInternetSession session("FTP Session");
	if (m_pFtpConnection != NULL)
		m_pFtpConnection->Close();
	delete m_pFtpConnection;
	m_pFtpConnection = NULL;


	if (!AfxParseURL(m_Address, dwServiceType, strServerName, strObject, nPort))
	{
		// 如果失败，可能是没有加ftp://
		CString strFtpURL = _T("ftp://");
		m_Address = strFtpURL + m_Address;
	
		if (!AfxParseURL(m_Address, dwServiceType, strServerName, strObject, nPort))
		{
			AfxMessageBox(IDS_INVALID_URL, MB_OK);
			return;
		}
	}

	CWaitCursor cursor; // 显示等待光标

	// 打开FTP连接
	if ((dwServiceType == INTERNET_SERVICE_FTP) && !strServerName.IsEmpty())
	{
		try
		{
			m_pFtpConnection = session.GetFtpConnection(strServerName, m_UserName, 
				m_Password, nPort);
		}
		catch (CInternetException* pEx)
		{
			// 从WinINet中检查错误
			TCHAR szErr[1024];
			if (pEx->GetErrorMessage(szErr, 1024))
				AfxMessageBox(szErr, MB_OK);
			else
				AfxMessageBox(IDS_EXCEPTION, MB_OK);
			pEx->Delete();

			m_pFtpConnection = NULL;
		}
	}
	else
	{
		AfxMessageBox(IDS_INVALID_URL, MB_OK);
	}

	if (m_pFtpConnection != NULL)
	{
		ShowFiles();
	}
}

//显示FTP站点上的内容
void CFTPSampleView::ShowFiles()
{
	CFtpFileFind ftpFind(m_pFtpConnection);
	CString strFileName;

	BOOL bContinue = ftpFind.FindFile(_T("/*"));
	while (bContinue) 
	{
		bContinue = ftpFind.FindNextFile();
		strFileName = ftpFind.GetFileName();
		m_fileCtrl.AddString(strFileName);
	}

	ftpFind.Close();
}
