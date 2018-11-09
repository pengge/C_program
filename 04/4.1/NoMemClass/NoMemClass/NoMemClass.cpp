#include <iostream>
using namespace std;

class NoMemClass				// 定义不包含任何成员的NoMemClass类
{
};
void main()
{
	NoMemClass  obj;  			// NoMemClass类的对象
	// 输出类空类占用的空间大小
	cout << "空类对象的大小为: " << sizeof(obj)  << endl;
	system("pause");
}
