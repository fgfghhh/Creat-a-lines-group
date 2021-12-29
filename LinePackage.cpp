#include<iostream>
using namespace std;
#include"LinePackage.h"
#include <cmath>
#define _USE_MATH_DEFINES

/*计算线某比例处的点坐标，比例值是从起点开始计算
参数a表示比例，在[0—1]范围内
返回值为此比例处点的坐标*/
Point Package:: proportionPt(double a)
{
	Point p(0.000, 0.000);
	cout << "在比例a处各线条的坐标为：" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->proportionPt(a).PrintPoint();
		//return v[i]->proportionPt(a);
	}
	return p;
}

//计算并返回直线的长度
double Package::Length()const
{
	double len = 0;
	cout << "每段线条的长度:" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]->Length() << endl;
		len += v[i]->Length();
	}
	cout << "线条总长度:" << endl;
	cout << len << endl;
	return len;
}

/*判断点是否在线上,参数pt表示要确定的点
返回值为index，当值为-1时，表示点不在线上，当值为1时，表示点在线上*/
int Package::IsInLine(const Point &pt)
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		
		cout << (*it)->IsInLine(pt) << " ";
		//return (*it)->IsInLine(pt);
	}
	cout << endl;
	return 0;
}

/*线自我平移，参数传入一个点Dis（x,y)，表示平移的方向和距离。
	数值为正时表示向上（向右）平移，为负时相反*/
void Package::Translation(const Point &Dis)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "平移前线的信息：" << endl;
		v[i]->PrintLine();
		cout << endl;
		cout << "平移后线的信息：" << endl;
		v[i]->Translation(Dis);
		v[i]->PrintLine();
		cout << endl;
	}
}

//线点的自我反向
void Package::ReverseLine()
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "反向前线的信息：" << endl;
		(*it)->PrintLine();
		cout << endl;
		(*it)->ReverseLine();
		cout << "反向后线的信息：" << endl;
		(*it)->PrintLine();
		cout << endl;
	}
}

//线自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
//参数pt表示线段绕点pt旋转
void Package::RotationLine(double degree, const Point &pt)
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "旋转前线的信息：" << endl;
		(*it)->PrintLine();
		cout << endl;
		(*it)->RotationLine(degree, pt);
		cout << "旋转后线的信息：" << endl;
		(*it)->PrintLine();
		cout << endl;
	}
}

//将圆弧某端点延伸一段距离
	//参数p为布尔值，如果p为true，延长点为起点；反之为终点；
	//参数a为延长距离
void Package::Extent(bool p, double a) 
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "延长前线的信息：" << endl;
		(*it)->PrintLine();
		cout << endl;
		(*it)->Extent(p,a);
		cout << "延长后线的信息：" << endl;
		(*it)->PrintLine();
		cout << endl;
	}
}

//打印线的信息
void Package::PrintLine()
{

}


Package:: ~Package()
{

}
