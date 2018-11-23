#include "StdAfx.h"
#include "CDatabase.h"
#include "mysql.h"

// ���캯����ʼ��MYSQL����
CDatabase::CDatabase()
{
	mysql_init(&mysql);
}

// ��������
CDatabase::~CDatabase()
{
	Close();
	mysql_library_end();
}

// �ر����ݿ�����
void CDatabase::Close()
{
	if(query)	mysql_free_result(query);
	mysql_close(&mysql);
}

// �����ݿ�
bool CDatabase::Open(char* host, char* user, char* pass, char* db)
{
	if(!mysql_real_connect(&mysql, host, user, pass, db, 0, NULL, 0))
	{ 		
		printf("ִ�в�ѯ����ʧ�ܡ�����ԭ��: %s\n",  mysql_error(&mysql));		
		return false;
	}
	return true;
}

//ѡ���¼
bool CDatabase::Execute(char* sql)
{
	if(mysql_real_query(&mysql, sql, strlen(sql)))	return false;
	query = mysql_use_result(&mysql);
	return true;
}

//��ȡ�ֶθ���
int CDatabase::GetFieldNum()
{
	if (query) return mysql_num_fields(query);
	return 0;
}

//��ȡ��¼��
MYSQL_ROW CDatabase::GetRecord()
{
	if (query) 
	{
		row = mysql_fetch_row(query);
		return row;
	}
	return NULL;
}

// ��ȡ��¼��
void CDatabase::GetRecords()
{
	query = mysql_use_result(&mysql);
}

// ��ȡ��¼���ֶ�ֵ�ĳ���
unsigned long * CDatabase::GetRecordFieldLength()
{
	if (query) return mysql_fetch_lengths(query);
	return NULL;
}

// ��ʾ��ѯ�����
bool CDatabase::ShowRecords(char* sql)
{
	// ִ�в�ѯ����
	if (!Execute(sql)) return FALSE;
	
	printf("--------------------------------------------------\n");
	printf("�����¼����\n");

	unsigned int nFields = GetFieldNum();

	while ((row = GetRecord()))
	{
		unsigned long *lengths;
		lengths = GetRecordFieldLength();
		for(UINT i = 0; i < nFields; i++)
		{
			printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	printf("--------------------------------------------------\n");
	return TRUE;
}



