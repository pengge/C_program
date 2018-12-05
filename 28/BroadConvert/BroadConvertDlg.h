// BroadConvertDlg.h : header file
//

#if !defined(AFX_BROADCONVERTDLG_H__C8A42575_04D5_44C7_B334_3FF322A8544C__INCLUDED_)
#define AFX_BROADCONVERTDLG_H__C8A42575_04D5_44C7_B334_3FF322A8544C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "audioplay.h"
#include "TagDefine.h"




class CAudioPlay;
/////////////////////////////////////////////////////////////////////////////
// CBroadConvertDlg dialog

class CBroadConvertDlg : public CDialog
{
// Construction
public:
	
	CBroadConvertDlg(CWnd* pParent = NULL);	// standard constructor
	
	

// Dialog Data
	//{{AFX_DATA(CBroadConvertDlg)
	enum { IDD = IDD_BROADCONVERT_DIALOG };	
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBroadConvertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBroadConvertDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnButLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROADCONVERTDLG_H__C8A42575_04D5_44C7_B334_3FF322A8544C__INCLUDED_)
