// SysToolSampleDlg.h : header file
//

#if !defined(AFX_SYSTOOLSAMPLEDLG_H__E80FC03E_480D_4343_9BAD_83D806116B2E__INCLUDED_)
#define AFX_SYSTOOLSAMPLEDLG_H__E80FC03E_480D_4343_9BAD_83D806116B2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSysToolSampleDlg dialog

class CSysToolSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);
	CSysToolSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSysToolSampleDlg)
	enum { IDD = IDD_SYSTOOLSAMPLE_DIALOG };
	CEdit	m_editLog;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysToolSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSysToolSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCreatelink();
	afx_msg void OnButtonClearbin();
	afx_msg void OnButtonGetmillsecond();
	afx_msg void OnButtonRegistcom();
	afx_msg void OnButtonUnregistcom();
	afx_msg void OnButtonShowprodig();
	afx_msg void OnButtonGetproclist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTOOLSAMPLEDLG_H__E80FC03E_480D_4343_9BAD_83D806116B2E__INCLUDED_)
