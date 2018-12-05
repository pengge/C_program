// ExtMFCDLLTestDlg.h : header file
//

#if !defined(AFX_EXTMFCDLLTESTDLG_H__8B0C5520_4461_4C89_AC5F_7A76E644CA75__INCLUDED_)
#define AFX_EXTMFCDLLTESTDLG_H__8B0C5520_4461_4C89_AC5F_7A76E644CA75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExtMFCDLLTestDlg dialog

class CExtMFCDLLTestDlg : public CDialog
{
// Construction
public:
	CExtMFCDLLTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExtMFCDLLTestDlg)
	enum { IDD = IDD_EXTMFCDLLTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtMFCDLLTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExtMFCDLLTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonInvokedlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTMFCDLLTESTDLG_H__8B0C5520_4461_4C89_AC5F_7A76E644CA75__INCLUDED_)
