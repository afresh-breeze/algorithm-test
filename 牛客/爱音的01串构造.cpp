/*
https://ac.nowcoder.com/acm/contest/120564/F
思路解析： 
mex:子串无0，mex=0
	子串有0无1，mex=1
	子串有0有1，mex=2
字符串总长度n=a+b
总mex=(mex为1的子串数)*1+(mex为2的子串数)*2
	 =(包含0的子串数)+(同时包含0和1的子串数) 
f(0s)为仅由0组成的子串数量
f(1s)为仅由1组成的子串数量
总子串数T=n*(n+1)/2
包含0的子串数=T-f(1s)
同时包含0和1的子串数=T-f(0s)-f(1s)
总mex=2T-f(0s)-2*f(1s)
所以题目要求转化为最小化 f(0s)+2*f(1s)  （也可以直接想成理想情况是每个子串都是2，但是纯1和纯0都会有损失，损失量为此式）
因为相同的字符连在一起产生的“纯字符子串”的数量是呈平方级增长，所以我们切分得越均匀越好
1和0中少的字符孤立存在将另一字符尽可能均匀切分 
*/
#include<iotream>
#include<string>
using namespace std;

void solve()
{
	long long a,b;
	cin>>a>>b;
	if(a>b)
	{
		long long k=b+1;//切成多少份
		long long q=a/k;//每份多少个
		long long r=a%k;//剩多少个，分到前r组去
		for(long long) 
	}
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
