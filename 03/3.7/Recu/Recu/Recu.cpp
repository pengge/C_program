#include <iostream>
using namespace std;

long factorial(int number)  		// �ݹ麯���ĵ��ã������Ǽ���ָ�������Ľ׳�
{
	if (number < 0)
		return -1;		// �������Ĳ���С��0�����޷�����׳�
	if ((number == 0) || (number == 1))  
		return 1;		// �������Ĳ�������0��1����׳�Ϊ1
	else				// ���򣬵ݹ���ã�ֱ���������
		return (number * factorial(number - 1));	// �ݹ���ý׳˺���
}
void printRecuFunction()							// ʹ�õݹ麯����ʾ��
{
	int a;											// �������ͱ���a
	cout << "�ݹ�ʾ��������Ҫ����׳˵�����";			// �����ʾ��Ϣ
	cin >> a;										// �����û�����
	cout << a << "�Ľ׳� " << factorial(a) << "\n";	// �������Ľ׳˽��
}
int main()											// ������ں���
{
	printRecuFunction();				// ִ��printRecuFunction()����
	getchar();							// ��ֹ����̨�����Զ��˳�
	getchar();
	return 0;							// ����
}
