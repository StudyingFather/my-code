// Problem : P4774 [NOI2018]屠龙勇士
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4774
// Memory Limit : 500 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
long long a[100005],p[100005];
long long nswd[100005],c[100005];
multiset<long long> swd;
int n,m;
long long exgcd(long long a,long long b,long long&x,long long&y)
{
 if(b==0)
 {
  x=1,y=0;
  return a;
 }
 long long g=exgcd(b,a%b,x,y);
 int t=x;
 x=y;
 y=t-a/b*y;
 return g;
}
long long mul(long long x,long long y,long long p)
{
 long long ans=0;
 while(y)
 {
  if(y&1)ans=(ans+x)%p;
  x=(x+x)%p;
  y>>=1;
 }
 return ans;
}
namespace sub1//p_i maybe greater than a_i, but guaranteed p_i=1
{
 bool check()
 {
  bool flag=true;
  for(int i=1;i<=n;i++)
   flag&=(p[i]==1);
  return flag;
 }
 void solve()
 {
  long long ans=0;
  for(int i=1;i<=n;i++)
   ans=max(ans,(long long)((a[i]/c[i])+(a[i]%c[i]!=0)));
  cout<<ans<<endl;
 }
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  bool flag=true;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
   cin>>a[i];
  for(int i=1;i<=n;i++)
   cin>>p[i];
  for(int i=1;i<=n;i++)
   cin>>nswd[i];
  swd.clear();
  for(int i=1;i<=m;i++)
  {
   long long x;
   cin>>x;
   swd.insert(x);
  }
  for(int i=1;i<=n;i++)
  {
   auto it=swd.upper_bound(a[i]);
   if(it!=swd.begin())it--;
   c[i]=*it;
   swd.erase(it);
   swd.insert(nswd[i]);
  }
  long long ans=0,z=1;
  if(sub1::check())
  {
   sub1::solve();
   continue;
  }
  for(int i=1;i<=n;i++)
  {
   c[i]%=p[i],a[i]%=p[i];
   if(!c[i]&&a[i])
   {
    cout<<-1<<endl;
    flag=false;break;
   }
   if(!c[i]&&!a[i])continue;
   long long x,y;
   long long g=exgcd(c[i],p[i],x,y);
   if(a[i]%g)
   {
    cout<<-1<<endl;
    flag=false;break;
   }
   p[i]/=g;
   a[i]=mul(a[i]/g,(x%p[i]+p[i])%p[i],p[i]);
   g=exgcd(z,p[i],x,y);
   if((a[i]-ans)%g)
   {
    cout<<-1<<endl;
    flag=false;break;
   }
   z=z/g*p[i];
   ans=(ans+mul(mul(z/p[i],((a[i]-ans)%z+z)%z,z),(x%z+z)%z,z))%z;
  }
  if(flag)cout<<ans<<endl;
 }
 return 0;
}