#include "sqlext.h"

class MyODBCAPI
{// ODBC API类封装
public:
	MyODBCAPI();		// 构造函数
	~MyODBCAPI();		// 析构函数

	SQLHENV henv;		// 环境句柄
	SQLHDBC hdbc;		// 连接句柄
	SQLHSTMT hstmt;		// 语句句柄
	SQLRETURN retcode;	// 错误代码
	CString msg;		// 当前错误信息
	BOOL bInit;			// 是否初始化成功

	BOOL InitODBC();
	BOOL Connect(CString odbcName, CString userID, CString pass);
	BOOL ExecSQL(CString sql);
	void QueryCustomer();
	void InsertCustomer(CString CompanyName, CString ContactName);
	void DeleteCustomer(CString CustomerID);
};
