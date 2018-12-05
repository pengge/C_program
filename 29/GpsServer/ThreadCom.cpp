// ThreadSerial.cpp : implementation file
//

#include "stdafx.h"

#include "ThreadCom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadCom

IMPLEMENT_DYNCREATE(CThreadCom, CWinThread)

CThreadCom::CThreadCom(HANDLE hCom)
{
	m_hCom=hCom;
	m_bOpen=FALSE;	
	m_sError="�ɹ�";
	m_hThread=NULL;
	m_dwMsgToData=0;
	m_dwMsgToParent=0;
	m_pWndData=NULL;
	m_pWndParent=NULL;	
	memset((unsigned char*)&m_overRead,0,sizeof(OVERLAPPED));
	memset((unsigned char*)&m_overWrite,0,sizeof(OVERLAPPED));
	m_overRead.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
	m_overWrite.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
}

CThreadCom::~CThreadCom()
{
}

BOOL CThreadCom::InitInstance()
{
	// TODO:  perform and per-thread initialization here	
	m_bAutoDelete=FALSE;
	m_bDone=FALSE;
	return TRUE;
}

int CThreadCom::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	BOOL bFlag=CloseCom();	
	return CWinThread::ExitInstance();	
}

BEGIN_MESSAGE_MAP(CThreadCom, CWinThread)
	//{{AFX_MSG_MAP(CThreadCom)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadCom message handlers

///////////////////////////////////////////////////////////////////
// ��������	ReceiveData
// ��  �ܣ�	���մ��ڷ���������
// ��  ����	LPCTSTR rBuf--�������ݵĻ�����
//			int nMaxLength--���յ��ַ���󳤶�
// ����ֵ��	BOOL--���������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� �ڼ�⵽������������ʱ�����ô˺�����������
///////////////////////////////////////////////////////////////////
BOOL CThreadCom::ReceiveData(LPCTSTR rBuf, int nMaxLength)
{
	DWORD		dwLength;		// ���յ����ݵĳ���
	DWORD		dwError;		// �������
	DWORD		dwErrorFlags;	// �������
	COMSTAT		ComStat;		// ����״ֵ̬
	BOOL		fReadStat ;		// �Ӵ��ڶ����ݵ�״̬

	// ����˿ڵĴ�����Ϣ
    ClearCommError( m_hCom, &dwErrorFlags, &ComStat ) ;
	// ȡ�����ַ����е��ַ���Ŀ�Ϳռ��С����Сֵ��ΪҪ��ȡ���ַ���
	dwLength = min( (DWORD) nMaxLength, ComStat.cbInQue ) ;
	
	// �������û��������Ҫ���գ��򷵻�
	if (dwLength <= 0) return dwLength;
	

	// ��ȡ���ڵ�����
	fReadStat = ReadFile( m_hCom, (void*)rBuf,
		                dwLength, &dwLength, &m_overRead ) ;

	// ��������ڲ����ɹ����򷵻�
	if(fReadStat) return dwLength;

	// ��������ڲ���δ�ɹ������ȡ��������
	dwError = GetLastError();

	// ��������Ǵ��ڶ�д�첽δִ���꣬�������ȡ
	if (dwError == ERROR_IO_PENDING)
	{
		// ����Ӧ���жϽ����Ƿ����
		while(!GetOverlappedResult( m_hCom,
		&m_overRead, &dwLength, TRUE ))
		{
			dwError = GetLastError();
			if(dwError == ERROR_IO_INCOMPLETE)
			{
				// ������ͻ�û����ɣ�������ȴ����ͽ���						
				continue;
			}
			else
			{
				// ������������������
				m_sError.Format("<%u>", dwError) ;
				ClearCommError(m_hCom, &dwErrorFlags, &ComStat);
				if (dwErrorFlags > 0) 
				{
					printf(m_sError, "<%u>", dwErrorFlags);
				}
				break;
			}
		}				
	}
	// ����ڶ�ȡ�Ĺ����з��������������������Ϣ
	else
	{
		dwLength = 0;
		// ����������������������
		m_sError.Format("<%u>", dwError) ;
		ClearCommError( m_hCom, &dwErrorFlags, &ComStat ) ;
		if (dwErrorFlags > 0) 
		{
			printf(m_sError, "%s<%u>", m_sError, dwErrorFlags);
		}
	}

	// ���ؽ��յ������ݳ���
	return dwLength;
}

