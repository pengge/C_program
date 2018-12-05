// GDIBaseSampleDoc.h : interface of the CGDIBaseSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIBASESAMPLEDOC_H__6EE34F2B_E816_46B2_B8AF_A6EE4A588C3A__INCLUDED_)
#define AFX_GDIBASESAMPLEDOC_H__6EE34F2B_E816_46B2_B8AF_A6EE4A588C3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIBaseSampleDoc : public CDocument
{
protected: // create from serialization only
	CGDIBaseSampleDoc();
	DECLARE_DYNCREATE(CGDIBaseSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIBaseSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGDIBaseSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIBaseSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIBASESAMPLEDOC_H__6EE34F2B_E816_46B2_B8AF_A6EE4A588C3A__INCLUDED_)
