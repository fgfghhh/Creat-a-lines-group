#pragma once
#include<iostream>
using namespace std;
const double EPSINON = 0.00001;
#define PI  3.141592654
#include<algorithm>

class Point
{
public:
	Point();//默认构造函数
	
	Point(double x, double y);//拷贝构造函数，初始化点的x、y坐标
	
	~Point();//析构函数
	
	void operator=(Point &pt);//赋值操作符重载

	bool operator==(Point &pt);//==重载
	
	void PrintPoint();//输出点
	
	void SetPointx(double x);//设置点的x坐标
	void SetPointy(double y);//设置点的y坐标

	double GetPointx();//获取点的x轴坐标
	double GetPointy();//获取点的y轴坐标
	

	//求点关于某条直线对称后点的坐标
	//传入的参数是一条直线l，表示点相对直线l镜像
	//返回值是点镜像后新的点
	//Point NewMirrorPoint(Line l);

	//计算点绕p2旋转后的新坐标，参数1为旋转的弧度degree，参数2为绕的点
	//返回值为旋转后的坐标
	Point RotationPoint(double degree, Point p2);

	// 判断两个点坐标相同
	int double_equal_p(double a, double b);

	//“-”运算符重载
	//void operator-(Point p);

public                                                                                                                                                                                                                               :
	double m_x, m_y;//点的两个坐标值
};