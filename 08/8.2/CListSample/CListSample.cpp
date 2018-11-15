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

CStringList m_stringList;					// �����ַ���������

void PrintList()
{
    cout << "��ǰ�ַ��������й���" << m_stringList.GetCount() << "��Ԫ��" << endl;
    if (m_stringList.IsEmpty())
        return;
    POSITION pos = m_stringList.GetHeadPosition();
    int i = 0;
    while (pos != NULL)
    {
        cout << "��" << i+1 << "��Ԫ��='" << (LPCTSTR)m_stringList.GetAt(pos) << "'" << endl;
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
        CList<int,int> m_intList;					// ������������
        m_intList.AddHead(2008);
        m_intList.AddHead(2009);
        cout << "���������й���" << m_intList.GetCount() << "��Ԫ��" << endl;
        POSITION posInt = m_intList.GetHeadPosition();
        int i = 0;
        while (posInt != NULL) 
        {
            cout << "��" << i++ << "������Ԫ��=" << m_intList.GetAt(posInt) << endl;
            m_intList.GetNext(posInt);			
        }

        for (i = 0;i < 3; i++)
        {
            CString element;
            element.Format("���ǵ�%d��Ԫ��", (i+1));
            m_stringList.AddTail(element);			// ������β���Ԫ��
        }
        PrintList();

        POSITION pos = m_stringList.FindIndex(1);
        if (pos != NULL) 
        {
            cout << "ִ�в���----ʹ��InsertBefore�����ڵ�ǰ����ĵڶ���Ԫ��ǰ������Ԫ��" << endl;
            m_stringList.InsertBefore(pos, "�ڵڶ���Ԫ��ǰ�������Ԫ��");
            PrintList();

            cout << "ִ�в���----ʹ��SetAt�����޸ĵڶ���Ԫ��ֵ" << endl;
            m_stringList.SetAt(pos, "�޸��˵ڶ���Ԫ��");
            PrintList();

            pos = m_stringList.FindIndex(1);
            cout << "ִ�в���----ʹ��RemoveAt�����Ƴ��ڶ���Ԫ��" << endl;
            m_stringList.RemoveAt(pos);		// �Ƴ����һ��Ԫ��
            PrintList();

            cout << "ִ�в���----ʹ��RemoveAll�����Ƴ�����Ԫ��" << endl;
            m_stringList.RemoveAll();		// �Ƴ������е�����Ԫ��
            PrintList();
        }		
    }

    system("pause");
    return nRetCode;
}


