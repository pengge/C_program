#if !defined(AFX_ANIMATION_H__9408D0B6_E915_4D85_9B71_E9B455CFCF63__INCLUDED_)
#define AFX_ANIMATION_H__9408D0B6_E915_4D85_9B71_E9B455CFCF63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CAnimation wrapper class

class CAnimation : public CWnd
{
protected:
	DECLARE_DYNCREATE(CAnimation)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xb09de715, 0x87c1, 0x11d1, { 0x8b, 0xe3, 0x0, 0x0, 0xf8, 0x75, 0x4d, 0xa1 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	void SetAutoPlay(BOOL bNewValue);
	BOOL GetAutoPlay();
	void SetBackStyle(long nNewValue);
	long GetBackStyle();
	void SetCenter(BOOL bNewValue);
	BOOL GetCenter();
	void SetEnabled(BOOL bNewValue);
	BOOL GetEnabled();
	long GetHWnd();
	void SetBackColor(unsigned long newValue);
	unsigned long GetBackColor();
	long GetOLEDropMode();
	void SetOLEDropMode(long nNewValue);
	void Close();
	void Open(LPCTSTR bstrFilename);
	void Play(const VARIANT& varRepeatCount, const VARIANT& varStartFrame, const VARIANT& varEndFrame);
	void Stop();
	void OLEDrag();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATION_H__9408D0B6_E915_4D85_9B71_E9B455CFCF63__INCLUDED_)
