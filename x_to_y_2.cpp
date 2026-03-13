/*
https://www.nowcoder.com/practice/7c658c72c26643d681546085aa6dcd8b
思路解析：
x/2能去掉最高位的1
x|z能将某些0变成1 （不能把1变成0） 
为了让x变成y，必须将x不断去除高位1直到x是y的子集，即x二进制位的1全部包含在y的二进制1里面
代码表示：x|y==y 
*/


#include<iostream>
using namespace std;

void solve()
{
	long long x,y;
	cin>>x>>y;
	if(x==y)//相等情况 
	{
		cout<<0<<'\n';
		return ;
	}
	int n=0;//次数 
	while(true)
	{
		if((x|y)==y)//可以得到结果 
		{
			if(x==y)
			{
				cout<<n<<'\n';
			}
			else
			{
				cout<<n+1<<'\n';//不相等则需要进行一次操作2 
			}
			return ;
		}
		x/=2;//不能得到结果则反复进行操作1
		n++; 
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
