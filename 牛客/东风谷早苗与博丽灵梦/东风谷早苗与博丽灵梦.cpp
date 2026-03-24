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
	}
	int128 d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}

//向下取整函数
int128 floor_div(int128 a,int128 b)
{
	if(a>=0)//正数直接除 
	{
		return a/b;
	}
	return (a-b+1)/b;
 } 
 //向上取整函数
 int128 ceil_div(int128 a,int128 b)
 {
 	if(a>=0)
 	{
 		return (a+b-1)/b;
	}
	return a/b;
  } 

void solve()
{
	long long _x,_a,_s;
	cin>>_x>>_a>>_s;
	int128 x=_x,a=_a,s=_s;
	int128 _c1,_c2;
	int128 g=exgcd(a,s,_c1,_c2);//返回值就是a,s的最大公约数 
	if(x%g)//不能整除则无解 
	{
		cout<<"No"<<'\n';
		return ;
	}
	//得到一组特解
	int128 c1_=_c1*(x/g);
	int128 c2_=_c2*(x/g);
	int128 step1=s/g;
	int128 step2=a/g;
	//确定通解中k的范围,使得c1,c2>=0
	//c1=c1_+k*step1，所以 k>=-c1_/step1，因为k为整数，所以k的最小值为 -c1_/step1 的向上取整 
	//同理可知，k的最小值是 c2_/step2 的向下取整 
	int128 l=ceil_div(-c1_,step1);
	int128 r=floor_div(c2_,step2);
	if(l>r)
	{
		cout<<"No"<<'\n';
		return ;
	}
	//最小化max(c1,c2)
	//c1(k)是关于k的递增函数，c2(k)是递减函数,s所以最小值一定出现在两者交点附近
	//c1=c2 -> c1_+k*step1=c2_-k*step2
	//k=c2_-c1_/(step1+step2) ，这个k是个理想值，因为它可能是小数，于是我们要检查离它最近的两个整数，并且确保这两个整数在[l,r]范围内
	int128 k1=floor_div(c2_-c1_,step1+step2);
	int128 k2=ceil_div(c2_-c1_,step1+step2);
	int128 _k[]={l,r,k1,k2};//待选名单
	int128 k_=l;
	int128 res=-1;
	for(int128 k:_k)
	{
		if(k<l)//判断不能超过边界 
		{
			k=l;
		}
		if(k>r)
		{
			k=r;
		}
		int128 c1=c1_+k*step1;
		int128 c2=c2_-k*step2;
		int128 _max=(c1>c2?c1:c2);
		if(res==-1||_max<res)
		{
			res=_max;
			k_=k;
		}
	 } 
	cout<<"Yes"<<'\n';
	long long c1=(long long)(c1_+k_*step1);
	long long c2=(long long)(c2_-k_*step2);//因为int128不支持cout，于是进行强转 
	cout<<c1<<" "<<c2<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
