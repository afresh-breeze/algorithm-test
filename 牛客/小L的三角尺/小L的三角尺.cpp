/*
https://ac.nowcoder.com/acm/contest/120566/A
思路解析见附带文档 
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    long n,w;
    cin>>n>>w;
    vector<long long> x(n);
    vector<long long> y(n);
    for(long i=0;i<n;++i)
    {
    	cin>>x[i]>>y[i];
	}
	return 0;
}

