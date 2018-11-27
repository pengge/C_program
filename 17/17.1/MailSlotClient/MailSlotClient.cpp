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
        printf("创建客户端邮槽失败。错误代码=%d\n",  GetLastError());
        return -1;
    }

    sprintf(Content, "我是客户端邮槽，向服务器发送测试数据");
    if (WriteFile(hSlot,  Content, strlen(Content),  &dwByteWrites, NULL)  == 0)
    {
        printf("向邮槽写入数据失败。错误代码=%d\n",  GetLastError());
        return -1;
    }
    printf("向邮槽写入%d个字节数据\n", dwByteWrites);
    CloseHandle(hSlot);
    system("pause");
    return 0;
}