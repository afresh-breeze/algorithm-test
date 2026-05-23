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
			if(dp[i][j])
			{
				int x1=max(0,j-a[i]);
				dp[i+1][x1]=true;//在下一轮操作中，x的起始值可以为x1 
			}
		}
	}
	return 0;
}
