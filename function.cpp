#include<iostream>
#include"LinePackage.h"
using namespace std;

int main() {
	/*Package pk;
    Point p1(0, 0), p2(3,3),p3(0,5),p4(1,1),p5(0,-5),p6(3.5355339,3.5355339),p7(-3.5355339,-3.5355339);
	Point cen1(0,0);
	Line l1(p1, p4),l2(p2,p3);
	Point pf(0, 0), ps(4,0), cen2(4, 1),ps2(0,1),ps3(4,5),ps4(0,0);
    Arc c1(cen2, 0.5*PI, -1 * PI, 4);
	Arc c2(cen1, 0, PI, 5);
	pk.C_SetData(c1);
	pk.C_SetData(c2);*/
	//pk.S_SetData(l1);
	//pk.S_SetData(l2);

	//���㲢����ֱ�ߵĳ���
	//pk.Length();

	/*������ĳ�������ĵ����꣬����ֵ�Ǵ���㿪ʼ����
	����a��ʾ��������[0��1]��Χ��
	����ֵΪ�˱������������*/
	//pk.proportionPt(0.5);

	/*������ƽ�ƣ���������һ����Dis��x,y)����ʾƽ�Ƶķ���;��롣
	��ֵΪ��ʱ��ʾ���ϣ����ң�ƽ�ƣ�Ϊ��ʱ�෴*/
	//pk.Translation(p4);

	//�ߵ�����ҷ���
	//pk.ReverseLine();
	
	//��Բ��ĳ�˵�����һ�ξ���
	//����pΪ����ֵ�����pΪtrue���ӳ���Ϊ��㣻��֮Ϊ�յ㣻
	//����aΪ�ӳ�����
	//pk.Extent(true,3);

	//��������תdegree(degreeΪ����ֵ��������Ϊ��ʱ��ʾ˳ʱ�룬Ϊ��ʱ��ʾ��ʱ�룻
	//����pt��ʾ�߶��Ƶ�pt��ת
	//pk.RotationLine(-0.5*PI,p1);
	
	/*�жϵ��Ƿ�������,����pt��ʾҪȷ���ĵ�
	����ֵΪindex����ֵΪ-1ʱ����ʾ�㲻�����ϣ���ֵΪ1ʱ����ʾ��������*/
	//pk.IsInLine(p7);

	/*for (vector<LineBase*>::iterator it = pk.v.begin(); it != pk.v.end(); it++)
	{
		cout << (*it)->Length() << endl;
		
	}*/

	/*for (int i = 0; i < pk.v.size(); i++)
	{
		pk.v[i]->Length();
		cout << pk.v[i]->Length() << endl;
	}*/


	//Point p1(0, 0),  p2(3, 3),p3(0,3),p4(3,0),pt;
	//Line L1(p1, p2);
	//Line L2(p3, p4);
	////L1.Extent(false,3);
	////L1.PrintLine();
	////cout << "-----------------------------" << endl;

	////Line newLine = L2.NewExtent(false, 3);
	////newLine.PrintLine();
	//L1.LinePoint(L2, pt);
	//pt.PrintPoint();

	system("pause");
	return 0;
}