#if !defined(AFX_PAGETEACHER_H__022C3FF7_A5EE_4294_934B_A652FF384A9A__INCLUDED_)
#define AFX_PAGETEACHER_H__022C3FF7_A5EE_4294_934B_A652FF384A9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTeacher.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageTeacher dialog

class CPageTeacher : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageTeacher)

// Construction
public:
	CPageTeacher();
	~CPageTeacher();

// Dialog Data
	//{{AFX_DATA(CPageTeacher)
	enum { IDD = IDD_DIALOG_TEACHER };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageTeacher)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageTeacher)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETEACHER_H__022C3FF7_A5EE_4294_934B_A652FF384A9A__INCLUDED_)
