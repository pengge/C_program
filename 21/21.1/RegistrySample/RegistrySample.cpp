// RegistrySample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"

// 22.1.3(OK)
void CreateKeyTest()		// ���ٴ���ע����
{
	HKEY hKey;				// ����ע��������
	int iRet = RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", &hKey);// ������ע����
	if (iRet == ERROR_SUCCESS)
        printf("���ٴ���ע���ɹ�");	// ����ɹ���Ϣ
	else
        printf("���ٴ���ע���ʧ��.�������=%d", iRet);		// ���������Ϣ
}

// 22.1.4(OK)
void OpenKeyTest()			// ��ע����
{
	HKEY hKey;				// ����ע��������
	int iResult = RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", &hKey);	// ��ע����
	if (iResult == ERROR_SUCCESS)	printf("��ע���ɹ�.HKEY=%d", hKey);	// ����ɹ���Ϣ	
	else	printf("��ע���ʧ��.�������=%d", iResult);	// ���������Ϣ
}

// 22.1.5(OK)
bool IfKeyExistTest()
{	
	HKEY hKey;
	long lResult =RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		&hKey);
	if (lResult == ERROR_FILE_NOT_FOUND)
	{
		printf("ָ����ע��������\r\n"); return false;
	}
	else
	{
		printf("ָ����ע��������\r\n"); return true;
	}
}

// 22.1.6(OK)
bool DeleteKeyTest()	// ɾ��ע�����
{
    if(RegDeleteKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest") == ERROR_SUCCESS)
    {
        printf("ɾ��ע�����ɹ�\r\n");
        return TRUE;
    }
    else
    {
        printf("ɾ��ע�����ʧ��\r\n");
        return FALSE;
    }
}

// 22.1.7(OK)
bool OpenRootKeyTest()	// ��ע������
{
	HKEY hKey;			// ע����ֵ
	int iResult = RegOpenKey(HKEY_CURRENT_USER, NULL, &hKey);	// �򿪸���
	if (iResult == ERROR_SUCCESS)	// �򿪳ɹ�
	{
		printf("��ע������ɹ�\r\n");
		return TRUE;
	}
	else							// ��ʧ��
	{
		printf("��ע������ʧ��\r\n");
		return FALSE;
	}
}

// 22.1.8(OK)
bool WriteKeyDefaultValueTest()		// ��ؼ�ֵд��Ĭ��ֵ
{
	DWORD value = 21;			// ����д��ֵ����
	HKEY hKey;				// �����ֵ���
	if (RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		&hKey) != ERROR_SUCCESS) 	// ��ע�����
	{
		printf("��ע�����ʧ��");
		return FALSE;
	}
	bool bRet;
	if(RegSetValueEx(hKey, NULL, NULL, REG_DWORD, (const BYTE*)&value, sizeof(DWORD)) == ERROR_SUCCESS)	// д��Ĭ��ֵ
	{
        printf("��ָ��ע�����д��Ĭ��ֵ�ɹ�\r\n");
        bRet = true;
    }		// д��ɹ�
	else 
    { 
        printf("��ָ��ע�����д��Ĭ��ֵʧ��\r\n");
        bRet = false;
    }	// д��ʧ��
	RegCloseKey(hKey);		// �ر�ע�����
	return bRet;			// ��������
}

// 22.1.9(OK)
bool WriteKeyValueTest()		// ����ע����ֵ
{
	
	DWORD value = 5;		// ����д��ļ�ֵ����
	HKEY hKey;			// ����ע�������
	if (RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		&hKey) != ERROR_SUCCESS) 	// ��ע�����
	{
        printf("��ע�����ʧ��");
        return FALSE;	
    }
	bool bRet;							// ���巵��ֵ
	if(RegSetValueEx(hKey, "MaxVersion", NULL, REG_DWORD, (const BYTE*)&value, 
	sizeof(DWORD)) == ERROR_SUCCESS)	// д���ֵ
	{	
        printf("��ָ��ע�����д���ֵ�ɹ�\r\n");
        bRet = true;
    }
	else 
    {  
        printf("��ָ��ע�����д���ֵʧ��\r\n");
        bRet = false;
    }
	RegCloseKey(hKey);					// �ر�ע����ֵ
	return bRet;						// ��������
}


// 22.1.10(OK)
bool QuickWriteKeyValueTest()		// ��������ע����ֵʾ��
{
	char author[50]={0};			// д�����ֵ����			
	strcpy(author, "����");			// Ϊд�������ֵ
	bool bRet = false;			// ���巵��ֵ
	if (RegSetValue(HKEY_CURRENT_USER, "SOFTWARE\\LLN\\VC\\Registry\\CreateTest", 
		REG_SZ, (const char*)author, strlen(author)) == ERROR_SUCCESS)
	{
        printf("��������ע����ֵ�ַ������ݳɹ�\r\n");
        bRet = true;
    }
	else 
    { 
        printf("��������ע����ֵ�ַ�������ʧ��\r\n");
        bRet = false;
    }
	return bRet;
}


// ���������
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

