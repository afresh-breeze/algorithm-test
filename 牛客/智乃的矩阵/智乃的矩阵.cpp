/*
https://ac.nowcoder.com/acm/contest/120565/H
思路解析： 
这题只需要检查 3 类条件：
1. 总和能不能被 $n^2$ 整除；
2. 黑/白格总和是否等于 黑/白格数量 * x；
3. 每一行、每一列的和的奇偶性是否等于 (n * x) % 2。
全部满足就是 Yes，否则 No。
具体分析及证明过程见附带文档 
*/
#include<iostream>
#include<vector>
using namespace std;
long long mod(long long x)
{
	x%=2;
	if(x<0)
	{
		x+=2;
	}
	return x;
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<long long>> a(n,vector<long long>(n));
    long long sum=0;
    long long blacksum=0,whitesum=0;
    long long blackcnt=0,whitecnt=0;
    vector<long long> rowsum(n,0),colsum(n,0);
    for(int i=0;i<n;++i)
    {
    	for(int j=0;j<n;++j)
    	{
    		cin>>a[i][j];
    		sum+=a[i][j];
    		rowsum[i]+=a[i][j];
    		colsum[j]+=a[i][j];
    		if((i+j)&1)
    		{
    			whitesum+=a[i][j];
    			whitecnt++;
			}
			else
			{
				blacksum+=a[i][j];
				blackcnt++;
			}
		}
	}
	long long total=1LL*n*n;
	//条件1 
	if(sum%total)
	{
		cout<<"No\n";
		return 0;
	}
	long long x=sum/total;
	//条件2 
	if(blacksum!=blackcnt*x)
	{
		cout<<"No\n";
		return 0;
	}
	if(whitesum!=whitecnt*x)
	{
		cout<<"No\n";
		return 0;
	}
	//条件3
	long long target=mod(1LL*n*x);
	for(int i=0;i<n;++i)
	{
		if(mod(rowsum[i])!=target)
		{
			cout<<"No\n";
			return 0;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(mod(colsum[i])!=target)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}
