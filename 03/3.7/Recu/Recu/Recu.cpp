#include <iostream>
using namespace std;

long factorial(int number)  		// 递归函数的调用，功能是计算指定整数的阶乘
{
	if (number < 0)
		return -1;		// 如果传入的参数小于0，则无法计算阶乘
	if ((number == 0) || (number == 1))  
		return 1;		// 如果传入的参数等于0或1，则阶乘为1
	else				// 否则，递归调用，直到计算完成
		return (number * factorial(number - 1));	// 递归调用阶乘函数
}
void printRecuFunction()							// 使用递归函数的示例
{
	int a;											// 定义整型变量a
	cout << "递归示例，输入要计算阶乘的数：";			// 输出提示信息
	cin >> a;										// 接收用户输入
	cout << a << "的阶乘 " << factorial(a) << "\n";	// 输出计算的阶乘结果
}
int main()											// 程序入口函数
{
	printRecuFunction();				// 执行printRecuFunction()函数
	getchar();							// 阻止控制台程序自动退出
	getchar();
	return 0;							// 返回
}
