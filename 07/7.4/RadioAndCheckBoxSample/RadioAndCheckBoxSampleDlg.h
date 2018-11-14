// RadioAndCheckBoxSampleDlg.h : header file
//

#if !defined(AFX_RADIOANDCHECKBOXSAMPLEDLG_H__725FC19C_749A_4175_B274_42207F646DED__INCLUDED_)
#define AFX_RADIOANDCHECKBOXSAMPLEDLG_H__725FC19C_749A_4175_B274_42207F646DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRadioAndCheckBoxSampleDlg dialog

class CRadioAndCheckBoxSampleDlg : public CDialog
{
// Construction
public:
	CRadioAndCheckBoxSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRadioAndCheckBoxSampleDlg)
	enum { IDD = IDD_RADIOANDCHECKBOXSAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRadioAndCheckBoxSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRadioAndCheckBoxSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGetstate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RADIOANDCHECKBOXSAMPLEDLG_H__725FC19C_749A_4175_B274_42207F646DED__INCLUDED_)
