// RegistrySample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"

// 22.1.3(OK)
void CreateKeyTest()		// 快速创建注册表键
{
	HKEY hKey;				// 定义注册表键变量
	int iRet = RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", &hKey);// 创建新注册表键
	if (iRet == ERROR_SUCCESS)
        printf("快速创建注册表成功");	// 输出成功信息
	else
        printf("快速创建注册表失败.错误代码=%d", iRet);		// 输出错误信息
}

// 22.1.4(OK)
void OpenKeyTest()			// 打开注册表键
{
	HKEY hKey;				// 定义注册表键变量
	int iResult = RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", &hKey);	// 打开注册表键
	if (iResult == ERROR_SUCCESS)	printf("打开注册表成功.HKEY=%d", hKey);	// 输出成功信息	
	else	printf("打开注册表失败.错误代码=%d", iResult);	// 输出错误信息
}

// 22.1.5(OK)
bool IfKeyExistTest()
{	
	HKEY hKey;
	long lResult =RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		&hKey);
	if (lResult == ERROR_FILE_NOT_FOUND)
	{
		printf("指定的注册表项不存在\r\n"); return false;
	}
	else
	{
		printf("指定的注册表项存在\r\n"); return true;
	}
}

// 22.1.6(OK)
bool DeleteKeyTest()	// 删除注册表项
{
    if(RegDeleteKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest") == ERROR_SUCCESS)
    {
        printf("删除注册表项成功\r\n");
        return TRUE;
    }
    else
    {
        printf("删除注册表项失败\r\n");
        return FALSE;
    }
}

// 22.1.7(OK)
bool OpenRootKeyTest()	// 打开注册表根项
{
	HKEY hKey;			// 注册表键值
	int iResult = RegOpenKey(HKEY_CURRENT_USER, NULL, &hKey);	// 打开根项
	if (iResult == ERROR_SUCCESS)	// 打开成功
	{
		printf("打开注册表根项成功\r\n");
		return TRUE;
	}
	else							// 打开失败
	{
		printf("打开注册表根项失败\r\n");
		return FALSE;
	}
}

// 22.1.8(OK)
bool WriteKeyDefaultValueTest()		// 向关键值写入默认值
{
	DWORD value = 21;			// 定义写入值变量
	HKEY hKey;				// 定义键值句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		&hKey) != ERROR_SUCCESS) 	// 打开注册表项
	{
		printf("打开注册表项失败");
		return FALSE;
	}
	bool bRet;
	if(RegSetValueEx(hKey, NULL, NULL, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS)	// 写入默认值
	{
        printf("向指定注册表项写入默认值成功\r\n");
        bRet = true;
    }		// 写入成功
	else 
    { 
        printf("向指定注册表项写入默认值失败\r\n");
        bRet = false;
    }	// 写入失败
	RegCloseKey(hKey);		// 关闭注册表项
	return bRet;			// 函数返回
}

// 22.1.9(OK)
bool WriteKeyValueTest()		// 设置注册表键值
{
	
	DWORD value = 5;		// 定义写入的键值变量
	HKEY hKey;			// 定义注册表项句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		&hKey) != ERROR_SUCCESS) 	// 打开注册表项
	{
        printf("打开注册表项失败");
        return FALSE;	
    }
	bool bRet;							// 定义返回值
	if(RegSetValueEx(hKey, "MaxVersion", NULL, REG_DWORD, (const BYTE*)&value, 
	sizeof(DWORD)) == ERROR_SUCCESS)	// 写入键值
	{	
        printf("向指定注册表项写入键值成功\r\n");
        bRet = true;
    }
	else 
    {  
        printf("向指定注册表项写入键值失败\r\n");
        bRet = false;
    }
	RegCloseKey(hKey);					// 关闭注册表键值
	return bRet;						// 函数返回
}


// 22.1.10(OK)
bool QuickWriteKeyValueTest()		// 快速设置注册表键值示例
{
	char author[50]={0};			// 写入的数值变量			
	strcpy(author, "杯子");			// 为写入变量赋值
	bool bRet = false;			// 定义返回值
	if (RegSetValue(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		REG_SZ, (const char*)author, strlen(author)) == ERROR_SUCCESS)
	{
        printf("快速设置注册表键值字符串数据成功\r\n");
        bRet = true;
    }
	else 
    { 
        printf("快速设置注册表键值字符串数据失败\r\n");
        bRet = false;
    }
	return bRet;
}


// 程序主入口
int main(int argc, char* argv[])
{	
	CreateKeyTest();
	//OpenKeyTest();
	//IfKeyExistTest();
	//DeleteKeyTest();
	//OpenRootKeyTest();
	//WriteKeyDefaultValueTest();
	//WriteKeyValueTest();
	QuickWriteKeyValueTest();
//	system("pause");
	return 0;
}

