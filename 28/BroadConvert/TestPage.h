#if !defined(AFX_TESTPAGE_H__98E189E4_1D13_4262_B631_1F52C3C7716A__INCLUDED_)
#define AFX_TESTPAGE_H__98E189E4_1D13_4262_B631_1F52C3C7716A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestPage dialog

class CTestPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTestPage)

// Construction
public:
	CTestPage();
	~CTestPage();

// Dialog Data
	//{{AFX_DATA(CTestPage)
	enum { IDD = IDD_DIALOG1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTestPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTestPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPAGE_H__98E189E4_1D13_4262_B631_1F52C3C7716A__INCLUDED_)
