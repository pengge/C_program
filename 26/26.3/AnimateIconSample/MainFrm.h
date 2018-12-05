// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__883FDC9D_E948_4C51_A7A6_12847DF21B52__INCLUDED_)
#define AFX_MAINFRM_H__883FDC9D_E948_4C51_A7A6_12847DF21B52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	CImageList m_TBImgList;
	CImageList m_SBImgList;

	int m_iTBIconCounter;
	int m_iMaxTBIcon;

	int m_iSBIconCounter;
	int m_iMaxSBIcon;
	int m_iIconCounter;

	HICON hTBIcon;
	HICON hTBPrevIcon;

	HICON hSBIcon;
	HICON hSBPrevIcon;

	BOOL SetTBImageList(int imageListID,int iMaxIcons, COLORREF tc);
	BOOL ShowTBNextIcon();

	BOOL SetSBImageList(int imageListID,int iMaxIcons, COLORREF tc);
	BOOL ShowSBNextIcon();

	BOOL DrawNextIcon();


	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__883FDC9D_E948_4C51_A7A6_12847DF21B52__INCLUDED_)
