// SubThread.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadCommSample.h"
#include "SubThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubThread

IMPLEMENT_DYNCREATE(CSubThread, CWinThread)

CSubThread::CSubThread()
{
	bRun = TRUE;
}

CSubThread::~CSubThread()
{
}

BOOL CSubThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CSubThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CSubThread, CWinThread)
	//{{AFX_MSG_MAP(CSubThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		ON_THREAD_MESSAGE(WM_PROCESS_TO_THREAD, ReceiveThreadMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubThread message handlers


void CSubThread::ReceiveThreadMsg( UINT wParam, LONG lParam)
{
	CString log;
		log.Format("我是第%d个线程\r\n接收来自进程的命令。\r\n要求我给线程ID=%u的线程发送数据\r\n发送的值=%u",
			iIndex, wParam, lParam);
		AfxMessageBox(log);
}

BOOL CSubThread::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_PROCESS_TO_THREAD)
	{
		CString log;
		log.Format("我是第%d个线程\r\n接收来自进程的命令。\r\n要求我给线程ID=%u的线程发送数据\r\n发送的值=%u",
			iIndex, pMsg->wParam, pMsg->lParam);
		AfxMessageBox(log);
	}
	
	return CWinThread::PreTranslateMessage(pMsg);
}

int CSubThread::Run() 
{
	while (bRun)
	{
		Sleep(1000);
	}
	return CWinThread::Run();
}

