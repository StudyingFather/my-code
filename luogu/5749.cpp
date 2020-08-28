// Problem: P5749 [IOI2019]排列鞋子
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5749
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
using namespace std;
struct BIT
{
 int a[200005],n;
 void init(int n)
 {
  this->n=n;
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void add(int x,int y)
 {
  while(x<=n)
  {
   a[x]+=y;
   x+=lowbit(x);
  }
 }
 int sum(int x)
 {
  int ans=0;
  while(x)
  {
   ans+=a[x];
   x-=lowbit(x);
  }
  return ans;
 }
}tr;
int a[200005],vis[200005];
vector<int> p[200005];
int main()
{
 int n;
 long long ans=0;
 cin>>n;
 tr.init(2*n);
 for(int i=1;i<=2*n;i++)
 {
  cin>>a[i];
  a[i]+=n;
  p[a[i]].push_back(i);
  tr.add(i,1);
 }
 for(int i=2*n;i;i--)
 {
  if(vis[i])continue;
  int prep=*(--p[2*n-a[i]].end());
  ans+=tr.sum(i)-tr.sum(prep-1)-2;
  if(a[i]<n)ans++;
  vis[i]=1,vis[prep]=1;
  p[a[i]].pop_back();
  p[2*n-a[i]].pop_back();
  tr.add(i,-1),tr.add(prep,-1);
 }
 cout<<ans<<endl;
 return 0;
}