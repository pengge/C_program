// FileSample.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <process.h>

FILE *stream, *stream1, *stream2;

void main()
{
	int numclosed;

	char list[30];				// 存放从文件中读取的数据
	int  i, numread, numwritten;	// 读取的数目，写入的数目

	// 打开文件data进行读，如果文件不存在，则失败
	if( (stream1  = fopen( "data", "r" )) == NULL )
		printf( "打开文件'data'进行读失败\n" );
	else
		printf( "打开文件'data'进行读\n" );

	// 打开文件data2进行写
	if( (stream2 = fopen( "data2", "w+" )) == NULL )
		printf( "打开文件'data2'进行写失败\n" );
	else
		printf( "打开文件'data2'进行写\n" );

	// 使用文本模式打开文件，对文件进行写操作
	if( (stream = fopen( "fread.out", "w+t" )) != NULL )
	{
		// 向文件流中写入25个字符
		for ( i = 0; i < 25; i++ )
			list[i] = (char)('z' - i);

		numwritten = fwrite( list, sizeof( char ), 25, stream );
		printf( "写入 %d 个字符\n", numwritten );
		fclose( stream );
	}
	else
		printf( "打开文件fread.out时，发生错误，无法写数据到文件中\n" );

	if( (stream = fopen( "fread.out", "r+t" )) != NULL )
	{	
		// 从文件中读取25个字符      
		numread = fread( list, sizeof( char ), 25, stream );
		printf( "读取的数据个数 = %d\n", numread );
		printf( "读取的内容为 = %.25s\n", list );
		fclose( stream );
	}
	else
		printf( "打开文件fread.out时，发生错误，无法从文件中读取数据\n" );

	// 关闭文件
	if( fclose( stream2 ) )
		printf( "关闭文件'data2'失败\n" );

	// 关闭其他打开的文件
	numclosed = _fcloseall( );
	printf( "使用函数_fcloseall关闭的文件数目为 : %u\n", numclosed );
	system("pause");
}
