// MTSampleView.h : interface of the CMTSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTSAMPLEVIEW_H__463C56E3_CF54_4A5B_8DB1_6FF55B2C410A__INCLUDED_)
#define AFX_MTSAMPLEVIEW_H__463C56E3_CF54_4A5B_8DB1_6FF55B2C410A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ThreadRecv.h"
#include "ThreadSend.h"
#include "MTSampleDoc.h"

class CMTSampleView : public CView
{
protected: // create from serialization only
	CMTSampleView();
	DECLARE_DYNCREATE(CMTSampleView)

// Attributes
public:
	CMTSampleDoc* GetDocument();
	CThreadRecv* pThreadRecv;
	CThreadSend* pThreadSend;
	CClientDC *m_pDC;
	int y;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMTSampleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void WriteLog(CString log);
	virtual ~CMTSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMTSampleView)
	afx_msg void OnMenuitemStartrecvthread();
	afx_msg void OnMenuitemStartsendthread();
	afx_msg void OnMenuitemStopthread();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnRecvMsg(WPARAM wParam, LPARAM lParam);	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnCancelMode();
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MTSampleView.cpp
inline CMTSampleDoc* CMTSampleView::GetDocument()
   { return (CMTSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTSAMPLEVIEW_H__463C56E3_CF54_4A5B_8DB1_6FF55B2C410A__INCLUDED_)
