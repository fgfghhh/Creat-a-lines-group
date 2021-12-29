#pragma once
#include"point.h"
#include<vector>
#include"LineBase.h"
#include"Line.h"
#include"Arc.h"


class Package:public LineBase
{
public:

	vector<LineBase*>  v;//��������ָ��
	void C_SetData(const Arc &arc)
	{
		LineBase *linebase_c = new Arc(arc);
		 new Arc(arc);
		v.push_back(linebase_c);
	}
	void S_SetData(const Line &line)
	{
		LineBase *llinebase_s = new Line(line);
		v.push_back(llinebase_s);
	}

	/*������ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
	����a��ʾ��������[0��1]��Χ��
	����ֵΪ�˱������������*/
	virtual Point proportionPt(double a) ;

	//���㲢����ֱ�ߵĳ���
	virtual double Length()const ;

	/*�жϵ��Ƿ�������,����pt��ʾҪȷ���ĵ�
	����ֵΪindex����ֵΪ-1ʱ����ʾ�㲻�����ϣ���ֵΪ1ʱ����ʾ��������*/
	virtual int IsInLine(const Point &pt) ;

	/*������ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
	��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
	virtual void Translation(const Point &Dis) ;

	//�ߵ�����ҷ���
	virtual void ReverseLine() ;

	//��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
	//����pt��ʾ�߶��Ƶ�pt��ת
	virtual void RotationLine(double degree, const Point &pt) ;

	//��Բ��ĳ�˵�����һ�ξ���
	//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
	//����aΪ�ӳ�����
	virtual void Extent(bool p, double a) ;

	//��ӡ�ߵ���Ϣ
	virtual void PrintLine();

	virtual ~Package() ;

};