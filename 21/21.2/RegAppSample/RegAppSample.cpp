// RegAppSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"

// 22.2.1(OK)
void SaveRegKey()	// 保存注册表项
{	
	TOKEN_PRIVILEGES tp;	// 定义权限变量
	HANDLE hToken;			// 权限句柄
	LUID luid;				// 定义LUID

	// 打开进程权限句柄
	if(!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken )) 
	{
		printf("调用OpenProcessToken失败");
		return;
	}

	// 查找SE_BACKUP_NAME权限值
    if(!LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &luid)) 
	{
		printf("调用LookupPrivilegeValue失败");
		return;
	}

    tp.PrivilegeCount           = 1;			// 定义权限调整数量
    tp.Privileges[0].Luid       = luid;			// 设置权限值
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;	// 设置打开此权限

	// 调整进程权限
    AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES),  NULL, NULL );
    if (GetLastError() != ERROR_SUCCESS)		// 如果调整进程失败，则返回
	{
		printf("调用AdjustTokenPrivileges失败");
		return;
	}	

	HKEY hKeyToSave;		// 定义要保存的键句柄
    DWORD dwDisposition;	// 定义选项值

	// 创建并打开注册表项
    if(RegCreateKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 0,NULL,REG_OPTION_BACKUP_RESTORE, 
		  KEY_ALL_ACCESS, NULL,&hKeyToSave,&dwDisposition)==ERROR_SUCCESS)
    {
		// 保存注册表项到文件中
        if (RegSaveKey(hKeyToSave, "C:\\MyInfo.reg", NULL) == ERROR_SUCCESS)
			printf("保存注册表成功");
		else
            printf("保存注册表成功");
        RegCloseKey(hKeyToSave);	// 关闭注册表项
    }
	else
	{
		printf("打开注册表失败");
	}
    return;		// 函数返回
}


// 22.2.2(OK)
void SysStartRun()	// 开机自动运行
{
	char szValue[MAX_PATH]={0};			// 定义开机运行文件名变量
	strcpy(szValue, "C:\\Hello.exe");	// 为开机运行文件赋值
	HKEY hKey;							// 注册表项句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 
		&hKey) == ERROR_SUCCESS)		// 打开注册表项
	{
		// 添加启动项
		if(RegSetValueEx(hKey, "Hello", NULL, REG_SZ, (const BYTE*)&szValue, strlen(szValue)) == ERROR_SUCCESS)
			printf("添加开机自动运行项成功");
		else
            printf("添加开机自动运行项失败");
		RegCloseKey(hKey);				// 关闭注册表项
	}
	else
	{
		printf("打开注册表项失败");
	}	
}

// 22.2.3(OK)
void HideMyComputer(BOOL bHide)		// 隐藏和显示我的电脑
{
	DWORD dwValue;					// 定义设置的取值
	if (bHide) dwValue = 1;			// 如果隐藏
	else dwValue = 0;				// 如果显示
	HKEY hKey;						// 注册表键句柄
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\NonEnum", 
		&hKey) == ERROR_SUCCESS)	// 创建注册表项
	{
		// 设置注册表值
		if(RegSetValueEx(hKey, "{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("%s我的电脑成功", dwValue==1?"隐藏":"显示");
		else
            printf("%s我的电脑失败", dwValue==1?"隐藏":"显示");
		RegCloseKey(hKey);			// 关闭注册表项
	}
	else printf("创建注册表值失败");
}

// 22.2.4(OK)
void HideRcyBin(BOOL bHide)	// 隐藏和显示回收站
{	
	DWORD value;			// 定义设置的取值
	if (bHide) value = 1;	// 如果隐藏
	else value = 0;			// 如果显示
	HKEY hKey;				// 注册表键句柄
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\microsoft\\windows\\currentversion\\explorer\\hidedesktopicons\\newstartpanel", 
		&hKey) == ERROR_SUCCESS)	// 创建注册表项
	{
		// 设置注册表值
		if(RegSetValueEx(hKey, "{645ff040-5081-101b-9f08-00aa002f954e}", NULL, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("隐藏回收站成功");
		RegCloseKey(hKey);		// 关闭注册表项
	}	
	else
        printf("创建注册表值失败");
}

// 22.2.5(OK)
void HideDrivers(BOOL bHide)	// 隐藏显示所有驱动器
{
	
	DWORD dwValue;				// 定义设置的取值
	if (bHide) dwValue = 67108863;	// 如果隐藏
	else dwValue = 0;			// 如果显示
	HKEY hKey;					// 注册表键句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)// 创建注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, "NoDrives", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("隐藏所有驱动器成功");
		RegCloseKey(hKey);		// 关闭注册表项
	}
	else
        printf("创建注册表值失败");
}


// 22.2.6(OK)
void DisableFindMenu()	// 禁止"查找"菜单
{	
	DWORD dwValue=0;	// 定义设置的取值	
	HKEY hKey;			// 注册表键句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)	// 打开注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, "NoFind", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("禁止查找菜单成功");
		else printf("禁止查找菜单失败");
		RegCloseKey(hKey);	// 关闭注册表项
	}
	else printf("打开注册表值失败");
}

