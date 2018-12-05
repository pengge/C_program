// DLLAppSampleDlg.h : header file
//

#if !defined(AFX_DLLAPPSAMPLEDLG_H__915D24FC_1DFD_4631_BC74_0A4208F92A07__INCLUDED_)
#define AFX_DLLAPPSAMPLEDLG_H__915D24FC_1DFD_4631_BC74_0A4208F92A07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDLLAppSampleDlg dialog

BOOL CALLBACK EnumIconProcedure(HANDLE hModule, LPCTSTR lpszType, LPTSTR lpszName, LONG lParam);
BOOL CALLBACK EnumBitmapProcedure(HANDLE hModule, LPCTSTR lpszType, LPTSTR lpszName, LONG lParam);
BOOL CALLBACK EnumDialogProcedure(HANDLE hModule, LPCTSTR lpszType, LPTSTR lpszName, LONG lParam);

class CDLLAppSampleDlg : public CDialog
{
// Construction
public:
	void ResetContent();
	CDLLAppSampleDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList imagelist;
	HINSTANCE  hLibrary;
	void WriteLog(CString log);
	//HHOOK hOldHook;

// Dialog Data
	//{{AFX_DATA(CDLLAppSampleDlg)
	enum { IDD = IDD_DLLAPPSAMPLE_DIALOG };
	CEdit	m_editLog;
	CListCtrl	m_iconList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLLAppSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDLLAppSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGetallicon();
	afx_msg LRESULT OnIconMessage(WPARAM wParam,LPARAM lParam);
	afx_msg void OnButtonGetbitmap();
	afx_msg LRESULT OnBitmapMessage(WPARAM wParam,LPARAM lParam);
	afx_msg void OnButtonGetdialog();	
	afx_msg void OnButtonReplacedialog();
	afx_msg void OnButtonDisablePower();
	afx_msg void OnButtonDisableWin();
	afx_msg void OnButtonDisableAltf4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLAPPSAMPLEDLG_H__915D24FC_1DFD_4631_BC74_0A4208F92A07__INCLUDED_)
