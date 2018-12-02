// RegQueryEnumSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//查询注册表键值信息
void QueryKeyValue()
{	
	DWORD szValue;	
	DWORD dwType;
	DWORD dwLength = sizeof(szValue);	
	HKEY hKey;
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\LLN\\VC\\Registry\\CreateTest", &hKey) == ERROR_SUCCESS) 
	{
		if(RegQueryValueEx(hKey, "MaxVersion", NULL, &dwType, (LPBYTE)&szValue, &dwLength) == ERROR_SUCCESS)
		{
			switch(dwType)
			{
			case REG_BINARY:
				break;
			case REG_DWORD_BIG_ENDIAN:
			case REG_DWORD:
				printf("成功.类型=REG_DWORD;键值=%u",UINT(szValue));
				break;
			case REG_EXPAND_SZ:
			case REG_MULTI_SZ:
			case REG_SZ:
				printf("成功.类型=REG_SZ;键值=%s", szValue);
				break;
			case REG_LINK:
				printf("成功.类型=REG_LINK;");
				break;
			case REG_RESOURCE_LIST:
				printf("成功.类型=REG_RESOURCE_LIST;");
				break;
			case REG_NONE:
				printf("成功.类型=REG_NONE;");
				break;
			default:
				printf("成功.类型=未知;");
				break;			
			}
		}
		RegCloseKey(hKey);
	}
	return;
}

//快速查询注册表键值信息
void QuickQueryKeyValue()
{	
	char szValue[MAX_PATH];	
	long dwLength = sizeof(szValue);
	if (RegQueryValue(HKEY_CURRENT_USER, "Software\\LLN\\VC\\Registry\\CreateTest", 
		(char*)&szValue, &dwLength) == ERROR_SUCCESS) 
		printf("成功.键值=%s",szValue);	
	return;
}

//列举注册表中启动项
void EnumStartProgram()
{
	HKEY hKey;
	DWORD dwIndex=0;   
	char szValueName[MAX_PATH]={0};   
	DWORD dwValueName=sizeof(szValueName);
	DWORD dwType;
	BYTE szData[MAX_PATH]={0};   
	DWORD dwData=sizeof(szData);   
	
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 
		&hKey) == ERROR_SUCCESS) 
	{
		while (((RegEnumValue(hKey, dwIndex, (LPTSTR)szValueName,&dwValueName,   
			NULL, &dwType, (LPBYTE)szData, &dwData)) == ERROR_SUCCESS))  
		{   
			printf("[%d]	%s=%sd\n", dwIndex, szValueName, szData);   
			dwIndex++;   
			dwValueName=sizeof(szValueName);   
			memset(szValueName,0,dwValueName);   
			dwData=sizeof(szData);   
			memset(szData,0,dwData);
		} 
		RegCloseKey(hKey);
	}
}

//枚举安装程序
void EnumKeyProgram()
{
	HKEY hKey;
	DWORD dwIndex=0;   
	char szKeyName[MAX_PATH]={0};   
	DWORD dwNameLen=sizeof(szKeyName);   
	char szKeyClass[MAX_PATH]={0};   
	DWORD dwClassLen=sizeof(szKeyClass);   
	FILETIME item={0};   
    
    if (RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\MICROSOFT\\WINDOWS\\CurrentVersion\\uninstall", 
		&hKey) == ERROR_SUCCESS) 
	{
		while (((RegEnumKeyEx(hKey, dwIndex, szKeyName, &dwNameLen,   
			NULL, szKeyClass, &dwClassLen, &item)) == ERROR_SUCCESS))  
		{   
			printf("[%d]	名称=%sd\n", dwIndex, szKeyName);   
			dwIndex++;   
			dwNameLen=sizeof(szKeyName);   
			memset(szKeyName,0,dwNameLen);   
			dwClassLen=sizeof(szKeyClass);   
			memset(szKeyClass,0,dwClassLen);   
			memset(&item,0,sizeof(item));  
		} 
		RegCloseKey(hKey);
	}
}

int main(int argc, char* argv[])
{	
	//QueryKeyValue();
	//QuickQueryKeyValue();
	//EnumStartProgram();
	EnumKeyProgram();
	printf("\r\n");
	//system("pause");
	return 0;
}

