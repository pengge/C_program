// AddSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 3) return -1;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = a+b;
	printf("%d+%d=%d\n", a, b, c);
	char in;
	scanf("Press any key to exit.%c", in);
	return 0;
}

