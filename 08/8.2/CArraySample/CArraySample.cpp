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
CArray<CPoint,CPoint> m_ptArray;				// �����Ԫ���������

using namespace std;

void PrintArray()
{
    for (int i = 0 ;i < m_ptArray.GetSize(); i++)
    {
        cout << "��" << i+1 << "��Ԫ��=(" << m_ptArray[i].x 
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
        CPoint ptA(0, 0), ptB(20, 50), ptC(120,300);	// ����CPoint����
        m_ptArray.Add(ptA);								// ����Ԫ��	
        m_ptArray.Add(ptB);					
        m_ptArray.Add(ptC);

        cout << "��ʼCArray�����й���" << m_ptArray.GetSize() << "��Ԫ�أ�" << endl;
        PrintArray();

        CPoint ptD(800,600);
        m_ptArray[1] = ptD;				// �޸�Ԫ��ֵ
        cout << endl << "�޸ĵڶ���Ԫ�غ�CArray�����й���" << m_ptArray.GetSize() << "��Ԫ�أ�" << endl;
        PrintArray();

        m_ptArray.RemoveAt(0);			// �Ƴ���һ��Ԫ��ֵ
        cout << endl << "ɾ����һ��Ԫ�غ�CArray�����й���" << m_ptArray.GetSize() << "��Ԫ�أ�" << endl;
        PrintArray();

        m_ptArray.RemoveAll();				// �Ƴ�����Ԫ��ֵ
        cout << endl << "ɾ������Ԫ�غ�CArray�����й���" << m_ptArray.GetSize() << "��Ԫ�أ�" << endl;
        PrintArray();
    }

    system("pause");
    return nRetCode;
}