///////////////////////////////////////////////////////////////////
// ��������	Run
// ��  �ܣ�	�̵߳Ĺ�������������Ҫ�Ǽ�⴮���Ƿ������ݵ����������ݵ������մ�������
// ��  ����	
// ����ֵ��	��������
// ��  ע�� �ڼ�⵽������������ʱ������ReceiveData������������
///////////////////////////////////////////////////////////////////
int CThreadCom::Run() 
{
	// TODO: Add your specialized code here and/or call the base class	
	DWORD		dwEvent;						// �����¼�
	int			nLength ;						// 
	BYTE		rBuf[MAX_COM_IN_LENGTH+1];		// �������ݵĻ�����
	

	// ����̹߳���������ʶֵΪFALSE�����⴮�����ݣ�������
	while (!m_bDone)
	{		
		// ������ھ������Чֵ����ִ�д���
		while (m_hCom!=INVALID_HANDLE_VALUE)
		{	
			// ��⴮���¼�
			dwEvent = 0 ;
			WaitCommEvent(m_hCom, &dwEvent, NULL);				

			// ������ַ����մ����¼�������մ�������
			if ((dwEvent & EV_RXCHAR) == EV_RXCHAR)
			{
				// ѭ�����մ�������
				do
				{
					// ���մ�������
					if (nLength = ReceiveData((LPSTR)rBuf, MAX_COM_IN_LENGTH) )
					{
						// ����������������ַ������¼������¼����͸�CDataFlow���д���
						if(dwEvent & ~EV_RXCHAR) 
						{
							if(m_pWndData)
							{
								m_pWndData->SendMessage(m_dwMsgToData,dwEvent,0);
							}
						}

						//���յ����ݺ��͸�CDataFlow���д���
						if(nLength)
						{							
							if(m_pWndData)
							{
								m_pWndData->SendMessage(m_dwMsgToData,(DWORD)rBuf,nLength);
							}							
						}
					}
				}while ( nLength > 0 );			
			}
			Sleep(1);
		}
		Sleep(1);	
	}

	// �رն��첽�¼�����
	CloseHandle( m_overRead.hEvent);
	return CWinThread::Run();
}

///////////////////////////////////////////////////////////////////
// ��������	CloseCom
// ��  �ܣ�	�رմ���
// ��  ����	
// ����ֵ��	BOOL--�رմ��ڹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� ��������һ��Ҫ������������Ǵ���ȱ�ݵ�
///////////////////////////////////////////////////////////////////
BOOL CThreadCom::CloseCom()
{
	// ������ھ������Ч�ģ���������ڹ��������رվ����
	if (m_hCom!=INVALID_HANDLE_VALUE)
	{
		PurgeComm(m_hCom,PURGE_RXCLEAR);//clear input buffer
		CloseHandle(m_hCom);
		m_hCom=INVALID_HANDLE_VALUE;
	}	
	m_bOpen=FALSE;
	return TRUE;
}

HANDLE CThreadCom::GetComHandle()
{
	return m_hCom;
}


