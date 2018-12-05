// GpsServerDoc.cpp : implementation of the CGpsServerDoc class
//

#include "stdafx.h"
#include <afxdb.h>
#include "GpsServer.h"
#include "MainFrm.h"
#include "GpsServerDoc.h"
#include "GpsServerView.h"
#include "ThreadCom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGpsServerDoc

IMPLEMENT_DYNCREATE(CGpsServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CGpsServerDoc, CDocument)
	//{{AFX_MSG_MAP(CGpsServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGpsServerDoc construction/destruction

CGpsServerDoc::CGpsServerDoc()
{
	// TODO: add one-time construction code here	
	for (int i=0; i<2 ;i++)
	{
		MutexObject[i]=CreateMutex(NULL,FALSE,NULL);
	}	
}

CGpsServerDoc::~CGpsServerDoc()
{	
	CloseAllComWorkFlow();	
}
/////////////////////////////////////////////////////////////////////////////
// CGpsServerDoc serialization

void CGpsServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

CMainFrame* CGpsServerDoc::GetMainFrame()
{
	return (CMainFrame*)AfxGetApp()->GetMainWnd();
}

/////////////////////////////////////////////////////////////////////////////
// CGpsServerDoc diagnostics

#ifdef _DEBUG
void CGpsServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGpsServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGpsServerDoc commands

///////////////////////////////////////////////////////////////////
// ��������	OnNewDocument
// ��  �ܣ�	��ʼ���ĵ�����
// ��  ����	
// ����ֵ��	BOOL--��ʼ���Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� �����ĵ�ʹ�õ����ݿ����
///////////////////////////////////////////////////////////////////
BOOL CGpsServerDoc::OnNewDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!CDocument::OnNewDocument())
		return FALSE;

	
//	return ConnectDB();
	return true;
}

BOOL CGpsServerDoc::ConnectDB() 
{
	BOOL bResult = FALSE;

	// 1��ִ�����ݿ�ĳ�ʼ��
	TRY
	{
		// �������ݿ���󣬲����䳬ʱʱ������Ϊ5��
		m_pDBGps = new CDatabase();
		if (m_pDBGps == NULL) return FALSE;

		m_pDBGps->SetLoginTimeout(5);

		// ���ݿ�������ӵ�����ΪGPSCOMDB��ODBC����Դ
		m_pDBGps->OpenEx("DSN=GPSCOMDB");

		// �ж����ݿ��Ƿ��Ǳ༭��
		if(! m_pDBGps->CanUpdate())
		{
			AfxMessageBox("ע�⣺���ݿ�Ϊֻ��!");
		}

		// ���õ�ǰ�Ĺ���ģʽ����ʹ�����ݿ�
		m_bUseDB = TRUE;

		bResult = TRUE;
	}	
	CATCH(CException,e)
	{
		// ���������ݿ����������ʱ�����õ�ǰ�Ĺ���ģʽ������ʹ�����ݿ�
		e->ReportError();
		delete m_pDBGps;
		m_pDBGps = NULL;		
		bResult = FALSE;
	}
	END_CATCH

	return bResult;
}

//////////////////////////////////////////////////
// ��������CheckSendList
// ��  �ܣ����Ҫ���͵����ݣ�����ͨ�����ڷ��ͳ�ȥ
// ��  ����
// ����ֵ��
// ��  ע��
//////////////////////////////////////////////////
void CGpsServerDoc::CheckSendList()
{	
	while (m_CommandList.GetSize() > 0)	
	{
		if (!m_bInitCom)
		{
			return;
		}

		CSendObject* cmd = (CSendObject*)m_CommandList.GetAt(0);
		CComWorkFlow* pFlow = GetComWorkFlow(cmd->m_Com);
		
		if (pFlow == NULL)	return;
		if (pFlow->m_ThreadCom == NULL) return;

		if (pFlow->m_ThreadCom->m_bOpen)
		{
			pFlow->m_ThreadCom->SendData((LPCTSTR)cmd->command,strlen(cmd->command)+1);	
			WaitForSingleObject(MutexObject[0],INFINITE);		
			m_CommandList.RemoveAt(0);
			ReleaseMutex(MutexObject[0]);	
		}
		
		return;
	}
}

