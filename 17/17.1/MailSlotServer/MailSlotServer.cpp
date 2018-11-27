// MailSlotServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#define MAX_BUFFER_LEN	256

int main(int argc, char* argv[])
{
    HANDLE   hSlot;
    char     buffer[MAX_BUFFER_LEN];
    DWORD    nReadBytes;
    hSlot = CreateMailslot("\\\\.\\Mailslot\\slotSample",
        0, MAILSLOT_WAIT_FOREVER, NULL);
    if (hSlot == INVALID_HANDLE_VALUE)
    {
        printf("创建邮槽失败。错误代码=%d\n", GetLastError());
        return 0;
    }

    while (ReadFile(hSlot, buffer, MAX_BUFFER_LEN, &nReadBytes, NULL) != 0)
    {
        printf("接收到邮槽数据=%.*s\n",  nReadBytes, buffer);
    }
    return 0;
}
