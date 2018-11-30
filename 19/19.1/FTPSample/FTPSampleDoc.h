// FTPSampleDoc.h : interface of the CFTPSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPSAMPLEDOC_H__BFD7AF9F_A4CA_4E46_93ED_B1F9A724EEF8__INCLUDED_)
#define AFX_FTPSAMPLEDOC_H__BFD7AF9F_A4CA_4E46_93ED_B1F9A724EEF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFTPSampleDoc : public CDocument
{
protected: // create from serialization only
	CFTPSampleDoc();
	DECLARE_DYNCREATE(CFTPSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFTPSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFTPSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPSAMPLEDOC_H__BFD7AF9F_A4CA_4E46_93ED_B1F9A724EEF8__INCLUDED_)
