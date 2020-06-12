// Problem : P2519 [HAOI2011]problem a
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P2519
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
struct seg
{
 int l,r,v;
 seg(int L,int R,int V)
 {
  l=L,r=R,v=V;
 }
 seg(){}
 bool operator==(const seg&a)const
 {
  return l==a.l&&r==a.r&&v==a.v;
 }
}a[100005],b[100005];
int f[100005],cnt;
bool cmp1(const seg&a,const seg&b)
{
 return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
bool cmp2(const seg&a,const seg&b)
{
 return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x,y;
  cin>>x>>y;
  a[i].l=x+1,a[i].r=n-y;
 }
 sort(a+1,a+n+1,cmp1);
 for(int i=1;i<=n;i++)
 {
  if(a[i].l>a[i].r)continue;
  if(a[i]==a[i-1])
   b[cnt].v=min(b[cnt].v+1,b[cnt].r-b[cnt].l+1);
  else
  {
   cnt++;
   b[cnt].l=a[i].l,b[cnt].r=a[i].r,b[cnt].v=1;
  }
 }
 sort(b+1,b+cnt+1,cmp2);
 for(int i=1;i<=cnt;i++)
 {
  int p=lower_bound(b+1,b+i,seg(0,b[i].l,0),cmp2)-b-1;
  f[i]=max(f[i-1],f[p]+b[i].v);
 }
 cout<<n-f[cnt]<<endl;
 return 0;
}