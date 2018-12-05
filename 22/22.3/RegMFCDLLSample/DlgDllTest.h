#if !defined(AFX_DLGDLLTEST_H__646CF4F7_E92D_4D26_91C3_D19DFD55AB16__INCLUDED_)
#define AFX_DLGDLLTEST_H__646CF4F7_E92D_4D26_91C3_D19DFD55AB16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDllTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDllTest dialog

class CDlgDllTest : public CDialog
{
// Construction
public:
	CDlgDllTest(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDllTest)
	enum { IDD = IDD_DIALOG_DLL_TEST };
	CStatic	m_static;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDllTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDllTest)
	afx_msg void OnButtonHello();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDLLTEST_H__646CF4F7_E92D_4D26_91C3_D19DFD55AB16__INCLUDED_)
