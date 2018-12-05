// DrawCubeDlg.h : header file
//

#if !defined(AFX_DRAWCUBEDLG_H__D0D765C8_778E_4623_92A0_FCC7A74E7C2A__INCLUDED_)
#define AFX_DRAWCUBEDLG_H__D0D765C8_778E_4623_92A0_FCC7A74E7C2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Cube3D.h"

/////////////////////////////////////////////////////////////////////////////
// CDrawCubeDlg dialog

class CDrawCubeDlg : public CDialog
{
// Construction
public:
	CDrawCubeDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL bCameraReset;  // 是否重置摄像机
    BOOL bFirstRender;  // 是否是第一次渲染
	Cube3D cube;

// Dialog Data
	//{{AFX_DATA(CDrawCubeDlg)
	enum { IDD = IDD_DRAWCUBE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawCubeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrawCubeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCUBEDLG_H__D0D765C8_778E_4623_92A0_FCC7A74E7C2A__INCLUDED_)
