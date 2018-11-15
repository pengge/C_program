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
		char* pFileName="comm.ini";		// ��λ�ļ�������
		TRY
		{
		   CFile f( pFileName, CFile::modeRead );	// ��д�Ĵ��ļ�
		}
		CATCH( CFileException, e )		// ������ļ������쳣�������쳣
		{
			// ����������쳣ʱ�ļ�δ�ҵ������ӡ����ԭ��
			if( e->m_cause == CFileException::fileNotFound )
                printf( "����: �ļ�û���ҵ�\n");
		}
		END_CATCH       
	}

	system("pause");
	return nRetCode;
}


