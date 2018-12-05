// ThreadGlobalShareSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "process.h"


DWORD WINAPI ThreadFunc( LPVOID lpParam ) 
{
    printf("启动线程.参数值=%d\n", lpParam); 
    return 0; 
} 


int main(int argc, char* argv[])
{
	DWORD dwThreadId;
	DWORD dwValue = 7;
	HANDLE hThread; 
	hThread = CreateThread(NULL,0, (LPTHREAD_START_ROUTINE)ThreadFunc, 
		(LPVOID)dwValue, 0, &dwThreadId); 
	if (hThread == NULL) printf("创建线程失败");
	Sleep(2000);
	CloseHandle( hThread );
	printf("主线程结束\n");
	system("pause");
	return 0;
}


