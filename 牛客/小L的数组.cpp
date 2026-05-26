/*
https://ac.nowcoder.com/acm/contest/120566/H
思路解析：
由题目易知，两种规则都不会让x大于ai或bi，所以x一定<2048 
于是我们定义一个bool类型的二维vector，横坐标表示操作次数，纵坐标表示此轮操作后x的值
即dp[i][j]=true代表第i轮操作后x可以为j
最后要求的则是横坐标为n、且值为true时最大的纵坐标 
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
	vector<vector<bool>> dp(2049,vector<bool>(2048,false));//注意n最大可为2048，横坐标最小要给到2049 
	dp[0][0]=true;
	for(int i=0;i<n;++i)//第i次操作 
	{
		for(int j=0;j<2048;++j)//j为x的值 
		{
			if(dp[i][j])//如果本轮x的值可以为j 
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
