/*
https://ac.nowcoder.com/acm/contest/120565/E
思路解析：
实际上我们要找到一对l,r，使S(l,r)最大
设pre[i]为前i个元素的累加和取模结果
则S(l,r)=(pre[r]-pre[l-1]+p)%p 
对于每一个r，我们想要找到一个l-1<r使得S(l,r)最大
于是有两种情况：
pre[r]>= pre[l-1] -> S(l,r)=pre[r]-pre[l-1]
pre[r]<pre[l-1]   -> S(l,r)=pre[r]-pre[l-1]+p 
*/
