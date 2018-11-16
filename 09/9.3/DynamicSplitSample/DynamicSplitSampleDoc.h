// DynamicSplitSampleDoc.h : interface of the CDynamicSplitSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMICSPLITSAMPLEDOC_H__B46C1564_652E_47A6_9980_A1843A3BF37A__INCLUDED_)
#define AFX_DYNAMICSPLITSAMPLEDOC_H__B46C1564_652E_47A6_9980_A1843A3BF37A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynamicSplitSampleDoc : public CDocument
{
protected: // create from serialization only
	CDynamicSplitSampleDoc();
	DECLARE_DYNCREATE(CDynamicSplitSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicSplitSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynamicSplitSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynamicSplitSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICSPLITSAMPLEDOC_H__B46C1564_652E_47A6_9980_A1843A3BF37A__INCLUDED_)
