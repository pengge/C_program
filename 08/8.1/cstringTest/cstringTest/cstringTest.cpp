#include <iostream>
#include <atlstr.h>
using namespace std;

int main() 
{
    // �����ַ���
    CString s( _T("abcdef") );
    cout << "��ʼ�ַ���=" << (LPCTSTR)s << endl;
    cout << "�������ַ���ʼ�������ַ��Ƿ�Ϊ'cde'=" 
        << (s.Mid( 2, 3 ) == _T("cde")) << endl;
    cout << "��������ַ��Ƿ�Ϊ'ab'=" 
        << (s.Left(2) == _T("ab") ) << endl;
    cout << "�ұ������ַ��Ƿ�Ϊ'ef'="
        << (s.Right(2) == _T("ef") ) << endl;
    // �����ַ���������ʼ��
    CString str("Welcome to Beijing");
    cout << "��ʼ�ַ���=" << (LPCTSTR)str
        << ";�ַ�������=" << str.GetLength() << endl;
    // ���ַ����ĵ��߸��ַ�������ַ���
    int n = str.Insert(7, " is");
    cout << "���'is '����ַ�������=" << (LPCTSTR)str
        << ";�ַ�������=" << str.GetLength()  << endl;   
    return 0;
}
