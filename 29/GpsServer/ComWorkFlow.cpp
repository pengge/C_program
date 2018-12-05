// ComWorkFlow.cpp: implementation of the CComWorkFlow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComWorkFlow.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComWorkFlow::CComWorkFlow()
{
	m_DataFlow = new CDataFlow;
	m_ThreadCom = new CThreadCom();
}

CComWorkFlow::~CComWorkFlow()
{

}

///////////////////////////////////////////////////////////////////
// ��������	StartComThread
// ��  �ܣ�	�������ڹ����߳�
// ��  ����	
// ����ֵ��	BOOL--�������ڹ����߳��Ƿ�ɹ�
// ��  ע��
//////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::StartComThread()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->GetMainWnd();
	BOOL bResult = FALSE;
		
	TRY
	{
		if (m_ThreadCom != NULL)
		{
			if (m_ThreadCom->m_bOpen)
			{
				if (pFrame != NULL)	
					pFrame->WriteLog(LOG_LEVEL_INFO, "����%s�Ѿ���!", m_Com);
				return FALSE;
			}
		}
		m_ThreadCom = (CThreadCom*)AfxBeginThread(RUNTIME_CLASS(CThreadCom));
		bResult = OpenCom();		
		if (pFrame != NULL)
			pFrame->WriteLog(LOG_LEVEL_INFO, "��������%s�����̳߳ɹ�!", m_Com);
	}
	CATCH(CException,e)
	{
		e->ReportError();		
		m_ThreadCom->m_bDone=TRUE;
		StopWinThread((CWinThread*)&m_ThreadCom,INFINITE);	
		if (pFrame != NULL)	
			pFrame->WriteLog(LOG_LEVEL_ERROR, "��������%s�����̴߳���!", m_Com);
		bResult = FALSE;		
	}
	END_CATCH	
	return bResult;
}

///////////////////////////////////////////////////////////////////
// ��������	StopComThread
// ��  �ܣ�	ֹͣ���ڹ����߳�
// ��  ����	
// ����ֵ��	BOOL--ֹͣ���ڹ����߳��Ƿ�ɹ�
// ��  ע��
//////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::StopComThread()
{	
	if (m_ThreadCom != NULL)
	{
		m_ThreadCom->CloseCom();
		m_ThreadCom->m_bDone=TRUE;
		StopWinThread((CWinThread*)m_ThreadCom,INFINITE);		
		m_ThreadCom = NULL;	
	}
	return TRUE;
}


///////////////////////////////////////////////////////////////////
// ��������	StopWinThread
// ��  �ܣ�	ֹͣ�߳�
// ��  ����	CWinThread *pThread--Ҫֹͣ���߳�
//			DWORD dwTimeout--��ʱʱ��
// ����ֵ��	BOOL--ֹͣ�̵߳��˳���
// ��  ע��
//////////////////////////////////////////////////////////////////
DWORD CComWorkFlow::StopWinThread(CWinThread *pThread, DWORD dwTimeout)
{
 	if (pThread==NULL) return NULL;
  	pThread->PostThreadMessage(WM_QUIT,0,0);
 	::WaitForSingleObject(pThread->m_hThread,dwTimeout);
 	DWORD nExitCode=0;
 	BOOL bFlag=::GetExitCodeThread(pThread->m_hThread,&nExitCode);
 	if (bFlag)
 	{
 		delete pThread;
 	}	
 	return nExitCode;
}

///////////////////////////////////////////////////////////////////
// ��������	OpenWorkFlow
// ��  �ܣ�	�򿪴��ڹ�����
// ��  ����	
// ����ֵ��	BOOL--�򿪴��ڹ������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� 
///////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::OpenWorkFlow()
{
	BOOL bResult;
	bResult = StartComThread();
	return bResult;
}

///////////////////////////////////////////////////////////////////
// ��������	CloseWorkFlow
// ��  �ܣ�	�رմ��ڹ�����
// ��  ����	
// ����ֵ��	BOOL--�رմ��ڹ������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� 
///////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::CloseWorkFlow()
{
	BOOL bResult;
	bResult = StopComThread();
	return bResult;
}

///////////////////////////////////////////////////////////////////
// ��������	InitWorkFlow
// ��  �ܣ�	��ʼ�����ڹ�����
// ��  ����	CString com--��������Ӧ�Ĺ�����������
//			DCB dcb--���ڹ�������
// ����ֵ��	BOOL--��ʼ�����ڹ������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� 
///////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::InitWorkFlow(CString com, DCB dcb)
{
	m_Com = com;
	m_dcb = dcb;
    
	m_DataFlow->Create();           //���ﴴ������ʧ��
	m_DataFlow->SendMessage(WM_INITCENTER,NULL,(LPARAM)0);      //���﷢����ֹ
	return TRUE;
}

///////////////////////////////////////////////////////////////////
// ��������	OpenCom
// ��  �ܣ�	�򿪴���
// ��  ����	
// ����ֵ��	BOOL--�򿪴��ڹ������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� 
///////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::OpenCom()
{
	if (m_ThreadCom == NULL)
	{
		return FALSE;
	}

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->GetMainWnd();		
		
	if (m_ThreadCom->m_bOpen)
	{	
		if (pFrame != NULL)	
			pFrame->WriteLog(LOG_LEVEL_INFO,"����%s�Ѿ���!", m_Com);			
		return FALSE;		
	}	

	if (m_ThreadCom->OpenCom(m_Com, m_dcb,
		m_DataFlow, m_DataFlow->GetMeMsg()))
	{	
		if (pFrame != NULL)	
			pFrame->WriteLog(LOG_LEVEL_INFO,"�򿪴���%s�ɹ�!", m_Com);
		m_DataFlow->m_Com = m_Com;
		return TRUE;
	}
	else
	{	
		if (pFrame != NULL)	
			pFrame->WriteLog(LOG_LEVEL_ERROR, m_ThreadCom->m_sError+",���������ô���!");
		m_ThreadCom->m_bOpen=FALSE;		
		return FALSE;		
	}
}

///////////////////////////////////////////////////////////////////
// ��������	CloseCom
// ��  �ܣ�	�رմ���
// ��  ����	
// ����ֵ��	BOOL--�رմ��ڹ������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� ֹͣ���ڹ����߳�
///////////////////////////////////////////////////////////////////
BOOL CComWorkFlow::CloseCom()
{
	if (m_ThreadCom == NULL) return FALSE;		
	return m_ThreadCom->CloseCom();	
}
