// SysControlSampleDlg.h : header file
//

#if !defined(AFX_SYSCONTROLSAMPLEDLG_H__9A521263_7964_4AD6_AF95_835E81DE98A3__INCLUDED_)
#define AFX_SYSCONTROLSAMPLEDLG_H__9A521263_7964_4AD6_AF95_835E81DE98A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSysControlSampleDlg dialog

class CSysControlSampleDlg : public CDialog
{
// Construction
public:
	CSysControlSampleDlg(CWnd* pParent = NULL);	// standard constructor
	void WriteLog(LPCTSTR format,...);	// ¼ÇÂ¼ÈÕÖ¾
	void FindExe(CString szPath);
	int iFileCount;

// Dialog Data
	//{{AFX_DATA(CSysControlSampleDlg)
	enum { IDD = IDD_SYSCONTROLSAMPLE_DIALOG };
	CEdit	m_editLog;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysControlSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSysControlSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonExe();
	afx_msg void OnButtonOpenScreensaver();
	afx_msg void OnButtonCloseMonitor();
	afx_msg void OnButtonOpenMonitor();
	afx_msg void OnButtonDisableScreensaver();
	afx_msg void OnButtonEnableScreensaver();
	afx_msg void OnButtonCloseimm();
	afx_msg void OnButtonBeep();
	afx_msg void OnButtonOpenCdrom();
	afx_msg void OnButtonCloseCdrom();
	afx_msg void OnButtonLogoffOs();
	afx_msg void OnButtonRestartOs();
	afx_msg void OnButtonCloseOs();
	afx_msg void OnButtonLinkWizard();
	afx_msg void OnButtonExeControlitem();
	afx_msg void OnButtonCloseSearchfile();
	afx_msg void OnButtonLockSystem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSCONTROLSAMPLEDLG_H__9A521263_7964_4AD6_AF95_835E81DE98A3__INCLUDED_)
