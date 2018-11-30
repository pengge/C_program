// GopherSampleDoc.h : interface of the CGopherSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOPHERSAMPLEDOC_H__ECA5EFA0_346E_404A_8497_6EF7AF319597__INCLUDED_)
#define AFX_GOPHERSAMPLEDOC_H__ECA5EFA0_346E_404A_8497_6EF7AF319597__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGopherSampleDoc : public CDocument
{
protected: // create from serialization only
	CGopherSampleDoc();
	DECLARE_DYNCREATE(CGopherSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGopherSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGopherSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGopherSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOPHERSAMPLEDOC_H__ECA5EFA0_346E_404A_8497_6EF7AF319597__INCLUDED_)
