/*
https://ac.nowcoder.com/acm/contest/120563/H
思路解析：
三角形 S=|AB x AC|/2 （AB、AC是向量） 
带入坐标计算
发现ya=yb时，如果 ya*(xa-xb) 等于4，则恒成立，不等于则无解 
*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double xa,ya,xb,yb;//也可以先用long long读入，用整数进行精确判定，最后再转double 
	cin>>xa>>ya>>xb>>yb;
	if(abs(ya-yb)<1e-9)//浮点数不要用== ,abs()最好加<cmath> 
	{
		if(abs(abs(ya*(xa-xb))-4.0)<1e-9) 
		{
			cout<<0.0;
		}
		else
		{
			cout<<"no answer";
		}
	}
	else
	{
		cout<<fixed<<setprecision(10)<<xa-(ya*(xa-xb)+4.0)/(ya-yb);//要加头文件<iomanip> 
	}
	
	return 0;
 } 
