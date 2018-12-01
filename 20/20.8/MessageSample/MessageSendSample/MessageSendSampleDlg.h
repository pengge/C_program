// MessageSendSampleDlg.h : header file
//

#if !defined(AFX_MESSAGESENDSAMPLEDLG_H__D8857D45_8068_476F_8739_FA2F209F249F__INCLUDED_)
#define AFX_MESSAGESENDSAMPLEDLG_H__D8857D45_8068_476F_8739_FA2F209F249F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMessageSendSampleDlg dialog

class CMessageSendSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(LPCTSTR format,...);	// ¼ÇÂ¼ÈÕÖ¾
	CMessageSendSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMessageSendSampleDlg)
	enum { IDD = IDD_MESSAGESENDSAMPLE_DIALOG };
	CString	m_content;
	CString	m_sender;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageSendSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMessageSendSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSendCopydata();
	afx_msg void OnButtonSendMymessage();
	afx_msg void OnButtonRegmessage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGESENDSAMPLEDLG_H__D8857D45_8068_476F_8739_FA2F209F249F__INCLUDED_)