///////////////////////////////////////////////////////////////////
// ��������	OpenCom
// ��  �ܣ�	�򿪴���
// ��  ����	CString com--Ҫ�򿪵Ĵ�������,����"COM1"
//			DCB dcb--�򿪴���ʱ�����ڵĲ�������
//			CWnd *pWndData--�����߳������Ĺ������������Ҫ�ǽ�������Ϣ��������Ϣ����Ӧ���� 
//			DWORD dwMsgToWndData--�����߳��빤����֮��ͨ�ŵ���Ϣ
//			CWnd *pWndParent--���ڵĸ�����
//			DWORD dwMsgToParent--�����߳��븸�������ͨ�ŵ���Ϣ
// ����ֵ��	BOOL--�򿪴����Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� 
///////////////////////////////////////////////////////////////////
BOOL CThreadCom::OpenCom(   CString com,
							DCB dcb, 
							CWnd *pWndData, 
							DWORD dwMsgToWndData, 
							CWnd *pWndParent, 
							DWORD dwMsgToParent)
{
	// �����ݽ����ı�������ֵ����Ա����
	m_Com = com;
	m_hCom=INVALID_HANDLE_VALUE;
	m_sError="No Error";	
	m_pWndData			=		pWndData;
	m_dwMsgToData		=		dwMsgToWndData;
	m_pWndParent		=		pWndParent;
	m_dwMsgToParent		=		dwMsgToParent;

	// �򿪴���
	m_hCom=::CreateFile(m_Com,
		GENERIC_READ|GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_FLAG_OVERLAPPED,
		NULL);
	if (m_hCom==INVALID_HANDLE_VALUE)
	{		
		m_sError.Format("Open %s Error", m_Com);
		return FALSE;
	}

	// ���ô��ڵ����뻺������С�������������С������������ʱ�����䶨��Ϊ��
	::SetupComm(m_hCom, MAX_COM_IN_LENGTH, MAX_COM_OUT_LENGTH);

	// ���ô��ڵĹ�����������NEMA0183�й涨��
	// ������Ϊ4800�������ϣ�����λΪ8λ������żУ�飬ֹͣλΪ1λ
	DCB tempdcb;
	int nSuccess	=	GetCommState(m_hCom,&tempdcb);
	if (!nSuccess)
	{
		m_sError="Can't get commstate!";
		CloseHandle(m_hCom);
		m_hCom=INVALID_HANDLE_VALUE;
		return FALSE;
	}

	tempdcb.BaudRate	=	dcb.BaudRate;
	tempdcb.ByteSize	=	dcb.ByteSize;
	tempdcb.Parity		=	dcb.Parity;
	tempdcb.StopBits	=	dcb.StopBits;

	if (SetCommState(m_hCom,&tempdcb)==0)
	{
		CloseHandle(m_hCom);
		m_hCom=INVALID_HANDLE_VALUE;		
		m_sError.Format("Init %s Error!", m_Com);
		return FALSE;
	}

	// ���ô��ڵĹ�����ʱ�������˴����������ʱ������д��ʱ����
	::GetCommTimeouts(m_hCom,&m_Commtimeout);
	m_Commtimeout.ReadTotalTimeoutMultiplier=5;
	m_Commtimeout.ReadTotalTimeoutConstant=100;
	m_Commtimeout.WriteTotalTimeoutMultiplier=0;
	m_Commtimeout.WriteTotalTimeoutConstant=1024;
	::SetCommTimeouts(m_hCom, &m_Commtimeout);

	// ���ô��ڼ����¼�
	DWORD CommMask;
	CommMask=0
			|	EV_BREAK	//��������ʱ����⵽�ж�
			|	EV_CTS		//CTS�źŸı�״̬
			|	EV_DSR		//DSR�źŸı�״̬
			|	EV_ERR		//������״̬���󣬰���CE_FRAME,CE_OVERRUN,��CE_RXPARITY.
			|	EV_EVENT1	//
			|	EV_EVENT2	//
			|	EV_PERR		//������ӡ����A printer error occured.
			|	EV_RING		//��⵽����
			|	EV_RLSD		//RLSD�źŸı�״̬
			|	EV_RX80FULL	//���ջ��������Ѿ�ռ��80%����
			|	EV_RXCHAR	//���յ��ַ���������������뻺����
			|	EV_RXFLAG	//���յ��¼��ַ�����������뵽���뻺������
			|	EV_TXEMPTY;	//��������������һ���ַ����ͳ�ȥ
	if (!SetCommMask(m_hCom, CommMask))
	{
		return FALSE;
	} 

	// һ�гɹ�������
	m_bOpen=TRUE;
	return TRUE;
}

