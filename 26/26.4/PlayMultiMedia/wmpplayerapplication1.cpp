// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "wmpplayerapplication1.h"


/////////////////////////////////////////////////////////////////////////////
// CWMPPlayerApplication properties

/////////////////////////////////////////////////////////////////////////////
// CWMPPlayerApplication operations

void CWMPPlayerApplication::switchToPlayerApplication()
{
	InvokeHelper(0x44d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CWMPPlayerApplication::switchToControl()
{
	InvokeHelper(0x44e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CWMPPlayerApplication::GetPlayerDocked()
{
	BOOL result;
	InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL CWMPPlayerApplication::GetHasDisplay()
{
	BOOL result;
	InvokeHelper(0x450, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}