#include"Line.h"

Line::Line()//Ĭ�Ϲ��캯��
{

}

//���캯�����ó�ʼ��ֱ�ߵ������˵㣬pt1��ֵ����㣬pt2��ֵ���յ�
Line::Line(Point pt1, Point pt2)
{
	m_ptf = pt1;
	m_pts = pt2;
}

//���㲢����ֱ�ߵĳ��ȣ�����ֵΪֱ�ߵĳ���
double Line::Length()const
{
	double a = (m_pts.m_x - m_ptf.m_x);
	double b = (m_pts.m_y - m_ptf.m_y);
	return sqrt(a*a + b * b);
}

//����ֱ��ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
//����a��ʾ�������ڣ�0��1����Χ��
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
		double len = this->Length();//ֱ�߳���
		double x1 = len * a;
		double k = x1 / len;//����

		Point fs;//��ʾֱ�����Ͷ˵㹹�ɵ�����
		fs.m_x = (m_pts.m_x - m_ptf.m_x);
		fs.m_y = (m_pts.m_y - m_ptf.m_y);

		Point fp;//��ʾֱ�����ͱ������㹹�ɵ�����
		fp.m_x = (k * fs.m_x);
		fp.m_y = (k * fs.m_y);

		Point of = m_ptf;//��ʾԭ�����㹹�ɵ�����
		Point op;//��ʾԭ��ͱ�����p�㹹�ɵ�����,���������������
		op.m_x = (of.m_x + fp.m_x);
		op.m_y = (of.m_y + fp.m_y);
		return op;
	}
}

/*�жϵ��Ƿ����߶�L��,����pt��ʾҪȷ���ĵ�
����ֵΪindex����ֵΪ-1ʱ����ʾ�㲻�����ϣ���ֵΪ1ʱ����ʾ��������*/
int Line::IsInLine(const Point &pt)
{
	int index = -1;
	if ((pt.m_x - this->m_ptf.m_x) * (this->m_pts.m_y - this->m_ptf.m_y) == (this->m_pts.m_x - this->m_ptf.m_x) * (pt.m_y - this->m_ptf.m_y)  //��� 
		//��֤Q��������pi,pj֮�� 
		&& min(this->m_ptf.m_x, this->m_pts.m_x) <= pt.m_x && pt.m_x <= max(this->m_ptf.m_x, this->m_pts.m_x)
		&& min(this->m_ptf.m_y, this->m_pts.m_y) <= pt.m_y && pt.m_y <= max(this->m_ptf.m_y, this->m_pts.m_y))
	{
		index = 1;
		//cout << "�����߶���" << endl;
		return index;
	}
	else
	{
		index = -1;
		//cout << "�㲻���߶���" << endl;
		return index;
	}
}


/*�߶�����ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
void Line::Translation(const Point &Dis)
{
	this->m_ptf.m_x += Dis.m_x;
	this->m_ptf.m_y += Dis.m_y;
	this->m_pts.m_x += Dis.m_x;
	this->m_pts.m_y += Dis.m_y;
}

/*�߶�ƽ�ƺ�����һ�����ߣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴
����ֵ�������ɵ���*/
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

void Line::ReverseLine()//�߶����ҷ���
{
	Point temp(0, 0);
	temp = this->m_ptf;
	this->m_ptf = this->m_pts;
	this->m_pts = temp;
}

//�߶�������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
//����pt��ʾ�߶��Ƶ�pt��ת
void Line::RotationLine(double degree, const Point &pt)
{
	Point pf = this->m_ptf.RotationPoint(degree, pt);
	Point ps = this->m_pts.RotationPoint(degree, pt);
	this->m_ptf = pf;
	this->m_pts = ps;	
}

//�߶���������,����aΪ�ӳ�����,����p�ж��ӳ���Ϊ�Ǹ���true��ʾ��㣬false��ʾ�յ�
void Line::Extent(bool p, double a)
{
	double len = 0;
	len = this->Length();

	if (p == true)//���ӳ��ĵ�Ϊ���
	{
		if (this->m_ptf.m_x < this->m_pts.m_x)//������յ����ߣ��ӳ�����Ϊ��
		{
			double L = this->Length() + a;
			double k = L / this->Length();
		
			double x0 = this->m_ptf.m_x - this->m_pts.m_x;
			double y0 = this->m_ptf.m_y - this->m_pts.m_y;
			Point sf(x0, y0);//����m_pts-m_ptf
			Point sc(k*x0, k*y0);//�ӳ�����
			//�ӳ������˵��������
			this->m_ptf.m_x = this->m_pts.m_x + sc.m_x;
			this->m_ptf.m_y = this->m_pts.m_y + sc.m_y;
		    this->m_pts.m_x = this->m_pts.m_x;
			this->m_pts.m_y = this->m_pts.m_y;
		}
	}
	else if (p == false)//���ӳ��ĵ�Ϊ�յ�
	{
		double L = this->Length() + a;
		double k = L / this->Length();

		double x0 = this->m_pts.m_x - this->m_ptf.m_x;
		double y0 = this->m_pts.m_y - this->m_ptf.m_y;
		Point fs(x0, y0);//����m_ptf-m_pts
		Point fc(k*x0, k*y0);//�ӳ��������
		//�ӳ������˵��������
		this->m_pts.m_x = this->m_ptf.m_x + fc.m_x;
		this->m_pts.m_y = this->m_ptf.m_y + fc.m_y;
		this->m_pts.m_x = this->m_pts.m_x;
		this->m_pts.m_y = this->m_pts.m_y;
	}
}

