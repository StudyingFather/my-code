#include <iostream>
#include <algorithm>
using namespace std;
struct bit
{
 int n,a[100005];
 void init(int N)
 {
  n=N;
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
}tr1,tr2;
int a[100005],b[100005],l[100005],r[100005];
int main()
{
 int n,ans=0;
 cin>>n;
 tr1.init(n),tr2.init(n);
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  b[i]=a[i];
 }
 sort(b+1,b+n+1);
 for(int i=1;i<=n;i++)
 {
  int x=n+1-(lower_bound(b+1,b+n+1,a[i])-b);
  l[i]=tr1.sum(x);
  tr1.add(x,1);
 }
 for(int i=n;i;i--)
 {
  int x=n+1-(lower_bound(b+1,b+n+1,a[i])-b);
  r[i]=tr2.sum(x);
  tr2.add(x,1);
 }
 for(int i=1;i<=n;i++)
 {
  int x=min(l[i],r[i]),y=max(l[i],r[i]);
  ans+=(x*2<y);
 }
 cout<<ans<<endl;
 return 0;
}