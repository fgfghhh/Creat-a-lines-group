#pragma once
#include"point.h"
#include<vector>

class LineBase
{
public:

	/*������ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
	����a��ʾ��������[0��1]��Χ��
	����ֵΪ�˱������������*/
	virtual Point proportionPt(double a) = 0;

	//���㲢����ֱ�ߵĳ���
	virtual double Length()const = 0;

	/*�жϵ��Ƿ�������,����pt��ʾҪȷ���ĵ�
	����ֵΪindex����ֵΪ-1ʱ����ʾ�㲻�����ϣ���ֵΪ1ʱ����ʾ��������*/
	virtual int IsInLine( const Point &pt) = 0;

	/*������ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
	��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
	virtual void Translation(const Point &Dis) = 0;

	//�ߵ�����ҷ���
	virtual void ReverseLine() = 0;

	//��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
	//����pt��ʾ�߶��Ƶ�pt��ת
	virtual void RotationLine(double degree, const Point &pt) = 0;

	//��Բ��ĳ�˵�����һ�ξ���
	//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
	//����aΪ�ӳ�����
	virtual void Extent(bool p, double a) = 0;

	//��ӡ�ߵ���Ϣ
	virtual void PrintLine() = 0;

	virtual ~LineBase() {};
};
//LineBase::~LineBase() {};