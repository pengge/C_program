// MailSlotClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include "process.h"

int main(int argc, char* argv[])
{
    HANDLE		hSlot;
    DWORD		dwByteWrites;
    char        ComputerName[256];
    char		Content[256];
    sprintf(ComputerName,   "\\\\.\\Mailslot\\slotSample");
    hSlot = CreateFile(ComputerName, GENERIC_WRITE,
        FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hSlot == INVALID_HANDLE_VALUE)
    {
        printf("�����ͻ����ʲ�ʧ�ܡ��������=%d\n",  GetLastError());
        return -1;
    }

    sprintf(Content, "���ǿͻ����ʲۣ�����������Ͳ�������");
    if (WriteFile(hSlot,  Content, strlen(Content),  &dwByteWrites, NULL)  == 0)
    {
        printf("���ʲ�д������ʧ�ܡ��������=%d\n",  GetLastError());
        return -1;
    }
    printf("���ʲ�д��%d���ֽ�����\n", dwByteWrites);
    CloseHandle(hSlot);
    system("pause");
    return 0;
}