//////////////////////////////////////////////////
// ��������GetComCount
// ��  �ܣ���ȡ��ǰ�����Ĵ�����Ŀ
// ��  ����
// ����ֵ��int--��ǰ�����Ĵ�����
// ��  ע��
//////////////////////////////////////////////////
int CGpsServerDoc::GetComCount()
{	
	return m_ComWorkFlow.GetSize();
}


///////////////////////////////////////////////////////////////////
// ��������	IsUserValid
// ��  �ܣ�	�ж��û����������Ƿ���ȷ
// ��  ����	CString UserName--Ҫ�жϵ��û���
//			CString Pass	--Ҫ�жϵ�����
// ����ֵ��	BOOL--�û��Ƿ���Ч����Ч�򷵻�TRUE����Ч�򷵻�FALSE
// ��  ע��
//////////////////////////////////////////////////////////////////
BOOL CGpsServerDoc::IsUserValid(CString UserName, CString Pass)
{
	BOOL bValid = FALSE;
		
	TRY
	{
		m_pRSUser = new CRSUser(m_pDBGps);

		char sql[512];	
		sprintf(sql,"select * from User where UserName='%s' and Pass='%s'", UserName, Pass);	
		m_pRSUser->Open(AFX_DB_USE_DEFAULT_TYPE,sql);

		if (!m_pRSUser->IsEOF())
		{
			bValid = TRUE;				
		}
		else
		{
			bValid = FALSE;
		}

		m_pRSUser->Close();		
	}
	CATCH(CException,e)
	{
		e->ReportError();
		bValid = FALSE;
	}
	END_CATCH

	delete m_pRSUser;
	m_pRSUser=NULL;

	return bValid;
}

//////////////////////////////////////////////////
// ��������ReadComConfigs
// ��  �ܣ������ݿ��ж�ȡ���ڵ�����
// ��  ����
// ����ֵ��BOOL--��ȡ�Ƿ�ɹ�
// ��  ע��
//////////////////////////////////////////////////
BOOL CGpsServerDoc::ReadComConfigs()
{
    return ReadDefaultComConfigs();
}

///////////////////////////////////////////////////////////////////
// ��������	ReadDefaultComConfigs
// ��  �ܣ�	��ȡĬ�ϴ��ڲ���
// ��  ����	
// ����ֵ��	BOOL--��ȡĬ�ϴ��ڲ����Ƿ�ɹ�
// ��  ע��
//////////////////////////////////////////////////////////////////
BOOL CGpsServerDoc::ReadDefaultComConfigs()
{
	// ��ȡ������
	CMainFrame* pFrame = GetMainFrame();
	
	// ��ʼ�����ڲ�������
	m_ComWorkFlow.RemoveAll();

	// ����Ĭ�ϵĴ���
	CComWorkFlow* pFlow = new CComWorkFlow();
	if (pFlow==NULL) return FALSE;
	DCB dcb;	
	dcb.BaudRate = COM_BAUD_RATE;
	dcb.ByteSize = COM_DATA_BYTE_SIZE;
	dcb.Parity  = COM_PARITY;
	dcb.StopBits = COM_STOP_BIT;
	pFlow->InitWorkFlow(COM_NAME, dcb);	
	m_ComWorkFlow.Add(pFlow);
	
	// ��¼��־
	if (pFrame != NULL)
		pFrame->WriteLog(LOG_LEVEL_PROMPT, 
			"��ȡĬ�ϴ�����Ϣ----����--%s;������--%d;����λ--%d;��żУ��--%d;ֹͣλ--%d;", 
			pFlow->m_Com, pFlow->m_dcb.BaudRate, pFlow->m_dcb.ByteSize,
			pFlow->m_dcb.Parity, pFlow->m_dcb.StopBits);

	return TRUE;
}

