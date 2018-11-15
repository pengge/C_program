#include <iostream>
#include <atlstr.h>
using namespace std;

int main() 
{
    // 定义字符串
    CString s( _T("abcdef") );
    cout << "初始字符串=" << (LPCTSTR)s << endl;
    cout << "第三个字符开始的三个字符是否为'cde'=" 
        << (s.Mid( 2, 3 ) == _T("cde")) << endl;
    cout << "左边两个字符是否为'ab'=" 
        << (s.Left(2) == _T("ab") ) << endl;
    cout << "右边两个字符是否为'ef'="
        << (s.Right(2) == _T("ef") ) << endl;
    // 定义字符串，并初始化
    CString str("Welcome to Beijing");
    cout << "初始字符串=" << (LPCTSTR)str
        << ";字符串长度=" << str.GetLength() << endl;
    // 在字符串的第七个字符后添加字符串
    int n = str.Insert(7, " is");
    cout << "添加'is '后的字符串内容=" << (LPCTSTR)str
        << ";字符串长度=" << str.GetLength()  << endl;   
    return 0;
}
