#include "mysql.h"

class CDatabase 
{
public:	
	CDatabase();		// ���캯����ʼ��MYSQL����
	~CDatabase();	// ��������
	void Close();			// �ر����ݿ�����
	bool Open(char* host, char* user, char* pass, char* db);// �����ݿ�
	bool Execute(char* sql);		//ѡ���¼
	int GetFieldNum();			//��ȡ�ֶθ���
	MYSQL_ROW GetRecord();		//��ȡ��¼��
	void GetRecords();			// ��ȡ��¼��
	unsigned long * GetRecordFieldLength();// ��ȡ��¼���ֶ�ֵ�ĳ���
	bool ShowRecords(char* sql);	// ��ʾ��ѯ�����

private:
	MYSQL mysql;		//���ݿ����Ӿ��
	MYSQL_RES *query;	//�����
	MYSQL_ROW row;		//��¼��
	MYSQL_FIELD *field; //�ֶ���Ϣ
};
