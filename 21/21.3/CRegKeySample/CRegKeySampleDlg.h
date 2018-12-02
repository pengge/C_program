// CRegKeySampleDlg.h : header file
//

#if !defined(AFX_CREGKEYSAMPLEDLG_H__2E99DE6A_3647_499B_981B_06FCBEC866DE__INCLUDED_)
#define AFX_CREGKEYSAMPLEDLG_H__2E99DE6A_3647_499B_981B_06FCBEC866DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCRegKeySampleDlg dialog

class CCRegKeySampleDlg : public CDialog
{
// Construction
public:
	CCRegKeySampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCRegKeySampleDlg)
	enum { IDD = IDD_CREGKEYSAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCRegKeySampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCRegKeySampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonWritenewkey();
	afx_msg void OnButtonQuerykey();
	afx_msg void OnButtonWritedefaultkey();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREGKEYSAMPLEDLG_H__2E99DE6A_3647_499B_981B_06FCBEC866DE__INCLUDED_)