///////////////////////////////////////////////////////////////////
// ��������	ReadDefaultComConfigs
// ��  �ܣ�	�����ݿ��ж�ȡ���ڲ���
// ��  ����	
// ����ֵ��	BOOL--�����ݿ��ж�ȡ���ڲ����Ƿ�ɹ�
// ��  ע��
//////////////////////////////////////////////////////////////////
BOOL CGpsServerDoc::ReadDBComConfigs()
{
	BOOL bResult = FALSE;

	// ��ȡ������
	CMainFrame* pFrame= GetMainFrame();

	// ��ʼ�����ڲ�������
	m_ComWorkFlow.RemoveAll();	

/*	TRY
	{
		// �����ݿ��л�ȡ���ڵ����ã��ӱ�ComConfig�ж�ȡ���õĲ���		
		m_pRSComConfig= new CRSComConfig(m_pDBGps);

		CString sql;
		sql.Format("select * from ComConfig where IsValid=true");		
		m_pRSComConfig->Open(CRecordset::dynaset,sql);
		
		m_pRSComConfig->MoveFirst();
		int iCount = 0;
		CDBVariant varValue;
		while(!m_pRSComConfig->IsEOF())
		{
			iCount ++;

			m_pRSComConfig->GetFieldValue("Name", varValue);

			CComWorkFlow* pFlow = new CComWorkFlow();
			if (pFlow==NULL) continue;
			DCB dcb;
			pFlow->m_Com.Format("%s", *varValue.m_pstring);
			dcb.BaudRate =m_pRSComConfig->m_BoundRate;
			dcb.ByteSize = (unsigned char)m_pRSComConfig->m_ByteSize;
			dcb.Parity  = (unsigned char)m_pRSComConfig->m_Parity;
			dcb.StopBits = (unsigned char)m_pRSComConfig->m_StopBits;
			pFlow->InitWorkFlow(COM_NAME, dcb);	
			m_ComWorkFlow.Add(pFlow);

			if (pFrame != NULL)	
				pFrame->WriteLog(LOG_LEVEL_PROMPT, 
					"��ȡ��%d��������Ϣ----����--%s;������--%d;����λ--%d;��żУ��--%d;ֹͣλ--%d;", 
					iCount, pFlow->m_Com, 
					pFlow->m_dcb.BaudRate, pFlow->m_dcb.ByteSize,
					pFlow->m_dcb.Parity, pFlow->m_dcb.StopBits);				
			
			m_pRSComConfig->MoveNext();		
		}
		
		m_pRSComConfig->Close();	

		// ��ȡ���õĴ�����Ŀ����������ʾ�ĳ��������
		if (pFrame != NULL)	
			pFrame->WriteLog(LOG_LEVEL_PROMPT,"����ȡ%d����������", iCount);	
			
		bResult = TRUE;
	}
	CATCH(CDBException, e)
	{
		e->ReportError();		
		bResult = FALSE;
	}
	END_CATCH	*/

	DCB dcb;
	dcb.BaudRate =9600;
	dcb.ByteSize = 8;
	dcb.Parity  = 0;
	dcb.StopBits = 1;

	CComWorkFlow* pFlow = new CComWorkFlow();
	pFlow->InitWorkFlow("com3", dcb);
	m_ComWorkFlow.Add(pFlow);
		
	// ��������
//	m_pRSComConfig->Close();		
//	delete m_pRSComConfig;
//	m_pRSComConfig=NULL;

	return bResult;
}



CComWorkFlow* CGpsServerDoc::GetComWorkFlow(CString com)
{

	for (int i = 0; i < m_ComWorkFlow.GetSize(); i++)
	{
		CComWorkFlow* pFlow = (CComWorkFlow*)m_ComWorkFlow.GetAt(i);
		if (pFlow != NULL)
		{
			if (pFlow->m_Com == com)
			{
				return pFlow;
			}
		}
	}
	return NULL;	

}

