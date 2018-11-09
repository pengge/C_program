// Rect.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class Shape							// 定义基类形状类
{
public:
    Shape();						// 声明基类的构造函数
    ~Shape();						// 声明基类的析构函数
};
Shape::Shape()						// 定义基类的构造函数
{
    cout << "这是基类Shape的构造函数" << endl;
}
Shape::~Shape()						// 定义基类的析构函数
{
    cout << "这是基类Shape的析构函数" << endl;
}
class Rectangle : public Shape		// Rectangle从Shape派生
{
public:
    Rectangle ();					// 声明派生类的构造函数
    ~Rectangle();					// 声明派生类的析构函数
};
Rectangle::Rectangle()				// 定义派生类的构造函数
{
    cout << "这是派生类Rectangle的构造函数" << endl;
}
Rectangle::~Rectangle()				// 定义派生类的析构函数
{
    cout << "这是派生类Rectangle的析构函数" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Rectangle rect;
    return 0;
}

