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
		log.Format("���ǵ�%d���߳�\r\n�������Խ��̵����\r\nҪ���Ҹ��߳�ID=%u���̷߳�������\r\n���͵�ֵ=%u",
			iIndex, wParam, lParam);
		AfxMessageBox(log);
}

BOOL CSubThread::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_PROCESS_TO_THREAD)
	{
		CString log;
		log.Format("���ǵ�%d���߳�\r\n�������Խ��̵����\r\nҪ���Ҹ��߳�ID=%u���̷߳�������\r\n���͵�ֵ=%u",
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

