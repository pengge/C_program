// MFCSOCKServerSampleDlg.h : header file
//

#if !defined(AFX_MFCSOCKSERVERSAMPLEDLG_H__2B186E6B_86FE_432D_BD0B_06AFDB18B719__INCLUDED_)
#define AFX_MFCSOCKSERVERSAMPLEDLG_H__2B186E6B_86FE_432D_BD0B_06AFDB18B719__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCSOCKServerSampleDlg dialog
#include "SocketServer.h"
class CMFCSOCKServerSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(CString log);
	CSocketServer* pSocketServer;
	CMFCSOCKServerSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCSOCKServerSampleDlg)
	enum { IDD = IDD_MFCSOCKSERVERSAMPLE_DIALOG };
	CIPAddressCtrl	m_IP;
	CEdit	m_editLog;
	CString	m_Port;
	CString	m_editRecv;
	CString	m_editSend;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSOCKServerSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCSOCKServerSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonListen();
	afx_msg void OnButtonSend();
	afx_msg LRESULT OnLogMsg(WPARAM dwEvent, LPARAM dwLen);
	afx_msg LRESULT OnRecvMsg(WPARAM dwEvent, LPARAM dwLen);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
      
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSOCKSERVERSAMPLEDLG_H__2B186E6B_86FE_432D_BD0B_06AFDB18B719__INCLUDED_)
