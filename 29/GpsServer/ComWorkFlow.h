// ComWorkFlow.h: interface for the CComWorkFlow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMWORKFLOW_H__A096D640_8212_45A7_A555_01F42033DFCF__INCLUDED_)
#define AFX_COMWORKFLOW_H__A096D640_8212_45A7_A555_01F42033DFCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DataFlow.h"
#include "ThreadCom.h"

class CComWorkFlow  
{
public:
	CComWorkFlow();				// ���캯��
	virtual ~CComWorkFlow();	// ��������

private:
	DWORD StopWinThread(CWinThread *pThread, DWORD dwTimeout);	// ֹͣWindows�߳�
	BOOL StartComThread();		// ���������߳�
	BOOL StopComThread();		// ֹͣ�����߳�

	BOOL OpenCom();				// �򿪴���
	BOOL CloseCom();			// �رմ���

public:
	BOOL InitWorkFlow(CString com, DCB dcb);	// ��ʼ��������
	BOOL OpenWorkFlow();						// �򿪹�����
	BOOL CloseWorkFlow();						// �رչ�����

	DCB m_dcb;									// ���ڲ������ýṹ
	CString m_Com;								// Ҫ�����Ĵ���
	CDataFlow* m_DataFlow;						// ���ڶ�Ӧ��NEMA0183Э�������
	CThreadCom* m_ThreadCom;					// ���ڶ�Ӧ�Ĺ����߳�
};

#endif // !defined(AFX_COMWORKFLOW_H__A096D640_8212_45A7_A555_01F42033DFCF__INCLUDED_)
