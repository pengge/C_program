// ODBCAPISampleDoc.h : interface of the CODBCAPISampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCAPISAMPLEDOC_H__B49C848F_53BE_4183_845C_C85630DB87AE__INCLUDED_)
#define AFX_ODBCAPISAMPLEDOC_H__B49C848F_53BE_4183_845C_C85630DB87AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CODBCAPISampleDoc : public CDocument
{
protected: // create from serialization only
	CODBCAPISampleDoc();
	DECLARE_DYNCREATE(CODBCAPISampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCAPISampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBCAPISampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBCAPISampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCAPISAMPLEDOC_H__B49C848F_53BE_4183_845C_C85630DB87AE__INCLUDED_)
