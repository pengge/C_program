// FaceAppSampleDoc.h : interface of the CFaceAppSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACEAPPSAMPLEDOC_H__95ED5278_0D81_42A2_95E6_C1F3550876D0__INCLUDED_)
#define AFX_FACEAPPSAMPLEDOC_H__95ED5278_0D81_42A2_95E6_C1F3550876D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceAppSampleDoc : public CDocument
{
protected: // create from serialization only
	CFaceAppSampleDoc();
	DECLARE_DYNCREATE(CFaceAppSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceAppSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFaceAppSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFaceAppSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FACEAPPSAMPLEDOC_H__95ED5278_0D81_42A2_95E6_C1F3550876D0__INCLUDED_)
