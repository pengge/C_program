// SysCSSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadProc1(LPVOID lpParam);
DWORD WINAPI ThreadProc2(LPVOID lpParam);
int iGolbalCount=0;
int iMax = 12;
CRITICAL_SECTION cs;

int main(int argc, char* argv[])
{
	HANDLE hThread1, hThread2; 
	InitializeCriticalSection(&cs);
	hThread1=CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
	hThread2=CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);	
	Sleep(50000); 
	DeleteCriticalSection(&cs);	//删除临界区对象
	printf("主线程结束!\n");
	return 0;
}


DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
	while (TRUE)
	{
		EnterCriticalSection(&cs);	
		if (iGolbalCount < iMax)
		{
			printf("这里是线程1，iGolbalCount=%d\r\n", iGolbalCount++);			
			LeaveCriticalSection(&cs);
		}
		else
		{
			LeaveCriticalSection(&cs);
			break;
		}
		Sleep(10);
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	while (TRUE)
	{
		EnterCriticalSection(&cs);
		if (iGolbalCount < iMax)
		{
			printf("这里是线程2，iGolbalCount=%d\r\n", iGolbalCount++);			
			LeaveCriticalSection(&cs);
		}
		else
		{
			LeaveCriticalSection(&cs);
			break;
		}
		Sleep(10);
	}
	return 0;
}