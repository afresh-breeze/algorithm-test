/*
https://ac.nowcoder.com/acm/contest/120563/I
思路解析：
对于c中每一个元素c[i]，有a[i]和b[i]两种选择，因为 a^a^b=b ，可以先默认全部选a，然后把 a[i]^b[i] 当成一个元素，运用线性基进行求解。
【线性基】 
 线性基是原始集合 S 的一个最小化的子集 B，它与原集合 S 有着相同的“异或张成空间”。也就是说，原集合 S 能异或出的任何数，都可以通过线性基 B 中的元素异或出来，反之亦然。 
 线性基最核心的操作就是 insert(x)，即向基中插入一个数 x。它的构造过程非常巧妙，利用了异或的性质。
我们通常用一个数组 p[] 来表示线性基，其中 p[i] 存储的是一个“基向量”，这个基向量的最高位恰好是第 i 位。如果 p[i] = 0，说明我们还没有一个最高位是 i 的基。
插入过程 insert(x)：
我们从高位到低位遍历 x 的二进制表示（例如，从第 62 位到第 0 位，对于 long long 类型）。
1.检查 x 的第 i 位是否为 1。
2.如果第 i 位是 0，我们就不关心这一位，继续看下一位（i-1）。
3.如果第 i 位是 1，这时有两种情况：
情况A：p[i] 为 0。 这意味着我们找到了一个新的、无法被现有基表示的“方向”。我们就让 p[i] = x，然后直接结束插入过程。因为 x 已经被成功地加入到基中，成为了一个新的基向量。
情况B：p[i] 不为 0。 这意味着我们已经有一个最高位为 i 的基向量 p[i]。为了消去 x 的第 i 位，我们执行 x = x XOR p[i]。这样操作后，新的 x 的第 i 位必然为 0，并且它的最高位变得比 i 更低了。我们继续用这个新的、更小的 x 去尝试插入到更低的位。
4.如果遍历完所有位，x 变成了 0，这意味着 x 完全可以由现有的基向量异或表示出来，我们不需要做任何事，插入过程结束。

于是我们可以由线性基尝试约简目标数，如果无法将目标数插入线性基，则可以异或出目标数。
在本题中，还需要进行记录——如何约简，用了哪些数。
于是我们创建一个数组m记录每一个p[i]的来时路，具体方式见代码。 

注意：因题目数据范围原因采用long、30的大小和范围，若数据较大用long long和62 
*/
#include<iostream>
#include<vector>
using namespace std;

void solve()
{
	long n;
	cin>>n;
	vector<long> a(n);
	vector<long> b(n);
	long sum=0;
	for(long i=0;i<n;++i)
	{
		cin>>a[i];
		sum^=a[i];//sum就是目标数 
	}
	for(long i=0;i<n;++i)
	{
		cin>>b[i];
	}
	//开始插入线性基
	vector<long> p(30,0);//线性基 
	vector<long> pos(30,0);//原始编号 
	vector<long> m(30,0);//线性基元素的组成成分 
	for(long i=0;i<n;++i)
	{
		long s=a[i]^b[i];//尝试插入的元素 
		long _m=0;//辅助记录组成成分的临时变量 
		for(long j=29;j>=0;--j)
		{
			if(s>>j&1)
			{
				if(!p[j])
				{
					p[j]=s;//成功插入
					m[j]=_m^(1LL<<j);//1LL是把1强转成long long
					//m记录数据的原理就是，最高位为j的线性基，其本身记录为m[j]的二进制第j位为1，若在插入之前异或了其他线性基，则会把其他线性基的m异或进去，从而记录其组成成分 
					pos[j]=i;//记录原始编号
					break;//成功插入后关注下一个待插入元素 
				}
				else
				{
					s^=p[j];
					_m^=m[j];//更新组成成分 
				}
			}
		}
	 } 
	long ans=0;
	//尝试插入目标数sum 
	for(int i=29;i>=0;--i)
	{ 
		if(sum>>i&1)
		{
			if(!p[i])
			{
				cout<<-1<<'\n';//如果可以插入则无法异或出sum
				return ;//直接结束程序 
			}
			sum^=p[i];
			ans^=m[i];//ans通过组成成分记录哪些位的a要换成b
		}
	}
	vector<long> c=a;
	for(int i=0;i<30;++i)
	{
		if(ans>>i&1)
		{
			c[pos[i]]=b[pos[i]];
		}
	}
	for(int i=0;i<n;++i)
	{
		cout<<c[i]<<(i==n-1?"":" ");
	}
	cout<<'\n';
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
