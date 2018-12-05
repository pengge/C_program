// SysMutexSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadProc1(LPVOID lpParam);
DWORD WINAPI ThreadProc2(LPVOID lpParam);
int iGolbalCount=0;
int iMax = 12;
HANDLE hMutex;

int main(int argc, char* argv[])
{
	HANDLE hThread1, hThread2;
	hThread1=CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
	hThread2=CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

	hMutex=CreateMutex(NULL,TRUE,LPCTSTR("iGolbalCount"));
	if (hMutex == NULL) 
	{
		printf("创建互斥对象失败！\r\n");
		return 0;
	}
	
	WaitForSingleObject(hMutex,INFINITE);
	ReleaseMutex(hMutex);
	ReleaseMutex(hMutex);
    Sleep(5000);
	printf("主线程结束!\n");
	return 0;
}


DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
	while (TRUE)
	{
		WaitForSingleObject(hMutex,INFINITE);		
		if (iGolbalCount < iMax)
            printf("这里是线程1，iGolbalCount=%d\r\n", iGolbalCount++);
		else
            break;
		ReleaseMutex(hMutex);
		Sleep(10);
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	while (TRUE)
	{
		WaitForSingleObject(hMutex,INFINITE);		
		if (iGolbalCount < iMax)
            printf("这里是线程2，iGolbalCount=%d\r\n", iGolbalCount++);			
		else
            break;
		ReleaseMutex(hMutex);
		Sleep(10);
	}
	return 0;
}

