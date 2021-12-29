#include<iostream>
using namespace std;
#include"Point.h"

Point::Point()//Ĭ�Ϲ��캯��
{
	m_x = 0;
	m_y = 0;
}

Point::Point(double x, double y)//�������캯������ʼ�����x��y����
{
	this->m_x = x;
	this->m_y = y;
}

void Point::operator=(Point &pt)//��ֵ����������
{
	this->m_x = pt.m_x;
	this->m_y = pt.m_y;
}

void Point::SetPointx(double x)//���õ��x����
{
	m_x = x;
}

void Point::SetPointy(double y)//���õ��y����
{
	m_y = y;
}

double Point::GetPointx()//��ȡ���x������
{
	return m_x;
}

double Point::GetPointy()//��ȡ���y������
{
	return m_y;
}

bool Point::operator==(Point &pt)//==����
{
	if (this->m_x == pt.m_x &&this->m_y == pt.m_y)
	{
		return true;
	}
	return false;
}

void Point::PrintPoint()////�����
{
	cout << "(" << m_x << "," << m_y << ")" << endl;
}

//�������ĳ����ת�������
//����pt��ʾ���Ƶĵ㣻degree��ʾ��ת�Ļ��ȣ���ʱ��Ϊ��������Ϊ��
Point Point::RotationPoint(double degree, Point pt)
{
	double x0 = pt.m_x;
	double y0 = pt.m_y;
	Point newPoint;
	double x1 = this->m_x;
	double y1 = this->m_y;

	if (degree < 0)//˳ʱ��
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
	else if (degree > 0)//��ʱ����ת
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

// ��������ͬ
int Point::double_equal_p(double a, double b)
{
	static const double ZERO = 1e-9;
	return fabs(a - b) < ZERO;
}

Point::~Point()
{

}
