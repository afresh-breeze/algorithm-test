/*
https://ac.nowcoder.com/acm/contest/120564/C?by=history&from=kkframenew
思路解析：
格雷码（Gray Code），又称二进制反射码（Reflected Binary Code），是一种特殊的二进制编码方式。在格雷码中，任意两个相邻的数值，其二进制表示中只有一位不同。
格雷码同时也满足题目条件 
格雷码的第i项=i^(i>>1) 
*/
#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<(1<<n);++i)
	{
		cout<<(i^(i>>1))<<(i==(1<<n)-1?"":" ");// 注意<<的优先级高于 ^
	}
	return 0;
}
