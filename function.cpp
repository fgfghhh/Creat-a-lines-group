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

	//计算并返回直线的长度
	//pk.Length();

	/*计算线某比例处的点坐标，比例值是从起点开始计算
	参数a表示比例，在[0—1]范围内
	返回值为此比例处点的坐标*/
	//pk.proportionPt(0.5);

	/*线自我平移，参数传入一个点Dis（x,y)，表示平移的方向和距离。
	数值为正时表示向上（向右）平移，为负时相反*/
	//pk.Translation(p4);

	//线点的自我反向
	//pk.ReverseLine();
	
	//将圆弧某端点延伸一段距离
	//参数p为布尔值，如果p为true，延长点为起点；反之为终点；
	//参数a为延长距离
	//pk.Extent(true,3);

	//线自我旋转degree(degree为弧度值）当弧度为负时表示顺时针，为正时表示逆时针；
	//参数pt表示线段绕点pt旋转
	//pk.RotationLine(-0.5*PI,p1);
	
	/*判断点是否在线上,参数pt表示要确定的点
	返回值为index，当值为-1时，表示点不在线上，当值为1时，表示点在线上*/
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