// PipeServerSampleDlg.h : header file
//

#if !defined(AFX_PIPESERVERSAMPLEDLG_H__31D8C684_B821_4FD7_8EE6_69686432EE47__INCLUDED_)
#define AFX_PIPESERVERSAMPLEDLG_H__31D8C684_B821_4FD7_8EE6_69686432EE47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPipeServerSampleDlg dialog

class CPipeServerSampleDlg : public CDialog
{
// Construction
public:
	CPipeServerSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPipeServerSampleDlg)
	enum { IDD = IDD_PIPESERVERSAMPLE_DIALOG };
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPipeServerSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPipeServerSampleDlg)
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

#endif // !defined(AFX_PIPESERVERSAMPLEDLG_H__31D8C684_B821_4FD7_8EE6_69686432EE47__INCLUDED_)
