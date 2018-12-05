// SoundSampleDlg.h : header file
//

#if !defined(AFX_SOUNDSAMPLEDLG_H__FC04ECF9_8AFD_495E_BF02_296CB2FCDC46__INCLUDED_)
#define AFX_SOUNDSAMPLEDLG_H__FC04ECF9_8AFD_495E_BF02_296CB2FCDC46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mmsystem.h"
/////////////////////////////////////////////////////////////////////////////
// CSoundSampleDlg dialog

class CSoundSampleDlg : public CDialog
{
// Construction
public:
	CSoundSampleDlg(CWnd* pParent = NULL);	// standard constructor
	void WriteLog(CString log);
	HWAVEIN m_hWaveIn;
	WAVEHDR m_wavehdr;
	char* inbuf;
	HWND m_hWndMCI;
	long m_lPosition;
	CString fileName;

// Dialog Data
	//{{AFX_DATA(CSoundSampleDlg)
	enum { IDD = IDD_SOUNDSAMPLE_DIALOG };
	CSliderCtrl	m_ctrlVolumn;
	CEdit	m_editLog;
	UINT	m_Volumn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSoundSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonRecord();
	afx_msg void OnButtonStoprecord();
	afx_msg void OnButtonCtrlvolumn();
	afx_msg void OnButtonPlaycd();
	afx_msg void OnButtonCtrlleft();
	afx_msg void OnButtonPcplay();
	afx_msg void OnButtonPlaywav();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonPlaymidi();
	afx_msg void OnButtonPlaymp3();
	afx_msg void OnButtonStopmp3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDSAMPLEDLG_H__FC04ECF9_8AFD_495E_BF02_296CB2FCDC46__INCLUDED_)
