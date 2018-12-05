// RedDLLDoc.h : interface of the CRedDLLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REDDLLDOC_H__1CA46DAC_D2B3_4CBB_9776_666E789D3124__INCLUDED_)
#define AFX_REDDLLDOC_H__1CA46DAC_D2B3_4CBB_9776_666E789D3124__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRedDLLDoc : public CDocument
{
protected: // create from serialization only
	CRedDLLDoc();
	DECLARE_DYNCREATE(CRedDLLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRedDLLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRedDLLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRedDLLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDDLLDOC_H__1CA46DAC_D2B3_4CBB_9776_666E789D3124__INCLUDED_)
