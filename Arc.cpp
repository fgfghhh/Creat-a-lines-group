#include"Arc.h"

Arc::Arc()
{

}

//构造函数，初始化圆弧的参数，点pt1赋值给圆心；
//a赋值给起点与x轴正方向夹角，b赋值给起点到终点扫过的角度，r赋值给圆的半径
Arc::Arc(Point pt1, double a, double b, double r)
{
	m_center = pt1;
	m_Stangle = a;
	m_Swangle = b;
	m_R = r;
}

//获取圆心
Point Arc::GetCen()
{
	return this->m_center;
}

//获取起点夹角
double Arc::GetStarAngle()
{
	return this->m_Stangle;
}

//获取扫过的角
double Arc::GetSwAngle()
{
	return this->m_Swangle;
}

//获取半径
double Arc::GetR()
{
	return this->m_R;
}

//计算圆弧起点并返回起点坐标
Point Arc::Gain_Star()
{
	Point Star;
	if (this->m_Stangle >= 0 && this->m_Stangle <= 2 * PI)
	{
		Star.m_x = this->m_R * cos(this->m_Stangle) + this->m_center.m_x;
		if (Star.m_x >= -EPSINON && Star.m_x <= EPSINON)
		{
			Star.m_x = 0;
		}
		Star.m_y = this->m_R * sin(this->m_Stangle) + this->m_center.m_y;
		if (Star.m_y >= -EPSINON && Star.m_y <= EPSINON)
		{
			Star.m_y = 0;
		}
	}
	else if (this->m_Stangle >= -2 * PI && this->m_Stangle <= 0)
	{
		Star.m_y = this->m_R * sin(this->m_Stangle) + this->m_center.m_y;
		if (Star.m_y >= -EPSINON && Star.m_y <= EPSINON)
		{
			Star.m_y = 0;
		}
		Star.m_x = this->m_R * cos(this->m_Stangle) + this->m_center.m_x;
		if (Star.m_x >= -EPSINON && Star.m_x <= EPSINON)
		{
			Star.m_x = 0;
		}
	}
	return Star;
}

//计算圆弧终点并返回终点坐标
Point Arc::Gain_Fin()
{
	Point Fin;
	Fin.m_x = this->m_R * cos(this->m_Stangle + this->m_Swangle) + this->m_center.m_x;
	if (Fin.m_x >= -EPSINON && Fin.m_x <= EPSINON)
	{
		Fin.m_x = 0;
	}
	Fin.m_y = this->m_R * sin(this->m_Stangle + this->m_Swangle) + this->m_center.m_y;
	if (Fin.m_y >= -EPSINON && Fin.m_y <= EPSINON)
	{
		Fin.m_y = 0;
	}
	return Fin;
}

// 判断两个点坐标相同
int Arc::double_equal_c(double a, double b)
{
	static const double ZERO = 0.5;
	return fabs(a - b) < ZERO;
}


//计算并返回圆弧的长度
double Arc::Length()const
{
	return abs(m_Swangle * m_R);
}

/*计算线某比例处的点坐标，比例值是从起点开始计算
参数a表示比例，在[0—1]范围内
返回值为此比例处点的坐标*/
Point Arc::proportionPt(double a)
{
	if (a == 0)
	{
		Point Star = this->Gain_Star();
		return Star;
	}
	else if (a == 1)
	{
		Point Fin = this->Gain_Fin();
		return Fin;
	}
	else
	{
		//相当于圆弧缩短a*Length长度生成新圆，圆起点与x轴正方向的夹角
		double NewStarAngle = (this->m_Swangle) * a + this->m_Stangle;
		Arc NewCircle(this->m_center, NewStarAngle, (this->m_Swangle - (this->m_Swangle * a)), this->m_R);
		Point NewPoint = NewCircle.Gain_Star();
		return NewPoint;
	}
}

//判断点pt是否在圆弧上,参数表示待判断的点；返回值返回1或-1.
//点返回值为 -1时点不在圆弧上，返回值为1时，点在圆弧上
int Arc::IsInLine(const Point &pt)
{
	double a = (pt.m_x - this->m_center.m_x);
	double b = (pt.m_y - this->m_center.m_y);
	double Dis = sqrt(a * a + b * b);
	//cout << Dis << endl;
	int index = 0;

	if (!double_equal_c(Dis, this->m_R))
	{
		index = -1;
		//cout << "点不在圆弧上" << endl;
	}
	else if (double_equal_c(Dis, this->m_R))
	{
		Point Star = this->Gain_Star();
		Point Fin = this->Gain_Fin();
		Point p = this->proportionPt(0.5);//圆弧中点坐标
		Line l1(this->m_center, pt);
		Line l2(Star, p);
		Line l3(p, Fin);
		bool p1 = l1.IsOverlap(l2);
		bool p2 = l1.IsOverlap(l3);
		if (p1 == true || p2 == true)
		{
			index = 1;
			//cout << "点在圆弧上" << endl;
		}
		else
		{
			index = -1;
			//cout << "点不在圆弧上" << endl;
		}
	}
	return index;
}

