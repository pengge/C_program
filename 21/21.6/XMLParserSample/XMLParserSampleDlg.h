// XMLParserSampleDlg.h : header file
//

#if !defined(AFX_XMLPARSERSAMPLEDLG_H__C87A91B1_CC73_4A30_9CA6_623A050839FC__INCLUDED_)
#define AFX_XMLPARSERSAMPLEDLG_H__C87A91B1_CC73_4A30_9CA6_623A050839FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXMLParserSampleDlg dialog

class CXMLParserSampleDlg : public CDialog
{
// Construction
public:
	CXMLParserSampleDlg(CWnd* pParent = NULL);	// standard constructor
	void WriteLog(CString log);

// Dialog Data
	//{{AFX_DATA(CXMLParserSampleDlg)
	enum { IDD = IDD_XMLPARSERSAMPLE_DIALOG };
	CEdit	m_editLog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLParserSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CXMLParserSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonReadXml();
	afx_msg void OnButtonWriteXml();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLPARSERSAMPLEDLG_H__C87A91B1_CC73_4A30_9CA6_623A050839FC__INCLUDED_)
