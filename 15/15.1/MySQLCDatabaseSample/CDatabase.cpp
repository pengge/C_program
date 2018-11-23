#include "StdAfx.h"
#include "CDatabase.h"
#include "mysql.h"

// 构造函数初始化MYSQL对象
CDatabase::CDatabase()
{
	mysql_init(&mysql);
}

// 析构函数
CDatabase::~CDatabase()
{
	Close();
	mysql_library_end();
}

// 关闭数据库连接
void CDatabase::Close()
{
	if(query)	mysql_free_result(query);
	mysql_close(&mysql);
}

// 打开数据库
bool CDatabase::Open(char* host, char* user, char* pass, char* db)
{
	if(!mysql_real_connect(&mysql, host, user, pass, db, 0, NULL, 0))
	{ 		
		printf("执行查询操作失败。错误原因: %s\n",  mysql_error(&mysql));		
		return false;
	}
	return true;
}

//选择记录
bool CDatabase::Execute(char* sql)
{
	if(mysql_real_query(&mysql, sql, strlen(sql)))	return false;
	query = mysql_use_result(&mysql);
	return true;
}

//获取字段个数
int CDatabase::GetFieldNum()
{
	if (query) return mysql_num_fields(query);
	return 0;
}

//获取记录行
MYSQL_ROW CDatabase::GetRecord()
{
	if (query) 
	{
		row = mysql_fetch_row(query);
		return row;
	}
	return NULL;
}

// 获取记录集
void CDatabase::GetRecords()
{
	query = mysql_use_result(&mysql);
}

// 获取记录集字段值的长度
unsigned long * CDatabase::GetRecordFieldLength()
{
	if (query) return mysql_fetch_lengths(query);
	return NULL;
}

// 显示查询结果集
bool CDatabase::ShowRecords(char* sql)
{
	// 执行查询操作
	if (!Execute(sql)) return FALSE;
	
	printf("--------------------------------------------------\n");
	printf("结果记录集：\n");

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



