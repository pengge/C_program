// ThreadRecv.cpp : implementation file
//

#include "stdafx.h"
#include "MTSample.h"
#include "ThreadRecv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CRITICAL_SECTION cs;
extern CStringList globalList;
/////////////////////////////////////////////////////////////////////////////
// CThreadRecv

IMPLEMENT_DYNCREATE(CThreadRecv, CWinThread)

CThreadRecv::CThreadRecv()
{
	bRun = TRUE;
}

CThreadRecv::~CThreadRecv()
{
}

BOOL CThreadRecv::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CThreadRecv::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CThreadRecv, CWinThread)
	//{{AFX_MSG_MAP(CThreadRecv)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadRecv message handlers

int CThreadRecv::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	while (bRun)
	{
		EnterCriticalSection(&cs);
		if (globalList.GetCount() > 0)
		{
			CString out=globalList.RemoveHead();			
			if (hParent)
				SendMessage(hParent, WM_RECEIVE_MESSAGE, (DWORD)out.GetBuffer(out.GetLength()), out.GetLength());
		}
		LeaveCriticalSection(&cs);
		Sleep(1000);
	}
	return CWinThread::Run();
}
