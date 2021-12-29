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

	//���캯������ʼ��Բ���Ĳ�����a��ֵ�������x��������нǣ�
	//b��ֵ����㵽�յ�ɨ���ĽǶȣ�r��ֵ��Բ�İ뾶
	Arc(Point pt1, double a, double b, double r);

	//��ȡԲ��
	Point GetCen();

	//��ȡ���н�
	double GetStarAngle();

	//��ȡɨ���Ľ�
	double GetSwAngle();

	//��ȡ�뾶
	double GetR();

	//����Բ����㲢�����������
	Point Gain_Star();

	//����Բ���յ㲢�����յ�����
	Point Gain_Fin();

	// �ж�������������ͬ
	int double_equal_c(double a, double b);

	//���㲢����Բ���ĳ���
	virtual double Length()const;

	/*������ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
	����a��ʾ��������[0��1]��Χ��
	����ֵΪ�˱������������*/
	virtual Point proportionPt(double a);

	/*�жϵ��Ƿ�������,����pt��ʾҪȷ���ĵ�
	����ֵΪindex����ֵΪ-1ʱ����ʾ�㲻�����ϣ���ֵΪ1ʱ����ʾ��������*/
	virtual int IsInLine(const Point &pt);

	/*������ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
	��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
	virtual void Translation(const Point &Dis);

	/*��ƽ�ƺ�����һ�����ߣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
	��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴
	����ֵ�������ɵ���*/
	Arc* NewLine(const Point &Dis);

	//�ߵ�����ҷ���
	virtual void ReverseLine();

	//��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
	//����pt��ʾ�߶��Ƶ�pt��ת
	virtual void RotationLine(double degree, const Point &pt);

	//����ĳ�˵�����һ�ξ���
	//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
	//����aΪ�ӳ�����
	//����ֵΪ������Բ��ָ��
	virtual void Extent(bool p, double a);

	//��������Բ���Ľ��㣬����Ϊ��һ��Բ����
	//����ֵΪ�������꣬��������ڽ��㣬���ؿ�ֵ��
	//�������һ�����㣬����һ���������ꣻ
	//��������������㣬�����������������ֵ
	vector<Point> ArcPoint(Arc c1);

	virtual ~Arc();

	//��ӡ�ߵ���Ϣ
	virtual void PrintLine();

private:
	Point m_center;//Բ����Բ��
	double m_Stangle;//Բ����ʼ����x��������ļн�(��ʱ��Ϊ����
	double m_Swangle;//Բ����㵽�յ�ɨ���ĽǶ�(��ʱ��Ϊ����
	double m_R;//Բ���뾶R
};
