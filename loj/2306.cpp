#include <cmath>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 100005
using namespace std;
const int p=100000;
struct vegetable
{
 long long a,s,c,x;
}a[MAXN];
struct node
{
 long long val;
 int u;
 bool operator<(const node&a)const
 {
  return val<a.val;
 }
 bool operator>(const node&a)const
 {
  return val>a.val;
 }
};
bool vis[MAXN];
long long ans[MAXN],s[MAXN];
priority_queue<node> q1;
priority_queue<node,vector<node>,greater<node> > q2;
queue<int> q;
vector<int> v[MAXN];
int main()
{
 int n,m,k;
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
  cin>>a[i].a>>a[i].s>>a[i].c>>a[i].x;
 for(int i=1;i<=n;i++)
  if(!a[i].x)v[p].push_back(i);
  else v[min(p,int(ceil(1.0*a[i].c/a[i].x)))].push_back(i);
 for(int i=p;i;i--)
 {
  for(int j=0;j<v[i].size();j++)
   q1.push({a[v[i][j]].a+a[v[i][j]].s,v[i][j]});
  if(q1.empty())continue;
  long long rem=m;
  while(rem)
  {
   if(q1.empty())break;
   int u=q1.top().u;
   long long val=q1.top().val;
   q1.pop();
   if(!vis[u])
   {
    vis[u]=1,ans[p]+=val,s[u]++,rem--;
    if(a[u].c!=1)q1.push({a[u].a,u});
   }
   else
   {
    long long num=a[u].c-s[u]-(i-1)*a[u].x;
    long long used=min(num,rem);
    ans[p]+=used*val;s[u]+=used;rem-=used;
    if(s[u]!=a[u].c)q.push(u);
   }
  }
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   q1.push({a[u].a,u});
  }
 }
 long long tot=0;
 for(int i=1;i<=n;i++)
 {
  if(s[i]==1)q2.push({a[i].a+a[i].s,i});
  else if(s[i])q2.push({a[i].a,i});
  tot+=s[i];
 }
 for(int i=p-1;i;i--)
 {
  ans[i]=ans[i+1];
  if(tot<=m*i)continue;
  long long rem=tot-m*i;
  while(rem)
  {
   if(q2.empty())break;
   int u=q2.top().u;
   long long val=q2.top().val;
   q2.pop();
   if(s[u]!=1)
   {
    long long used=min(rem,s[u]-1);
    s[u]-=used,rem-=used,ans[i]-=used*val;
    if(s[u]==1)q2.push({a[u].a+a[u].s,u});
    else q2.push({a[u].a,u});
   }
   else
    rem--,s[u]--,ans[i]-=val;
  }
  tot=m*i;
 }
 while(k--)
 {
  int t;
  cin>>t;
  cout<<ans[t]<<endl;
 }
 return 0;
}