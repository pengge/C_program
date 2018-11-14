// LBAndCBSampleDlg.h : header file
//

#if !defined(AFX_LBANDCBSAMPLEDLG_H__1C402192_5078_4A9E_915C_C5CD0A851C91__INCLUDED_)
#define AFX_LBANDCBSAMPLEDLG_H__1C402192_5078_4A9E_915C_C5CD0A851C91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLBAndCBSampleDlg dialog

class CLBAndCBSampleDlg : public CDialog
{
// Construction
public:
	void InitComboBoxData();
	void InitListBoxData();
	CLBAndCBSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLBAndCBSampleDlg)
	enum { IDD = IDD_LBANDCBSAMPLE_DIALOG };
	CListBox	m_listTest;
	CComboBox	m_comboTest;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLBAndCBSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLBAndCBSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeListTest();
	afx_msg void OnSelchangeComboTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LBANDCBSAMPLEDLG_H__1C402192_5078_4A9E_915C_C5CD0A851C91__INCLUDED_)
