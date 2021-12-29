#include"Arc.h"

Arc::Arc()
{

}

//���캯������ʼ��Բ���Ĳ�������pt1��ֵ��Բ�ģ�
//a��ֵ�������x��������нǣ�b��ֵ����㵽�յ�ɨ���ĽǶȣ�r��ֵ��Բ�İ뾶
Arc::Arc(Point pt1, double a, double b, double r)
{
	m_center = pt1;
	m_Stangle = a;
	m_Swangle = b;
	m_R = r;
}

//��ȡԲ��
Point Arc::GetCen()
{
	return this->m_center;
}

//��ȡ���н�
double Arc::GetStarAngle()
{
	return this->m_Stangle;
}

//��ȡɨ���Ľ�
double Arc::GetSwAngle()
{
	return this->m_Swangle;
}

//��ȡ�뾶
double Arc::GetR()
{
	return this->m_R;
}

//����Բ����㲢�����������
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

//����Բ���յ㲢�����յ�����
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

// �ж�������������ͬ
int Arc::double_equal_c(double a, double b)
{
	static const double ZERO = 0.5;
	return fabs(a - b) < ZERO;
}


//���㲢����Բ���ĳ���
double Arc::Length()const
{
	return abs(m_Swangle * m_R);
}

/*������ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
����a��ʾ��������[0��1]��Χ��
����ֵΪ�˱������������*/
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
		//�൱��Բ������a*Length����������Բ��Բ�����x��������ļн�
		double NewStarAngle = (this->m_Swangle) * a + this->m_Stangle;
		Arc NewCircle(this->m_center, NewStarAngle, (this->m_Swangle - (this->m_Swangle * a)), this->m_R);
		Point NewPoint = NewCircle.Gain_Star();
		return NewPoint;
	}
}

//�жϵ�pt�Ƿ���Բ����,������ʾ���жϵĵ㣻����ֵ����1��-1.
//�㷵��ֵΪ -1ʱ�㲻��Բ���ϣ�����ֵΪ1ʱ������Բ����
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
		//cout << "�㲻��Բ����" << endl;
	}
	else if (double_equal_c(Dis, this->m_R))
	{
		Point Star = this->Gain_Star();
		Point Fin = this->Gain_Fin();
		Point p = this->proportionPt(0.5);//Բ���е�����
		Line l1(this->m_center, pt);
		Line l2(Star, p);
		Line l3(p, Fin);
		bool p1 = l1.IsOverlap(l2);
		bool p2 = l1.IsOverlap(l3);
		if (p1 == true || p2 == true)
		{
			index = 1;
			//cout << "����Բ����" << endl;
		}
		else
		{
			index = -1;
			//cout << "�㲻��Բ����" << endl;
		}
	}
	return index;
}

//*Բ������ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
//��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
void Arc::Translation(const Point &Dis)
{
	this->m_center.m_x += Dis.m_x;
	this->m_center.m_y += Dis.m_y;
	this->m_Stangle = this->m_Stangle;
	this->m_Swangle = this->m_Swangle;
	this->m_R = this->m_R;
}

//*Բ��ƽ��������Բ������������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
//��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴������ֵΪ��Բ����ָ��*/
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
	

//Բ�����ҷ���
void Arc::ReverseLine()
{
	this->m_center = this->m_center;
	this->m_Stangle = this->m_Stangle + this->m_Swangle;
	this->m_Swangle = -(this->m_Swangle);
	this->m_R = this->m_R;
}

//Բ��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
//����pt��ʾ�߶��Ƶ�pt��ת
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

