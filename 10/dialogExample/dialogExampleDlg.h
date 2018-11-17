// dialogExampleDlg.h : header file
//

#if !defined(AFX_DIALOGEXAMPLEDLG_H__C8C80B48_CB51_4E69_9FCB_B374DD4300F8__INCLUDED_)
#define AFX_DIALOGEXAMPLEDLG_H__C8C80B48_CB51_4E69_9FCB_B374DD4300F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogExampleDlg dialog

class CDialogExampleDlg : public CDialog
{
// Construction
public:
	CButton* GetPassCheckBox();
	CDialogExampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogExampleDlg)
	enum { IDD = IDD_DIALOGEXAMPLE_DIALOG };
	BOOL	m_bPass;
	CString	m_strSex;
	CString	m_strName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogExampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogExampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSetcheck();
	afx_msg void OnButtonDialogMessage();
	afx_msg void OnButtonDialogColor();
	afx_msg void OnButtonDialogFile();
	afx_msg void OnButtonDialogFont();
	afx_msg void OnButtonDialogFind();
	afx_msg void OnButtonDialogPrint();
	afx_msg void OnButtonModal();
	afx_msg void OnButtonNonmodal();
	afx_msg void OnButtonOpenSheet();
	afx_msg void OnButtonTest2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEXAMPLEDLG_H__C8C80B48_CB51_4E69_9FCB_B374DD4300F8__INCLUDED_)
