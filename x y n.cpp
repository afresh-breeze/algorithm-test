/*
https://ac.nowcoder.com/acm/contest/120562/F
思路解析：
x+y>=x^y>=|x-y|
前一个取=条件是x&y=0，后一个取=条件是x^y=y(x>y时) 
后一个推导：
x-y=x^y
x=(x^y)+y 
x=((x^y)^y)+(((x^y)&y)<<1)  //a+b=(a^b)+((a&b)<<1)
x=x+(((x^y)&y)<<1)
即 (x^y)&y=0 等式成立 
即 x&y=y  -> y为1的位x也必须为1，即y为x的子集 

为了保证x^y最小，首先x-y要最小，其次要满足第二个取等条件 
因为gcd(x,y)=n，所以x-y最小等于n，即取x=(a+1)*n,y=a*n
并满足(a+1)*n&a*n=a*n
当a*n+n=a*n^n时(条件为a*n&n=0 -> y&n=0 ),x=y^n,因为y和n完全不重叠，所以满足y是x的子集
于是最终把条件简化为a*n&n=0  
但直接判定此条件并a++效率很低会超时
需要进行进一步优化 
因为只需要构造出一个符合条件的a
所以可以把a定为2的k次倍，则a*n=n<<k，要使a*n&a=0，可以让a>n，即平移后a*n的最低位比n最高位还高 
*/
#include<iostream>
using namespace std;

void solve()
{
	long long n;
	cin>>n;
	long long a=1;
	while(a<=n)
	{
		a<<=1;
	}
	cout<<(a+1)*n<<" "<<a*n<<'\n';
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