//��Բ��ĳ�˵�����һ�ξ���
//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
//����aΪ�ӳ�����
void Arc::Extent(bool p, double a)
{
	Point NewCenter = this->m_center;
	//NewCenter.PrintPoint();

	double NewR = this->m_R;
	////this->m_center.PrintPoint();
	//
	double degree = a / this->m_R;
	if (p == true)//�ӳ���ΪԲ�����
	{
		//cout << (this->m_Stangle - degree)/PI << endl;;
		//cout << this->m_Stangle << endl;
		if (this->m_Swangle < 0)//����ӳ�Ϊ��ʱ��
		{
			this->m_Stangle = this->m_Stangle + degree;
			this->m_Swangle = this->m_Swangle - degree;
		}
		else//����ӳ�Ϊ˳ʱ��
		{
			this->m_Stangle = this->m_Stangle - degree;
			this->m_Swangle = this->m_Swangle + degree;
		}

	}
	else if (p == false)//�ӳ���ΪԲ���յ�
	{

		if (this->m_Swangle < 0)//�յ��ӳ�Ϊ˳ʱ��
		{
			this->m_Stangle = this->m_Stangle;
			this->m_Swangle = this->m_Swangle - degree;
		}
		else//�յ��ӳ�Ϊ��ʱ��
		{
			this->m_Stangle = this->m_Stangle;
			this->m_Swangle = this->m_Swangle + degree;
		}
	}
}

//��ӡ�ߵ���Ϣ
void Arc::PrintLine()
{
	cout << "Բ��:";
	this->m_center.PrintPoint();
	cout << endl;
	cout << "�뾶:";
	cout << this->m_R;
	cout << endl;
	cout << "��ʼ����x��������ļн�:";
	cout << (this->m_Stangle) / PI << "PI" << endl;
	cout << endl;
	cout << "��㵽�յ�ɨ���ĽǶ�(��ʱ��Ϊ����:";
	cout << this->m_Swangle / PI << "PI" << endl;
	cout << "Բ���ĳ�����:" << Length() << endl;
}

vector<Point> Arc::ArcPoint(Arc c1)//Բ���󽻵㣬�����ؽ���.
{
	vector<Point> point;

	if (double_equal_c(this->m_center.m_x, c1.m_center.m_x) &&
		double_equal_c(this->m_center.m_y, c1.m_center.m_y) &&
		double_equal_c(this->m_R, c1.m_R) &&
		double_equal_c(this->m_Stangle, c1.m_Stangle) &&
		double_equal_c(this->m_Swangle, c1.m_Swangle))
	{
		cout << "��Բ���غ�" << endl;
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
		Point pointcut;//�е�����
		//int ret = 0;
		Line L(this->m_center, c1.m_center);//������Բ�ĵõ����߶�
		if (Dis == (R1 + R2) || Dis == (abs(R1 - R2)))//��Բ�ڻ�������
		{
			if (Dis == (R1 + R2))//����
			{
				double k = R1 / (R1 + R2);
				Point pointcut = L.proportionPt(k);//�е�����

				int ret1 = this->IsInLine(pointcut);
				int ret2 = c1.IsInLine(pointcut);
				if (ret1 == 1 && ret2 == 1)
				{
					point.push_back(pointcut);
				}
			}
			else if (Dis == (abs(R1 - R2)))//����
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
		else if (Dis < (R1 + R2))//Բ������������
		{
			//cout << Dis << endl;
			double  a, b, c, p, q, r;
			double cos_c0, cos_c1;
			double sin_c0, sin_c1;
			double dis_x = c1.m_center.m_x - this->m_center.m_x;
			double dis_y = c1.m_center.m_y - this->m_center.m_y;
			//Բ����Ӧ��Բ�ĵľ���
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

			Point p1, p2;//������������
			p1.m_x = this->m_R*cos_c0 + this->m_center.m_x;
			p2.m_x = this->m_R*cos_c1 + this->m_center.m_x;
			p1.m_y = this->m_R*sin_c0 + this->m_center.m_x;
			p2.m_y = this->m_R*sin_c1 + this->m_center.m_x;

			double disx1 = p1.m_x - c1.m_center.m_x;
			double disy1 = p1.m_y - c1.m_center.m_y;
			double dis1 = sqrt((disx1*disx1) + (disy1*disy1));
			//��֤����Ľ��Ƿ���ȷ
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

			// �����õ�������������ͬ, ���Ȼ����һ����������귴�ſ��������һ������
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
		else//��Բ���룬�����ڽ���
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