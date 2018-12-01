// DiskInfoDlg.h : header file
//

#if !defined(AFX_DISKINFODLG_H__6FD9FC6A_4D1C_4866_96C0_0285736B1A9B__INCLUDED_)
#define AFX_DISKINFODLG_H__6FD9FC6A_4D1C_4866_96C0_0285736B1A9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskInfoDlg dialog

class CDiskInfoDlg : public CDialog
{
// Construction
public:
	void HandleDeviceChange(UINT message,   WPARAM   wParam,   LPARAM   lParam);
	char GetDriveFromMask (ULONG unitmask);
	void WriteLog(LPCTSTR format, ... );
	CDiskInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDiskInfoDlg)
	enum { IDD = IDD_DISKINFO_DIALOG };
	CEdit	m_editLog;
	CString	m_DiskName;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONGetMediaType();
	afx_msg void OnButtonCheckA();
	afx_msg void OnButtonGetvol();
	afx_msg void OnButtonGetmediatype();
	afx_msg void OnButtonGetserial();
	afx_msg void OnButtonGetfreespace();
	afx_msg void OnButtonCheckcdrom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKINFODLG_H__6FD9FC6A_4D1C_4866_96C0_0285736B1A9B__INCLUDED_)
