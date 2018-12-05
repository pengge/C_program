// GDIEffectSampleDoc.h : interface of the CGDIEffectSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIEFFECTSAMPLEDOC_H__FE6955A5_C9E0_47D7_80EB_08E5979C63D8__INCLUDED_)
#define AFX_GDIEFFECTSAMPLEDOC_H__FE6955A5_C9E0_47D7_80EB_08E5979C63D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIEffectSampleDoc : public CDocument
{
protected: // create from serialization only
	CGDIEffectSampleDoc();
	DECLARE_DYNCREATE(CGDIEffectSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIEffectSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGDIEffectSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIEffectSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIEFFECTSAMPLEDOC_H__FE6955A5_C9E0_47D7_80EB_08E5979C63D8__INCLUDED_)
