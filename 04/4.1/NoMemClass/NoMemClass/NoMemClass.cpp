#include <iostream>
using namespace std;

class NoMemClass				// ���岻�����κγ�Ա��NoMemClass��
{
};
void main()
{
	NoMemClass  obj;  			// NoMemClass��Ķ���
	// ��������ռ�õĿռ��С
	cout << "�������Ĵ�СΪ: " << sizeof(obj)  << endl;
	system("pause");
}
