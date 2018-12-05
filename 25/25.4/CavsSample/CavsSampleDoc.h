// CavsSampleDoc.h : interface of the CCavsSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAVSSAMPLEDOC_H__A52A0254_B80E_4E1A_AA8F_AFA5E9FDBAC3__INCLUDED_)
#define AFX_CAVSSAMPLEDOC_H__A52A0254_B80E_4E1A_AA8F_AFA5E9FDBAC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCavsSampleDoc : public CDocument
{
protected: // create from serialization only
	CCavsSampleDoc();
	DECLARE_DYNCREATE(CCavsSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCavsSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCavsSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCavsSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAVSSAMPLEDOC_H__A52A0254_B80E_4E1A_AA8F_AFA5E9FDBAC3__INCLUDED_)
