#include<iostream>
using namespace std;
#include"Point.h"

Point::Point()//默认构造函数
{
	m_x = 0;
	m_y = 0;
}

Point::Point(double x, double y)//拷贝构造函数，初始化点的x、y坐标
{
	this->m_x = x;
	this->m_y = y;
}

void Point::operator=(Point &pt)//赋值操作符重载
{
	this->m_x = pt.m_x;
	this->m_y = pt.m_y;
}

void Point::SetPointx(double x)//设置点的x坐标
{
	m_x = x;
}

void Point::SetPointy(double y)//设置点的y坐标
{
	m_y = y;
}

double Point::GetPointx()//获取点的x轴坐标
{
	return m_x;
}

double Point::GetPointy()//获取点的y轴坐标
{
	return m_y;
}

bool Point::operator==(Point &pt)//==重载
{
	if (this->m_x == pt.m_x &&this->m_y == pt.m_y)
	{
		return true;
	}
	return false;
}

void Point::PrintPoint()////输出点
{
	cout << "(" << m_x << "," << m_y << ")" << endl;
}

//计算点绕某点旋转后的坐标
//参数pt表示被绕的点；degree表示旋转的弧度，逆时针为正，反正为负
Point Point::RotationPoint(double degree, Point pt)
{
	double x0 = pt.m_x;
	double y0 = pt.m_y;
	Point newPoint;
	double x1 = this->m_x;
	double y1 = this->m_y;

	if (degree < 0)//顺时针
	{
		newPoint.m_x = (x1 - x0) * cos(degree) - (y1 - y0) * sin(degree) + x0;
		if (newPoint.m_x >= -EPSINON && this->m_x <= EPSINON)
		{
			newPoint.m_x = 0;
		}
		newPoint.m_y = (x1 - x0) * sin(degree) + (y1 - y0) * cos(degree) + y0;
		if (newPoint.m_y >= -EPSINON && newPoint.m_y <= EPSINON)
		{
			newPoint.m_y = 0;
		}
	}
	else if (degree > 0)//逆时针旋转
	{
		newPoint.m_x = (x1 - x0)*cos(degree) - (y1 - y0)*sin(degree) + x0;
		if (newPoint.m_x >= -EPSINON && newPoint.m_x <= EPSINON)
		{
			newPoint.m_x = 0;
		}
		newPoint.m_y = (x1 - x0)*sin(degree) + (y1 - y0)*cos(degree) + y0;
		if (newPoint.m_y >= -EPSINON && newPoint.m_y <= EPSINON)
		{
			newPoint.m_y = 0;
		}
	}
	return newPoint;
}

// 浮点数判同
int Point::double_equal_p(double a, double b)
{
	static const double ZERO = 1e-9;
	return fabs(a - b) < ZERO;
}

Point::~Point()
{

}
