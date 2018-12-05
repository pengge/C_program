// GreenDLLDoc.h : interface of the CGreenDLLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GREENDLLDOC_H__AE3E4F75_E8AF_4B80_AB4D_2B9936A00529__INCLUDED_)
#define AFX_GREENDLLDOC_H__AE3E4F75_E8AF_4B80_AB4D_2B9936A00529__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGreenDLLDoc : public CDocument
{
protected: // create from serialization only
	CGreenDLLDoc();
	DECLARE_DYNCREATE(CGreenDLLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGreenDLLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGreenDLLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGreenDLLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREENDLLDOC_H__AE3E4F75_E8AF_4B80_AB4D_2B9936A00529__INCLUDED_)
