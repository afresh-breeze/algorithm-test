/*
https://ac.nowcoder.com/acm/contest/120561/H
思路解析：
a+b=(a|b)+(a&b) -> a|b是有1为1  a&b是都1为1  a+b是都1进1、单1为1 
所以a|b <= a+b ，相等条件为 a&b=0 
可以采用dp动态规划，计算前n项有几种方案dp[n]，再定义dp[]的前缀和s[] 
对于每一项dp[i]，从第i项从后往前找第一个和后面所有数二进制位1有冲突的数的位置j，则第j位之后的位都是合法的（即寻找最远的合法起点），此时，所有合法起点的范围是[j+1,i-1] 
所以dp[i]=dp[j+1]+...+dp[i-1]=s[i-1]-s[j] 
理解：要把前i个数分好，我可以把最后一段分得长一点或短一点。只要最后这一段是合法的，我就把前面剩下的那部分的所有可能性都加起来 

扩展： 
a+b+c = (a|b|c) + ((a&b) | (a&c) | (b&c)) + (a&b&c)
a1|a2|...|an = a1+a2+...+an的充要条件是：任意两个数之间都没有共同的 1，即任意i!=j  ai&aj=0 
*/
#include<iostream>
#include<vector>
const int MOD=998244353;
using namespace std;

void solve()
{
	long long n;
	cin>>n;
	vector<long long> a(n);
	vector<int> pre(n);//预处理一个pre，记录上一个a(n)中不为0的元素的编号，这样在从后往前找j时就可以直接跳过0，因为0一定满足条件 
	int last=-1;//第0个指向-1，后续会对此进行处理 
	for(long long i=0;i<n;++i)
	{
		cin>>a[i];
		pre[i]=last;
		if(a[i])
		{
			last=i;//把last更新为不为0的元素的坐标，这样就可以形成一个“错位直通车” 
		}
	}
	vector<long long> dp(n+1,1);//dp[0]=1，对应不擦黑板
	vector<long long> s(n+1,1);//s[0]=1
	for(long long i=1;i<=n;++i)//从1开始
	{
		//找j
		long long j=i-1;
		long long sum=0;
		while(j>=0 && (a[j]&sum)==0)
		{
			sum|=a[j];
			j=pre[j];//更新j的坐标为前一个不为零的a中元素的下标 
		}
		if(j+1==0)//即j直接找到了最前面
		{
			dp[i]=s[i-1]%MOD;
		} 
		else
		{
			dp[i]=(s[i-1]-s[j]+MOD)%MOD;
		}
		s[i]=(s[i-1]+dp[i])%MOD;//更新s[i] 
	} 
	cout<<dp[n]<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
