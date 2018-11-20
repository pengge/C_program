#include "sqlext.h"

class MyODBCAPI
{// ODBC API���װ
public:
	MyODBCAPI();		// ���캯��
	~MyODBCAPI();		// ��������

	SQLHENV henv;		// �������
	SQLHDBC hdbc;		// ���Ӿ��
	SQLHSTMT hstmt;		// �����
	SQLRETURN retcode;	// �������
	CString msg;		// ��ǰ������Ϣ
	BOOL bInit;			// �Ƿ��ʼ���ɹ�

	BOOL InitODBC();
	BOOL Connect(CString odbcName, CString userID, CString pass);
	BOOL ExecSQL(CString sql);
	void QueryCustomer();
	void InsertCustomer(CString CompanyName, CString ContactName);
	void DeleteCustomer(CString CustomerID);
};
