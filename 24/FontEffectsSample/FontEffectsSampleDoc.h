// FontEffectsSampleDoc.h : interface of the CFontEffectsSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FONTEFFECTSSAMPLEDOC_H__B644864A_467A_4D6A_B43F_7980D3641C07__INCLUDED_)
#define AFX_FONTEFFECTSSAMPLEDOC_H__B644864A_467A_4D6A_B43F_7980D3641C07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFontEffectsSampleDoc : public CDocument
{
protected: // create from serialization only
	CFontEffectsSampleDoc();
	DECLARE_DYNCREATE(CFontEffectsSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontEffectsSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetData();
	virtual ~CFontEffectsSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFontEffectsSampleDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_data;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTEFFECTSSAMPLEDOC_H__B644864A_467A_4D6A_B43F_7980D3641C07__INCLUDED_)
