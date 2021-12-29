#pragma once
#include"point.h"
#include<vector>

class LineBase
{
public:

	/*计算线某比例处的点坐标，比例值是从起点开始计算
	参数a表示比例，在[0—1]范围内
	返回值为此比例处点的坐标*/
	virtual Point proportionPt(double a) = 0;

	//计算并返回直线的长度
	virtual double Length()const = 0;

	/*判断点是否在线上,参数pt表示要确定的点
	返回值为index，当值为-1时，表示点不在线上，当值为1时，表示点在线上*/
	virtual int IsInLine( const Point &pt) = 0;

	/*线自我平移，参数传入一个点Dis（x,y)，表示平移的方向和距离。
	数值为正时表示向上（向右）平移，为负时相反*/
	virtual void Translation(const Point &Dis) = 0;

	//线点的自我反向
	virtual void ReverseLine() = 0;

	//线自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
	//参数pt表示线段绕点pt旋转
	virtual void RotationLine(double degree, const Point &pt) = 0;

	//将圆弧某端点延伸一段距离
	//参数p为布尔值，如果p为true，延长点为起点；反之为终点；
	//参数a为延长距离
	virtual void Extent(bool p, double a) = 0;

	//打印线的信息
	virtual void PrintLine() = 0;

	virtual ~LineBase() {};
};
//LineBase::~LineBase() {};