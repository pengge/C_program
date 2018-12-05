#if !defined(AFX_WMPERROR_H__ED51CA6A_EECD_409B_B033_BEFE2CDA7D99__INCLUDED_)
#define AFX_WMPERROR_H__ED51CA6A_EECD_409B_B033_BEFE2CDA7D99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CWMPErrorItem;

/////////////////////////////////////////////////////////////////////////////
// CWMPError wrapper class

class CWMPError : public COleDispatchDriver
{
public:
	CWMPError() {}		// Calls COleDispatchDriver default constructor
	CWMPError(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPError(const CWMPError& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void clearErrorQueue();
	long GetErrorCount();
	CWMPErrorItem GetItem(long dwIndex);
	void webHelp();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPERROR_H__ED51CA6A_EECD_409B_B033_BEFE2CDA7D99__INCLUDED_)