// 22.2.7(OK)
void DisableDocumentMenu()	// 禁止"文档"菜单 
{
	DWORD dwValue=0;		// 定义设置的取值
	HKEY hKey;				// 注册表键句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)	// 打开注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, "NoRecentDocsMenu", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("禁止文档菜单成功");
		else printf("禁止文档菜单失败");
		RegCloseKey(hKey);	// 关闭注册表项
	}
	else printf("打开注册表值失败");
}

// 22.2.8(OK)
void ClearRecentDocBeforeExit()	// 在退出WINDOWS时清除“文档”中的记录
{
	BYTE szValue[4]={01,00,00,00};	// 定义设置的取值
	HKEY hKey;						// 注册表键句柄
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)	// 打开注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, "ClearRecentDocsonExit", NULL, REG_BINARY, (const BYTE*)&szValue, sizeof(szValue)) == ERROR_SUCCESS)
			printf("在退出WINDOWS时清除文档中的记录 成功");
		else printf("在退出WINDOWS时清除文档中的记录 失败");
		RegCloseKey(hKey);		// 关闭注册表项
	}
	else printf("打开注册表值失败");
} 

// 22.2.9(OK)
void DisableRigisterEdit(BOOL bHide)	// 禁用注册表编辑器
{
	DWORD dwValue;			// 定义设置的取值
	if (bHide) dwValue = 1;	// 如果隐藏
	else dwValue = 0;		// 如果显示
	HKEY hKey;				// 注册表键句柄
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", 
		&hKey) == ERROR_SUCCESS)	// 打开注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, "DisableRegistryTools", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("禁用注册表编辑器成功");
		else printf("禁用注册表编辑器失败");
		RegCloseKey(hKey);	// 关闭注册表项
	}
	else printf("打开注册表值失败");
}

// 22.2.10(OK)
void DisableInfFile(BOOL bDisable)	// 禁止使用inf文件
{
	char szValue[50]={0};			// 定义设置的取值
	if (bDisable) strcpy(szValue, "txtfile");	// 如果禁用inf文件	
	else strcpy(szValue, "inffile");			// 如果启用inf文件
	HKEY hKey;									// 注册表键句柄
	if (RegOpenKey(HKEY_CLASSES_ROOT, ".inf", 
		&hKey) == ERROR_SUCCESS)	// 打开注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, NULL, NULL, REG_SZ, (const BYTE*)&szValue, strlen(szValue)) == ERROR_SUCCESS)
			printf("禁止使用inf文件成功");
		else printf("禁止使用inf文件失败");
		RegCloseKey(hKey);	// 关闭注册表项
	}
	else printf("打开注册表值失败");
}

// 22.2.11(OK)
void DisableRegFile(BOOL bDisable)	// 禁止使用reg文件
{
	char szValue[50]={0};						// 定义设置的取值
	if (bDisable) strcpy(szValue, "txtfile");	// 如果禁用reg文件	
	else strcpy(szValue, "regfile");			// 如果启用reg文件
	HKEY hKey;									// 注册表键句柄
	if (RegOpenKey(HKEY_CLASSES_ROOT, ".reg", 
		&hKey) == ERROR_SUCCESS)				// 打开注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, NULL, NULL, REG_SZ, (const BYTE*)&szValue, strlen(szValue)) == ERROR_SUCCESS)
			printf("禁止使用reg文件成功");
		else printf("禁止使用reg文件失败");	
		RegCloseKey(hKey);						// 关闭注册表项
	}
	else printf("打开注册表值失败");
}

// 22.2.12(OK)
void ShowHideFile(BOOL bDisable)	// 显示隐藏文件或文件夹
{
	DWORD dwValue;			// 定义设置的取值
	if (bDisable) dwValue = 1;	// 如果隐藏
	else dwValue = 0;		// 如果显示
	HKEY hKey;				// 注册表键句柄
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\AdvancedFolderHiddenSHOWALL", 
		&hKey) == ERROR_SUCCESS)	// 创建注册表项
	{	// 设置注册表值
		if(RegSetValueEx(hKey, "CheckedValue", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("显示隐藏文件或文件夹成功");
		else printf("显示隐藏文件或文件夹失败");	
		RegCloseKey(hKey);	// 关闭注册表项
	}
	else printf("创建注册表值失败");
}

int main(int argc, char* argv[])
{
	//SaveRegKey();
	SysStartRun();
	//HideMyComputer(FALSE);
	//HideRcyBin(FALSE);
	//HideDrivers(FALSE);
	//DisableFindMenu();
	//DisableDocumentMenu();
	//ClearRecentDocBeforeExit();
	//DisableRigisterEdit(FALSE);
	//DisableInfFile(FALSE);
	//DisableRegFile(TRUE);
	//ShowHideFile(TRUE);
	printf("\r\n");
	//system("pause");
	return 0;
}


