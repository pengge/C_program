// ExtDLLClass.cpp: implementation of the CExtDLLClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExtDLLClass.h"
#include "DlgExtDLL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExtDLLClass::CExtDLLClass()
{

}

CExtDLLClass::~CExtDLLClass()
{
}
void CExtDLLClass::ShowDlg()
{
	CDlgExtDLL dlg;
	dlg.DoModal();
}
