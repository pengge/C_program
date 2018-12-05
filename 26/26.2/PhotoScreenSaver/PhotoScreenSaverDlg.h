// PhotoScreenSaverDlg.h : header file
//

#if !defined(AFX_PHOTOSCREENSAVERDLG_H__90B7B44D_0F20_4AA0_A8F7_545EBDB98055__INCLUDED_)
#define AFX_PHOTOSCREENSAVERDLG_H__90B7B44D_0F20_4AA0_A8F7_545EBDB98055__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPhotoScreenSaverDlg dialog

class CPhotoScreenSaverDlg : public CDialog
{
// Construction
public:
	CPhotoScreenSaverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPhotoScreenSaverDlg)
	enum { IDD = IDD_PHOTOSCREENSAVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoScreenSaverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPhotoScreenSaverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTOSCREENSAVERDLG_H__90B7B44D_0F20_4AA0_A8F7_545EBDB98055__INCLUDED_)
