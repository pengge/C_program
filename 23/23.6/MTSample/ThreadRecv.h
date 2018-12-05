#if !defined(AFX_THREADRECV_H__93C04247_9C58_4E29_8684_3D7CABABE824__INCLUDED_)
#define AFX_THREADRECV_H__93C04247_9C58_4E29_8684_3D7CABABE824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadRecv.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CThreadRecv thread

class CThreadRecv : public CWinThread
{
	DECLARE_DYNCREATE(CThreadRecv)
protected:
	CThreadRecv();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	BOOL bRun;
	HWND hParent;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadRecv)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CThreadRecv();

	// Generated message map functions
	//{{AFX_MSG(CThreadRecv)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADRECV_H__93C04247_9C58_4E29_8684_3D7CABABE824__INCLUDED_)
