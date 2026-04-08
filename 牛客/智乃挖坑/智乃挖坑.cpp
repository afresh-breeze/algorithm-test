/*
https://ac.nowcoder.com/acm/contest/120565/I
思路解析：
深度增加 max(f-|j-p|,0) ，相当于给区间增加了一个等差数列
j=p+f和j=p-f时增量等于0，即挖坑只对[p-f+1,p+f-1]范围内的坐标产生影响
并且在j=p时达到最大，[p-f+1,p]单调递增，[p+1,p+f-1]单调递减
我们需要找到最早在第几次操作时挖穿边界，而操作的过程时单调叠加的，于是我们可以通过二分查找来找到临界值
即写一个check函数用于判断进行mid次操作能否挖穿边界，二分缩小mid范围
注意check函数的逻辑：如果每次都暴力模拟会超时，我们利用二阶差分数组来处理（二阶差分见附带文档）
单调递增和单调递减段范围处理：
差分最小要从第2项开始才有意义（A1单独处理），同时注意不能超出边界n，同时p+f虽然增量为0，对于前一格仍然-1
所以单增范围为 [max(2,p-f+1),min(n,p)] ，单减范围为 [max(2,p+1),min(n,p+f)] 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n,m,h;
	cin>>n>>m>>h;
	vector<long long> p(m),f(m);
	for(long long i=0;i<m;++i)
	{
		cin>>p[i]>>f[i];
	}
	vector<long long> D2(n+2);//二阶差分数组 
	//检查执行前mid次操作后是否挖穿（因调用数组较多，写成Lambda表达式比较方便）
	auto check=[&](long long mid){
		fill(D2.begin(),D2.end(),0);//每次清空数组
		long long A1=0;//单独维护位置1的数据
		for(long long i=0;i<mid;++i)
		{
			long long _p=p[i];
			long long _f=f[i];
			A1+=max(0LL,_f-(_p-1));//A1直接累加
			//等差递增段
			long long l1=max(2LL,_p-_f+1);
			long long r1=min(n,_p);
			if(l1<=r1)
			{
				D2[l1]+=1;
				D2[r1+1]-=1;
			}
			//等差递减段
			long long l2=max(2LL,_p+1);
			long long r2=min(n,_p+_f);
			if(l2<=r2)
			{
				D2[l2]-=1;
				D2[r2+1]+=1;
			} 
		}
		if(A1>h) return true;//直接判断A1
		long long d=0,a=A1;
		for(long long j=2;j<=n;++j)
		{
			d+=D2[j];
			a+=d;//两次前缀和还原
			if(a>h) return true; 
		} 
		return false;
	};
	long long low=1,high=m,ans=-1;
	while(low<=high)//二分查找答案 
	{
		long long mid=low+(high-low)/2;
		if(check(mid))
		{
			ans=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(ans!=-1)
	{
		cout<<"Yes\n"<<ans<<'\n';
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
