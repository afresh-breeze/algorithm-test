/*
https://ac.nowcoder.com/acm/contest/120565/F
思路解析：
实际上有三种选择：
长度2 值b
长度7 值a
长度8 值a+b
当长度为56的倍数时，可以全填其中一种，看哪个值最高即可
长度不为56的倍数时，就需要留一部分进行dp（注意不能只留n%56，因为最优解可能需要稍微多一点空间进行灵活组合，所以我们保留n%56+56的长度）
于是就可以分为两种情况，一种是n本身就很小，我们直接进行dp
一种是n很大，前面大部分我们全选其中一种，后面的n%56+56这部分进行dp 
备注：另一详细dp在Blackboard 
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve()
{
	long long n,a,b;
	cin>>n>>a>>b;
	//计算长度为56的三种单一方式填充的最优方案
	long long v=max({28*b,8*a,7*(a+b)}); 
	//n较小时，取150
	if(n<=150)
	{
		vector<long long> dp(n+1,0);//填充前n项得到的最大值
		for(int i=1;i<=n;++i)
		{
			dp[i]=dp[i-1];//什么都不填时最大值没有增多，直接继承 
			if(i>=2)//足以放下td 
			{
				dp[i]=max(dp[i],dp[i-2]+b);//直接继承或是最后两个位置换成td 
			}
			if(i>=7)
			{
				dp[i]=max(dp[i],dp[i-7]+a);//前一个判断的结果和最后7项变成qcjjkkt的放法进行比较 
			}
			if(i>=8)
			{
				dp[i]=max(dp[i],dp[i-8]+a+b);//前一个判断的结果和最后8项变成qcjjkktd的放法进行比较 
			}
		} 
		cout<<dp[n]<<'\n';
	} 
	else
	{
		long long k=n/56-1;//前面要填k组56
		long long r=(n%56)+56;//剩下要进行dp的部分
		vector<long long> dp(r+1,0);
		for(int i=1;i<=r;++i)
		{
			dp[i]=dp[i-1];
			if(i>=2) dp[i]=max(dp[i],dp[i-2]+b);
			if(i>=7) dp[i]=max(dp[i],dp[i-7]+a);
			if(i>=8) dp[i]=max(dp[i],dp[i-8]+a+b);
		} 
		cout<<k*v+dp[r]<<'\n'; 
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	long long t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
