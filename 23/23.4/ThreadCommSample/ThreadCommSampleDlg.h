// ThreadCommSampleDlg.h : header file
//

#if !defined(AFX_THREADCOMMSAMPLEDLG_H__7B75E137_4E7D_4812_BC15_4AA5928C316D__INCLUDED_)
#define AFX_THREADCOMMSAMPLEDLG_H__7B75E137_4E7D_4812_BC15_4AA5928C316D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SubThread.h"

/////////////////////////////////////////////////////////////////////////////
// CThreadCommSampleDlg dialog

class CThreadCommSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(CString log);
	CThreadCommSampleDlg(CWnd* pParent = NULL);	// standard constructor
	CWinThread* pThread;

// Dialog Data
	//{{AFX_DATA(CThreadCommSampleDlg)
	enum { IDD = IDD_THREADCOMMSAMPLE_DIALOG };
	CEdit	m_editLog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadCommSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadCommSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnClose();
	afx_msg LRESULT OnThreadMsg(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADCOMMSAMPLEDLG_H__7B75E137_4E7D_4812_BC15_4AA5928C316D__INCLUDED_)
