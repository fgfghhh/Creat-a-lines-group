#pragma once
#include"point.h"
#include<vector>
#include"LineBase.h"


class Line :public LineBase
{
public:
	//默认构造函数
	Line();

	//构造函数，用初始化直线的两个端.pt1赋值给起点，pt2赋值给终点
	Line(Point pt1, Point pt2);

	//获取起点坐标
	Point GetPtf();
	
	//获取终点坐标
	Point GetPts();
	
	//计算并返回线的长度
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
	Line* NewLine(Point Dis);

	//线点的自我反向
	virtual void ReverseLine();

	//线自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
	//参数pt表示线段绕点pt旋转
	virtual void RotationLine(double degree, const Point &pt);

	//将线某端点延伸一段距离
	//参数p为布尔值，如果p为true，延长点为起点；反之为终点；
	//参数a为延长距离
	virtual void Extent(bool p, double a);

	//线段延伸生成新线;
	//参数p用来判定延长点为哪个,true表示直线的起点，false表示直线的终点
	//参数a表示延长距离
	//返回值为新线
	Line NewExtent(bool p, double a);

	//判断线是否相交，参数线段l为另一条线
	//返回值为bool，如果为false，表示不相，为true表示相交
	bool IsOverlap(Line l);

	//线段求交点，并返回交点坐标。
	//参数是另一条直线，和点pt
	//如果存在交点，pt记录交点的坐标；如果不存在交点，则返回false
	//Point LinePoint(Line l1);
	bool LinePoint(Line l, Point& pt);

	//打印线的信息
	virtual void PrintLine();

	//析构函数
	virtual ~Line();

private:
	Point m_ptf;//直线起点
	Point m_pts;//直线终点
};
