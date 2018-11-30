// HTTPSampleDoc.h : interface of the CHTTPSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTTPSAMPLEDOC_H__7FEEF7D0_DDCC_4BDD_8BBB_84132F45D5AD__INCLUDED_)
#define AFX_HTTPSAMPLEDOC_H__7FEEF7D0_DDCC_4BDD_8BBB_84132F45D5AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHTTPSampleDoc : public CDocument
{
protected: // create from serialization only
	CHTTPSampleDoc();
	DECLARE_DYNCREATE(CHTTPSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTTPSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHTTPSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHTTPSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPSAMPLEDOC_H__7FEEF7D0_DDCC_4BDD_8BBB_84132F45D5AD__INCLUDED_)
