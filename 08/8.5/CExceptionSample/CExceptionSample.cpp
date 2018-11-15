// CExceptionSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CExceptionSample.h"
#include "process.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		char* pFileName="comm.ini";		// 定位文件名变量
		TRY
		{
		   CFile f( pFileName, CFile::modeRead );	// 可写的打开文件
		}
		CATCH( CFileException, e )		// 如果打开文件发生异常，则处理异常
		{
			// 如果发生的异常时文件未找到，则打印错误原因
			if( e->m_cause == CFileException::fileNotFound )
                printf( "错误: 文件没有找到\n");
		}
		END_CATCH       
	}

	system("pause");
	return nRetCode;
}


