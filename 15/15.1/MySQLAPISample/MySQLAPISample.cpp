// MySQLAPISample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"
#include "mysql.h"


static char *server_args[] = {
  "mysql test",      
  "--datadir=.",
  "--key_buffer_size=32M"
};
static char *server_groups[] = {
  "mysql test",
  "127.0.0.1",
  "mysql test",
  (char *)NULL
};

// 参数是主机、用户名、密码和数据库
int main(int argc, char* argv[])
{
	try
	{
		// 初始化MySQL库
		if(mysql_library_init(sizeof(server_args) / sizeof(char *),
                        server_args, server_groups))
		{
			printf("初始化MySQL库失败");
			return 0;
		}

		MYSQL mysql;

		// 初始化连接
		mysql_init(&mysql);

		// 连接MySQL数据库
		if (argc == 5)
		{
			if (!mysql_real_connect(&mysql, argv[1], argv[2], argv[3], argv[4], 0, NULL, 0))
			{
				printf("连接数据库失败。错误原因: %s\n",  mysql_error(&mysql));			
				return 0;
			}
		}
		else
		{
			if (!mysql_real_connect(&mysql, "127.0.0.1", "root", "pangzi90hou", "world", 0, NULL, 0))
			{
				printf("连接数据库失败。错误原因: %s\n",  mysql_error(&mysql));
				return 0;
			}
		}
 

		char sql[500]={0};
		sprintf(sql, "select * from city");
		// 执行查询操作
		if (mysql_real_query(&mysql, sql, strlen(sql)))
		{
			printf("执行查询操作失败。错误原因: %s\n",  mysql_error(&mysql));
			return 0;
		}

		printf("--------------------------------------------------\n");
		printf("查询到city表中的记录：\n");

		MYSQL_RES* result = mysql_use_result(&mysql);

		MYSQL_ROW row;
		unsigned int nFields;
		unsigned int i;
 
		nFields = mysql_num_fields(result);
		while ((row = mysql_fetch_row(result)))
		{
			unsigned long *lengths;
			lengths = mysql_fetch_lengths(result);
			for(i = 0; i < nFields; i++)
			{
				printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
			}
			printf("\n");
		}

		printf("--------------------------------------------------\n");

		// 关闭MySQL连接
		mysql_close(&mysql);

		// 释放MySQL库
		mysql_library_end();
	}
	catch(...)
	{		
		printf("执行MySQL C API发生异常\n");
	}

	system("pause");
	return 0;
}



