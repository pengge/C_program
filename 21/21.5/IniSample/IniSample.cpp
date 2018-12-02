// IniSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"

// 向INI文件中指定的键值下写入字符串数据
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
		printf("遗憾--向INI文件中指定的键值下写入字符串数据失败!\n");
	else
		printf("恭喜--向INI文件中指定的键值下写入字符串数据成功!\n");
}

// 获取字符串键值
void GetIniKeyString()
{	
	char sResult[256];
	DWORD dwResult, iSize = 256;
	dwResult = GetPrivateProfileString("Baby", "First", "未知", sResult, iSize, "hobby.ini" );
	if (dwResult > 0 )
	{
		printf("恭喜--从INI文件中读取指定键值的字符串数据成功！\nBaby's First hobby is:%s", sResult);
	}
	else
	{
		printf("遗憾--从INI文件中读取指定键值的字符串数据失败！\n");
	}
}

// 获取整型键值
void GetIniKeyInt()
{	
	UINT uiResult = GetPrivateProfileInt("Baby", "Number", 99, "hobby.ini" );
	if (uiResult > 0 )
	{
		printf("恭喜--从INI文件中读取指定键值的整型数据成功！\nBaby's Number hobby is:%d", uiResult);
	}
	else
	{
		printf("遗憾--从INI文件中读取指定键值的整型数据失败！\n");
	}
}

// 向INI文件中指定的节下写入数据
bool WriteIniSection()
{
	if (!WritePrivateProfileSection ("MaMa", "Third=Read\r\nNumber=5", "C:\hobby.ini")) return FALSE;	
	if (!WritePrivateProfileSection ("Baby", "Third=Toy\r\nForth=Play", "C:\hobby.ini")) return FALSE;
	return TRUE;
}

void RunWriteIniSection()
{
	if (!WriteIniSection())
		printf("遗憾--向INI文件中指定的节下写入数据失败!\n");
	else
		printf("恭喜--向INI文件中指定的节下写入数据成功!\n");
}

// 获取节名
void GetSectionNames()
{	
	char sResult[256];
	DWORD dwResult, iSize = 256;
	dwResult = GetPrivateProfileSectionNames(sResult, iSize, "C:\hobby.ini" );
	if (dwResult > 0 )
	{
		printf("恭喜--获取节名成功！长度=%d\n", dwResult);		
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
		printf("遗憾--获取节名失败！\n");
	}
}

// 向INI文件中指定的键值下写入结构数据
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
	strcpy(st.name, "张三");
	if (!WritePrivateProfileStruct ("Student", "First", &st, sizeof(st), "student.ini")) return FALSE;	
	return TRUE;
}

void RunWriteIniKeyStruct()
{
	if (!WriteIniKeyStruct())
		printf("遗憾--向INI文件中指定的键值下写入结构数据失败!\n");
	else
		printf("恭喜--向INI文件中指定的键值下写入结构数据成功!\n");
}

// 获取结构数据
void GetIniKeyStruct()
{	
	student st;	
	memset(st.name, 0x00, sizeof(st.name));
	if (GetPrivateProfileStruct("Student", "First", &st, sizeof(st), "student.ini" ))
	{
		printf("恭喜--从INI文件中读取指定键值的字符串数据成功！\n学号=%d\n姓名=%s\n年龄=%d", st.ID,st.name,st.age);
	}
	else
	{
		printf("遗憾--从INI文件中读取指定键值的字符串数据失败！\n");
	}
}

// 获取指定节下的键名和数据
void GetSectionKeyAndData()
{	
	char sResult[256];
	DWORD dwResult, iSize = 256;
	dwResult = GetPrivateProfileSection("Baby", sResult, iSize, "C:\hobby.ini" );
	if (dwResult > 0 )
	{
		printf("恭喜--获取Baby节下的键名和数据成功！长度=%d\n", dwResult);		
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
				printf("键名=%s		数据=%s\n", key, data);
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
		printf("遗憾--获取Baby节下的键名和数据失败！\n");
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



