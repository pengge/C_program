#if !defined(AFX_DLGTEST2_H__768A0A77_2E11_411D_9C03_EA92182F4EE6__INCLUDED_)
#define AFX_DLGTEST2_H__768A0A77_2E11_411D_9C03_EA92182F4EE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTest2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgTest2 dialog

class CDlgTest2 : public CDialog
{
// Construction
public:
	CDlgTest2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTest2)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_editLog;
	CString	m_szLog;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTest2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTest2)
	afx_msg void OnButtonTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTEST2_H__768A0A77_2E11_411D_9C03_EA92182F4EE6__INCLUDED_)
