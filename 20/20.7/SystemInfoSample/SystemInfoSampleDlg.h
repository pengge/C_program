// SystemInfoSampleDlg.h : header file
//

#if !defined(AFX_SYSTEMINFOSAMPLEDLG_H__E10DBC40_D19A_4400_9130_DD931F28F777__INCLUDED_)
#define AFX_SYSTEMINFOSAMPLEDLG_H__E10DBC40_D19A_4400_9130_DD931F28F777__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSystemInfoSampleDlg dialog

class CSystemInfoSampleDlg : public CDialog
{
// Construction
public:
	CSystemInfoSampleDlg(CWnd* pParent = NULL);	// standard constructor
	void CSystemInfoSampleDlg::WriteLog(LPCTSTR format,...);// ¼ÇÂ¼ÈÕÖ¾

// Dialog Data
	//{{AFX_DATA(CSystemInfoSampleDlg)
	enum { IDD = IDD_SYSTEMINFOSAMPLE_DIALOG };
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemInfoSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSystemInfoSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGetSysversion();
	afx_msg void OnButtonGetWindowpath();
	afx_msg void OnButtonGetSystempath();
	afx_msg void OnButtonGetUsername();
	afx_msg void OnButtonSetComputeName();
	afx_msg void OnButtonGetruntime();
	afx_msg void OnButtonGetstarttime();
	afx_msg void OnButtonGetstartmode();
	afx_msg void OnButtonGetProcessor();
	afx_msg void OnButtonGetScreenxy();
	afx_msg void OnButtonGetScreencolor();
	afx_msg void OnButtonGetEnrovar();
	afx_msg void OnButtonGetCpuid();
	afx_msg void OnButtonGetCpufrequency();
	afx_msg void OnButtonIsaudio();
	afx_msg void OnButtonGetspecialpath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMINFOSAMPLEDLG_H__E10DBC40_D19A_4400_9130_DD931F28F777__INCLUDED_)
