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
#define MAXCOMINBUF	1024
#define MAXCOMOUTBUF	1024
IMPLEMENT_DYNCREATE(CThreadCom, CWinThread)

    CThreadCom::CThreadCom(HANDLE hCom)
{
    m_hCom=hCom;
    m_bInit=FALSE;
    m_sCom="";
    m_sError="No Error!";
    m_hThread=NULL;	
    m_dwSendMsgToParent=0;	
    m_dwRecvMsgToParent=0;	
    m_pWndParent=NULL;
    memset((unsigned char*)&m_overRead,0,sizeof(OVERLAPPED));
    memset((unsigned char*)&m_overWrite,0,sizeof(OVERLAPPED));
    m_overRead.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
    m_overWrite.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
}

CThreadCom::~CThreadCom()
{
	CloseHandle(m_overRead.hEvent);
	CloseHandle(m_overWrite.hEvent);
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

int CThreadCom::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	/*if (m_hCom==INVALID_HANDLE_VALUE)
		return 0;*/
	
	DWORD CommMask;
	CommMask=0
			|	EV_BREAK	//A break was detected on input.
			|	EV_CTS		//The CTS(clear-to-send) signal changed state.
			|	EV_DSR		//The DSR(data-set-ready) signal changed state.
			|	EV_ERR		//A line-status error occurred.Line_status errors are CE_FRAME,CE_OVERRUN,and CE_RXPARITY.
			|	EV_EVENT1	//An event of the first provider-specific type occured
			|	EV_EVENT2	//An event of the second provider-specific type occured.
			|	EV_PERR		//A printer error occured.
			|	EV_RING		//A ring indicator was detected
			|	EV_RLSD		//The RLSD(receive-line-signal-detect) signal changed state.
			|	EV_RX80FULL	//The receive buffer is 80 percent full.
			|	EV_RXCHAR	//A character was received and placed in the input buffer.
			|	EV_RXFLAG	//The event character was received and placed in the input buffer.The event character is specified in the device's DCB structure,which is applied to a serial port by using the SetCommState function.
			|	EV_TXEMPTY;	//The last character in the output buffer was sent.
	::SetCommMask(m_hCom,CommMask);

	::GetCommTimeouts(m_hCom,&m_Commtimeout);
	m_Commtimeout.ReadTotalTimeoutMultiplier=5;
	m_Commtimeout.ReadTotalTimeoutConstant=100;

	DWORD dwError,dwReadNum,dwByteRead,dwEvent;
	COMSTAT ComStat;
	BYTE rBuf[MAXCOMINBUF];
	
	while (!m_bDone)
	{		
		while (m_hCom!=INVALID_HANDLE_VALUE)
		{			
			if(::WaitCommEvent(m_hCom,&dwEvent,NULL))
			{
				dwByteRead=0;
				if((dwEvent & EV_RXCHAR))
				{
					ClearCommError(m_hCom,&dwError,&ComStat);
					if(ComStat.cbInQue!=0)
					{
						dwReadNum=ComStat.cbInQue;
						dwByteRead=0;
						if(dwReadNum>200) dwReadNum=200;
						memset(rBuf,0,sizeof(rBuf));
						DWORD i=::ReadFile(m_hCom,rBuf,dwReadNum,&dwByteRead,&m_overRead);
						for(i=dwByteRead;i<1024;i++) rBuf[i]=0;
					}
				}				
				if(dwByteRead) if(m_pWndParent)
					m_pWndParent->SendMessage(m_dwRecvMsgToParent,(DWORD)rBuf,dwByteRead);			
			}	
		}
		Sleep(1000);
	}
	
	return CWinThread::Run();
}

BOOL CThreadCom::CloseCom()
{
	if (m_hCom!=INVALID_HANDLE_VALUE)
	{
		PurgeComm(m_hCom,PURGE_RXCLEAR);//clear input buffer
		CloseHandle(m_hCom);
		m_hCom=INVALID_HANDLE_VALUE;
	}	
	m_bInit=FALSE;
	return TRUE;
}

HANDLE CThreadCom::GetComHandle()
{
	return m_hCom;
}

