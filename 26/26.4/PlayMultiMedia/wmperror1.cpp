// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "wmperror1.h"

// Dispatch interfaces referenced by this interface
#include "wmperroritem1.h"


/////////////////////////////////////////////////////////////////////////////
// CWMPError properties

/////////////////////////////////////////////////////////////////////////////
// CWMPError operations

void CWMPError::clearErrorQueue()
{
	InvokeHelper(0x353, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long CWMPError::GetErrorCount()
{
	long result;
	InvokeHelper(0x354, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CWMPErrorItem CWMPError::GetItem(long dwIndex)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x355, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, parms,
		dwIndex);
	return CWMPErrorItem(pDispatch);
}

void CWMPError::webHelp()
{
	InvokeHelper(0x356, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
