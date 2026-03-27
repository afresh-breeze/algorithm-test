/*
https://ac.nowcoder.com/acm/contest/120564/G
思路解析：
如果数字中有0，则一次就没了 
如果数字中有1，实际上不会对答案造成任何影响。
如果数字中有5，那么它后续变化中一定都有0/5，且数位中一旦出现偶数，就会变0，导致快速结束。
如果数字中有4/6/8/9，其贡献相当于2*2/2*3/2*2*2/3*3
所以可以把一个数字的第一次f(x)看成 2^x*3^y*7^z （^表示次方），求出x,y,z后还原成6/7/8/9（多余的2,3保留即可）
要使数字不超过10^18，即不超过18位，把判断条件转化为x/3+y/2+z<=18 
我们通过暴力搜索找到符合条件的两组x,y,z值即可（思路有多种，此处只给出一种） 
注意：虽然要求不大于10^18，但搜索过程中会远远超出，需要使用int128，具体关于int128的md文件在东风谷早苗与博丽灵梦文件夹中  
*/
#include<iostream>
using namespace std;
typedef __int128_t int128; 
int128 f(int128 x)
{
    int128 res=1;
    while(x)
    {
        res*=x%10;
        x/=10;
    }
    return res;
}

int128 _pow(int128 a,int b)//pow函数精度和范围不符合要求，需要自己写一个快速幂（带注释的快速幂在A+B Problem中） 
{
    if(b==0) return 1;
    int128 res=1;
    while(b)
    {
        if(b&1)
        {
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int128 m;
    int x,y,z;
    int max=0;
    int _x,_y,_z,x_,y_,z_;
    for(int x=0;x<=54;++x)//假如另外两个都为0，得出范围 
    {
        for(int y=0;y<=36;++y)
        {
            for(int z=0;z<=18;++z)
            {
                if(x/3.0+y/2.0+z>18.0) break;//如果此时超过范围，后续的z更大，也一定超过，所以直接break 
                m=_pow(2,x)*_pow(3,y)*_pow(7,z);
                int a=1;
                while(m/10)
                {
                    m=f(m);
                    a++;
                }
                if(a>max)
                {
                    _x=x;
                    _y=y;
                    _z=z;
                    max=a;
                }
                else if(a==max)//相当于取的是第一个最大值和最后一个最大值，因为x,y,z取值不一样，所以f(m)也不可能一样 
                {
                    x_=x;
                    y_=y;
                    z_=z;
                }
            }
        }
    }
    cout<<_x<<" "<<_y<<" "<<_z<<'\n';
    cout<<x_<<" "<<y_<<" "<<z_;
    return 0;
}
//运行结果是： 
//4 20 5
//19 4 6
//还原后为99999999998277777 888888299777777（数字可任意组合） 
//注意：因为题目只要结果，以上代码未优化效率不高 
//最终提交代码为： 
#include<iostream>
using namespace std;
int main()
{
    cout<<"99999999998277777 888888299777777";
    return 0;
}




