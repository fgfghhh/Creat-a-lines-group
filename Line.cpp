#include"Line.h"

Line::Line()//默认构造函数
{

}

//构造函数，用初始化直线的两个端点，pt1赋值给起点，pt2赋值给终点
Line::Line(Point pt1, Point pt2)
{
	m_ptf = pt1;
	m_pts = pt2;
}

//计算并返回直线的长度，返回值为直线的长度
double Line::Length()const
{
	double a = (m_pts.m_x - m_ptf.m_x);
	double b = (m_pts.m_y - m_ptf.m_y);
	return sqrt(a*a + b * b);
}

//计算直线某比例处的点坐标，比例值是从起点开始计算
//参数a表示比例，在（0—1）范围内
Point Line::proportionPt(double a)
{
	vector<Point> v;
	if (a == 0)
	{
		return (this->m_ptf);
	}
	else if (a == 1)
	{
		return (this->m_ptf);
	}
	else
	{
		double len = this->Length();//直线长度
		double x1 = len * a;
		double k = x1 / len;//比率

		Point fs;//表示直线起点和端点构成的向量
		fs.m_x = (m_pts.m_x - m_ptf.m_x);
		fs.m_y = (m_pts.m_y - m_ptf.m_y);

		Point fp;//表示直线起点和比例处点构成的向量
		fp.m_x = (k * fs.m_x);
		fp.m_y = (k * fs.m_y);

		Point of = m_ptf;//表示原点和起点构成的向量
		Point op;//表示原点和比例处p点构成的向量,即比例处点的坐标
		op.m_x = (of.m_x + fp.m_x);
		op.m_y = (of.m_y + fp.m_y);
		return op;
	}
}

/*判断点是否在线段L上,参数pt表示要确定的点
返回值为index，当值为-1时，表示点不在线上，当值为1时，表示点在线上*/
int Line::IsInLine(const Point &pt)
{
	int index = -1;
	if ((pt.m_x - this->m_ptf.m_x) * (this->m_pts.m_y - this->m_ptf.m_y) == (this->m_pts.m_x - this->m_ptf.m_x) * (pt.m_y - this->m_ptf.m_y)  //叉乘 
		//保证Q点坐标在pi,pj之间 
		&& min(this->m_ptf.m_x, this->m_pts.m_x) <= pt.m_x && pt.m_x <= max(this->m_ptf.m_x, this->m_pts.m_x)
		&& min(this->m_ptf.m_y, this->m_pts.m_y) <= pt.m_y && pt.m_y <= max(this->m_ptf.m_y, this->m_pts.m_y))
	{
		index = 1;
		//cout << "点在线段上" << endl;
		return index;
	}
	else
	{
		index = -1;
		//cout << "点不在线段上" << endl;
		return index;
	}
}


/*线段自我平移，参数传入一个点Dis（x,y)，表示平移的方向和距离。
数值为正时表示向上（向右）平移，为负时相反*/
void Line::Translation(const Point &Dis)
{
	this->m_ptf.m_x += Dis.m_x;
	this->m_ptf.m_y += Dis.m_y;
	this->m_pts.m_x += Dis.m_x;
	this->m_pts.m_y += Dis.m_y;
}

/*线段平移后生成一条新线，参数传入一个点Dis（x,y)，表示平移的方向和距离。
数值为正时表示向上（向右）平移，为负时相反
返回值是新生成的线*/
Line* Line::NewLine(Point Dis)
{
	if (Dis.m_x, Dis.m_y >= -EPSINON && Dis.m_x, Dis.m_y <= EPSINON)
	{
		return NULL;
	}
	Line* L = new Line;
	L->m_ptf.m_x = this->m_ptf.m_x + Dis.m_x;
	L->m_ptf.m_y = this->m_ptf.m_x + Dis.m_x;
	L->m_pts.m_x = this->m_pts.m_x + Dis.m_x;
	L->m_pts.m_y = this->m_pts.m_x + Dis.m_x;
	return L;
}

