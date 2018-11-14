// menuSampleDoc.h : interface of the CMenuSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUSAMPLEDOC_H__EDC0E8BE_552E_45FB_B94A_B8B72FEE622C__INCLUDED_)
#define AFX_MENUSAMPLEDOC_H__EDC0E8BE_552E_45FB_B94A_B8B72FEE622C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuSampleDoc : public CDocument
{
protected: // create from serialization only
	CMenuSampleDoc();
	DECLARE_DYNCREATE(CMenuSampleDoc)

// Attributes
public:
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenuSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuSampleDoc)	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuitemsettitle();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUSAMPLEDOC_H__EDC0E8BE_552E_45FB_B94A_B8B72FEE622C__INCLUDED_)
