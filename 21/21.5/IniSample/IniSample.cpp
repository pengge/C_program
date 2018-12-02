// IniSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"

// ��INI�ļ���ָ���ļ�ֵ��д���ַ�������
bool WriteIniKeyString()
{
	if (!WritePrivateProfileString ("MaMa", "First", "Sleep", "hobby.ini")) return FALSE;
	if (!WritePrivateProfileString ("MaMa", "Second", "Music", "hobby.ini")) return FALSE;
	if (!WritePrivateProfileString ("Baby", "First", "Milk", "hobby.ini")) return FALSE;
	if (!WritePrivateProfileString ("Baby", "Second", "Dance", "hobby.ini")) return FALSE;
	if (!WritePrivateProfileString ("Baby", "Number", "5", "hobby.ini")) return FALSE;
	return TRUE;
}

void RunWriteIniKeyString()
{
	if (!WriteIniKeyString())
		printf("�ź�--��INI�ļ���ָ���ļ�ֵ��д���ַ�������ʧ��!\n");
	else
		printf("��ϲ--��INI�ļ���ָ���ļ�ֵ��д���ַ������ݳɹ�!\n");
}

// ��ȡ�ַ�����ֵ
void GetIniKeyString()
{	
	char sResult[256];
	DWORD dwResult, iSize = 256;
	dwResult = GetPrivateProfileString("Baby", "First", "δ֪", sResult, iSize, "hobby.ini" );
	if (dwResult > 0 )
	{
		printf("��ϲ--��INI�ļ��ж�ȡָ����ֵ���ַ������ݳɹ���\nBaby's First hobby is:%s", sResult);
	}
	else
	{
		printf("�ź�--��INI�ļ��ж�ȡָ����ֵ���ַ�������ʧ�ܣ�\n");
	}
}

// ��ȡ���ͼ�ֵ
void GetIniKeyInt()
{	
	UINT uiResult = GetPrivateProfileInt("Baby", "Number", 99, "hobby.ini" );
	if (uiResult > 0 )
	{
		printf("��ϲ--��INI�ļ��ж�ȡָ����ֵ���������ݳɹ���\nBaby's Number hobby is:%d", uiResult);
	}
	else
	{
		printf("�ź�--��INI�ļ��ж�ȡָ����ֵ����������ʧ�ܣ�\n");
	}
}

// ��INI�ļ���ָ���Ľ���д������
bool WriteIniSection()
{
	if (!WritePrivateProfileSection ("MaMa", "Third=Read\r\nNumber=5", "C:\hobby.ini")) return FALSE;	
	if (!WritePrivateProfileSection ("Baby", "Third=Toy\r\nForth=Play", "C:\hobby.ini")) return FALSE;
	return TRUE;
}

void RunWriteIniSection()
{
	if (!WriteIniSection())
		printf("�ź�--��INI�ļ���ָ���Ľ���д������ʧ��!\n");
	else
		printf("��ϲ--��INI�ļ���ָ���Ľ���д�����ݳɹ�!\n");
}

// ��ȡ����
void GetSectionNames()
{	
	char sResult[256];
	DWORD dwResult, iSize = 256;
	dwResult = GetPrivateProfileSectionNames(sResult, iSize, "C:\hobby.ini" );
	if (dwResult > 0 )
	{
		printf("��ϲ--��ȡ�����ɹ�������=%d\n", dwResult);		
		char item[256];
		int  len=0;
		int strEnd = 0x00;  

		memset(item, 0x00, sizeof(item));
		for (int i = 0; i<dwResult ; i++)
		{			
			if (sResult[i] != strEnd)
			{
				item[len] = sResult[i];
				len++;
			}
			else
			{
				printf("%s\n", item);
				memset(item, 0x00, sizeof(item));
				len = 0;
				if (sResult[i+1] == strEnd)
				{
					break;
				}
			}
		}
	}
	else
	{
		printf("�ź�--��ȡ����ʧ�ܣ�\n");
	}
}

// ��INI�ļ���ָ���ļ�ֵ��д��ṹ����
struct student
{
	int		ID;
	int		age;
	char	name[20];
};

bool WriteIniKeyStruct()
{
	student st;
	st.ID = 1;
	st.age = 20;	
	memset(st.name, 0x00, sizeof(st.name));
	strcpy(st.name, "����");
	if (!WritePrivateProfileStruct ("Student", "First", &st, sizeof(st), "student.ini")) return FALSE;	
	return TRUE;
}

void RunWriteIniKeyStruct()
{
	if (!WriteIniKeyStruct())
		printf("�ź�--��INI�ļ���ָ���ļ�ֵ��д��ṹ����ʧ��!\n");
	else
		printf("��ϲ--��INI�ļ���ָ���ļ�ֵ��д��ṹ���ݳɹ�!\n");
}

// ��ȡ�ṹ����
void GetIniKeyStruct()
{	
	student st;	
	memset(st.name, 0x00, sizeof(st.name));
	if (GetPrivateProfileStruct("Student", "First", &st, sizeof(st), "student.ini" ))
	{
		printf("��ϲ--��INI�ļ��ж�ȡָ����ֵ���ַ������ݳɹ���\nѧ��=%d\n����=%s\n����=%d", st.ID,st.name,st.age);
	}
	else
	{
		printf("�ź�--��INI�ļ��ж�ȡָ����ֵ���ַ�������ʧ�ܣ�\n");
	}
}

// ��ȡָ�����µļ���������
void GetSectionKeyAndData()
{	
	char sResult[256];
	DWORD dwResult, iSize = 256;
	dwResult = GetPrivateProfileSection("Baby", sResult, iSize, "C:\hobby.ini" );
	if (dwResult > 0 )
	{
		printf("��ϲ--��ȡBaby���µļ��������ݳɹ�������=%d\n", dwResult);		
		char item[256];
		int  len=0;
		int strEnd = 0x00;  

		memset(item, 0x00, sizeof(item));
		for (int i = 0; i<dwResult ; i++)
		{			
			if (sResult[i] != strEnd)
			{
				item[len] = sResult[i];
				len++;
			}
			else
			{
				char* pdest;
				char key[256], data[256];
				pdest = strchr(item, '=');				
				memset(key, 0x00, sizeof(key));
				memcpy(key, item, pdest-item);
				memset(data, 0x00, sizeof(data));
				strcpy(data, pdest+1);
				printf("����=%s		����=%s\n", key, data);
				memset(item, 0x00, sizeof(item));
				len = 0;
				if (sResult[i+1] == strEnd)
				{
					break;
				}
			}
		}
	}
	else
	{
		printf("�ź�--��ȡBaby���µļ���������ʧ�ܣ�\n");
	}
}

int main(int argc, char* argv[])
{
    //RunWriteIniKeyString();
	//GetIniKeyInt();
	//GetIniKeyString();		
	//RunWriteIniKeyStruct();
	//GetIniKeyStruct();
	//RunWriteIniSection();
	//GetSectionNames();	
	GetSectionKeyAndData();
	printf("\r\n");
	//system("pause");
	return 0;
}



