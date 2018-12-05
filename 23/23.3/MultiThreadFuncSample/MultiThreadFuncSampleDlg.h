// MultiThreadFuncSampleDlg.h : header file
//

#if !defined(AFX_MULTITHREADFUNCSAMPLEDLG_H__4D4E9D8B_BB03_44A2_A306_D4923BE00FC5__INCLUDED_)
#define AFX_MULTITHREADFUNCSAMPLEDLG_H__4D4E9D8B_BB03_44A2_A306_D4923BE00FC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFuncSampleDlg dialog

class CMultiThreadFuncSampleDlg : public CDialog
{
// Construction
public:
	CMultiThreadFuncSampleDlg(CWnd* pParent = NULL);	// standard constructor
	CWinThread* pThread;

// Dialog Data
	//{{AFX_DATA(CMultiThreadFuncSampleDlg)
	enum { IDD = IDD_MULTITHREADFUNCSAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadFuncSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThreadFuncSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStartThread();
	afx_msg void OnButtonSuspendThread();
	afx_msg void OnButtonStopThread();
	afx_msg void OnButtonResumeThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREADFUNCSAMPLEDLG_H__4D4E9D8B_BB03_44A2_A306_D4923BE00FC5__INCLUDED_)
