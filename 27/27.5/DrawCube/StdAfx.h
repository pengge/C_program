// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__8ADCF4D4_50BC_4C57_BF6F_65A4659CE5E4__INCLUDED_)
#define AFX_STDAFX_H__8ADCF4D4_50BC_4C57_BF6F_65A4659CE5E4__INCLUDED_

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

template<class TYPE> inline void SAFE_RELEASE(TYPE*& pObj) 
{     
	if (pObj != NULL)      
	{          
		pObj->Release();          
		pObj = NULL;      
	}      
	else      
	{          
		TRACE(_T("无法释放空指针\n"));      
	} 
} 
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__8ADCF4D4_50BC_4C57_BF6F_65A4659CE5E4__INCLUDED_)
