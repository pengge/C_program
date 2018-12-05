// AnimateIconSampleDoc.h : interface of the CAnimateIconSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIMATEICONSAMPLEDOC_H__5EACA6FC_C09C_4592_9FB4_CBD09CCDDB8A__INCLUDED_)
#define AFX_ANIMATEICONSAMPLEDOC_H__5EACA6FC_C09C_4592_9FB4_CBD09CCDDB8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAnimateIconSampleDoc : public CDocument
{
protected: // create from serialization only
	CAnimateIconSampleDoc();
	DECLARE_DYNCREATE(CAnimateIconSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateIconSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAnimateIconSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAnimateIconSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATEICONSAMPLEDOC_H__5EACA6FC_C09C_4592_9FB4_CBD09CCDDB8A__INCLUDED_)
