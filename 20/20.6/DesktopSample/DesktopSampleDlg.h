// DesktopSampleDlg.h : header file
//

#if !defined(AFX_DESKTOPSAMPLEDLG_H__B60CDFA3_1362_40D1_96DD_0F975A56A924__INCLUDED_)
#define AFX_DESKTOPSAMPLEDLG_H__B60CDFA3_1362_40D1_96DD_0F975A56A924__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDesktopSampleDlg dialog

class CDesktopSampleDlg : public CDialog
{
// Construction
public:
	CDesktopSampleDlg(CWnd* pParent = NULL);	// standard constructor
	void WriteLog(LPCTSTR format,...);	// ¼ÇÂ¼ÈÕÖ¾

// Dialog Data
	//{{AFX_DATA(CDesktopSampleDlg)
	enum { IDD = IDD_DESKTOPSAMPLE_DIALOG };
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesktopSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDesktopSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonShowStart();
	afx_msg void OnButtonHideStart();
	afx_msg void OnButtonHideBar();
	afx_msg void OnButtonShowBar();
	afx_msg void OnButtonGetFont();
	afx_msg void OnButtonGetBar();
	afx_msg void OnButtonShowClock();
	afx_msg void OnButtonHideClock();
	afx_msg void OnButtonHideDesktop();
	afx_msg void OnButtonShowDesktop();
	afx_msg void OnButtonSaverscreenRunning();
	afx_msg void OnButtonSetBackgroud();
	afx_msg void OnButtonGetDesklist();
	afx_msg void OnButtonGettoolbarpro();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKTOPSAMPLEDLG_H__B60CDFA3_1362_40D1_96DD_0F975A56A924__INCLUDED_)
