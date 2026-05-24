/*
https://ac.nowcoder.com/acm/contest/120566/H
思路解析：
 
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a(2048);
	vector<int> b(2048);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;++i)
	{
		cin>>b[i];
	}
	vector<vector<bool>> dp(2048,false));
	dp[0][0]=true;
	for(int i=0;i<n;++i)//第i次操作 
	{
		for(int j;j<2048;++j)//j为x的值 
		{
			if(dp[i][j])//如果本轮x的起始值可以为j 
			{
				int x1=max(0,j-a[i]);
				dp[i+1][x1]=true;//在下一轮操作中，x的起始值可以为x1 
				int x2=j^b[i];
				dp[i+1][x2]=true;//在下一轮操作中，x的起始值可以为x2
			}
		}
	}
	for(int i=2047;i>=0;--i)//找第n轮操作后最大的x 
	{
		if(dp[n][i])
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
