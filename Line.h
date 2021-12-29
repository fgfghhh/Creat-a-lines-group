#pragma once
#include"point.h"
#include<vector>
#include"LineBase.h"


class Line :public LineBase
{
public:
	//Ĭ�Ϲ��캯��
	Line();

	//���캯�����ó�ʼ��ֱ�ߵ�������.pt1��ֵ����㣬pt2��ֵ���յ�
	Line(Point pt1, Point pt2);

	//��ȡ�������
	Point GetPtf();
	
	//��ȡ�յ�����
	Point GetPts();
	
	//���㲢�����ߵĳ���
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
	Line* NewLine(Point Dis);

	//�ߵ�����ҷ���
	virtual void ReverseLine();

	//��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
	//����pt��ʾ�߶��Ƶ�pt��ת
	virtual void RotationLine(double degree, const Point &pt);

	//����ĳ�˵�����һ�ξ���
	//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
	//����aΪ�ӳ�����
	virtual void Extent(bool p, double a);

	//�߶�������������;
	//����p�����ж��ӳ���Ϊ�ĸ�,true��ʾֱ�ߵ���㣬false��ʾֱ�ߵ��յ�
	//����a��ʾ�ӳ�����
	//����ֵΪ����
	Line NewExtent(bool p, double a);

	//�ж����Ƿ��ཻ�������߶�lΪ��һ����
	//����ֵΪbool�����Ϊfalse����ʾ���࣬Ϊtrue��ʾ�ཻ
	bool IsOverlap(Line l);

	//�߶��󽻵㣬�����ؽ������ꡣ
	//��������һ��ֱ�ߣ��͵�pt
	//������ڽ��㣬pt��¼��������ꣻ��������ڽ��㣬�򷵻�false
	//Point LinePoint(Line l1);
	bool LinePoint(Line l, Point& pt);

	//��ӡ�ߵ���Ϣ
	virtual void PrintLine();

	//��������
	virtual ~Line();

private:
	Point m_ptf;//ֱ�����
	Point m_pts;//ֱ���յ�
};
