#include <iostream>
#include <fstream>
using namespace std;

void WriteOrderFile()					// д˳���ļ�
{
	ofstream myFile;					// ����д�ļ���
	myFile.open( "data.txt", ios::out);// ���ļ�
	if (!myFile)						// �жϴ��ļ��Ƿ�ɹ�
	{
		cout << "���ļ�����" << endl;
		return;
	}
	// ���ļ�˳��д����������
	myFile << "01--����" << endl << "02--����" << endl;
	myFile.close();						// �ر��ļ�
	cout << "��data.txt�ļ�д����������." << endl;
}
void ReadOrderFile()			// ��˳���ļ�
{
	ifstream myFile;			// ������ļ���
	myFile.open( "data.txt", ios::in );	// ���ļ�
	if (!myFile)				// �жϴ��ļ��Ƿ�ɹ�
	{
		cout << "���ļ�����" << endl;
		return;
	}
	cout << "��ȡdata.txt�ļ�����������ʾ:" << endl;	
	int value;
	while((value = myFile.get()) != EOF)
								// ʹ��get()����˳����ļ����ж�ȡ�ַ�����ʾ
	{
		cout << (char)value;
	}
	myFile.close();				// �ر��ļ�
}

int main()
{
	WriteOrderFile();
	ReadOrderFile();
	system("pause");
	return 0;
}
