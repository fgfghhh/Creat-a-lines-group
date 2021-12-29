#pragma once
#include<iostream>
#include"Point.h"
using namespace std;
#include"Line.h"
#include<cmath>
#include<vector>
#include<algorithm>

class Arc :public LineBase
{
public:
	Arc();

	//构造函数，初始化圆弧的参数，a赋值给起点与x轴正方向夹角，
	//b赋值给起点到终点扫过的角度，r赋值给圆的半径
	Arc(Point pt1, double a, double b, double r);

	//获取圆心
	Point GetCen();

	//获取起点夹角
	double GetStarAngle();

	//获取扫过的角
	double GetSwAngle();

	//获取半径
	double GetR();

	//计算圆弧起点并返回起点坐标
	Point Gain_Star();

	//计算圆弧终点并返回终点坐标
	Point Gain_Fin();

	// 判断两个点坐标相同
	int double_equal_c(double a, double b);

	//计算并返回圆弧的长度
	virtual double Length()const;

	/*计算线某比例处的点坐标，比例值是从起点开始计算
	参数a表示比例，在[0—1]范围内
	返回值为此比例处点的坐标*/
	virtual Point proportionPt(double a);

	/*判断点是否在线上,参数pt表示要确定的点
	返回值为index，当值为-1时，表示点不在线上，当值为1时，表示点在线上*/
	virtual int IsInLine(const Point &pt);

	/*线自我平移，参数传入一个点Dis（x,y)，表示平移的方向和距离。
	数值为正时表示向上（向右）平移，为负时相反*/
	virtual void Translation(const Point &Dis);

	/*线平移后生成一条新线，参数传入一个点Dis（x,y)，表示平移的方向和距离。
	数值为正时表示向上（向右）平移，为负时相反
	返回值是新生成的线*/
	Arc* NewLine(const Point &Dis);

	//线点的自我反向
	virtual void ReverseLine();

	//线自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
	//参数pt表示线段绕点pt旋转
	virtual void RotationLine(double degree, const Point &pt);

	//将线某端点延伸一段距离
	//参数p为布尔值，如果p为true，延长点为起点；反之为终点；
	//参数a为延长距离
	//返回值为延伸后的圆弧指针
	virtual void Extent(bool p, double a);

	//计算两个圆弧的交点，参数为另一条圆弧；
	//返回值为两个坐标，如果不存在交点，返回空值；
	//如果存在一个交点，返回一个交点坐标；
	//如果存在两个交点，返回两个交点的坐标值
	vector<Point> ArcPoint(Arc c1);

	virtual ~Arc();

	//打印线的信息
	virtual void PrintLine();

private:
	Point m_center;//圆弧的圆心
	double m_Stangle;//圆弧起始点与x轴正方向的夹角(逆时针为正）
	double m_Swangle;//圆弧起点到终点扫过的角度(逆时针为正）
	double m_R;//圆弧半径R
};