//�߶�������������;
//����p�����ж��ӳ���Ϊ�ĸ�,true��ʾֱ�ߵ���㣬false��ʾֱ�ߵ��յ�
//����a��ʾ�ӳ�����
//����ֵΪ����
Line Line::NewExtent(bool p, double a)
{
	Line NewLine;
	double len = 0;
	len = this->Length();

	if (p == true)//���ӳ��ĵ�Ϊ���
	{
		if (this->m_ptf.m_x < this->m_pts.m_x)//������յ����ߣ��ӳ�����Ϊ��
		{
			double L = this->Length() + a;
			double k = L / this->Length();

			double x0 = this->m_ptf.m_x - this->m_pts.m_x;
			double y0 = this->m_ptf.m_y - this->m_pts.m_y;
			Point sf(x0, y0);//����m_pts-m_ptf
			Point sc(k*x0, k*y0);//�ӳ�����
			//�ӳ������˵��������
			NewLine.m_ptf.m_x = this->m_pts.m_x + sc.m_x;
			NewLine.m_ptf.m_y = this->m_pts.m_y + sc.m_y;
			NewLine.m_pts.m_x = this->m_pts.m_x;
			NewLine.m_pts.m_y = this->m_pts.m_y;
		}
	}
	else if (p == false)//���ӳ��ĵ�Ϊ�յ�
	{
		double L = this->Length() + a;
		double k = L / this->Length();

		double x0 = this->m_pts.m_x - this->m_ptf.m_x;
		double y0 = this->m_pts.m_y - this->m_ptf.m_y;
		Point fs(x0, y0);//����m_ptf-m_pts
		Point fc(k*x0, k*y0);//�ӳ��������
		//�ӳ������˵��������
		NewLine.m_pts.m_x = this->m_ptf.m_x + fc.m_x;
		NewLine.m_pts.m_y = this->m_ptf.m_y + fc.m_y;
		NewLine.m_ptf.m_x = this->m_pts.m_x;
		NewLine.m_ptf.m_y = this->m_pts.m_y;
	}
	return NewLine;
}

//�ж����Ƿ��ཻ�������߶�lΪ��һ����
//����ֵΪbool�����Ϊfalse����ʾ���࣬Ϊtrue��ʾ�ཻ
bool Line::IsOverlap(Line l)
{
	double a1 = this->m_pts.m_y - this->m_ptf.m_y;
	double b1 = this->m_ptf.m_x - this->m_pts.m_x;
	double c1 = this->m_ptf.m_x*this->m_pts.m_y - this->m_pts.m_x*this->m_ptf.m_y;
	double a2 = l.m_pts.m_y - l.m_ptf.m_y;
	double b2 = l.m_ptf.m_x - l.m_pts.m_x;
	double c2 = l.m_ptf.m_x*l.m_pts.m_y - l.m_pts.m_x*l.m_ptf.m_y;

	//���߶ε���������Ϊ���ʾƽ�У���Ϊ���ʾ��ƽ��
	double det = a1 * b2 - a2 * b1;
	//cout << det << endl;
	if (det >= -EPSINON && det <= EPSINON)//�߶�ƽ��
	{
		int ret1 = this->IsInLine(l.m_ptf);
		int ret2 = this->IsInLine(l.m_pts);
		if (ret1 == 1 || ret2 == 1) //�߶��غ�
		{
			//cout << "�غ�" << endl;
			return true;
		}
		else //û���غ�
		{
			return false;
		}
	}
	else //��Ӧֱ���ཻ
	{
		Point pt;
		pt.m_x = (c1*b2 - c2 * b1) / det;
		pt.m_y = (a1*c2 - a2 * c1) / det;
		//pt.PrintPoint();

		int index = this->IsInLine(pt);
		int ret = l.IsInLine(pt);
		//pt.PrintPoint();
		//�жϽ����ڲ����������ϣ�ͬʱ�ڱ�ʾ�߶��н��㣬���ⲻ�ڱ�ʾ�޽���
		//this->PrintLine();
		//int ret1 = this->IsInLine(pt);
		//cout << ret1 << endl;
		//l.PrintLine();
		//int ab = l.IsInLine(pt);

		//pt.PrintPoint();
		//cout << ab << endl;
		if (ret == 1 && index == 1)//�н���
		{
			return true;
		}
		else//�޽���
		{
			return false;
		}
	}
}

//��ӡ�ߵ���Ϣ
void Line::PrintLine()
 {
	cout << "��һ����:";
	m_ptf.PrintPoint();
	cout << endl;
	cout << "�ڶ�����:";
	m_pts.PrintPoint();
	cout << endl;
	cout << "ֱ�ߵĳ�����:" << Length() << endl;
 }

//��ȡ�������
Point Line::GetPtf()
{
	return this->m_ptf;
}

//��ȡ�յ�����
Point Line::GetPts()
{
	return this->m_pts;
}

bool Line::LinePoint(Line l, Point& pt)
{
	bool ret = this->IsOverlap(l);
	if (ret == false)
	{

		cout << "�����߶�û�н���" << endl;
		return false;
	}
	else
	{
		cout << "��ֱ�ߴ��ڽ���" << endl;

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

