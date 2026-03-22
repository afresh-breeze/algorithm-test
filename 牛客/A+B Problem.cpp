/*
https://ac.nowcoder.com/acm/contest/120561/A
思路解析： 
先处理分数取模：用快速幂和求逆元函数（进行概率运算除法时使用） 
计算每根灯管亮和不亮的概率并放在两个vector中
计算一个显示器显示出每个数字的概率并存放在一个vector中 
由于C的范围较小，可以枚举出一排数字为0-c的所有概率并放入一个vector 
计算符合条件的所有两排数字概率并相加 
*/

#include<iostream>
#include<vector>
using namespace std;
const int MOD=998244353;//记得随时取模防止超出范围 

//快速幂运算
long long _pow(long long a,long long b)
{
	long long n=1;
	a%=MOD;
	while(b)
	{
		if(b&1)//如果b的此二进制位为1，则n乘上对应权重的a 
		{
			n=(n*a)%MOD;
		}
		a=a*a%MOD;//将a变为下一次对应的权重
		b>>=1; 
	}
	return n;
}
//求逆元运算
long long inv(long long n)
{
	return _pow(n,MOD-2);
 } 

void solve()
{
	int c;
	cin>>c;
	vector<long long> p_on(8);//p虽然是概率，但经过分数取模后，是对MOD取模意义下的换算，其数值可能超过100，故用long long 
	vector<long long> p_off(8);
	long long inv100=inv(100);//避免重复运算 
	for(int i=0;i<7;++i)
	{
		cin>>p_on[i];
		p_on[i]=p_on[i]*inv100%MOD;//数据处理成概率 
		p_off[i]=(1-p_on[i]+MOD)%MOD;
	}
	//计算单个数字出现概率
	static const vector<vector<int>> s=//用static避免重复内存分配和数据拷贝 
	{{1,1,1,0,1,1,1},
	 {0,0,1,0,0,1,0},
	 {1,0,1,1,1,0,1},
	 {1,0,1,1,0,1,1},
	 {0,1,1,1,0,1,0},
	 {1,1,0,1,0,1,1},
	 {1,1,0,1,1,1,1},
	 {1,0,1,0,0,1,0},
	 {1,1,1,1,1,1,1},
	 {1,1,1,1,0,1,1}
	};
	vector<long long> p(10,1);
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<7;++j)
		{
			if(s[i][j])
			{
				p[i]=p[i]*p_on[j]%MOD;
			}
			else
			{
				p[i]=p[i]*p_off[j]%MOD;
			}
		}
	}
	//枚举一排数字为0-c的概率
	vector<long long> f(c+1,1);
	for(int i=0;i<=c;++i)
	{
		int d1=i/1000;//千位
		int d2=(i/100)%10;//百位 
		int d3=(i/10)%10;//十位
		int d4=i%10;//个位
		f[i]=p[d1]*p[d2]%MOD*p[d3]%MOD*p[d4]%MOD;
	}
	//计算结果
	long long res=0;
	for(int i=0;i<=c;++i)
	{
		res=(res+f[i]*f[c-i]%MOD)%MOD;
	 } 
	 cout<<res<<'\n';
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
