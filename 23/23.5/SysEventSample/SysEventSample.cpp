// SysEventSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "process.h"

DWORD WINAPI ThreadProc1(LPVOID lpParam);
DWORD WINAPI ThreadProc2(LPVOID lpParam);
int iGolbalCount=0;
int iMax = 12;
HANDLE hEvent;

int main(int argc, char* argv[])
{
	HANDLE hThread1, hThread2;
	hEvent=CreateEvent(NULL,FALSE,FALSE,LPCTSTR("iGolbalCount"));
	if (hEvent == NULL) 
	{
		printf("�����¼�����ʧ�ܣ�\r\n");
		return 0;		
	}

	SetEvent(hEvent);
 
	hThread1=CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
	hThread2=CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

	Sleep(40000); 
	CloseHandle(hEvent);	//�ر��¼�������
	printf("���߳̽���!\n");
	system("pause");
	return 0;
}


DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
	while (TRUE)
	{
		WaitForSingleObject(hEvent,INFINITE);		
		if (iGolbalCount < iMax)
		{
			printf("�������߳�1��iGolbalCount=%d\r\n", iGolbalCount++);			
			SetEvent(hEvent);
		}
		else
		{
			SetEvent(hEvent);
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
		WaitForSingleObject(hEvent,INFINITE);		
		if (iGolbalCount < iMax)
		{
			printf("�������߳�2��iGolbalCount=%d\r\n", iGolbalCount++);			
			SetEvent(hEvent);
		}
		else
		{
			SetEvent(hEvent);
			break;
		}
		Sleep(10);
	}
	return 0;
}


