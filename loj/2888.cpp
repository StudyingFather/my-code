// Problem : #2888. 「APIO2015」巴邻旁之桥 Palembang Bridges
// Contest : LibreOJ
// URL : https://loj.ac/problem/2888
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int k,n;
namespace sub1
{
 int a[200005],cnt;
 void solve()
 {
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
   string s,t;
   int x,y;
   cin>>s>>x>>t>>y;
   if(s==t)
    ans+=abs(x-y);
   else
    ans++,a[++cnt]=x,a[++cnt]=y;
  }
  sort(a+1,a+cnt+1);
  int pos=a[cnt/2];
  for(int i=1;i<=cnt;i++)
   ans+=abs(a[i]-pos);
  cout<<ans<<endl;
 }
}
namespace sub2
{
 struct point
 {
  int x,y;
  bool operator<(const point&a)const
  {
   return x+y<a.x+a.y;
  }
 }a[100005];
 int cnt;
 long long pre[100005],post[100005];
 priority_queue<int> q1;
 priority_queue<int,vector<int>,greater<int> > q2;
 void solve()
 {
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
   string s,t;
   int x,y;
   cin>>s>>x>>t>>y;
   if(s==t)
    ans+=abs(x-y);
   else
    ans++,a[++cnt].x=x,a[cnt].y=y;
  }
  sort(a+1,a+cnt+1);
  long long s1=0,s2=0;
  for(int i=1;i<=cnt;i++)
  {
   q1.push(a[i].x),q1.push(a[i].y);
   s1+=a[i].x,s1+=a[i].y;
   int u=q1.top();
   q1.pop(),s1-=u;
   q2.push(u),s2+=u;
   if(q1.top()>q2.top())
   {
    int x=q1.top(),y=q2.top();
    q1.pop(),q2.pop();
    q1.push(y),q2.push(x);
    s1+=y-x,s2+=x-y;
   }
   pre[i]=s2-s1;
  }
  while(!q1.empty())
   q1.pop();
  while(!q2.empty())
   q2.pop();
  s1=0,s2=0;
  for(int i=cnt;i;i--)
  {
   q1.push(a[i].x),q1.push(a[i].y);
   s1+=a[i].x,s1+=a[i].y;
   int u=q1.top();
   q1.pop(),s1-=u;
   q2.push(u),s2+=u;
   if(q1.top()>q2.top())
   {
    int x=q1.top(),y=q2.top();
    q1.pop(),q2.pop();
    q1.push(y),q2.push(x);
    s1+=y-x,s2+=x-y;
   }
   post[i]=s2-s1;
  }
  long long sum=(cnt?1e18:0);
  for(int i=1;i<cnt;i++)
   sum=min(sum,pre[i]+post[i+1]);
  cout<<ans+sum<<endl;
 }
}
int main()
{
 cin>>k>>n;
 if(k==1)sub1::solve();
 else sub2::solve();
 return 0;
}