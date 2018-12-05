// DrawTriangleDlg.h : header file
//

#if !defined(AFX_DRAWTRIANGLEDLG_H__5E1B6FC2_CF8E_4660_95B2_FFEA9441DB9B__INCLUDED_)
#define AFX_DRAWTRIANGLEDLG_H__5E1B6FC2_CF8E_4660_95B2_FFEA9441DB9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TRIANGLE3D.h"

/////////////////////////////////////////////////////////////////////////////
// CDrawTriangleDlg dialog

class CDrawTriangleDlg : public CDialog
{
// Construction
public:
	CDrawTriangleDlg(CWnd* pParent = NULL);	// standard constructor
	TRIANGLE3D triangle;

// Dialog Data
	//{{AFX_DATA(CDrawTriangleDlg)
	enum { IDD = IDD_DRAWTRIANGLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTriangleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrawTriangleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTRIANGLEDLG_H__5E1B6FC2_CF8E_4660_95B2_FFEA9441DB9B__INCLUDED_)
