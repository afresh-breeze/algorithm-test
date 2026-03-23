/*
https://ac.nowcoder.com/acm/contest/120564/D
思路解析： 
本题就是要找出 a*c1+s*c2=x 使max(c1,c2)最小化的解 
使用扩展欧几里得算法求出方程 a*c1+s*c2=gcd(a,s) 的一组特解。
通过裴蜀定理判断是否有解：如果 x 不能被 gcd(a,s) 整除，则无解，输出 No。
如果有解，将特解放大得到 a*c1+s*c2=x 的一组特解 (c1',c2')。
利用通解公式表示所有解
由于 f(k)=max(c1(k), c2(k)) 是一个关于 k 的下凸函数（V形），其最小值出现在 c1=c2 的附近。我们只需检查 k 在范围内的端点以及使 c1 与 c2 最接近的整数 k 即可。
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int128_t int128;//__int128 是一种非标准的整数类型，由 GCC 和 Clang 等编译器提供，旨在处理超过 64 位整数范围的计算，缺点是需要手写输入输出函数，具体见附带文档 

//扩展欧几里得算法，详见文档 
int128 exgcd(int128 a,int128 b,int128 &x,int128 &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
		int128 d=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
		return d;
	}
}

void solve()
{
	long long _x,_a,_s;
	cin>>_x>>_a>>_s;
	int128 x=_x,a=_a,s=_s;
	int128 _c1,_c2;
	if(x%g)
	{
		cout<<"No"<<'\n';
		return ;
	}
	//得到一组特解
	 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