void Line::ReverseLine()//线段自我反向
{
	Point temp(0, 0);
	temp = this->m_ptf;
	this->m_ptf = this->m_pts;
	this->m_pts = temp;
}

//线段自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
//参数pt表示线段绕点pt旋转
void Line::RotationLine(double degree, const Point &pt)
{
	Point pf = this->m_ptf.RotationPoint(degree, pt);
	Point ps = this->m_pts.RotationPoint(degree, pt);
	this->m_ptf = pf;
	this->m_pts = ps;	
}

//线段自我延伸,参数a为延长长度,参数p判定延长点为那个，true表示起点，false表示终点
void Line::Extent(bool p, double a)
{
	double len = 0;
	len = this->Length();

	if (p == true)//待延长的点为起点
	{
		if (this->m_ptf.m_x < this->m_pts.m_x)//起点在终点的左边，延长方向为左
		{
			double L = this->Length() + a;
			double k = L / this->Length();
		
			double x0 = this->m_ptf.m_x - this->m_pts.m_x;
			double y0 = this->m_ptf.m_y - this->m_pts.m_y;
			Point sf(x0, y0);//向量m_pts-m_ptf
			Point sc(k*x0, k*y0);//延长向量
			//延长后两端点的新坐标
			this->m_ptf.m_x = this->m_pts.m_x + sc.m_x;
			this->m_ptf.m_y = this->m_pts.m_y + sc.m_y;
		    this->m_pts.m_x = this->m_pts.m_x;
			this->m_pts.m_y = this->m_pts.m_y;
		}
	}
	else if (p == false)//待延长的点为终点
	{
		double L = this->Length() + a;
		double k = L / this->Length();

		double x0 = this->m_pts.m_x - this->m_ptf.m_x;
		double y0 = this->m_pts.m_y - this->m_ptf.m_y;
		Point fs(x0, y0);//向量m_ptf-m_pts
		Point fc(k*x0, k*y0);//延长后的向量
		//延长后两端点的新坐标
		this->m_pts.m_x = this->m_ptf.m_x + fc.m_x;
		this->m_pts.m_y = this->m_ptf.m_y + fc.m_y;
		this->m_pts.m_x = this->m_pts.m_x;
		this->m_pts.m_y = this->m_pts.m_y;
	}
}

//线段延伸生成新线;
//参数p用来判定延长点为哪个,true表示直线的起点，false表示直线的终点
//参数a表示延长距离
//返回值为新线
Line Line::NewExtent(bool p, double a)
{
	Line NewLine;
	double len = 0;
	len = this->Length();

	if (p == true)//待延长的点为起点
	{
		if (this->m_ptf.m_x < this->m_pts.m_x)//起点在终点的左边，延长方向为左
		{
			double L = this->Length() + a;
			double k = L / this->Length();

			double x0 = this->m_ptf.m_x - this->m_pts.m_x;
			double y0 = this->m_ptf.m_y - this->m_pts.m_y;
			Point sf(x0, y0);//向量m_pts-m_ptf
			Point sc(k*x0, k*y0);//延长向量
			//延长后两端点的新坐标
			NewLine.m_ptf.m_x = this->m_pts.m_x + sc.m_x;
			NewLine.m_ptf.m_y = this->m_pts.m_y + sc.m_y;
			NewLine.m_pts.m_x = this->m_pts.m_x;
			NewLine.m_pts.m_y = this->m_pts.m_y;
		}
	}
	else if (p == false)//待延长的点为终点
	{
		double L = this->Length() + a;
		double k = L / this->Length();

		double x0 = this->m_pts.m_x - this->m_ptf.m_x;
		double y0 = this->m_pts.m_y - this->m_ptf.m_y;
		Point fs(x0, y0);//向量m_ptf-m_pts
		Point fc(k*x0, k*y0);//延长后的向量
		//延长后两端点的新坐标
		NewLine.m_pts.m_x = this->m_ptf.m_x + fc.m_x;
		NewLine.m_pts.m_y = this->m_ptf.m_y + fc.m_y;
		NewLine.m_ptf.m_x = this->m_pts.m_x;
		NewLine.m_ptf.m_y = this->m_pts.m_y;
	}
	return NewLine;
}

