#if !defined(AFX_PAGESTUDENT_H__C95C67E8_C522_4162_9D8E_91B505B7A550__INCLUDED_)
#define AFX_PAGESTUDENT_H__C95C67E8_C522_4162_9D8E_91B505B7A550__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageStudent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageStudent dialog

class CPageStudent : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageStudent)

// Construction
public:
	CPageStudent();
	~CPageStudent();

// Dialog Data
	//{{AFX_DATA(CPageStudent)
	enum { IDD = IDD_DIALOG_STUDENT };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageStudent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageStudent)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESTUDENT_H__C95C67E8_C522_4162_9D8E_91B505B7A550__INCLUDED_)
