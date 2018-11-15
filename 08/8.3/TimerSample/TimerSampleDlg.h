// TimerSampleDlg.h : header file
//

#if !defined(AFX_TIMERSAMPLEDLG_H__AD269B70_E5D9_441D_ABF0_1C7888816567__INCLUDED_)
#define AFX_TIMERSAMPLEDLG_H__AD269B70_E5D9_441D_ABF0_1C7888816567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimerSampleDlg dialog

class CTimerSampleDlg : public CDialog
{
// Construction
public:
	CTime m_BeginTime;
	CTimerSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimerSampleDlg)
	enum { IDD = IDD_TIMERSAMPLE_DIALOG };
	CString	m_StaticTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimerSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSAMPLEDLG_H__AD269B70_E5D9_441D_ABF0_1C7888816567__INCLUDED_)