///////////////////////////////////////////////////////////////////
// ��������	SendData
// ��  �ܣ�	�򴮿ڷ�������
// ��  ����	LPCTSTR sBuf--�������ݵĻ�����
//			DWORD dwLen--�������ݵĴ�С
// ����ֵ��	BOOL--���������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE
// ��  ע�� �˺���ִ�е����첽���͹���
///////////////////////////////////////////////////////////////////
BOOL CThreadCom::SendData(LPCTSTR sBuf, DWORD dwLen)
{
	BOOL bResult = FALSE;
	// �жϴ��ھ���Ƿ���Ч
	if (m_hCom != INVALID_HANDLE_VALUE)
	{		
		DWORD   	dwError;			// ���Ͳ���ʱ�Ĵ������
		DWORD       dwErrorFlags;		// ���Ͳ���ʱ�Ĵ���״̬
		DWORD       dwByteSent=0;		// ���͵��ַ���
		DWORD		dwByteWrite;		// �����ַ�����ʱ����
		COMSTAT		ComStat;			// ���ڵĹ���״̬

		// �򴮿ڷ������ݣ���Ҫע��m_overWrite��ʹ�ã�����ִ���첽д�����Ĺؼ�
		BOOL fWriteStat = WriteFile(m_hCom, sBuf, dwLen, &dwByteWrite, &m_overWrite);	
		// ����������ݷ������������жϴ�������
		if (!fWriteStat)
		{			
			dwError = GetLastError();		// ��ȡ�������
			// ����������첽��дδ��ɣ�������ȴ�����
			if(dwError == ERROR_IO_PENDING)
			{
				// ����Ӧ���жϷ����Ƿ����
				while(!GetOverlappedResult( m_hCom,
				&m_overWrite, &dwByteWrite, TRUE ))
				{
					dwError = GetLastError();

					if(dwError == ERROR_IO_INCOMPLETE)
					{
						// ������ͻ�û����ɣ�������ȴ����ͽ���
						dwByteSent += dwByteWrite;
						continue;
					}
					else
					{
						// ������������������
						m_sError.Format("<%u>", dwError) ;
						ClearCommError(m_hCom, &dwErrorFlags, &ComStat);
						if (dwErrorFlags > 0) 
						{
							printf(m_sError, "%s<%u>", m_sError, dwErrorFlags);
						}
						break;
					}			
				}		

				// �ۼ����ӷ��ͳɹ����ַ����������������д��Ϣ��ʾ
				dwByteSent += dwByteWrite;

				if( dwByteSent != dwLen )
				{
					printf(m_sError, "%s-���ͳ�ʱ��%ld/%ld�Ѿ�����/�����ֽ�", m_sError, dwByteSent, dwLen);
					bResult = FALSE;
				}				 
				else
				{
					printf(m_sError, "%s-������ɣ����ɹ�����%ld���ֽ�", m_sError, dwByteSent);					
					bResult = TRUE;
				}
			}
			else
			{				
				// ����������������������
				m_sError.Format("<%u>", dwError) ;
				ClearCommError( m_hCom, &dwErrorFlags, &ComStat ) ;
				if (dwErrorFlags > 0) 
				{
					printf(m_sError, "%s<%u>", m_sError, dwErrorFlags);
				}
				bResult = FALSE;
			}
		}
		// ������ͳɹ���ֱ�ӱ�д��Ϣ��ʾ
		else
		{
			printf(m_sError, "������ɣ����ɹ�����%ld���ֽ�", dwByteSent);					
			bResult = TRUE;
		}
	}
	// ������ھ����Ч���򷵻ش���
	else
	{
		m_sError="���ھ����Ч";
		return FALSE;
	}	

	// �����ͽ�����͸������ڣ��������ڴ��������ʾ������
	::SendMessage(AfxGetApp()->GetMainWnd()->m_hWnd, WM_SEND_COM_DATA_RESULT, (WPARAM)&m_Com, (LPARAM)&m_sError);
	return bResult;
}



