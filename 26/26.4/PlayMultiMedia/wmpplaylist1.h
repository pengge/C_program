#if !defined(AFX_WMPPLAYLIST1_H__F22728A2_96C4_4137_858B_07AEF5A1FC03__INCLUDED_)
#define AFX_WMPPLAYLIST1_H__F22728A2_96C4_4137_858B_07AEF5A1FC03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CWMPMedia;

/////////////////////////////////////////////////////////////////////////////
// CWMPPlaylist wrapper class

class CWMPPlaylist : public COleDispatchDriver
{
public:
	CWMPPlaylist() {}		// Calls COleDispatchDriver default constructor
	CWMPPlaylist(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlaylist(const CWMPPlaylist& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	CString GetName();
	void SetName(LPCTSTR lpszNewValue);
	long GetAttributeCount();
	CString GetAttributeName(long lIndex);
	CWMPMedia GetItem(long lIndex);
	CString getItemInfo(LPCTSTR bstrName);
	void setItemInfo(LPCTSTR bstrName, LPCTSTR bstrValue);
	BOOL GetIsIdentical(LPDISPATCH pIWMPPlaylist);
	void clear();
	void insertItem(long lIndex, LPDISPATCH pIWMPMedia);
	void appendItem(LPDISPATCH pIWMPMedia);
	void removeItem(LPDISPATCH pIWMPMedia);
	void moveItem(long lIndexOld, long lIndexNew);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPPLAYLIST1_H__F22728A2_96C4_4137_858B_07AEF5A1FC03__INCLUDED_)
