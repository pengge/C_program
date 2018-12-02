// RegAppSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"

// 22.2.1(OK)
void SaveRegKey()	// ����ע�����
{	
	TOKEN_PRIVILEGES tp;	// ����Ȩ�ޱ���
	HANDLE hToken;			// Ȩ�޾��
	LUID luid;				// ����LUID

	// �򿪽���Ȩ�޾��
	if(!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken )) 
	{
		printf("����OpenProcessTokenʧ��");
		return;
	}

	// ����SE_BACKUP_NAMEȨ��ֵ
    if(!LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &luid)) 
	{
		printf("����LookupPrivilegeValueʧ��");
		return;
	}

    tp.PrivilegeCount           = 1;			// ����Ȩ�޵�������
    tp.Privileges[0].Luid       = luid;			// ����Ȩ��ֵ
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;	// ���ô򿪴�Ȩ��

	// ��������Ȩ��
    AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES),  NULL, NULL );
    if (GetLastError() != ERROR_SUCCESS)		// �����������ʧ�ܣ��򷵻�
	{
		printf("����AdjustTokenPrivilegesʧ��");
		return;
	}	

	HKEY hKeyToSave;		// ����Ҫ����ļ����
    DWORD dwDisposition;	// ����ѡ��ֵ

	// ��������ע�����
    if(RegCreateKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 0,NULL,REG_OPTION_BACKUP_RESTORE, 
		  KEY_ALL_ACCESS, NULL,&hKeyToSave,&dwDisposition)==ERROR_SUCCESS)
    {
		// ����ע�����ļ���
        if (RegSaveKey(hKeyToSave, "C:\\MyInfo.reg", NULL) == ERROR_SUCCESS)
			printf("����ע���ɹ�");
		else
            printf("����ע���ɹ�");
        RegCloseKey(hKeyToSave);	// �ر�ע�����
    }
	else
	{
		printf("��ע���ʧ��");
	}
    return;		// ��������
}


// 22.2.2(OK)
void SysStartRun()	// �����Զ�����
{
	char szValue[MAX_PATH]={0};			// ���忪�������ļ�������
	strcpy(szValue, "C:\\Hello.exe");	// Ϊ���������ļ���ֵ
	HKEY hKey;							// ע�������
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 
		&hKey) == ERROR_SUCCESS)		// ��ע�����
	{
		// ���������
		if(RegSetValueEx(hKey, "Hello", NULL, REG_SZ, (const BYTE*)&szValue, strlen(szValue)) == ERROR_SUCCESS)
			printf("��ӿ����Զ�������ɹ�");
		else
            printf("��ӿ����Զ�������ʧ��");
		RegCloseKey(hKey);				// �ر�ע�����
	}
	else
	{
		printf("��ע�����ʧ��");
	}	
}

// 22.2.3(OK)
void HideMyComputer(BOOL bHide)		// ���غ���ʾ�ҵĵ���
{
	DWORD dwValue;					// �������õ�ȡֵ
	if (bHide) dwValue = 1;			// �������
	else dwValue = 0;				// �����ʾ
	HKEY hKey;						// ע�������
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\NonEnum", 
		&hKey) == ERROR_SUCCESS)	// ����ע�����
	{
		// ����ע���ֵ
		if(RegSetValueEx(hKey, "{20D04FE0-3AEA-1069-A2D8-08002B30309D}", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("%s�ҵĵ��Գɹ�", dwValue==1?"����":"��ʾ");
		else
            printf("%s�ҵĵ���ʧ��", dwValue==1?"����":"��ʾ");
		RegCloseKey(hKey);			// �ر�ע�����
	}
	else printf("����ע���ֵʧ��");
}

// 22.2.4(OK)
void HideRcyBin(BOOL bHide)	// ���غ���ʾ����վ
{	
	DWORD value;			// �������õ�ȡֵ
	if (bHide) value = 1;	// �������
	else value = 0;			// �����ʾ
	HKEY hKey;				// ע�������
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\microsoft\\windows\\currentversion\\explorer\\hidedesktopicons\\newstartpanel", 
		&hKey) == ERROR_SUCCESS)	// ����ע�����
	{
		// ����ע���ֵ
		if(RegSetValueEx(hKey, "{645ff040-5081-101b-9f08-00aa002f954e}", NULL, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("���ػ���վ�ɹ�");
		RegCloseKey(hKey);		// �ر�ע�����
	}	
	else
        printf("����ע���ֵʧ��");
}

// 22.2.5(OK)
void HideDrivers(BOOL bHide)	// ������ʾ����������
{
	
	DWORD dwValue;				// �������õ�ȡֵ
	if (bHide) dwValue = 67108863;	// �������
	else dwValue = 0;			// �����ʾ
	HKEY hKey;					// ע�������
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)// ����ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, "NoDrives", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("���������������ɹ�");
		RegCloseKey(hKey);		// �ر�ע�����
	}
	else
        printf("����ע���ֵʧ��");
}


