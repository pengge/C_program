// SysSemaphoreSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadProc1(LPVOID lpParam);
DWORD WINAPI ThreadProc2(LPVOID lpParam);
int iGolbalCount=0;
int iMax = 12;
int cMax = 1;
HANDLE hSemaphore;

int main(int argc, char* argv[])
{
	HANDLE hThread1, hThread2; 
	hSemaphore = CreateSemaphore( NULL, cMax, cMax, NULL); 
	if (hSemaphore == NULL) 
	{
		printf("创建信号量对象失败");
		return 0;
	}

	hThread1=CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
	hThread2=CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);
	Sleep(5000);
	printf("主线程结束!");
	system("pause");
	return 0;
}


DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
	while (TRUE)
	{
		DWORD dwWaitResult = WaitForSingleObject(hSemaphore, 0L);
		if (dwWaitResult == WAIT_OBJECT_0)
		{		
			if (iGolbalCount < iMax)
			{
				printf("这里是线程1，iGolbalCount=%d\r\n", iGolbalCount++);			
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
			else
			{
				ReleaseSemaphore(hSemaphore, 1, NULL);
				break;
			}
		}
		Sleep(10);
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	while (TRUE)
	{
		DWORD dwWaitResult = WaitForSingleObject(hSemaphore, 0L);
		if (dwWaitResult == WAIT_OBJECT_0)
		{		
			if (iGolbalCount < iMax)
			{
				printf("这里是线程2，iGolbalCount=%d\r\n", iGolbalCount++);			
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
			else
			{
				ReleaseSemaphore(hSemaphore, 1, NULL);
				break;
			}
		}
		Sleep(10);
	}
	return 0;
}
