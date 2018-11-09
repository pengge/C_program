#include <iostream>
#include <fstream>
using namespace std;

struct Record									// ��¼�ṹ
{
	char value[10];								// ����������ݵĳ�Ա����
};
void WriteRandomFile()							// д����ļ�
{
	// ����Ҫд������� 
	Record records[3] = {"01-����", "02-����", "03-����"};
	ofstream myFile;							// ����д�ļ���
	// ���ļ�
	myFile.open( "data.txt", ios::out | ios::binary); 
	if (!myFile)								// �жϴ��ļ��Ƿ�ɹ�
	{
		cout << "���ļ�����" << endl;
		return;
	}
	for (int i = 0;i < 3;i++)					// ����д��3����¼
	{
		// ����write()����д������
		myFile.write((const char*)&records[i], sizeof(Record));
	}
	myFile.close();								// �ر��ļ�
	cout << "��data.txt�ļ���д����������." << endl;
}
void ReadRandomFile()				// ��˳���ļ�
{
	ifstream myFile;				// ������ļ���
	myFile.open( "data.txt", ios::in | ios::binary );
	if (!myFile)					// �жϴ��ļ��Ƿ�ɹ�
	{
		cout << "���ļ�����" << endl;
		return;
	}
	cout << "��ȡdata.txt�ļ��ĵڶ�������������ʾ:" << endl;
	Record record;					// �����Ż�ȡ�ļ�¼�ı���
	// ���ļ���дָ����ļ���ͷ�����һ����¼
	myFile.seekg(sizeof(Record), ios::beg);
	// ��ȡ�ļ��еĵڶ�����¼
	myFile.read((char*)&record, sizeof(record));
	cout  << (char*)&record;		// ����ȡ�ļ�¼��ʾ����Ļ��
	cout  << endl;
	myFile.close();					// �ر��ļ�
}
int main()
{
	WriteRandomFile();
	ReadRandomFile();
	system("pause");
	return 0;
}