//*圆弧自我平移，参数传入一个点Dis（x,y)，表示平移的方向和距离。
//数值为正时表示向上（向右）平移，为负时相反*/
void Arc::Translation(const Point &Dis)
{
	this->m_center.m_x += Dis.m_x;
	this->m_center.m_y += Dis.m_y;
	this->m_Stangle = this->m_Stangle;
	this->m_Swangle = this->m_Swangle;
	this->m_R = this->m_R;
}

//*圆弧平移生成新圆弧，参数传入一个点Dis（x,y)，表示平移的方向和距离。
//数值为正时表示向上（向右）平移，为负时相反；返回值为新圆弧的指针*/
Arc* Arc::NewLine(const Point &Dis)
{
	Arc* arc = new Arc;
	arc->m_center.m_x += Dis.m_x;
	arc->m_center.m_y += Dis.m_y;
	arc->m_Stangle = this->m_Stangle;
	arc->m_Swangle = this->m_Swangle;
	arc->m_R = this->m_R;
	return arc;
}
	

//圆弧自我反向
void Arc::ReverseLine()
{
	this->m_center = this->m_center;
	this->m_Stangle = this->m_Stangle + this->m_Swangle;
	this->m_Swangle = -(this->m_Swangle);
	this->m_R = this->m_R;
}

//圆弧自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
//参数pt表示线段绕点pt旋转
void Arc::RotationLine(double degree, const Point &pt)
{
	Point p_star = this->Gain_Star();
	Point p_Fin = this->Gain_Fin();

	Point newStar = p_star.RotationPoint(degree, pt);
	Point newFin = p_Fin.RotationPoint(degree, pt);
	Point cp = this->m_center.RotationPoint(degree, pt);

	double a = acos((newStar.m_x - cp.m_x) / this->m_R);
	if (newStar.m_y < cp.m_y)
	{
		a += PI;
	}
	double b = this->m_Swangle;

	this->m_center = cp;
	this->m_R = this->m_R;

	this->m_Stangle = a;
	this->m_Swangle = b;
}

//将圆弧某端点延伸一段距离
//参数p为布尔值，如果p为true，延长点为起点；反之为终点；
//参数a为延长距离
void Arc::Extent(bool p, double a)
{
	Point NewCenter = this->m_center;
	//NewCenter.PrintPoint();

	double NewR = this->m_R;
	////this->m_center.PrintPoint();
	//
	double degree = a / this->m_R;
	if (p == true)//延长点为圆弧起点
	{
		//cout << (this->m_Stangle - degree)/PI << endl;;
		//cout << this->m_Stangle << endl;
		if (this->m_Swangle < 0)//起点延长为逆时针
		{
			this->m_Stangle = this->m_Stangle + degree;
			this->m_Swangle = this->m_Swangle - degree;
		}
		else//起点延长为顺时针
		{
			this->m_Stangle = this->m_Stangle - degree;
			this->m_Swangle = this->m_Swangle + degree;
		}

	}
	else if (p == false)//延长点为圆弧终点
	{

		if (this->m_Swangle < 0)//终点延长为顺时针
		{
			this->m_Stangle = this->m_Stangle;
			this->m_Swangle = this->m_Swangle - degree;
		}
		else//终点延长为逆时针
		{
			this->m_Stangle = this->m_Stangle;
			this->m_Swangle = this->m_Swangle + degree;
		}
	}
}

//打印线的信息
void Arc::PrintLine()
{
	cout << "圆心:";
	this->m_center.PrintPoint();
	cout << endl;
	cout << "半径:";
	cout << this->m_R;
	cout << endl;
	cout << "起始点与x轴正方向的夹角:";
	cout << (this->m_Stangle) / PI << "PI" << endl;
	cout << endl;
	cout << "起点到终点扫过的角度(逆时针为正）:";
	cout << this->m_Swangle / PI << "PI" << endl;
	cout << "圆弧的长度是:" << Length() << endl;
}

