// DrawPictureSampleDoc.h : interface of the CDrawPictureSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWPICTURESAMPLEDOC_H__7B8DD2F4_BB09_4CB2_A89E_F1F1E5E8182C__INCLUDED_)
#define AFX_DRAWPICTURESAMPLEDOC_H__7B8DD2F4_BB09_4CB2_A89E_F1F1E5E8182C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawPictureSampleDoc : public CDocument
{
protected: // create from serialization only
	CDrawPictureSampleDoc();
	DECLARE_DYNCREATE(CDrawPictureSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawPictureSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawPictureSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawPictureSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWPICTURESAMPLEDOC_H__7B8DD2F4_BB09_4CB2_A89E_F1F1E5E8182C__INCLUDED_)
