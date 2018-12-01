// MessageReceiveSampleDlg.h : header file
//

#if !defined(AFX_MESSAGERECEIVESAMPLEDLG_H__7870E1A9_CAE5_442B_8C60_A180F3C40BF4__INCLUDED_)
#define AFX_MESSAGERECEIVESAMPLEDLG_H__7870E1A9_CAE5_442B_8C60_A180F3C40BF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMessageReceiveSampleDlg dialog

class CMessageReceiveSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);	// ¼ÇÂ¼ÈÕÖ¾
	CMessageReceiveSampleDlg(CWnd* pParent = NULL);	// standard constructor
	UINT myMsg;

// Dialog Data
	//{{AFX_DATA(CMessageReceiveSampleDlg)
	enum { IDD = IDD_MESSAGERECEIVESAMPLE_DIALOG };
	CEdit	m_editLog;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageReceiveSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMessageReceiveSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGERECEIVESAMPLEDLG_H__7870E1A9_CAE5_442B_8C60_A180F3C40BF4__INCLUDED_)
