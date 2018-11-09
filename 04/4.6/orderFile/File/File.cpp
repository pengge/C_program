#include <iostream>
#include <fstream>
using namespace std;

void WriteOrderFile()					// 写顺序文件
{
	ofstream myFile;					// 定义写文件流
	myFile.open( "data.txt", ios::out);// 打开文件
	if (!myFile)						// 判断打开文件是否成功
	{
		cout << "打开文件错误" << endl;
		return;
	}
	// 向文件顺序写入两条数据
	myFile << "01--张三" << endl << "02--李四" << endl;
	myFile.close();						// 关闭文件
	cout << "向data.txt文件写入两条数据." << endl;
}
void ReadOrderFile()			// 读顺序文件
{
	ifstream myFile;			// 定义读文件流
	myFile.open( "data.txt", ios::in );	// 打开文件
	if (!myFile)				// 判断打开文件是否成功
	{
		cout << "打开文件错误" << endl;
		return;
	}
	cout << "读取data.txt文件内容如下所示:" << endl;	
	int value;
	while((value = myFile.get()) != EOF)
								// 使用get()函数顺序从文件流中读取字符并显示
	{
		cout << (char)value;
	}
	myFile.close();				// 关闭文件
}

int main()
{
	WriteOrderFile();
	ReadOrderFile();
	system("pause");
	return 0;
}
