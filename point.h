#pragma once
#include<iostream>
using namespace std;
const double EPSINON = 0.00001;
#define PI  3.141592654
#include<algorithm>

class Point
{
public:
	Point();//Ĭ�Ϲ��캯��
	
	Point(double x, double y);//�������캯������ʼ�����x��y����
	
	~Point();//��������
	
	void operator=(Point &pt);//��ֵ����������

	bool operator==(Point &pt);//==����
	
	void PrintPoint();//�����
	
	void SetPointx(double x);//���õ��x����
	void SetPointy(double y);//���õ��y����

	double GetPointx();//��ȡ���x������
	double GetPointy();//��ȡ���y������
	

	//������ĳ��ֱ�߶Գƺ�������
	//����Ĳ�����һ��ֱ��l����ʾ�����ֱ��l����
	//����ֵ�ǵ㾵����µĵ�
	//Point NewMirrorPoint(Line l);

	//�������p2��ת��������꣬����1Ϊ��ת�Ļ���degree������2Ϊ�Ƶĵ�
	//����ֵΪ��ת�������
	Point RotationPoint(double degree, Point p2);

	// �ж�������������ͬ
	int double_equal_p(double a, double b);

	//��-�����������
	//void operator-(Point p);

public                                                                                                                                                                                                                               :
	double m_x, m_y;//�����������ֵ
};