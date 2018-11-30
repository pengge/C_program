// MAPISampleDoc.h : interface of the CMAPISampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPISAMPLEDOC_H__148CE919_ADEF_49F5_8763_B027E3255C68__INCLUDED_)
#define AFX_MAPISAMPLEDOC_H__148CE919_ADEF_49F5_8763_B027E3255C68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMAPISampleDoc : public CDocument
{
protected: // create from serialization only
	CMAPISampleDoc();
	DECLARE_DYNCREATE(CMAPISampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMAPISampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMAPISampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMAPISampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPISAMPLEDOC_H__148CE919_ADEF_49F5_8763_B027E3255C68__INCLUDED_)
