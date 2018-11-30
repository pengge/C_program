// FTPSampleView.h : interface of the CFTPSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FTPSAMPLEVIEW_H__B40AA951_AD08_4EC6_854F_DA7C0ED570D7__INCLUDED_)
#define AFX_FTPSAMPLEVIEW_H__B40AA951_AD08_4EC6_854F_DA7C0ED570D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxinet.h"

class CFTPSampleView : public CFormView
{
protected: // create from serialization only
	CFTPSampleView();
	
	CFtpConnection* m_pFtpConnection;		// FTP¡¨Ω”¿‡
	
	DECLARE_DYNCREATE(CFTPSampleView)

public:
	//{{AFX_DATA(CFTPSampleView)
	enum { IDD = IDD_FTPSAMPLE_FORM };
	CListBox	m_fileCtrl;
	CString	m_Address;
	CString	m_UserName;
	CString	m_Password;
	//}}AFX_DATA

// Attributes
public:
	CFTPSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPSampleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SaveFile();
	void ShowFiles();
	virtual ~CFTPSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFTPSampleView)
	afx_msg void OnButtonGoto();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FTPSampleView.cpp
inline CFTPSampleDoc* CFTPSampleView::GetDocument()
   { return (CFTPSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPSAMPLEVIEW_H__B40AA951_AD08_4EC6_854F_DA7C0ED570D7__INCLUDED_)