BOOL CGpsServerDoc::OpenAllComWorkFlow()
{
	for (int i = 0;i < m_ComWorkFlow.GetSize(); i++)
	{
		CComWorkFlow* pFlow = m_ComWorkFlow.GetAt(i);
		if (pFlow == NULL) continue;

		OpenComWorkFlow(pFlow->m_Com);
		
		if (i == 0)
		{
			// ��ȡ������
			CMainFrame* pFrame =  GetMainFrame();
			if (pFrame != NULL)	
				pFrame->AddViewComData(pFlow->m_Com);
		}
	}
	
	return TRUE;
}

BOOL CGpsServerDoc::OpenComWorkFlow(CString com)
{
	// ��ȡ������
	CMainFrame* pFrame =  GetMainFrame();

	CComWorkFlow* pWorkFlow = GetComWorkFlow(com);	
	if (pWorkFlow == NULL)
	{
		return FALSE;
	}	

	BOOL bResult = pWorkFlow->OpenWorkFlow();
	if (bResult)
	{		
		if (pFrame != NULL)	
			pFrame->WriteComWorkFlowLog(pWorkFlow, TRUE);
	}	
	
	return bResult;

}

BOOL CGpsServerDoc::CloseAllComWorkFlow()
{	
	for (int i = 0;i < m_ComWorkFlow.GetSize(); i++)
	{
		CComWorkFlow* pFlow = m_ComWorkFlow.GetAt(i);
		if (pFlow == NULL) continue;
		CloseComWorkFlow(pFlow->m_Com);
	}
	return TRUE;
}

BOOL CGpsServerDoc::CloseComWorkFlow(CString com)
{
	CComWorkFlow* pWorkFlow = GetComWorkFlow(com);
	if (pWorkFlow == NULL)
	{
		return FALSE;
	}

	BOOL bResult = pWorkFlow->CloseWorkFlow();
	if (bResult)
	{
		// ��ȡ������
		CMainFrame* pFrame = GetMainFrame();
		if (pFrame != NULL)	
			pFrame->WriteComWorkFlowLog(pWorkFlow, FALSE);
	}
	return bResult;
}


void CGpsServerDoc::FuncCommTimer()
{	
	CheckSendList();
}

void CGpsServerDoc::AddGPSPackToDB(GPSPack *pack, CString m_com)
{
	/*CGpsServerDoc* pDoc=(CGpsServerDoc*)GetDocument();	

	CString tele;
	tele.Format("%s",pack->ToGisInfor.gpsinfor.telephone);
	CString sql;
	CString mydate;
	mydate.Format("%04d-%02d-%02d",pack->ToGisInfor.gpsinfor.time.GetYear(),pack->ToGisInfor.gpsinfor.time.GetMonth(),pack->ToGisInfor.gpsinfor.time.GetDay());
    CString mytime;
	mytime.Format("%04d-%02d-%02d %02d:%02d:%02d",pack->ToGisInfor.gpsinfor.time.GetYear(),pack->ToGisInfor.gpsinfor.time.GetMonth(),pack->ToGisInfor.gpsinfor.time.GetDay(),pack->ToGisInfor.gpsinfor.time.GetHour(),pack->ToGisInfor.gpsinfor.time.GetMinute(),pack->ToGisInfor.gpsinfor.time.GetSecond());
	
	sql.Format("insert into GpsReceStatu (telephone,recetime,recedate,LCDStatu,RAMStatu,OEMStatu,GSMStatu,Reserved) values ('%s','%s','%s','%d','%d','%d','%d','%d')",tele,mytime,mydate,pack->ToGisInfor.gpsinfor.starCondition,pack->ToGisInfor.gpsinfor.starNum,pack->ToGisInfor.gpsinfor.statu,pack->ToGisInfor.gpsinfor.carCondition);
	TRY{
		pDoc->GpsDB->ExecuteSQL(sql);
	}
	CATCH(CDBException, e)
	{
		e->ReportError();	
		InsertOutputstr("��Ӵ���״̬��Ϣ������!");
	}
	END_CATCH*/
	return;
}