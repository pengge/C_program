// DiskOperDlg.h : header file
//

#if !defined(AFX_DISKOPERDLG_H__9891CB08_E759_47C3_8897_98E2A93150A8__INCLUDED_)
#define AFX_DISKOPERDLG_H__9891CB08_E759_47C3_8897_98E2A93150A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskOperDlg dialog

class CDiskOperDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);	// ¼ÇÂ¼ÈÕÖ¾
	BOOL bMonitor;
	CDiskOperDlg(CWnd* pParent = NULL);	// standard constructor
	char szPath[MAX_PATH];

// Dialog Data
	//{{AFX_DATA(CDiskOperDlg)
	enum { IDD = IDD_DISKOPER_DIALOG };
	CString	m_Log;
	CString	m_DiskName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskOperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskOperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFormat();
	afx_msg void OnButtonMonitorDisk();
	afx_msg void OnButtonHidedisk();
	afx_msg void OnButtonDelshare();
	afx_msg void OnButtonSetvolum();
	afx_msg void OnButtonFat32tontfs();
	afx_msg void OnButtonUpdatediskno();
	afx_msg void OnButtonShowdisk();
	afx_msg void OnButtonSpzl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKOPERDLG_H__9891CB08_E759_47C3_8897_98E2A93150A8__INCLUDED_)
