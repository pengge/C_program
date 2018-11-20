// MFCODBCSampleDoc.h : interface of the CMFCODBCSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCODBCSAMPLEDOC_H__EDE6811D_D6A9_495E_B96F_0DC8DC84067A__INCLUDED_)
#define AFX_MFCODBCSAMPLEDOC_H__EDE6811D_D6A9_495E_B96F_0DC8DC84067A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MFCODBCSampleSet.h"


class CMFCODBCSampleDoc : public CDocument
{
protected: // create from serialization only
	CMFCODBCSampleDoc();
	DECLARE_DYNCREATE(CMFCODBCSampleDoc)

// Attributes
public:
	CMFCODBCSampleSet m_mFCODBCSampleSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCODBCSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCODBCSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCODBCSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMFCODBCSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCODBCSAMPLEDOC_H__EDE6811D_D6A9_495E_B96F_0DC8DC84067A__INCLUDED_)
