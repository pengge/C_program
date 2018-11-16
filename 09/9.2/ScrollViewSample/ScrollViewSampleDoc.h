// ScrollViewSampleDoc.h : interface of the CScrollViewSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCROLLVIEWSAMPLEDOC_H__A9FEBB5F_0C4C_46BA_9136_C9F3D578EFD8__INCLUDED_)
#define AFX_SCROLLVIEWSAMPLEDOC_H__A9FEBB5F_0C4C_46BA_9136_C9F3D578EFD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CScrollViewSampleDoc : public CDocument
{
protected: // create from serialization only
	CScrollViewSampleDoc();
	DECLARE_DYNCREATE(CScrollViewSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollViewSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScrollViewSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScrollViewSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLVIEWSAMPLEDOC_H__A9FEBB5F_0C4C_46BA_9136_C9F3D578EFD8__INCLUDED_)