BOOL CThreadCom::OpenCom(CString strCom, CWnd *pWndParent, 
							DWORD dwSendMsgToParent, DWORD dwRecvMsgToParent)
{
	CloseCom();
	CString strLog;
	m_hCom=::CreateFile(strCom,	GENERIC_READ|GENERIC_WRITE,	0, NULL,
		OPEN_EXISTING,FILE_FLAG_OVERLAPPED,	NULL);
	if (m_hCom==INVALID_HANDLE_VALUE)
	{		
		strLog.Format("Open %s Error",strCom);
		AfxMessageBox(strLog);
		return FALSE;
	}
	
	::SetupComm(m_hCom,MAXCOMINBUF,MAXCOMOUTBUF);		
	DCB dcb;
	if (!GetCommState(m_hCom,&dcb))
	{
		AfxMessageBox("获取串口状态错误!");
		CloseHandle(m_hCom);
		m_hCom=INVALID_HANDLE_VALUE;
		return FALSE;
	}

	/*dcb.BaudRate	=	9600;
	dcb.ByteSize	=	1;
	//dcb.Parity = NOPARITY;
	dcb.StopBits=ONESTOPBIT;*/
	
	if (!SetCommState(m_hCom,&dcb))
	{
		CloseHandle(m_hCom);
		m_hCom=INVALID_HANDLE_VALUE;		
		strLog.Format("Set %s CommState Error!",strCom);
		DWORD nError=GetLastError();
		AfxMessageBox(strLog);
		return FALSE;
	}
	
	m_sError="No Error";	
	m_pWndParent	=	pWndParent;
	m_dwSendMsgToParent	= dwSendMsgToParent;
	m_dwRecvMsgToParent	= dwRecvMsgToParent;
	
	DWORD CommMask;
	CommMask=0
			|	EV_BREAK	//A break was detected on input.
			|	EV_CTS		//The CTS(clear-to-send) signal changed state.
			|	EV_DSR		//The DSR(data-set-ready) signal changed state.
			|	EV_ERR		//A line-status error occurred.Line_status errors are CE_FRAME,CE_OVERRUN,and CE_RXPARITY.
			|	EV_EVENT1	//An event of the first provider-specific type occured
			|	EV_EVENT2	//An event of the second provider-specific type occured.
			|	EV_PERR		//A printer error occured.
			|	EV_RING		//A ring indicator was detected
			|	EV_RLSD		//The RLSD(receive-line-signal-detect) signal changed state.
			|	EV_RX80FULL	//The receive buffer is 80 percent full.
			|	EV_RXCHAR	//A character was received and placed in the input buffer.
			|	EV_RXFLAG	//The event character was received and placed in the input buffer.The event character is specified in the device's DCB structure,which is applied to a serial port by using the SetCommState function.
			|	EV_TXEMPTY;	//The last character in the output buffer was sent.
	::SetCommMask(m_hCom,CommMask);

	::GetCommTimeouts(m_hCom,&m_Commtimeout);
	m_Commtimeout.ReadTotalTimeoutMultiplier=5;
	m_Commtimeout.ReadTotalTimeoutConstant=100;

	m_bInit=TRUE;
	return TRUE;
}

BOOL CThreadCom::SendData(BYTE *s, DWORD dwLen)
{
	if (!dwLen) return TRUE;
	::GetCommTimeouts(m_hCom,&m_Commtimeout);
	m_Commtimeout.WriteTotalTimeoutMultiplier=0;
	m_Commtimeout.WriteTotalTimeoutConstant=2*dwLen;
	::SetCommTimeouts(m_hCom,&m_Commtimeout);

	if (m_hCom!=INVALID_HANDLE_VALUE)
	{
		DWORD dwSend;
		m_pWndParent->SendMessage(m_dwSendMsgToParent,(DWORD)s,dwLen);			
		if (!WriteFile(m_hCom,s,dwLen,&dwSend,&m_overWrite))
		{
			DWORD len=GetLastError();
			m_sError="串口发送数据错误";			
			return FALSE;
		}		
		return TRUE;
	}
	else
	{
		m_sError="串口句柄无效";
		return FALSE;
	}	
}

CString CThreadCom::GetComStr()
{
	return m_sCom;
}

void CThreadCom::SetComStr(CString s)
{
	m_sCom=s;
}

