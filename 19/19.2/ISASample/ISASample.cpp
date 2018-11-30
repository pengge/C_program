// ISASAMPLE.CPP - Implementation file for your Internet Server
//    ISASample Extension

#include "stdafx.h"
#include "ISASample.h"
#include <afxisapi.h>

///////////////////////////////////////////////////////////////////////
// The one and only CWinApp object
// NOTE: You may remove this object if you alter your project to no
// longer use MFC in a DLL.

CWinApp theApp;

///////////////////////////////////////////////////////////////////////
// command-parsing map

BEGIN_PARSE_MAP(CISASampleExtension, CHttpServer)
	// TODO: insert your ON_PARSE_COMMAND() and 
	// ON_PARSE_COMMAND_PARAMS() here to hook up your commands.
	// For example:

	ON_PARSE_COMMAND(Default, CISASampleExtension, ITS_EMPTY)
	DEFAULT_PARSE_COMMAND(Default, CISASampleExtension)

	ON_PARSE_COMMAND(AddUser, CISASampleExtension, ITS_PSTR ITS_PSTR ITS_PSTR)
	ON_PARSE_COMMAND_PARAMS("First Middle Last")
END_PARSE_MAP(CISASampleExtension)

///////////////////////////////////////////////////////////////////////
// The one and only CISASampleExtension object

CISASampleExtension theExtension;


///////////////////////////////////////////////////////////////////////
// CISASampleExtension implementation

CISASampleExtension::CISASampleExtension()
{
}

CISASampleExtension::~CISASampleExtension()
{
}

BOOL CISASampleExtension::GetExtensionVersion(HSE_VERSION_INFO* pVer)
{
	// Call default implementation for initialization
	CHttpServer::GetExtensionVersion(pVer);

	// Load description string
	TCHAR sz[HSE_MAX_EXT_DLL_NAME_LEN+1];
	ISAPIVERIFY(::LoadString(AfxGetResourceHandle(),
			IDS_SERVER, sz, HSE_MAX_EXT_DLL_NAME_LEN));
	_tcscpy(pVer->lpszExtensionDesc, sz);
	return TRUE;
}

BOOL CISASampleExtension::TerminateExtension(DWORD dwFlags)
{
	// extension is being terminated
	//TODO: Clean up any per-instance resources
	return TRUE;
}

///////////////////////////////////////////////////////////////////////
// CISASampleExtension command handlers

void CISASampleExtension::Default(CHttpServerContext* pCtxt)
{
	StartContent(pCtxt);
	WriteTitle(pCtxt);

	*pCtxt << _T("This default message was produced by the Internet");
	*pCtxt << _T(" Server DLL Wizard. Edit your CISASampleExtension::Default()");
	*pCtxt << _T(" implementation to change it.\r\n");

	EndContent(pCtxt);
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CISASampleExtension, CHttpServer)
	//{{AFX_MSG_MAP(CISASampleExtension)
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

LPCTSTR CISASampleExtension::GetTitle() const
{
	
	return CHttpServer::GetTitle();
}

int CISASampleExtension::CallFunction(CHttpServerContext* pCtxt, LPTSTR pszQuery, LPTSTR pszCommand) 
{
	char ip[50]={0};
	ULONG len = sizeof(ip);
	BOOL bResult = pCtxt->GetServerVariable("REMOTE_ADDR", ip, &len);
	if (bResult)
	{
		/*CFile file;
		file.Open("Login.txt", CFile::modeCreate|CFile::modeWrite);
		CString log;
		log.Format("Login IP=%s;\r\n", ip);
		file.Write(log, log.GetLength());
		file.Close();*/
	}
	return CHttpServer::CallFunction(pCtxt, pszQuery, pszCommand);
}

void CISASampleExtension::StartContent(CHttpServerContext* pCtxt) const
{
	// TODO: Add your specialized code here and/or call the base class
	
	CHttpServer::StartContent(pCtxt);
}

#define BUFF_SIZE		1024
//增加用户函数
DWORD  CISASampleExtension::AddUser( CHttpServerContext* pctxt, LPCTSTR pstrFirst, LPCTSTR pstrMiddle, LPCTSTR pstrLast )
{

	/*char szStatus[] = "200 OK"; 
	char szContent[] = "<html>" 
		"<head><title>Redirect URL</title></head>" 
		"<body>" 
		"<h1>Redirect.dll</h1>\r\n<hr>\r\n" 
		"Redirect.dll returns the resource specified on the query string.<br>\r\n<br>\r\n" 
		"To specify a resource on the same server as Redirect.dll, use the following form:<br>\r\n<br>\r\n" 
		"<code> http://server/scripts/Redirect.dll?/virtualdir/file.htm </code><br>\r\n<br>\r\n" 
		"To specify a resource on another server, use the following form:<br>\r\n<br>\r\n" 
		"<code> http://server/scripts/Redirect.dll?http://server/virtualdir/file.htm </code>"
		"</body>" "</html>"; 
	char szHeaderBase[] = "Content-Length: %lu\r\nContent-type: text/html\r\n\r\n"; 
	char szHeader[BUFF_SIZE];    

	DWORD cchContent = strlen( szContent );  
	sprintf( szHeader, szHeaderBase, cchContent );   
  HSE_SEND_HEADER_EX_INFO SendHeaderExInfo;  
  SendHeaderExInfo.pszStatus = szStatus; 
  SendHeaderExInfo.pszHeader = szHeader; 
  SendHeaderExInfo.cchStatus = strlen( szStatus ); 
  SendHeaderExInfo.cchHeader = strlen( szHeader ); 
  SendHeaderExInfo.fKeepConn = FALSE;      
  if ( !pctxt->ServerSupportFunction(  HSE_REQ_SEND_RESPONSE_HEADER_EX, &SendHeaderExInfo, NULL, NULL     ) ) 
  {  
	  return HSE_STATUS_ERROR; 
  }  
  if ( !pctxt->WriteClient(szContent, &cchContent, 0 ) ) 
  {  return HSE_STATUS_ERROR; }  
  return HSE_STATUS_SUCCESS;  */
	        *pctxt << _T("Your name is:  ");
        *pctxt << _T(pstrFirst);
        *pctxt << _T("\n");
        *pctxt << _T("Your Address is:  ");
        *pctxt << _T(pstrMiddle);
        *pctxt << _T("\n");
       *pctxt << _T("Your E_mail is:  ");
        *pctxt << _T(pstrLast);
return HSE_STATUS_SUCCESS; 
} 


