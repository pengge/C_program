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

// �������������û�������������ݿ�
int main(int argc, char* argv[])
{
	try
	{
		// ��ʼ��MySQL��
		if(mysql_library_init(sizeof(server_args) / sizeof(char *),
                        server_args, server_groups))
		{
			printf("��ʼ��MySQL��ʧ��");
			return 0;
		}

		MYSQL mysql;

		// ��ʼ������
		mysql_init(&mysql);

		// ����MySQL���ݿ�
		if (argc == 5)
		{
			if (!mysql_real_connect(&mysql, argv[1], argv[2], argv[3], argv[4], 0, NULL, 0))
			{
				printf("�������ݿ�ʧ�ܡ�����ԭ��: %s\n",  mysql_error(&mysql));			
				return 0;
			}
		}
		else
		{
			if (!mysql_real_connect(&mysql, "127.0.0.1", "root", "pangzi90hou", "world", 0, NULL, 0))
			{
				printf("�������ݿ�ʧ�ܡ�����ԭ��: %s\n",  mysql_error(&mysql));
				return 0;
			}
		}
 

		char sql[500]={0};
		sprintf(sql, "select * from city");
		// ִ�в�ѯ����
		if (mysql_real_query(&mysql, sql, strlen(sql)))
		{
			printf("ִ�в�ѯ����ʧ�ܡ�����ԭ��: %s\n",  mysql_error(&mysql));
			return 0;
		}

		printf("--------------------------------------------------\n");
		printf("��ѯ��city���еļ�¼��\n");

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

		// �ر�MySQL����
		mysql_close(&mysql);

		// �ͷ�MySQL��
		mysql_library_end();
	}
	catch(...)
	{		
		printf("ִ��MySQL C API�����쳣\n");
	}

	system("pause");
	return 0;
}



