// Rect.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class Shape							// ���������״��
{
public:
    Shape();						// ��������Ĺ��캯��
    ~Shape();						// �����������������
};
Shape::Shape()						// �������Ĺ��캯��
{
    cout << "���ǻ���Shape�Ĺ��캯��" << endl;
}
Shape::~Shape()						// ����������������
{
    cout << "���ǻ���Shape����������" << endl;
}
class Rectangle : public Shape		// Rectangle��Shape����
{
public:
    Rectangle ();					// ����������Ĺ��캯��
    ~Rectangle();					// �������������������
};
Rectangle::Rectangle()				// ����������Ĺ��캯��
{
    cout << "����������Rectangle�Ĺ��캯��" << endl;
}
Rectangle::~Rectangle()				// �������������������
{
    cout << "����������Rectangle����������" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Rectangle rect;
    return 0;
}

