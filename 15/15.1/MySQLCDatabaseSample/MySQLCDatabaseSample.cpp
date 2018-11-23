// MySQLCDatabaseSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CDatabase.h"

int main(int argc, char* argv[])
{
	if (argc == 5) 
	{
		CDatabase db;
		if (db.Open(argv[1], argv[2], argv[3], argv[4]))
//        if (db.Open("127.0.0.1","root","pangzi90hou", "world"))
			db.ShowRecords("Select * from city");
	}
	else
		printf(" ‰»Î≤Œ ˝¥ÌŒÛ");
	return 0;
}

