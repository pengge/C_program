#if !defined(AFX_DLGELLIP_H__2DDC8814_5567_44F7_A5CE_E1D809B164F5__INCLUDED_)
#define AFX_DLGELLIP_H__2DDC8814_5567_44F7_A5CE_E1D809B164F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgEllip.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgEllip dialog

class CDlgEllip : public CDialog
{
// Construction
public:
	CRgn m_rgnWnd;
	CDlgEllip(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgEllip)
	enum { IDD = IDD_DIALOG_ELLIPSEWND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEllip)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEllip)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGELLIP_H__2DDC8814_5567_44F7_A5CE_E1D809B164F5__INCLUDED_)