// 22.2.6(OK)
void DisableFindMenu()	// ��ֹ"����"�˵�
{	
	DWORD dwValue=0;	// �������õ�ȡֵ	
	HKEY hKey;			// ע�������
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)	// ��ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, "NoFind", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("��ֹ���Ҳ˵��ɹ�");
		else printf("��ֹ���Ҳ˵�ʧ��");
		RegCloseKey(hKey);	// �ر�ע�����
	}
	else printf("��ע���ֵʧ��");
}

// 22.2.7(OK)
void DisableDocumentMenu()	// ��ֹ"�ĵ�"�˵� 
{
	DWORD dwValue=0;		// �������õ�ȡֵ
	HKEY hKey;				// ע�������
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)	// ��ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, "NoRecentDocsMenu", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("��ֹ�ĵ��˵��ɹ�");
		else printf("��ֹ�ĵ��˵�ʧ��");
		RegCloseKey(hKey);	// �ر�ע�����
	}
	else printf("��ע���ֵʧ��");
}

// 22.2.8(OK)
void ClearRecentDocBeforeExit()	// ���˳�WINDOWSʱ������ĵ����еļ�¼
{
	BYTE szValue[4]={01,00,00,00};	// �������õ�ȡֵ
	HKEY hKey;						// ע�������
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 
		&hKey) == ERROR_SUCCESS)	// ��ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, "ClearRecentDocsonExit", NULL, REG_BINARY, (const BYTE*)&szValue, sizeof(szValue)) == ERROR_SUCCESS)
			printf("���˳�WINDOWSʱ����ĵ��еļ�¼ �ɹ�");
		else printf("���˳�WINDOWSʱ����ĵ��еļ�¼ ʧ��");
		RegCloseKey(hKey);		// �ر�ע�����
	}
	else printf("��ע���ֵʧ��");
} 

// 22.2.9(OK)
void DisableRigisterEdit(BOOL bHide)	// ����ע���༭��
{
	DWORD dwValue;			// �������õ�ȡֵ
	if (bHide) dwValue = 1;	// �������
	else dwValue = 0;		// �����ʾ
	HKEY hKey;				// ע�������
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", 
		&hKey) == ERROR_SUCCESS)	// ��ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, "DisableRegistryTools", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("����ע���༭���ɹ�");
		else printf("����ע���༭��ʧ��");
		RegCloseKey(hKey);	// �ر�ע�����
	}
	else printf("��ע���ֵʧ��");
}

// 22.2.10(OK)
void DisableInfFile(BOOL bDisable)	// ��ֹʹ��inf�ļ�
{
	char szValue[50]={0};			// �������õ�ȡֵ
	if (bDisable) strcpy(szValue, "txtfile");	// �������inf�ļ�	
	else strcpy(szValue, "inffile");			// �������inf�ļ�
	HKEY hKey;									// ע�������
	if (RegOpenKey(HKEY_CLASSES_ROOT, ".inf", 
		&hKey) == ERROR_SUCCESS)	// ��ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, NULL, NULL, REG_SZ, (const BYTE*)&szValue, strlen(szValue)) == ERROR_SUCCESS)
			printf("��ֹʹ��inf�ļ��ɹ�");
		else printf("��ֹʹ��inf�ļ�ʧ��");
		RegCloseKey(hKey);	// �ر�ע�����
	}
	else printf("��ע���ֵʧ��");
}

// 22.2.11(OK)
void DisableRegFile(BOOL bDisable)	// ��ֹʹ��reg�ļ�
{
	char szValue[50]={0};						// �������õ�ȡֵ
	if (bDisable) strcpy(szValue, "txtfile");	// �������reg�ļ�	
	else strcpy(szValue, "regfile");			// �������reg�ļ�
	HKEY hKey;									// ע�������
	if (RegOpenKey(HKEY_CLASSES_ROOT, ".reg", 
		&hKey) == ERROR_SUCCESS)				// ��ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, NULL, NULL, REG_SZ, (const BYTE*)&szValue, strlen(szValue)) == ERROR_SUCCESS)
			printf("��ֹʹ��reg�ļ��ɹ�");
		else printf("��ֹʹ��reg�ļ�ʧ��");	
		RegCloseKey(hKey);						// �ر�ע�����
	}
	else printf("��ע���ֵʧ��");
}

// 22.2.12(OK)
void ShowHideFile(BOOL bDisable)	// ��ʾ�����ļ����ļ���
{
	DWORD dwValue;			// �������õ�ȡֵ
	if (bDisable) dwValue = 1;	// �������
	else dwValue = 0;		// �����ʾ
	HKEY hKey;				// ע�������
	if (RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\AdvancedFolderHiddenSHOWALL", 
		&hKey) == ERROR_SUCCESS)	// ����ע�����
	{	// ����ע���ֵ
		if(RegSetValueEx(hKey, "CheckedValue", NULL, REG_DWORD, (const BYTE*)&dwValue, sizeof(DWORD)) == ERROR_SUCCESS)
			printf("��ʾ�����ļ����ļ��гɹ�");
		else printf("��ʾ�����ļ����ļ���ʧ��");	
		RegCloseKey(hKey);	// �ر�ע�����
	}
	else printf("����ע���ֵʧ��");
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


