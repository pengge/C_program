// RegMFCDllTestDlg.h : header file
//

#if !defined(AFX_REGMFCDLLTESTDLG_H__618109EC_C4C0_4D32_AB1E_FC1D777090F8__INCLUDED_)
#define AFX_REGMFCDLLTESTDLG_H__618109EC_C4C0_4D32_AB1E_FC1D777090F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRegMFCDllTestDlg dialog

class CRegMFCDllTestDlg : public CDialog
{
// Construction
public:
	CRegMFCDllTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegMFCDllTestDlg)
	enum { IDD = IDD_REGMFCDLLTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegMFCDllTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegMFCDllTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonInvokedll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGMFCDLLTESTDLG_H__618109EC_C4C0_4D32_AB1E_FC1D777090F8__INCLUDED_)
