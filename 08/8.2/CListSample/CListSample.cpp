// CListSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxtempl.h>
#include "CListSample.h"
#include "process.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

CStringList m_stringList;					// 定义字符串型链表

void PrintList()
{
    cout << "当前字符串链表中共有" << m_stringList.GetCount() << "个元素" << endl;
    if (m_stringList.IsEmpty())
        return;
    POSITION pos = m_stringList.GetHeadPosition();
    int i = 0;
    while (pos != NULL)
    {
        cout << "第" << i+1 << "个元素='" << (LPCTSTR)m_stringList.GetAt(pos) << "'" << endl;
        m_stringList.GetNext(pos);
    }
    cout << endl;
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
        CList<int,int> m_intList;					// 定义整型链表
        m_intList.AddHead(2008);
        m_intList.AddHead(2009);
        cout << "整数链表中共有" << m_intList.GetCount() << "个元素" << endl;
        POSITION posInt = m_intList.GetHeadPosition();
        int i = 0;
        while (posInt != NULL) 
        {
            cout << "第" << i++ << "个整数元素=" << m_intList.GetAt(posInt) << endl;
            m_intList.GetNext(posInt);			
        }

        for (i = 0;i < 3; i++)
        {
            CString element;
            element.Format("这是第%d个元素", (i+1));
            m_stringList.AddTail(element);			// 向链表尾添加元素
        }
        PrintList();

        POSITION pos = m_stringList.FindIndex(1);
        if (pos != NULL) 
        {
            cout << "执行操作----使用InsertBefore函数在当前链表的第二个元素前插入新元素" << endl;
            m_stringList.InsertBefore(pos, "在第二个元素前插入的新元素");
            PrintList();

            cout << "执行操作----使用SetAt函数修改第二个元素值" << endl;
            m_stringList.SetAt(pos, "修改了第二个元素");
            PrintList();

            pos = m_stringList.FindIndex(1);
            cout << "执行操作----使用RemoveAt函数移除第二个元素" << endl;
            m_stringList.RemoveAt(pos);		// 移除最后一个元素
            PrintList();

            cout << "执行操作----使用RemoveAll函数移除所有元素" << endl;
            m_stringList.RemoveAll();		// 移除链表中的所有元素
            PrintList();
        }		
    }

    system("pause");
    return nRetCode;
}


