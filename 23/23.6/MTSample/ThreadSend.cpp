// ThreadSend.cpp : implementation file
//

#include "stdafx.h"
#include "MTSample.h"
#include "ThreadSend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadSend
extern CRITICAL_SECTION cs;
extern CStringList globalList;

IMPLEMENT_DYNCREATE(CThreadSend, CWinThread)

CThreadSend::CThreadSend()
{
	iIndex = 0;
	bRun = TRUE;
}

CThreadSend::~CThreadSend()
{
}

BOOL CThreadSend::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CThreadSend::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CThreadSend, CWinThread)
	//{{AFX_MSG_MAP(CThreadSend)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadSend message handlers

int CThreadSend::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	while (bRun)
	{
		EnterCriticalSection(&cs);
		if (globalList.GetCount() < 100)
		{
			CTime time = CTime::GetCurrentTime();
			CString in;
			in.Format("第%d次的运行时间=%s", iIndex++, time.Format( "%Y-%m-%d %H:%M:%S" ));			
			globalList.AddTail(in);
		}
		LeaveCriticalSection(&cs);
		Sleep(1000);
	}
	return CWinThread::Run();
}
