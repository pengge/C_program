// SpinSliderProgressSampleDlg.h : header file
//

#if !defined(AFX_SPINSLIDERPROGRESSSAMPLEDLG_H__C1332D94_1793_4208_893A_1E2FF6E20183__INCLUDED_)
#define AFX_SPINSLIDERPROGRESSSAMPLEDLG_H__C1332D94_1793_4208_893A_1E2FF6E20183__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSpinSliderProgressSampleDlg dialog

class CSpinSliderProgressSampleDlg : public CDialog
{
// Construction
public:
	void InitSpinData();
	void InitSliderData();
	void InitProgressData();

	CSpinSliderProgressSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpinSliderProgressSampleDlg)
	enum { IDD = IDD_SPINSLIDERPROGRESSSAMPLE_DIALOG };
	CProgressCtrl	m_progressPercent;
	CEdit	m_editPercent;
	CSliderCtrl	m_sliderPercent;
	CSpinButtonCtrl	m_spinPercent;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinSliderProgressSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpinSliderProgressSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReleasedcaptureSliderPercent(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonTimer();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINSLIDERPROGRESSSAMPLEDLG_H__C1332D94_1793_4208_893A_1E2FF6E20183__INCLUDED_)