vector<Point> Arc::ArcPoint(Arc c1)//圆弧求交点，并返回交点.
{
	vector<Point> point;

	if (double_equal_c(this->m_center.m_x, c1.m_center.m_x) &&
		double_equal_c(this->m_center.m_y, c1.m_center.m_y) &&
		double_equal_c(this->m_R, c1.m_R) &&
		double_equal_c(this->m_Stangle, c1.m_Stangle) &&
		double_equal_c(this->m_Swangle, c1.m_Swangle))
	{
		cout << "两圆弧重合" << endl;
		return point;
	}
	else
	{
		double a = (this->m_center.m_x - c1.m_center.m_x);
		double b = (this->m_center.m_y - c1.m_center.m_y);
		double Dis = (sqrt(a*a + b * b));
		double R1 = this->m_R;
		double R2 = c1.m_R;
		//cout << Dis << endl;
		Point pointcut;//切点坐标
		//int ret = 0;
		Line L(this->m_center, c1.m_center);//连接两圆心得到的线段
		if (Dis == (R1 + R2) || Dis == (abs(R1 - R2)))//两圆内或者外切
		{
			if (Dis == (R1 + R2))//外切
			{
				double k = R1 / (R1 + R2);
				Point pointcut = L.proportionPt(k);//切点坐标

				int ret1 = this->IsInLine(pointcut);
				int ret2 = c1.IsInLine(pointcut);
				if (ret1 == 1 && ret2 == 1)
				{
					point.push_back(pointcut);
				}
			}
			else if (Dis == (abs(R1 - R2)))//内切
			{

				if (R1 > R2)
				{
					//cout << "zaiz" << endl;
					Line l1 = L.NewExtent(false, R2);
					//l1.PrintLine();
					Point l1_pts = l1.GetPts();
					int ret1 = this->IsInLine(l1_pts);
					//cout << ret1 << endl;
					int ret2 = c1.IsInLine(l1_pts);
					//cout << ret2 << endl;
					if (ret1 == 1 && ret2 == 1)
					{
						point.push_back(l1_pts);
					}
				}
				else if (R1 < R2)
				{
					Line l2 = L.NewExtent(true, R1);
					Point l2_pts = l2.GetPts();
					int ret1 = this->IsInLine(l2_pts);
					int ret2 = c1.IsInLine(l2_pts);
					if (ret1 == 1 && ret2 == 1)
					{
						point.push_back(l2_pts);
					}
				}
			}
		}
		else if (Dis < (R1 + R2))//圆存在两个交点
		{
			//cout << Dis << endl;
			double  a, b, c, p, q, r;
			double cos_c0, cos_c1;
			double sin_c0, sin_c1;
			double dis_x = c1.m_center.m_x - this->m_center.m_x;
			double dis_y = c1.m_center.m_y - this->m_center.m_y;
			//圆弧对应两圆心的距离
			double dis = sqrt((dis_x*dis_x) + (dis_y*dis_y));

			a = 2 * this->m_R * (this->m_center.m_x - c1.m_center.m_x);
			b = 2 * this->m_R * (this->m_center.m_y - c1.m_center.m_y);
			c = c1.m_R * c1.m_R - this->m_R*this->m_R - dis_x * dis_x - dis_y * dis_y;
			p = a * a + b * b;
			q = -2 * a*c;
			r = c * c - b * b;

			cos_c0 = (sqrt(q*q - 4 * p*r) - q) / p / 2;
			cos_c1 = (-sqrt(q*q - 4 * p*r) - q) / p / 2;

			sin_c0 = sqrt(1 - cos_c0 * cos_c0);
			sin_c1 = sqrt(1 - cos_c1 * cos_c1);

			Point p1, p2;//两个交点坐标
			p1.m_x = this->m_R*cos_c0 + this->m_center.m_x;
			p2.m_x = this->m_R*cos_c1 + this->m_center.m_x;
			p1.m_y = this->m_R*sin_c0 + this->m_center.m_x;
			p2.m_y = this->m_R*sin_c1 + this->m_center.m_x;

			double disx1 = p1.m_x - c1.m_center.m_x;
			double disy1 = p1.m_y - c1.m_center.m_y;
			double dis1 = sqrt((disx1*disx1) + (disy1*disy1));
			//验证所求的解是否正确
			if (!double_equal_c(dis, (c1.m_R*c1.m_R)))
			{
				p1.m_y = this->m_center.m_y - this->m_R*sin_c0;
			}
			double disx2 = p2.m_x - c1.m_center.m_x;
			double disy2 = p2.m_y - c1.m_center.m_y;
			double dis2 = sqrt((disx2*disx2) + (disy2*disy2));
			if (!double_equal_c(dis2, (c1.m_R*c1.m_R)))
			{
				p2.m_y = this->m_center.m_y - this->m_R*sin_c1;
			}

			// 如果求得的两个点坐标相同, 则必然其中一个点的纵坐标反号可以求得另一点坐标
			if (double_equal_c(p1.m_x, p2.m_x) && double_equal_c(p1.m_y, p2.m_y))
			{
				if (p1.m_y > 0)
				{
					p2.m_y = -p2.m_y;
				}
				else
				{
					p1.m_y = -p1.m_y;
				}
			}

			p1.PrintPoint();
			//p2.PrintPoint();
			int ret1 = this->IsInLine(p1);
			int ret2 = c1.IsInLine(p1);

			//cout << ret1 << endl;
			//cout << ret2 << endl;
			if (ret1 == 1 && ret2 == 1)
			{
				point.push_back(p1);
			}
			int ret3 = this->IsInLine(p2);
			int ret4 = c1.IsInLine(p2);
			if (ret3 == 1 && ret4 == 1)
			{
				point.push_back(p2);
			}
			//cout << ret1<<endl;
			//cout << ret2 << endl;
			//cout << ret3<< endl;
			//cout << ret4 << endl;
			//point.push_back(p1);
			//point.push_back(p2);
		}
		else//两圆相离，不存在交点
		{
			//ret = -1;
			return point;
		}
		//return point;
	}
}

Arc::~Arc()
{

}