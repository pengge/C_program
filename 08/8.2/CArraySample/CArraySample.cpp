// CArraySample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxtempl.h>
#include "CArraySample.h"
#include "process.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;
CArray<CPoint,CPoint> m_ptArray;				// 定义点元素数组对象

using namespace std;

void PrintArray()
{
    for (int i = 0 ;i < m_ptArray.GetSize(); i++)
    {
        cout << "第" << i+1 << "个元素=(" << m_ptArray[i].x 
            << "," << m_ptArray.GetAt(i).y << ")" << endl;
    }
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
    int nRetCode = 0;

    // initialize MFC and print and error on failure
    if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
    {
        // TODO: change error code to suit your needs
        cerr << _T("Fatal Error: MFC initialization failed") << endl;
        nRetCode = 1;
    }
    else
    {		
        CPoint ptA(0, 0), ptB(20, 50), ptC(120,300);	// 构造CPoint对象
        m_ptArray.Add(ptA);								// 增加元素	
        m_ptArray.Add(ptB);					
        m_ptArray.Add(ptC);

        cout << "初始CArray对象中共有" << m_ptArray.GetSize() << "个元素：" << endl;
        PrintArray();

        CPoint ptD(800,600);
        m_ptArray[1] = ptD;				// 修改元素值
        cout << endl << "修改第二个元素后CArray对象中共有" << m_ptArray.GetSize() << "个元素：" << endl;
        PrintArray();

        m_ptArray.RemoveAt(0);			// 移除第一个元素值
        cout << endl << "删除第一个元素后CArray对象中共有" << m_ptArray.GetSize() << "个元素：" << endl;
        PrintArray();

        m_ptArray.RemoveAll();				// 移除所有元素值
        cout << endl << "删除所有元素后CArray对象中共有" << m_ptArray.GetSize() << "个元素：" << endl;
        PrintArray();
    }

    system("pause");
    return nRetCode;
}



