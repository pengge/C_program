// statusbarSampleDoc.h : interface of the CStatusbarSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSBARSAMPLEDOC_H__91464D95_14FC_40D2_A0A8_5945F4138D4B__INCLUDED_)
#define AFX_STATUSBARSAMPLEDOC_H__91464D95_14FC_40D2_A0A8_5945F4138D4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusbarSampleDoc : public CDocument
{
protected: // create from serialization only
	CStatusbarSampleDoc();
	DECLARE_DYNCREATE(CStatusbarSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusbarSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStatusbarSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusbarSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSBARSAMPLEDOC_H__91464D95_14FC_40D2_A0A8_5945F4138D4B__INCLUDED_)
