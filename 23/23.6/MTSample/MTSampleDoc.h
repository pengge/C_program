// MTSampleDoc.h : interface of the CMTSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTSAMPLEDOC_H__FDC8CF1B_DA16_4D6F_AC98_8A0BCAE2DB63__INCLUDED_)
#define AFX_MTSAMPLEDOC_H__FDC8CF1B_DA16_4D6F_AC98_8A0BCAE2DB63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CMTSampleDoc : public CDocument
{
protected: // create from serialization only
	CMTSampleDoc();
	DECLARE_DYNCREATE(CMTSampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMTSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	void StartThreadRecv();
	
	virtual ~CMTSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMTSampleDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTSAMPLEDOC_H__FDC8CF1B_DA16_4D6F_AC98_8A0BCAE2DB63__INCLUDED_)
