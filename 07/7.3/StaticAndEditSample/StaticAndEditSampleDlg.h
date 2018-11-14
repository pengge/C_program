// StaticAndEditSampleDlg.h : header file
//

#if !defined(AFX_STATICANDEDITSAMPLEDLG_H__EA170EC4_9A89_4D06_A735_3C4D64D712E0__INCLUDED_)
#define AFX_STATICANDEDITSAMPLEDLG_H__EA170EC4_9A89_4D06_A735_3C4D64D712E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticAndEditSampleDlg dialog

class CStaticAndEditSampleDlg : public CDialog
{
// Construction
public:
	void WriteLog(CString message, CString title);
	CStaticAndEditSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStaticAndEditSampleDlg)
	enum { IDD = IDD_STATICANDEDITSAMPLE_DIALOG };
	CEdit	m_editTestScroll;
	CEdit	m_editTest;
	CStatic	m_staticLog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticAndEditSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStaticAndEditSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEditTest();
	afx_msg void OnErrspaceEditTest();
	afx_msg void OnKillfocusEditTest();
	afx_msg void OnMaxtextEditTest();
	afx_msg void OnSetfocusEditTest();
	afx_msg void OnUpdateEditTest();
	afx_msg void OnHscrollEditTestScroll();
	afx_msg void OnVscrollEditTestScroll();
	afx_msg void OnButtonGetedittext();
	afx_msg void OnButtonSetedittext();
	afx_msg void OnButtonGetline();
	afx_msg void OnButtonGetsel();
	afx_msg void OnButtonSetsel();
	afx_msg void OnButtonReplacesel();
	afx_msg void OnStaticTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICANDEDITSAMPLEDLG_H__EA170EC4_9A89_4D06_A735_3C4D64D712E0__INCLUDED_)
