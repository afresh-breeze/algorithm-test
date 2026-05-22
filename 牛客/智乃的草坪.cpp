/*
https://ac.nowcoder.com/acm/contest/120565/C
思路解析：
明显观察到，纵坐标为r(-r)的点最难被覆盖，可以想象，如果所有y=r(-r)的坐标都被覆盖，则草坪一定被完全覆盖 
覆盖条件为 (x-p_i)^2+r^2<=(v_i*t)^2
即 |x-p_i|<=sqrt((v_i*t)^2-r^2) (v_i*t必须>=r)
设d_i=sqrt((v_i*t)^2-r^2)，则固定时间t后每个有用喷头会对应一个在x轴上的区间 [p_i-d_i,p_i+d_i]
于是问题变成了——能否从这些区间里面选不超过k个，使它们的并覆盖整个[0,c]
显然答案具有单调性，时间t能够覆盖，大于t的时间必然能够覆盖
于是我们使用二分查找
此时难点在于编写check(t)函数判断固定时间t是否可行
首先我们求出所有可用区间放进一个动态segs数组，并按照左端点大小排序
接下来： 
设当前已经覆盖到 cur
每次在所有 l_i<=cur 的区间中，选右端点最大的那个，把覆盖推进到最远
这样选一次就相当于启用一个喷头
如果最终能覆盖到 c，且用了不超过 k 个，就可行
 
注意：浮点数比较最好带上eps避免浮点误差卡边界，本题代码未使用 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct Sprinkler
{
	double p,v;
};
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    double r,c;//最后的时间可能是小数，所以此处用double便于后续计算 
    cin>>n>>k>>r>>c;
    vector<Sprinkler> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].p >> a[i].v;
    }
    //检查在时间为t时，能否用不超过k个喷头覆盖整个[0,c]
    auto check=[&](double t)->bool
	{
		vector<pair<double,double>> segs;//一个动态数组， 存储每个喷头在当下时间t下可用的覆盖区间 
		segs.reserve(n);//给segs预留空间 
		for(int i=0;i<n;++i)//计算每个喷头在x轴上能完整覆盖草坪高度的区间 
		{
			double radius=a[i].v*t;//当前时间下该喷头的喷水半径
			if(radius<r) continue;//如果半径连r都不到则该喷头在当前时间无用
			double dx=sqrt(radius*radius-r*r);
			double L=a[i].p-dx;//区间左端点
			double R=a[i].p+dx;//区间右端点
			segs.push_back({L,R});//存入segs数组 
		}
		if(segs.empty()) return false;//如果没有一个可用区间，则当前时间不行
		sort(segs.begin(),segs.end());//按左端点从小到大排序 
		//贪心覆盖[0,c] 
		double cur=0.0;//当前已经覆盖到的位置
		int used=0;//已经使用了多少个喷头
		int i=0;//扫描区间的指针
		int m=(int)segs.size();
		while(cur<c)//只要没覆盖到c，就继续选区间
		{
			double farthest=cur;//这一轮能扩展到的最远位置
			while(i<m && segs[i].first<=cur)//找左端点<=cur的，这样才能衔接上 
			{
				farthest=max(farthest,segs[i].second);//反复覆盖farthest 
				i++;
			} 
			if(farthest<=cur) return false;//这一轮没能正确推进，则出现了断层，当前时间不行
			cur=farthest;
			used++;
			if(used>k) return false;//超过k个喷头不合法 
		} 
		return true; 
	};
	double L=0,R=1;
	while(!check(R)) R*=2;//不断扩大r直到r可行
	//进行二分查找 
	for(int i=0;i<60;++i)//二分60次之后区间长度会缩小大约10^18倍，必然够用了；采用条件循环有风险，因为浮点数不是绝对精确 
	{
		double mid=(L+R)/2.0;
		if(check(mid))
		{
			R=mid;
		}
		else
		{
			L=mid;
		}
	} 
	cout<<fixed<<setprecision(10)<<r;//控制精度（不控制在本题也可以） 
	return 0;
}
