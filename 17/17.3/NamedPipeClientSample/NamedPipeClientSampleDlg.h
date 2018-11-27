// NamedPipeClientSampleDlg.h : header file
//

#if !defined(AFX_NAMEDPIPECLIENTSAMPLEDLG_H__CAF5F05D_A634_45E5_9E67_74B2555DD6FE__INCLUDED_)
#define AFX_NAMEDPIPECLIENTSAMPLEDLG_H__CAF5F05D_A634_45E5_9E67_74B2555DD6FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNamedPipeClientSampleDlg dialog

class CNamedPipeClientSampleDlg : public CDialog
{
// Construction
public:
	CNamedPipeClientSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNamedPipeClientSampleDlg)
	enum { IDD = IDD_NAMEDPIPECLIENTSAMPLE_DIALOG };
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedPipeClientSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNamedPipeClientSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPIPECLIENTSAMPLEDLG_H__CAF5F05D_A634_45E5_9E67_74B2555DD6FE__INCLUDED_)
