// NamedPipeServerSampleDlg.h : header file
//

#if !defined(AFX_NAMEDPIPESERVERSAMPLEDLG_H__084B3FDE_ABE4_418C_A670_1687C8FC7602__INCLUDED_)
#define AFX_NAMEDPIPESERVERSAMPLEDLG_H__084B3FDE_ABE4_418C_A670_1687C8FC7602__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNamedPipeServerSampleDlg dialog
UINT ListenProc(LPVOID lpVoid);
class CNamedPipeServerSampleDlg : public CDialog
{
// Construction
public:
	CNamedPipeServerSampleDlg(CWnd* pParent = NULL);	// standard constructor
	HANDLE m_hPipe;

// Dialog Data
	//{{AFX_DATA(CNamedPipeServerSampleDlg)
	enum { IDD = IDD_NAMEDPIPESERVERSAMPLE_DIALOG };
	CEdit	m_editLog;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedPipeServerSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNamedPipeServerSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPIPESERVERSAMPLEDLG_H__084B3FDE_ABE4_418C_A670_1687C8FC7602__INCLUDED_)
