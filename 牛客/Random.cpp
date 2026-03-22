/*
https://ac.nowcoder.com/acm/contest/120563/B
思路解析：
因为数组元素为独立均匀随机生成，所以可以直接暴力
注意求最大公约数函数的写法
*/

#include<iostream>
#include<vector>
using namespace std;

/*
求最大公约数函数（欧几里得算法） 
原理为 gcd(a,b)=gcd(b,a(mod b)) 
long long gcd(long long a,long long b)
{
	while(b)
	{
		long long tem=a%b;
		a=b;
		b=tem;
	}
	return a;
}
*/

long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
void solve()
{
	long n;
	cin>>n;
	vector<long long> a(n);
	for(long i=0;i<n;++i)
	{
		cin>>a[i];
	}
	bool p=false;//记录是否已找到 
	for(long i=0;i<n;++i)
	{
		for(long j=i+1;j<n;++j)
		{
			if(gcd(a[i],a[j])>1)
			{
				cout<<a[i]<<" "<<a[j]<<'\n';
				p=true;
				break;
			}
		}
		if(p)
		{
			break;
		}
	}
	if(!p)
	{
		cout<<-1<<'\n';
	}
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
