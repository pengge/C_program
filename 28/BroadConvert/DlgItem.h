#if !defined(AFX_DLGITEM_H__E44BA1A8_EB1F_4AF5_B702_8ED22BD98933__INCLUDED_)
#define AFX_DLGITEM_H__E44BA1A8_EB1F_4AF5_B702_8ED22BD98933__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgItem.h : header file
//
#include "audioplay.h"
#include "TagDefine.h"




class CAudioPlay;
/////////////////////////////////////////////////////////////////////////////
// CDlgItem dialog

class CDlgItem : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgItem)

// Construction
public:
	BOOL m_bPlayBack;
	void InitFileName(TCHAR* pSource, TCHAR* pDestA, TCHAR* pDestB, TCHAR* pDestC, BOOL bPlayBack, TCHAR* pCaption);
	int SetItemText( UINT nControlID, LPCWSTR pwszText );
	CDlgItem();
	~CDlgItem();
	void SetTime( QWORD cnsTimeElapsed, QWORD cnsFileDuration );
	void SetCurrentStatus(AUDIOSTATUS currentStatus);
	void InsertLog(char* log);
	CAudioPlay*	g_pAudioplay;
	AUDIOSTATUS g_Status;
	TCHAR		g_ptszFileName[ MAX_PATH ];
	TCHAR		g_pSaveFileNameA[ MAX_PATH ];
	TCHAR		g_pSaveFileNameB[ MAX_PATH ];
	TCHAR		g_pSaveFileNameC[ MAX_PATH ];
	TCHAR		g_pCaption[MAX_PATH];
	BOOL		g_IsSeeking;
	HANDLE		hHeap;			//¶Ñ¾ä±ú

// Dialog Data
	//{{AFX_DATA(CDlgItem)
	enum { IDD = IDD_DLG_ITEM };
	CEdit	m_editDesFileC;
	CButton	m_CheckPlay;
	CEdit	m_editDesFileB;
	CEdit	m_editDesFileA;
	CButton	m_ButPlay;
	CEdit	m_editStatus;
	CEdit	m_editDuration;	
	CEdit	m_editSource;
	CSliderCtrl	m_ctrlSlider;
	CButton	m_ButStop;
	CButton	m_ButPause;
	CButton	m_ButOpen;
	CListBox	m_LogList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDlgItem)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgItem)
	virtual BOOL OnInitDialog();
	afx_msg void OnOpen();
	afx_msg void OnPause();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGITEM_H__E44BA1A8_EB1F_4AF5_B702_8ED22BD98933__INCLUDED_)
