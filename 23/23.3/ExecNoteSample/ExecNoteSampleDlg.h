// ExecNoteSampleDlg.h : header file
//

#if !defined(AFX_EXECNOTESAMPLEDLG_H__39C99529_1857_41C1_9D7D_3A80FEA8E676__INCLUDED_)
#define AFX_EXECNOTESAMPLEDLG_H__39C99529_1857_41C1_9D7D_3A80FEA8E676__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExecNoteSampleDlg dialog

class CExecNoteSampleDlg : public CDialog
{
// Construction
public:
	CExecNoteSampleDlg(CWnd* pParent = NULL);	// standard constructor
	CWinThread* pThread;
	CWinThread* pStartAndWaitThread;

// Dialog Data
	//{{AFX_DATA(CExecNoteSampleDlg)
	enum { IDD = IDD_EXECNOTESAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExecNoteSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExecNoteSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonClose();
	afx_msg void OnButtonWait();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonRestore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXECNOTESAMPLEDLG_H__39C99529_1857_41C1_9D7D_3A80FEA8E676__INCLUDED_)
