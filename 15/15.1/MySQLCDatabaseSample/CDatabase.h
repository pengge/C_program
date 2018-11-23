#include "mysql.h"

class CDatabase 
{
public:	
	CDatabase();		// 构造函数初始化MYSQL对象
	~CDatabase();	// 析构函数
	void Close();			// 关闭数据库连接
	bool Open(char* host, char* user, char* pass, char* db);// 打开数据库
	bool Execute(char* sql);		//选择记录
	int GetFieldNum();			//获取字段个数
	MYSQL_ROW GetRecord();		//获取记录行
	void GetRecords();			// 获取记录集
	unsigned long * GetRecordFieldLength();// 获取记录集字段值的长度
	bool ShowRecords(char* sql);	// 显示查询结果集

private:
	MYSQL mysql;		//数据库连接句柄
	MYSQL_RES *query;	//结果集
	MYSQL_ROW row;		//记录集
	MYSQL_FIELD *field; //字段信息
};
