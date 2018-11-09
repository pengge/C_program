#include <iostream>
#include <fstream>
using namespace std;

struct Record									// 记录结构
{
	char value[10];								// 存放数据内容的成员变量
};
void WriteRandomFile()							// 写随机文件
{
	// 定义要写入的数据 
	Record records[3] = {"01-张三", "02-李四", "03-王五"};
	ofstream myFile;							// 定义写文件流
	// 打开文件
	myFile.open( "data.txt", ios::out | ios::binary); 
	if (!myFile)								// 判断打开文件是否成功
	{
		cout << "打开文件错误" << endl;
		return;
	}
	for (int i = 0;i < 3;i++)					// 依次写入3条记录
	{
		// 调用write()函数写入数据
		myFile.write((const char*)&records[i], sizeof(Record));
	}
	myFile.close();								// 关闭文件
	cout << "向data.txt文件中写入三条数据." << endl;
}
void ReadRandomFile()				// 读顺序文件
{
	ifstream myFile;				// 定义读文件流
	myFile.open( "data.txt", ios::in | ios::binary );
	if (!myFile)					// 判断打开文件是否成功
	{
		cout << "打开文件错误" << endl;
		return;
	}
	cout << "读取data.txt文件的第二条内容如下所示:" << endl;
	Record record;					// 定义存放获取的记录的变量
	// 把文件的写指针从文件开头向后移一条记录
	myFile.seekg(sizeof(Record), ios::beg);
	// 读取文件中的第二条记录
	myFile.read((char*)&record, sizeof(record));
	cout  << (char*)&record;		// 将获取的记录显示在屏幕上
	cout  << endl;
	myFile.close();					// 关闭文件
}
int main()
{
	WriteRandomFile();
	ReadRandomFile();
	system("pause");
	return 0;
}