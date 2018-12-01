// ClicpBoardSampleDlg.h : header file
//

#if !defined(AFX_CLICPBOARDSAMPLEDLG_H__0F584C64_E46F_453A_BDCE_C2CDA7A21D15__INCLUDED_)
#define AFX_CLICPBOARDSAMPLEDLG_H__0F584C64_E46F_453A_BDCE_C2CDA7A21D15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClicpBoardSampleDlg dialog

class CClicpBoardSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);
	CClicpBoardSampleDlg(CWnd* pParent = NULL);	// standard constructor
	HWND hNextWnd;
	int iIndex;

// Dialog Data
	//{{AFX_DATA(CClicpBoardSampleDlg)
	enum { IDD = IDD_CLICPBOARDSAMPLE_DIALOG };
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClicpBoardSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClicpBoardSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonEnumClformat();
	afx_msg void OnButtonMonitor();
	afx_msg void OnButtonCancelMonitor();
	afx_msg void OnButtonSetClicp();
	afx_msg void OnButtonGetClicp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLICPBOARDSAMPLEDLG_H__0F584C64_E46F_453A_BDCE_C2CDA7A21D15__INCLUDED_)
