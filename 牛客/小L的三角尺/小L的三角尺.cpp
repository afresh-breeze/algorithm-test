/*
https://ac.nowcoder.com/acm/contest/120566/A
思路解析见附带文档 
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>//用了setprecision(9)
#include<utility>//用了pair<double,double> 
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    long n;
    double w;
    cin>>n>>w;
    vector<double> x(n),y(n);
    double sum_y=0;
    for(long i=0;i<n;++i)
    {
    	cin>>x[i]>>y[i];
    	sum_y+=y[i];
	}
	double S=sum_y-w;
	//S<=0时，全部磨完
	if(S<=0)
	{
		double ans=0;
		for(long i=0;i<n;++i)
		{
			ans+=x[i];
		}
		cout<<fixed<<setprecision(9)<<ans;
		return 0;
	} 
	//定义函数z_i(lambda)
	auto z_i=[&](double lambda)->pair<double,double>//计算输出所有Z的总和sum_z和所有斜边的总和sum_hypo 
	{
		double sum_z=0,sum_hypo=0;
		double m=lambda/sqrt(1-lambda*lambda);
		for(long i=0;i<n;++i)
		{
			double z=min(y[i],x[i]*m);
			sum_z+=z;
			sum_hypo+=sqrt(x[i]*x[i]+z*z);
		}
		return {sum_z,sum_hypo};
	};
	//二分查找lambda，使得g(lambda)=S，即sum_z=S 
	double left=0,right=1-1e-12;
	for(int i=0;i<200;i++)
	{
		double mid=(left+right)/2;
		double sum_z=z_i(mid).first;
		if(sum_z<S)
		{
			left=mid;
		}
		else
		{
			right=mid;
		}
	}
	double lambda=(left+right)/2;
	double ans=z_i(lambda).second;
	cout<<fixed<<setprecision(9)<<ans;
	return 0;
}

