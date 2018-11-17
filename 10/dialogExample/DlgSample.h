#if !defined(AFX_DLGSAMPLE_H__699C8236_B97A_455A_90A7_0E6611676F7B__INCLUDED_)
#define AFX_DLGSAMPLE_H__699C8236_B97A_455A_90A7_0E6611676F7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSample.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSample dialog

class CDlgSample : public CDialog
{
// Construction
public:
	CDlgSample(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSample)
	enum { IDD = IDD_DIALOG1 };
	CString	m_editName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSample)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSample)
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSAMPLE_H__699C8236_B97A_455A_90A7_0E6611676F7B__INCLUDED_)
