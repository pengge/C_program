#if !defined(AFX_DLGEXTDLL_H__D259C7F7_4675_429D_95F2_CA55EB43D6A7__INCLUDED_)
#define AFX_DLGEXTDLL_H__D259C7F7_4675_429D_95F2_CA55EB43D6A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgExtDLL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgExtDLL dialog

class AFX_EXT_CLASS CDlgExtDLL : public CDialog
{
// Construction
public:
	CDlgExtDLL(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgExtDLL)
	enum { IDD = IDD_DIALOG_EXTDLL };
	CStatic	m_static;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgExtDLL)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgExtDLL)
	afx_msg void OnButtonHello();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEXTDLL_H__D259C7F7_4675_429D_95F2_CA55EB43D6A7__INCLUDED_)
