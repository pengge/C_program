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
{// ��ʼ��ODBC
	henv = NULL;
	hdbc = NULL;
	hstmt = NULL;
	bInit = FALSE;
	//��ʼ����������
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	if ((retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)) 
	{// ����ODBC�汾����		
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
		msg = "��ʼ��ODBC APIʧ��";
		return FALSE;
	}
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); // �������Ӿ��
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
	{
		SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (void*)10, 0); // ���ó�ʱʱ��Ϊ10��
		// ��������Դ
		retcode = SQLConnect(hdbc, (SQLCHAR*)(LPCTSTR)odbcName, SQL_NTS, 
		(SQLCHAR*)(LPCTSTR)userID, SQL_NTS,(SQLCHAR*)(LPCTSTR)pass, SQL_NTS);
		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
		{
			msg = "��������Դ�ɹ�";
			return TRUE;
		}
		else 
		{
			msg = "��������Դʧ��";
			return FALSE;
		}
	}
	else	
	{
		msg = "�������Ӿ��ʧ��";
		return FALSE;
	}
}

BOOL MyODBCAPI::ExecSQL(CString sql)
{
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt); // ���������
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLExecDirect(hstmt, (SQLTCHAR*)(LPCTSTR)sql, sql.GetLength());
		if  (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		{
			msg = "ִ�Уӣѣ����ɹ�";
			return TRUE;
		}
		else
		{
			msg = "ִ�Уӣѣ����ʧ��";
			return FALSE;
		}
	}
	else 
	{
		msg = "���������ʧ��";
		return FALSE;
	}
}

void MyODBCAPI::QueryCustomer()
{// ��ѯ���еĿͻ��Ĺ�˾���ƺ���ϵ������
	if (!Connect("Test", "sa", "sa"))
	{
		msg = "��������Դʧ��\n";
		return;
	}
	if (!ExecSQL("SELECT CompanyName, ContactName FROM Customers")) 
	{
		msg = "ִ��SQL���ʧ��\n";
		return;
	}
	msg = "��ѯ���Ŀͻ���Ϣ����\r\n���\t��˾����\t��ϵ������\r\n";
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
{// ����ͻ���Ϣ
	if (!Connect("Test", "sa", "sa"))
	{
		msg = "��������Դʧ��\n";
		return;
	}
	CString sql;
	sql.Format("INSERT into  Customers (CompanyName, ContactName) values('%s', '%s')", 
		CustomerID, CompanyName);
	if (!ExecSQL(sql))
	{
		msg = "����ͻ���Ϣʧ��\n";
		return;
	}
	msg = "����ͻ���Ϣ�ɹ�.SQL=" + sql;
	return;
}
void MyODBCAPI::DeleteCustomer(CString CustomerID)
{// ɾ���ͻ���Ϣ
	if (!Connect("Test", "sa", "sa"))
	{
		msg = "��������Դʧ��\n";
		return;
	}
	CString sql;
	sql.Format("DELETE FROM Customers WHERE CompanyName='%s'", CustomerID);
	if (!ExecSQL(sql))
	{
		msg = "ɾ���ͻ���Ϣʧ��\n";
		return;
	}
	msg = "ɾ���ͻ���Ϣ�ɹ�.SQL=" + sql;
	return;
}

