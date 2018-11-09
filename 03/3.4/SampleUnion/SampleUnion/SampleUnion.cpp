#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <LIMITS.H>

enum NumType					// 声明一个枚举类型来描述要输出的类型
{ 
	INTEGER_INT, 				// 整型类型
	INTEGER_LONG, 				// 长整型类型
	INTEGER_DOUBLE 				// DOUBLE类型
};
union NumValue        			// 声明一个包含下面三种类型的共用体
{
	int         iValue;  		// int类型值
	long        lValue;  		// long类型值
	double      dValue;  		// double类型值
};

int main( int argc, char *argv[] )
{
	char aaa[101] = "16549897.321";
	*argv = aaa;
	int count = argc - 1;						// 计算输入的参数个数
	NumValue *Values = new NumValue[count];		// 存放值的共用体
	NumType *Types = new NumType[count];		// 存放类型的数组
	for( int i = 1; i < argc; ++i )				// 循环处理每个参数
	{
		if( strchr( argv[i], '.' ) != 0 )		// 判断输入参数中是否包含小数点
		{
			Values[i].dValue = atof( argv[i] ); // 为dValue成员赋值,并记录类型。
			Types[i] = INTEGER_DOUBLE;			// 记录数组的成员的类型为DOUBLE型
		}
		else   									// 不是Floating类型
		{
			if (( atol( argv[i] ) >  INT_MAX ) || (atol( argv[i] ) <  0))
			{
				// 如果数据大于int类型的最大值，则将其存储在lValue成员中,并记录类型
				Values[i].lValue = atol( argv[i] );		// 将值转换成长整型
				Types[i] = INTEGER_LONG;				// 记录数组的成员的类型为长整型
			}
			else
			{	
				// 否则，将其存储在iValue成员中,并记录类型
				Values[i].iValue = atoi( argv[i] );		// 将值转换成整型
				Types[i] = INTEGER_INT;					// 记录数组的成员的类型为整型
			}
		}
		switch( Types[i] )					// 根据类型种类，将种类信息和值信息输出
		{
		case INTEGER_INT:					// 如果数据为整型，输出整型值
			printf( "数据类型为Integer，值为%d\n", Values[i].iValue );
			break;
		case INTEGER_LONG:					// 如果数据为长整型，输出长整型值
			printf( "数据类型为Long，值为%d\n", Values[i].lValue );
			break;
		case INTEGER_DOUBLE:				// 如果数据为double型，输出double值
			printf( "数据类型为Double，值为%f\n", Values[i].dValue );
			break;
		}
	}
	system("pause");
	return 0;
}