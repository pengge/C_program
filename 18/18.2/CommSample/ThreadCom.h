#if !defined(AFX_THREADSERIAL_H__2644FDE3_FDF0_437A_BFBE_FB471DC99AAC__INCLUDED_)
#define AFX_THREADSERIAL_H__2644FDE3_FDF0_437A_BFBE_FB471DC99AAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadSerial.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CThreadCom thread

class CThreadCom : public CWinThread
{
	DECLARE_DYNCREATE(CThreadCom)
protected:
           // protected constructor used by dynamic creation

// Attributes
public:
	CThreadCom(HANDLE hCom=INVALID_HANDLE_VALUE);

// Operations
public:
	void SetComStr(CString s);
	CString GetComStr();
	
	BOOL m_bInit;
	
	BOOL SendData(BYTE *s, DWORD dwLen);
	BOOL CThreadCom::OpenCom(CString strCom, CWnd *pWndParent, 
							DWORD dwSendMsgToParent, DWORD dwRecvMsgToParent);
	CString m_sError;
	BOOL m_bDone;
	
	COMMTIMEOUTS m_Commtimeout;
	HANDLE GetComHandle();
	OVERLAPPED m_overWrite;
	OVERLAPPED m_overRead;
	BOOL CloseCom();
	
	virtual ~CThreadCom();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadCom)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	
	//}}AFX_VIRTUAL

// Implementation
protected:


	// Generated message map functions
	//{{AFX_MSG(CThreadCom)
		// NOTE - the ClassWizard will add and remove member functions here.
	
	
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	
	DCB m_dcb;
	CString m_sCom;
	DWORD m_dwSendMsgToParent;
	DWORD m_dwRecvMsgToParent;
	CWnd* m_pWndParent;
	HANDLE m_hCom;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSERIAL_H__2644FDE3_FDF0_437A_BFBE_FB471DC99AAC__INCLUDED_)
