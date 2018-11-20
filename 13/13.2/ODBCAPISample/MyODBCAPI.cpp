#include "stdafx.h"
#include "ODBCAPISample.h"
#include "MyODBCAPI.h"

MyODBCAPI::MyODBCAPI()
{
	InitODBC();
}

MyODBCAPI::~MyODBCAPI()
{
	if (hstmt != NULL)
        SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	if (hdbc != NULL)
	{
		SQLDisconnect(hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	}
	if (henv != NULL)
        SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

BOOL MyODBCAPI::InitODBC()
{// 初始化ODBC
	henv = NULL;
	hdbc = NULL;
	hstmt = NULL;
	bInit = FALSE;
	//初始化环境变量
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	if ((retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)) 
	{// 设置ODBC版本属性		
		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
			bInit = TRUE;
	}
	return bInit;
}

BOOL MyODBCAPI::Connect(CString odbcName, CString userID, CString pass)
{
	if (!bInit)
	{
		msg = "初始化ODBC API失败";
		return FALSE;
	}
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); // 分配连接句柄
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
	{
		SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (void*)10, 0); // 设置超时时间为10秒
		// 连接数据源
		retcode = SQLConnect(hdbc, (SQLCHAR*)(LPCTSTR)odbcName, SQL_NTS, 
		(SQLCHAR*)(LPCTSTR)userID, SQL_NTS,(SQLCHAR*)(LPCTSTR)pass, SQL_NTS);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{
			msg = "连接数据源成功";
			return TRUE;
		}
		else 
		{
			msg = "连接数据源失败";
			return FALSE;
		}
	}
	else	
	{
		msg = "分配连接句柄失败";
		return FALSE;
	}
}

BOOL MyODBCAPI::ExecSQL(CString sql)
{
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt); // 分配语句句柄
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLExecDirect(hstmt, (SQLTCHAR*)(LPCTSTR)sql, sql.GetLength());
		if  (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		{
			msg = "执行ＳＱＬ语句成功";
			return TRUE;
		}
		else
		{
			msg = "执行ＳＱＬ语句失败";
			return FALSE;
		}
	}
	else 
	{
		msg = "分配语句句柄失败";
		return FALSE;
	}
}

void MyODBCAPI::QueryCustomer()
{// 查询所有的客户的公司名称和联系人姓名
	if (!Connect("Test", "sa", "sa"))
	{
		msg = "连接数据源失败\n";
		return;
	}
	if (!ExecSQL("SELECT CompanyName, ContactName FROM Customers")) 
	{
		msg = "执行SQL语句失败\n";
		return;
	}
	msg = "查询到的客户信息如下\r\n编号\t公司名称\t联系人姓名\r\n";
	CString CompanyName, ContactName;
	long cbNameLen = 500;
	SQLBindCol(hstmt, 1, SQL_C_CHAR,(void*)(LPCTSTR)CompanyName.GetBuffer(cbNameLen), cbNameLen, &cbNameLen);
	SQLBindCol(hstmt, 2, SQL_C_CHAR, (void*)(LPCTSTR)ContactName.GetBuffer(cbNameLen), cbNameLen, &cbNameLen);
	int i = 0;
	while (SQLFetch(hstmt) == SQL_SUCCESS) 
	{
		i++;
		if (retcode == SQL_NO_DATA_FOUND) break;
		CString info;
		info.Format("%d	%s		%s\r\n", i, CompanyName, ContactName);
		msg += info;
	}
}

void MyODBCAPI::InsertCustomer(CString CustomerID, CString CompanyName)
{// 插入客户信息
	if (!Connect("Test", "sa", "sa"))
	{
		msg = "连接数据源失败\n";
		return;
	}
	CString sql;
	sql.Format("INSERT into  Customers (CompanyName, ContactName) values('%s', '%s')", 
		CustomerID, CompanyName);
	if (!ExecSQL(sql))
	{
		msg = "插入客户信息失败\n";
		return;
	}
	msg = "插入客户信息成功.SQL=" + sql;
	return;
}
void MyODBCAPI::DeleteCustomer(CString CustomerID)
{// 删除客户信息
	if (!Connect("Test", "sa", "sa"))
	{
		msg = "连接数据源失败\n";
		return;
	}
	CString sql;
	sql.Format("DELETE FROM Customers WHERE CompanyName='%s'", CustomerID);
	if (!ExecSQL(sql))
	{
		msg = "删除客户信息失败\n";
		return;
	}
	msg = "删除客户信息成功.SQL=" + sql;
	return;
}

