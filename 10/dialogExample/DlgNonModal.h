#if !defined(AFX_DLGNONMODAL_H__228F6803_0BA1_4B65_949E_5CA8BED15444__INCLUDED_)
#define AFX_DLGNONMODAL_H__228F6803_0BA1_4B65_949E_5CA8BED15444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgNonModal.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgNonModal dialog

class CDlgNonModal : public CDialog
{
// Construction
public:
	CDlgNonModal(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgNonModal)
	enum { IDD = IDD_DIALOG_NONMODAL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgNonModal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgNonModal)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGNONMODAL_H__228F6803_0BA1_4B65_949E_5CA8BED15444__INCLUDED_)
