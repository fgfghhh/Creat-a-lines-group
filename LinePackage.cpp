#include<iostream>
using namespace std;
#include"LinePackage.h"
#include <cmath>
#define _USE_MATH_DEFINES

/*������ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
����a��ʾ��������[0��1]��Χ��
����ֵΪ�˱������������*/
Point Package:: proportionPt(double a)
{
	Point p(0.000, 0.000);
	cout << "�ڱ���a��������������Ϊ��" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->proportionPt(a).PrintPoint();
		//return v[i]->proportionPt(a);
	}
	return p;
}

//���㲢����ֱ�ߵĳ���
double Package::Length()const
{
	double len = 0;
	cout << "ÿ�������ĳ���:" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]->Length() << endl;
		len += v[i]->Length();
	}
	cout << "�����ܳ���:" << endl;
	cout << len << endl;
	return len;
}

/*�жϵ��Ƿ�������,����pt��ʾҪȷ���ĵ�
����ֵΪindex����ֵΪ-1ʱ����ʾ�㲻�����ϣ���ֵΪ1ʱ����ʾ��������*/
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

/*������ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
	��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
void Package::Translation(const Point &Dis)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "ƽ��ǰ�ߵ���Ϣ��" << endl;
		v[i]->PrintLine();
		cout << endl;
		cout << "ƽ�ƺ��ߵ���Ϣ��" << endl;
		v[i]->Translation(Dis);
		v[i]->PrintLine();
		cout << endl;
	}
}

//�ߵ�����ҷ���
void Package::ReverseLine()
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����ǰ�ߵ���Ϣ��" << endl;
		(*it)->PrintLine();
		cout << endl;
		(*it)->ReverseLine();
		cout << "������ߵ���Ϣ��" << endl;
		(*it)->PrintLine();
		cout << endl;
	}
}

//��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
//����pt��ʾ�߶��Ƶ�pt��ת
void Package::RotationLine(double degree, const Point &pt)
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��תǰ�ߵ���Ϣ��" << endl;
		(*it)->PrintLine();
		cout << endl;
		(*it)->RotationLine(degree, pt);
		cout << "��ת���ߵ���Ϣ��" << endl;
		(*it)->PrintLine();
		cout << endl;
	}
}

//��Բ��ĳ�˵�����һ�ξ���
	//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
	//����aΪ�ӳ�����
void Package::Extent(bool p, double a) 
{
	for (vector<LineBase*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "�ӳ�ǰ�ߵ���Ϣ��" << endl;
		(*it)->PrintLine();
		cout << endl;
		(*it)->Extent(p,a);
		cout << "�ӳ����ߵ���Ϣ��" << endl;
		(*it)->PrintLine();
		cout << endl;
	}
}

//��ӡ�ߵ���Ϣ
void Package::PrintLine()
{

}


Package:: ~Package()
{

}
