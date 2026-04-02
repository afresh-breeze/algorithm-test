/*
https://ac.nowcoder.com/acm/contest/120565/E
思路解析：
实际上我们要找到一对l,r，使S(l,r)最大
设pre[i]为前i个元素的累加和取模结果
则S(l,r)=(pre[r]-pre[l-1]+p)%p 
对于每一个r，我们想要找到一个l-1<r使得S(l,r)最大
于是有两种情况：
pre[r]>= pre[l-1] -> S(l,r)=pre[r]-pre[l-1]  -> pre[l-1]越小越好，即找到所有目前出现过的前缀和的最小值 
pre[r]<pre[l-1]   -> S(l,r)=pre[r]-pre[l-1]+p  -> pre[r]-pre[l-1]负得越小越好，即找到第一个大于pre[r]的pre[l-1] 

接下来我们对当前已有的前缀进行上述两种查找（用set实现），对max进行覆盖
对每个r查找后得到的max就是最后结果
注意同时需要覆盖记录下标 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//为了在set内部同时记录下标，定义一个结构体类型
struct Node
{
	long long val;//值
	long long idx;//下标
	//重载<用于set排序
	bool operator<(const Node& other) const
	{
		if(val!=other.val)//先比较值 
		{
			return val<other.val;
		}
		return idx<other.idx;//值一样就比较下标 
	 } 
 };

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,p;
    cin>>n>>p;
    vector<long long> a(n);
    for(long long i=0;i<n;++i)
    {
    	cin>>a[i];
	}
	set<Node> pre;
	pre.insert({0,-1});//pre[-1]=0
	long long cur=0;//当前pre，一直累加
	long long _max=-1;
	long long l=0,r=0; 
	for(long long i=0;i<n;++i)//一个一个找 
	{
		cur=(cur+a[i])%p;
		//情况一
		auto it1=pre.begin();//当前最小的pre
		long long val1=(cur-it1->val)%p;
		if(val1>_max)//如果更大就进行覆盖 
		{
			_max=val1;
			l=it1->idx+1;
			r=i;
		}
		//情况二
		auto it2=pre.upper_bound({cur,n+1});//找比cur大一点的，找不到就找下标大于n+1的，即返回无效迭代器
		if(it2!=pre.end())//如果找到了
		{
			long long val2=(cur-it2->val +p)%p;
			if(val2>_max)
			{
				_max=val2;
				l=it2->idx+1;
				r=i;
			}
		} 
		pre.insert({cur,i});//加进pre 
	}
	cout<<l<<" "<<r<<" "<<_max;
	return 0;
}
