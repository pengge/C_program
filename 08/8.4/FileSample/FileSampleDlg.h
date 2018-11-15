// FileSampleDlg.h : header file
//

#if !defined(AFX_FILESAMPLEDLG_H__8D70593C_D0B2_44D5_B971_3DFFE3C2C49B__INCLUDED_)
#define AFX_FILESAMPLEDLG_H__8D70593C_D0B2_44D5_B971_3DFFE3C2C49B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileSampleDlg dialog

class CFileSampleDlg : public CDialog
{
// Construction
public:
	CFileSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileSampleDlg)
	enum { IDD = IDD_FILESAMPLE_DIALOG };
	CString	m_Content;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRead();
	afx_msg void OnButtonWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESAMPLEDLG_H__8D70593C_D0B2_44D5_B971_3DFFE3C2C49B__INCLUDED_)
