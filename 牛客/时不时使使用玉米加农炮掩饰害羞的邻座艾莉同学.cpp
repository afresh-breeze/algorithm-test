/*https://ac.nowcoder.com/acm/contest/120564/H
思路解析：
因为放有炸弹的坐标可以炸周围一片，所以可以给每个坐标一个数表示在此处放炮可以杀死的敌人数 
然后在增援后更新数组，并判断最大值
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;
	long q;
	cin>>n>>m>>q;
	vector<vector<long long>> b(n,vector<long long>(m,0));//可杀人数 
	int dr[]={0,0,0,1,-1,1,1,-1,-1,0,0,2,-2};
	int dc[]={0,1,-1,0,0,1,-1,1,-1,2,-2,0,0};//曼哈顿距离<=2的偏移量坐标 
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			long long a;
			cin>>a;
			if(a)//此处敌人不为0是会对周围的可杀人数产生贡献，把其贡献加进b 
			{
				for(int k=0;k<13;++k)
				{
					int r=i+dr[k];
					int c=j+dc[k];
					if(r>=0 && r<n && c>=0 && c<m)
					{
						b[r][c]+=a;
					}
				}
			}
		}
	 } 
	//找最大值
	long long _max=-1; 
	int _x,_y;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(b[i][j]>_max)
			{
				_max=b[i][j];
				_x=i+1;//注意题目不是从第0行开始的
				_y=j+1; 
			}
		}
	}
	//增援
	while(q--)
	{
		int x,y;
		long long z;
		cin>>x>>y>>z;
		x--;
		y--;
		for(int k=0;k<13;++k)
		{
			int r=x+dr[k];
			int c=y+dc[k];
			if(r>=0 && r<n && c>=0 && c<m)
			{
				b[r][c]+=z;
				if(b[r][c]>_max)
				{
					_max=b[r][c];
					_x=r+1;
					_y=c+1;
				}
			}
		}
		cout<<_x<<" "<<_y<<'\n';
		
	}
	return 0;
}
