#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <LIMITS.H>

enum NumType					// ����һ��ö������������Ҫ���������
{ 
	INTEGER_INT, 				// ��������
	INTEGER_LONG, 				// ����������
	INTEGER_DOUBLE 				// DOUBLE����
};
union NumValue        			// ����һ�����������������͵Ĺ�����
{
	int         iValue;  		// int����ֵ
	long        lValue;  		// long����ֵ
	double      dValue;  		// double����ֵ
};

int main( int argc, char *argv[] )
{
	char aaa[101] = "16549897.321";
	*argv = aaa;
	int count = argc - 1;						// ��������Ĳ�������
	NumValue *Values = new NumValue[count];		// ���ֵ�Ĺ�����
	NumType *Types = new NumType[count];		// ������͵�����
	for( int i = 1; i < argc; ++i )				// ѭ������ÿ������
	{
		if( strchr( argv[i], '.' ) != 0 )		// �ж�����������Ƿ����С����
		{
			Values[i].dValue = atof( argv[i] ); // ΪdValue��Ա��ֵ,����¼���͡�
			Types[i] = INTEGER_DOUBLE;			// ��¼����ĳ�Ա������ΪDOUBLE��
		}
		else   									// ����Floating����
		{
			if (( atol( argv[i] ) >  INT_MAX ) || (atol( argv[i] ) <  0))
			{
				// ������ݴ���int���͵����ֵ������洢��lValue��Ա��,����¼����
				Values[i].lValue = atol( argv[i] );		// ��ֵת���ɳ�����
				Types[i] = INTEGER_LONG;				// ��¼����ĳ�Ա������Ϊ������
			}
			else
			{	
				// ���򣬽���洢��iValue��Ա��,����¼����
				Values[i].iValue = atoi( argv[i] );		// ��ֵת��������
				Types[i] = INTEGER_INT;					// ��¼����ĳ�Ա������Ϊ����
			}
		}
		switch( Types[i] )					// �����������࣬��������Ϣ��ֵ��Ϣ���
		{
		case INTEGER_INT:					// �������Ϊ���ͣ��������ֵ
			printf( "��������ΪInteger��ֵΪ%d\n", Values[i].iValue );
			break;
		case INTEGER_LONG:					// �������Ϊ�����ͣ����������ֵ
			printf( "��������ΪLong��ֵΪ%d\n", Values[i].lValue );
			break;
		case INTEGER_DOUBLE:				// �������Ϊdouble�ͣ����doubleֵ
			printf( "��������ΪDouble��ֵΪ%f\n", Values[i].dValue );
			break;
		}
	}
	system("pause");
	return 0;
}