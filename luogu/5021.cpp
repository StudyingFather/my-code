#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct node
{
 int v,w,next;
}e[100005];
int head[50005],n,m,cnt;
int res,f[50005];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int dfs(int u,int fa,int x)
{
 multiset<int> s;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=fa)
  {
   int tmp=dfs(v,u,x)+e[i].w;
   if(tmp>=x)res++;
   else s.insert(tmp);
  }
 }
 int maxl=0;
 while(!s.empty())
 {
  auto it=s.lower_bound(x-*s.begin());
  if(it==s.begin()&&s.count(*it)==1)it++;
  if(it==s.end())
  {
   maxl=max(maxl,*s.begin());
   s.erase(s.begin());
  }
  else
  {
   res++;
   s.erase(it);
   s.erase(s.begin());
  }
 }
 return maxl;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  addedge(u,v,w);
  addedge(v,u,w);
 }
 int l=1,r=1e9,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  memset(f,0,sizeof(f));
  res=0,dfs(1,0,mid);
  if(res>=m)ans=mid,l=mid+1;
  else r=mid-1;
 }
 cout<<ans<<endl;
 return 0;
}