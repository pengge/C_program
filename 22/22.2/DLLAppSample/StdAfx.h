// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__6C7ED11C_D9A7_4EDB_98B0_F550C2380D15__INCLUDED_)
#define AFX_STDAFX_H__6C7ED11C_D9A7_4EDB_98B0_F550C2380D15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#define WM_ICON_MESSAGE		WM_USER + 6666
#define WM_BITMAP_MESSAGE	WM_USER + 6667
#define WM_DIALOG_MESSAGE	WM_USER + 6668


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__6C7ED11C_D9A7_4EDB_98B0_F550C2380D15__INCLUDED_)
