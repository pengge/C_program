// CommSampleDlg.h : header file
//

#if !defined(AFX_COMMSAMPLEDLG_H__EA13F454_896F_4ADA_A66F_D725DE453FC4__INCLUDED_)
#define AFX_COMMSAMPLEDLG_H__EA13F454_896F_4ADA_A66F_D725DE453FC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ThreadCom.h"

/////////////////////////////////////////////////////////////////////////////
// CCommSampleDlg dialog

class CCommSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(CString log);
	CCommSampleDlg(CWnd* pParent = NULL);	// standard constructor
	DWORD StopWinThread(CWinThread *pThread, DWORD dwTimeout);
	CThreadCom* pThreadCom;
	BOOL m_bCom;

// Dialog Data
	//{{AFX_DATA(CCommSampleDlg)
	enum { IDD = IDD_COMMSAMPLE_DIALOG };
	CEdit	m_editLog;
	CString	m_editRecv;
	CString	m_editSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCommSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpen();
	afx_msg LRESULT OnSendMsg(WPARAM dwEvent,LPARAM dwLen);
	afx_msg LRESULT OnRecvMsg(WPARAM dwEvent,LPARAM dwLen);
	afx_msg void OnButtonSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMSAMPLEDLG_H__EA13F454_896F_4ADA_A66F_D725DE453FC4__INCLUDED_)
