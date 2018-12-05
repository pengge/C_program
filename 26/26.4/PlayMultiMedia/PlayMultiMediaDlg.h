// PlayMultiMediaDlg.h : header file
//
//{{AFX_INCLUDES()
#include "animation.h"
#include "shockwaveflash.h"
#include "realaudio.h"
#include "wmpplayer4.h"
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_PLAYMULTIMEDIADLG_H__2440C7DF_0B07_47D7_801E_2E3EC6EA4A80__INCLUDED_)
#define AFX_PLAYMULTIMEDIADLG_H__2440C7DF_0B07_47D7_801E_2E3EC6EA4A80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlayMultiMediaDlg dialog

class CPlayMultiMediaDlg : public CDialog
{
// Construction
public:
	CPlayMultiMediaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayMultiMediaDlg)
	enum { IDD = IDD_PLAYMULTIMEDIA_DIALOG };
	CRealAudio	m_realplayCtrl;
	CWMPPlayer4	m_wmPlayer;
	CShockwaveFlash	m_shockWaveFlash;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayMultiMediaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlayMultiMediaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonPlaygif();
	afx_msg void OnButtonPlayflash();
	afx_msg void OnButtonPlayrm();
	afx_msg void OnDestroy();
	afx_msg void OnButtonPlaycd();
	afx_msg void OnButtonShowjpeg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYMULTIMEDIADLG_H__2440C7DF_0B07_47D7_801E_2E3EC6EA4A80__INCLUDED_)
