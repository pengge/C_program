// AppOperSampleDlg.h : header file
//

#if !defined(AFX_APPOPERSAMPLEDLG_H__A33A8CBE_EB77_4CB8_876C_AFF01CCB295C__INCLUDED_)
#define AFX_APPOPERSAMPLEDLG_H__A33A8CBE_EB77_4CB8_876C_AFF01CCB295C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAppOperSampleDlg dialog

class CAppOperSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);
	CAppOperSampleDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL static CALLBACK enumProcFunc(HWND hWnd, LPARAM lParam);
	void CreatePlugIns(CString szPath);
	void LoadPlugIns();

// Dialog Data
	//{{AFX_DATA(CAppOperSampleDlg)
	enum { IDD = IDD_APPOPERSAMPLE_DIALOG };
	CButton	m_Icon;
	CEdit	m_editLog;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppOperSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAppOperSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonIfRunning();
	afx_msg void OnButtonRunCopydos();
	afx_msg void OnButtonUpdateTitle();
	afx_msg void OnButtonIsResponse();
	afx_msg void OnButtonReplaceicon();
	afx_msg void OnButtonExecCommand();
	afx_msg void OnButtonSaveicon();
	afx_msg void OnButtonListtask();
	afx_msg void OnButtonPeparser();
	afx_msg void OnButtonExeusedlls();
	afx_msg void OnButtonWaitprocess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPOPERSAMPLEDLG_H__A33A8CBE_EB77_4CB8_876C_AFF01CCB295C__INCLUDED_)
