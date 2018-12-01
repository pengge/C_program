// MouseKeyBordSampleDlg.h : header file
//

#if !defined(AFX_MOUSEKEYBORDSAMPLEDLG_H__3C479B2C_3F20_4FD0_9059_134C54D83F98__INCLUDED_)
#define AFX_MOUSEKEYBORDSAMPLEDLG_H__3C479B2C_3F20_4FD0_9059_134C54D83F98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMouseKeyBordSampleDlg dialog

class CMouseKeyBordSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);	// ¼ÇÂ¼ÈÕÖ¾
	CMouseKeyBordSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMouseKeyBordSampleDlg)
	enum { IDD = IDD_MOUSEKEYBORDSAMPLE_DIALOG };
	CButton	m_ButHWND;
	int		m_DoubleClickTime;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseKeyBordSampleDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMouseKeyBordSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButSetdoubletime();
	afx_msg void OnButSwap();
	afx_msg void OnButRestoreswap();
	afx_msg void OnButHwnd();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonGetbuttons();
	afx_msg void OnButSendmouse();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnButtonGetkeyboard();
	afx_msg void OnButControlkey();
	afx_msg void OnButRegisthotkey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEKEYBORDSAMPLEDLG_H__3C479B2C_3F20_4FD0_9059_134C54D83F98__INCLUDED_)
