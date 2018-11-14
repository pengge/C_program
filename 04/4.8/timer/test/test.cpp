#include <iostream>
using namespace std;

void ShowClock()								// 显示电子时钟
{
	int second = -1,minute = -1, hour = -1, delay;		// 定义时间变量
	cout << "请输入24小时制的起始时间(时:分:秒):" ;
	cin >> hour >> minute >> second;			// 获取用户输入的当前时间

	while(true) 
	{
		for (;second<=60;second++)
		{
			for (delay=0;delay<=480000000;delay++) 
			{
				continue;		// 延时时间，此处根据CPU的时钟频率，设置延时时间
			}   
			if (second==60)		// 如果秒为60，则分加1，秒重新变成0
			{
				minute++;
				second=0;
			}
			if (minute==60)		// 如果分为60，则小时加1，分重新变成0
			{
				hour++;
				minute=0;
			}
			if (hour==24)		// 如果小时为24，则小时重新归为0
				hour=0;
			//在屏幕上输出时间
			cout << "现在时间："<< hour << ":"
				 << minute << ":" <<  second << "\r" ;
		}
	}
	system("pause");				// 暂停显示
}

int main()
{
	ShowClock();
	return 0;
}