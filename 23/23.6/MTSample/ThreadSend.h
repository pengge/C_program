#if !defined(AFX_THREADSEND_H__708EC4EB_8C1E_4E3A_B2A8_D5F4B212FE12__INCLUDED_)
#define AFX_THREADSEND_H__708EC4EB_8C1E_4E3A_B2A8_D5F4B212FE12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadSend.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CThreadSend thread

class CThreadSend : public CWinThread
{
	DECLARE_DYNCREATE(CThreadSend)
protected:
	CThreadSend();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	int iIndex;
	BOOL bRun;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSend)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CThreadSend();

	// Generated message map functions
	//{{AFX_MSG(CThreadSend)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSEND_H__708EC4EB_8C1E_4E3A_B2A8_D5F4B212FE12__INCLUDED_)