//判断线是否相交，参数线段l为另一条线
//返回值为bool，如果为false，表示不相，为true表示相交
bool Line::IsOverlap(Line l)
{
	double a1 = this->m_pts.m_y - this->m_ptf.m_y;
	double b1 = this->m_ptf.m_x - this->m_pts.m_x;
	double c1 = this->m_ptf.m_x*this->m_pts.m_y - this->m_pts.m_x*this->m_ptf.m_y;
	double a2 = l.m_pts.m_y - l.m_ptf.m_y;
	double b2 = l.m_ptf.m_x - l.m_pts.m_x;
	double c2 = l.m_ptf.m_x*l.m_pts.m_y - l.m_pts.m_x*l.m_ptf.m_y;

	//两线段的向量积，为零表示平行，不为零表示不平行
	double det = a1 * b2 - a2 * b1;
	//cout << det << endl;
	if (det >= -EPSINON && det <= EPSINON)//线段平行
	{
		int ret1 = this->IsInLine(l.m_ptf);
		int ret2 = this->IsInLine(l.m_pts);
		if (ret1 == 1 || ret2 == 1) //线段重合
		{
			//cout << "重合" << endl;
			return true;
		}
		else //没有重合
		{
			return false;
		}
	}
	else //对应直线相交
	{
		Point pt;
		pt.m_x = (c1*b2 - c2 * b1) / det;
		pt.m_y = (a1*c2 - a2 * c1) / det;
		//pt.PrintPoint();

		int index = this->IsInLine(pt);
		int ret = l.IsInLine(pt);
		//pt.PrintPoint();
		//判断交点在不在两条线上，同时在表示线段有交点，任意不在表示无交点
		//this->PrintLine();
		//int ret1 = this->IsInLine(pt);
		//cout << ret1 << endl;
		//l.PrintLine();
		//int ab = l.IsInLine(pt);

		//pt.PrintPoint();
		//cout << ab << endl;
		if (ret == 1 && index == 1)//有交点
		{
			return true;
		}
		else//无交点
		{
			return false;
		}
	}
}

//打印线的信息
void Line::PrintLine()
 {
	cout << "第一个点:";
	m_ptf.PrintPoint();
	cout << endl;
	cout << "第二个点:";
	m_pts.PrintPoint();
	cout << endl;
	cout << "直线的长度是:" << Length() << endl;
 }

//获取起点坐标
Point Line::GetPtf()
{
	return this->m_ptf;
}

//获取终点坐标
Point Line::GetPts()
{
	return this->m_pts;
}

bool Line::LinePoint(Line l, Point& pt)
{
	bool ret = this->IsOverlap(l);
	if (ret == false)
	{

		cout << "两条线段没有交点" << endl;
		return false;
	}
	else
	{
		cout << "两直线存在交点" << endl;

		double a1 = this->m_pts.m_y - this->m_ptf.m_y;
		double b1 = this->m_ptf.m_x - this->m_pts.m_x;
		double c1 = this->m_ptf.m_x*this->m_pts.m_y - this->m_pts.m_x*this->m_ptf.m_y;
		double a2 = l.m_pts.m_y - l.m_ptf.m_y;
		double b2 = l.m_ptf.m_x - l.m_pts.m_x;
		double c2 = l.m_ptf.m_x*l.m_pts.m_y - l.m_pts.m_x*l.m_ptf.m_y;
		double det = a1 * b2 - a2 * b1;
		
		pt.m_x = (c1*b2 - c2 * b1) / det;
		pt.m_y = (a1*c2 - a2 * c1) / det;
		return true;
	}
}

Line::~Line()
{

}

