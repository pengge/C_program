// FileSample.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <process.h>

FILE *stream, *stream1, *stream2;

void main()
{
	int numclosed;

	char list[30];				// ��Ŵ��ļ��ж�ȡ������
	int  i, numread, numwritten;	// ��ȡ����Ŀ��д�����Ŀ

	// ���ļ�data���ж�������ļ������ڣ���ʧ��
	if( (stream1  = fopen( "data", "r" )) == NULL )
		printf( "���ļ�'data'���ж�ʧ��\n" );
	else
		printf( "���ļ�'data'���ж�\n" );

	// ���ļ�data2����д
	if( (stream2 = fopen( "data2", "w+" )) == NULL )
		printf( "���ļ�'data2'����дʧ��\n" );
	else
		printf( "���ļ�'data2'����д\n" );

	// ʹ���ı�ģʽ���ļ������ļ�����д����
	if( (stream = fopen( "fread.out", "w+t" )) != NULL )
	{
		// ���ļ�����д��25���ַ�
		for ( i = 0; i < 25; i++ )
			list[i] = (char)('z' - i);

		numwritten = fwrite( list, sizeof( char ), 25, stream );
		printf( "д�� %d ���ַ�\n", numwritten );
		fclose( stream );
	}
	else
		printf( "���ļ�fread.outʱ�����������޷�д���ݵ��ļ���\n" );

	if( (stream = fopen( "fread.out", "r+t" )) != NULL )
	{	
		// ���ļ��ж�ȡ25���ַ�      
		numread = fread( list, sizeof( char ), 25, stream );
		printf( "��ȡ�����ݸ��� = %d\n", numread );
		printf( "��ȡ������Ϊ = %.25s\n", list );
		fclose( stream );
	}
	else
		printf( "���ļ�fread.outʱ�����������޷����ļ��ж�ȡ����\n" );

	// �ر��ļ�
	if( fclose( stream2 ) )
		printf( "�ر��ļ�'data2'ʧ��\n" );

	// �ر������򿪵��ļ�
	numclosed = _fcloseall( );
	printf( "ʹ�ú���_fcloseall�رյ��ļ���ĿΪ : %u\n", numclosed );
	system("pause");
}
