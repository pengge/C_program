#include <iostream>
using namespace std;

void ShowClock()								// ��ʾ����ʱ��
{
	int second = -1,minute = -1, hour = -1, delay;		// ����ʱ�����
	cout << "������24Сʱ�Ƶ���ʼʱ��(ʱ:��:��):" ;
	cin >> hour >> minute >> second;			// ��ȡ�û�����ĵ�ǰʱ��

	while(true) 
	{
		for (;second<=60;second++)
		{
			for (delay=0;delay<=480000000;delay++) 
			{
				continue;		// ��ʱʱ�䣬�˴�����CPU��ʱ��Ƶ�ʣ�������ʱʱ��
			}   
			if (second==60)		// �����Ϊ60����ּ�1�������±��0
			{
				minute++;
				second=0;
			}
			if (minute==60)		// �����Ϊ60����Сʱ��1�������±��0
			{
				hour++;
				minute=0;
			}
			if (hour==24)		// ���СʱΪ24����Сʱ���¹�Ϊ0
				hour=0;
			//����Ļ�����ʱ��
			cout << "����ʱ�䣺"<< hour << ":"
				 << minute << ":" <<  second << "\r" ;
		}
	}
	system("pause");				// ��ͣ��ʾ
}

int main()
{
	ShowClock();
	return 0;
}