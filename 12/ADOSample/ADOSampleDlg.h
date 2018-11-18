// ADOSampleDlg.h : header file
//

#if !defined(AFX_ADOSAMPLEDLG_H__4C447F42_ABD7_4430_BEC8_3D0D21EFC84F__INCLUDED_)
#define AFX_ADOSAMPLEDLG_H__4C447F42_ABD7_4430_BEC8_3D0D21EFC84F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOSampleDlg dialog

class CADOSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(CString log);
	void GetRecordContent();
	CADOSampleDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;	//连接对象
	_RecordsetPtr m_pRecordset;		//记录对象	

// Dialog Data
	//{{AFX_DATA(CADOSampleDlg)
	enum { IDD = IDD_ADOSAMPLE_DIALOG };
	CEdit	m_editLog;
	CString	m_FirstName;
	CString	m_ID;
	CString	m_LastName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	afx_msg void OnDestroy();
	afx_msg void OnButtonReadrecord();
	afx_msg void OnButtonFirst();
	afx_msg void OnButtonLast();
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonWriterecord();
	afx_msg void OnButtonDelrecord2();
	afx_msg void OnButtonExeproc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSAMPLEDLG_H__4C447F42_ABD7_4430_BEC8_3D0D21EFC84F__INCLUDED_)
