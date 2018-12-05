// GDIControlDoc.h : interface of the CGDIControlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDICONTROLDOC_H__14B3CB70_F85C_4FD3_BB93_CF174C17CD29__INCLUDED_)
#define AFX_GDICONTROLDOC_H__14B3CB70_F85C_4FD3_BB93_CF174C17CD29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIControlDoc : public CDocument
{
protected: // create from serialization only
	CGDIControlDoc();
	DECLARE_DYNCREATE(CGDIControlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIControlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGDIControlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIControlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDICONTROLDOC_H__14B3CB70_F85C_4FD3_BB93_CF174C17CD29__INCLUDED_)
