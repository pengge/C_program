// MSCOMMSampleDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_MSCOMMSAMPLEDLG_H__DEED4409_CF1C_4089_8C05_BE4A7A2B9F27__INCLUDED_)
#define AFX_MSCOMMSAMPLEDLG_H__DEED4409_CF1C_4089_8C05_BE4A7A2B9F27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMSCOMMSampleDlg dialog

class CMSCOMMSampleDlg : public CDialog
{
// Construction
public:
	CMSCOMMSampleDlg(CWnd* pParent = NULL);	// standard constructor
	void WriteLog(CString log);

// Dialog Data
	//{{AFX_DATA(CMSCOMMSampleDlg)
	enum { IDD = IDD_MSCOMMSAMPLE_DIALOG };
	CString	m_editReceive;
	CString	m_editSend;
	CMSComm	m_Comm;
	CString	m_Log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSCOMMSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMSCOMMSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnButtonSend();
	afx_msg void OnButtonOpen();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSCOMMSAMPLEDLG_H__DEED4409_CF1C_4089_8C05_BE4A7A2B9F27__INCLUDED_)
