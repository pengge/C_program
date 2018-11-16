// SDISampleDoc.h : interface of the CSDISampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDISAMPLEDOC_H__81E383E0_D538_48CC_945C_1E82CB9CFDB7__INCLUDED_)
#define AFX_SDISAMPLEDOC_H__81E383E0_D538_48CC_945C_1E82CB9CFDB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSDISampleDoc : public CDocument
{
protected: // create from serialization only
	CSDISampleDoc();
	DECLARE_DYNCREATE(CSDISampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDISampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetData() {return m_data;};
	virtual ~CSDISampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDISampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_data;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDISAMPLEDOC_H__81E383E0_D538_48CC_945C_1E82CB9CFDB7__INCLUDED_)
