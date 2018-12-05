// PhotoScreenWnd.h: interface for the CPhotoScreenWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHOTOSCREENWND_H__5FA16BCF_2846_40D9_9632_EF8E78040DC2__INCLUDED_)
#define AFX_PHOTOSCREENWND_H__5FA16BCF_2846_40D9_9632_EF8E78040DC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "windef.h"

class CPhotoScreenWnd : public CWnd  
{
public:
	LPCSTR lpszClassName;
	BOOL Create(); 
	CPhotoScreenWnd();
	virtual ~CPhotoScreenWnd();
	int type;//1==¹ö¶¯×ÖÌå£»2==Ïà²á
	int m_idTimer;
	int m_nIndex;
	int m_nBitmapCount;
	int m_nTextIndex;
	int m_nTextCount;
	CPoint m_Point;
	void DrawBitmap(CDC& dc, int nIndex);
	void DrawText(CDC& dc, int nIndex);
	//{{AFX_VIRTUAL(CPhotoScreenWnd)
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPhotoScreenWnd)
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, DWORD hTask);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP() 

};

#endif // !defined(AFX_PHOTOSCREENWND_H__5FA16BCF_2846_40D9_9632_EF8E78040DC2__INCLUDED_)
