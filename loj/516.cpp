// Problem: #516. 「LibreOJ β Round #2」DP 一般看规律
// Contest: LibreOJ
// URL: https://loj.ac/problem/516
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct query
{
 int x,y;
}q[100005];
int cnt,v[300005],a[100005];
set<int> s[300005];
int ans=(1ll<<31)-1;
void merge(int x,int y)
{
 if(s[x].size()>s[y].size())swap(s[x],s[y]);
 for(auto p:s[x])
 {
  auto it=s[y].insert(p).first,it1=it;
  if(it!=s[y].begin())
  {
   it--;
   ans=min(ans,p-(*it));
  }
  it1++;
  if(it1!=s[y].end())
   ans=min(ans,(*it1)-p);
 }
 s[x].clear();
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i],v[++cnt]=a[i];
 for(int i=1;i<=m;i++)
  cin>>q[i].x>>q[i].y,v[++cnt]=q[i].x,v[++cnt]=q[i].y;
 sort(v+1,v+cnt+1);
 cnt=unique(v+1,v+cnt+1)-v-1;
 for(int i=1;i<=n;i++)
 {
  a[i]=lower_bound(v+1,v+cnt+1,a[i])-v;
  s[a[i]].insert(i);
 }
 for(int i=1;i<=m;i++)
 {
  q[i].x=lower_bound(v+1,v+cnt+1,q[i].x)-v;
  q[i].y=lower_bound(v+1,v+cnt+1,q[i].y)-v;
 }
 for(int i=1;i<=m;i++)
 {
  int x=q[i].x,y=q[i].y;
  if(!s[x].size()||x==y)
   cout<<ans<<endl;
  else if(!s[y].size())
   cout<<ans<<endl,s[y]=s[x],s[x].clear();
  else
  {
   merge(x,y);
   cout<<ans<<endl;
  }
 }
 return 0;
}