// PlusAdd.cpp: implementation of the CPlusAdd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlusASample.h"
#include "PlusAdd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlusAdd::CPlusAdd()
{

}

CPlusAdd::~CPlusAdd()
{

}

int CPlusAdd::Add(int a, int b)
{
	CString result;
	result.Format("加法结果%d+%d=%d", a, b, a+b);
	AfxMessageBox(result);
	return (a+b);
}
