#if !defined(AFX_SUBTHREAD_H__0209D324_6AAB_4FBE_B5C2_93A3DE29D2AA__INCLUDED_)
#define AFX_SUBTHREAD_H__0209D324_6AAB_4FBE_B5C2_93A3DE29D2AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubThread.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSubThread thread

class CSubThread : public CWinThread
{
	DECLARE_DYNCREATE(CSubThread)
protected:
	CSubThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	BOOL bRun;
	int iIndex;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual int Run();
	afx_msg void ReceiveThreadMsg( UINT wParam, LONG lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSubThread();

	// Generated message map functions
	//{{AFX_MSG(CSubThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBTHREAD_H__0209D324_6AAB_4FBE_B5C2_93A3DE29D2AA__INCLUDED_)
