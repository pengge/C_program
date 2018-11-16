// MDISampleDoc.h : interface of the CMDISampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDISAMPLEDOC_H__8965DDDF_897F_4630_A5A7_3F63CCC22245__INCLUDED_)
#define AFX_MDISAMPLEDOC_H__8965DDDF_897F_4630_A5A7_3F63CCC22245__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDISampleDoc : public CDocument
{
protected: // create from serialization only
	CMDISampleDoc();
	DECLARE_DYNCREATE(CMDISampleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDISampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_Data;
	virtual ~CMDISampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDISampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDISAMPLEDOC_H__8965DDDF_897F_4630_A5A7_3F63CCC22245__INCLUDED_)
