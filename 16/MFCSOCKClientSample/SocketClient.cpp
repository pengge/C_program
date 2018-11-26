// SocketRemote.cpp : implementation file
//

#include "stdafx.h"
#include "SocketClient.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
class CThreadServSock;
class CTestmapDoc;
/////////////////////////////////////////////////////////////////////////////
// CSocketClient

CSocketClient::CSocketClient()
{
    m_nLength=0;
    memset(m_szReceBuf,0,sizeof(m_szReceBuf));
    memset(m_szSendBuf,0,sizeof(m_szSendBuf));
    m_bConnect=FALSE;
    m_hMsgWnd=NULL;
    m_strHost.Empty();
    m_strIP.Empty();
}

CSocketClient::~CSocketClient()
{	
	if (m_hSocket!=INVALID_SOCKET)
		Close();
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSocketClient, CAsyncSocket)
	//{{AFX_MSG_MAP(CSocketClient)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSocketClient member functions
// ��������
void CSocketClient::OnSend(int nErrorCode) 
{	
    int nSendBytes = Send(m_szSendBuf,strlen(m_szSendBuf),0);
    char* pLog=new char[200];
    sprintf(pLog, "�ͻ��˷���%d������", nSendBytes);
    if (m_hMsgWnd!=NULL)	
        ::SendMessage(m_hMsgWnd, WM_SOCKET_LOG, (WPARAM)pLog, strlen(pLog));
    memset(m_szSendBuf,0,sizeof(m_szSendBuf));	
    AsyncSelect(FD_READ|FD_CLOSE);	
}

// ��������
void CSocketClient::OnReceive(int nErrorCode) 
{	
    m_nLength=Receive((void*)m_szReceBuf,MAXSOCKBUF,0);
    m_szReceBuf[m_nLength]=0;	
    char* recvBuf=new char[MAXSOCKBUF];
    sprintf(recvBuf,(const char*)m_szReceBuf,m_nLength);	
    if (m_hMsgWnd!=NULL)	
        ::SendMessage(m_hMsgWnd, WM_SOCKET_RECEIVE, (WPARAM)recvBuf, strlen(recvBuf));	
    CAsyncSocket::OnReceive(nErrorCode);
}

void CSocketClient::OnConnect(int nErrorCode) 
{
    char* pLog=new char[200];
    if (nErrorCode == 0)
    {
        sprintf(pLog, "���ӷ������ɹ�");
        m_bConnect = TRUE;
    }
    else
        sprintf(pLog, "���ӷ�����ʧ�ܣ��������=%d", nErrorCode);	
    if (m_hMsgWnd!=NULL)	
        ::SendMessage(m_hMsgWnd, WM_SOCKET_LOG, (WPARAM)pLog, strlen(pLog));
}

void CSocketClient::OnClose(int nErrorCode) 
{	
	CAsyncSocket::OnClose(nErrorCode);
}

void CSocketClient::Init()
{
	memset(m_szReceBuf,0,sizeof(m_szReceBuf));
	m_nLength=MAXSOCKBUF;
}
