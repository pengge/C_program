// ISAPIFILTERSAMPLE.CPP - Implementation file for your Internet Server
//    ISAPIFilterSample Filter

#include "stdafx.h"
#include "ISAPIFilterSample.h"

///////////////////////////////////////////////////////////////////////
// The one and only CWinApp object
// NOTE: You may remove this object if you alter your project to no
// longer use MFC in a DLL.

CWinApp theApp;



///////////////////////////////////////////////////////////////////////
// The one and only CISAPIFilterSampleFilter object

CISAPIFilterSampleFilter theFilter;


///////////////////////////////////////////////////////////////////////
// CISAPIFilterSampleFilter implementation

CISAPIFilterSampleFilter::CISAPIFilterSampleFilter()
{
}

CISAPIFilterSampleFilter::~CISAPIFilterSampleFilter()
{
}

BOOL CISAPIFilterSampleFilter::GetFilterVersion(PHTTP_FILTER_VERSION pVer)
{
	// Call default implementation for initialization
	CHttpFilter::GetFilterVersion(pVer);

	// Clear the flags set by base class
	pVer->dwFlags &= ~SF_NOTIFY_ORDER_MASK;

	// Set the flags we are interested in
	pVer->dwFlags |= SF_NOTIFY_ORDER_HIGH | SF_NOTIFY_SECURE_PORT | SF_NOTIFY_NONSECURE_PORT
			 | SF_NOTIFY_LOG | SF_NOTIFY_AUTHENTICATION | SF_NOTIFY_PREPROC_HEADERS | SF_NOTIFY_READ_RAW_DATA | SF_NOTIFY_SEND_RAW_DATA | SF_NOTIFY_URL_MAP | SF_NOTIFY_END_OF_NET_SESSION;

	// Load description string
	TCHAR sz[SF_MAX_FILTER_DESC_LEN+1];
	ISAPIVERIFY(::LoadString(AfxGetResourceHandle(),
			IDS_FILTER, sz, SF_MAX_FILTER_DESC_LEN));
	_tcscpy(pVer->lpszFilterDesc, sz);
	return TRUE;
}

DWORD CISAPIFilterSampleFilter::OnPreprocHeaders(CHttpFilterContext* pCtxt,
	PHTTP_FILTER_PREPROC_HEADERS pHeaderInfo)
{
	// TODO: React to this notification accordingly and
	// return the appropriate status code
	CFile file;
	file.Open("C:\\ISAPIFilterUserName.txt", CFile::modeCreate | CFile::modeWrite);
	file.Write(CTime::GetCurrentTime().FormatGmt("%Y"), 4);
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

DWORD CISAPIFilterSampleFilter::OnAuthentication(CHttpFilterContext* pCtxt,
	PHTTP_FILTER_AUTHENT pAuthent)
{
	// TODO: React to this notification accordingly and
	// return the appropriate status code
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

DWORD CISAPIFilterSampleFilter::OnUrlMap(CHttpFilterContext* pCtxt,
	PHTTP_FILTER_URL_MAP pMapInfo)
{
	// TODO: React to this notification accordingly and
	// return the appropriate status code
	try
	{
		CFile file;
		file.Open("ISAPIFilterUserName.txt", CFile::modeCreate | CFile::modeWrite);		
		CString log="ÕâÀïÊÇOnUrlMap";
		file.Write(log, log.GetLength());
		file.Close();
	}
	catch(CException e)
	{
		e.ReportError();
		e.Delete();
	}
	//file.Write(pCtxt->m_pFC, strlen(pCtxt->m_pFC));	
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

DWORD CISAPIFilterSampleFilter::OnSendRawData(CHttpFilterContext* pCtxt,
	PHTTP_FILTER_RAW_DATA pRawData)
{
	// TODO: React to this notification accordingly and
	// return the appropriate status code
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

DWORD CISAPIFilterSampleFilter::OnReadRawData(CHttpFilterContext* pCtxt,
	PHTTP_FILTER_RAW_DATA pRawData)
{
	// TODO: React to this notification accordingly and
	// return the appropriate status code
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

DWORD CISAPIFilterSampleFilter::OnLog(CHttpFilterContext *pCtxt, PHTTP_FILTER_LOG pLog)
{
	CFile file;
	file.Open("C:\\ISAPIFilterUserName.txt", CFile::modeCreate | CFile::modeWrite);
	file.Write(pLog->pszClientHostName, strlen(pLog->pszClientHostName));
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

DWORD CISAPIFilterSampleFilter::OnEndOfNetSession(CHttpFilterContext* pCtxt)
{
	// TODO: React to this notification accordingly and
	// return the appropriate status code
	CFile file;
	file.Open("C:\\ISAPIFilterUserName.txt", CFile::modeCreate | CFile::modeWrite);
	file.Write(CTime::GetCurrentTime().FormatGmt("%Y"), 4);
	//file.Write(pCtxt->m_pFC, strlen(pCtxt->m_pFC));
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CISAPIFilterSampleFilter, CHttpFilter)
	//{{AFX_MSG_MAP(CISAPIFilterSampleFilter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

///////////////////////////////////////////////////////////////////////
// If your extension will not use MFC, you'll need this code to make
// sure the extension objects can find the resource handle for the
// module.  If you convert your extension to not be dependent on MFC,
// remove the comments arounn the following AfxGetResourceHandle()
// and DllMain() functions, as well as the g_hInstance global.

/****

static HINSTANCE g_hInstance;

HINSTANCE AFXISAPI AfxGetResourceHandle()
{
	return g_hInstance;
}

BOOL WINAPI DllMain(HINSTANCE hInst, ULONG ulReason,
					LPVOID lpReserved)
{
	if (ulReason == DLL_PROCESS_ATTACH)
	{
		g_hInstance = hInst;
	}

	return TRUE;
}

****/
