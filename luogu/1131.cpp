#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
 long long v,w,next;
}e[1000005];
long long head[500005],maxd[500005],n,s,ans,cnt;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int cur,int fa)
{
 for(int i=head[cur];i;i=e[i].next)
  if(e[i].v!=fa)dfs(e[i].v,cur);
 for(int i=head[cur];i;i=e[i].next)
  if(e[i].v!=fa)maxd[cur]=max(maxd[cur],e[i].w);
 for(int i=head[cur];i;i=e[i].next)
  if(e[i].v!=fa)ans+=maxd[cur]-e[i].w;
 for(int i=head[fa];i;i=e[i].next)
  if(e[i].v==cur)e[i].w+=maxd[cur];
}
int main()
{
 cin>>n>>s;
 for(int i=1;i<n;i++)
 {
  int a,b,t;
  cin>>a>>b>>t;
  addedge(a,b,t);
  addedge(b,a,t);
 }
 dfs(s,0);
 cout<<ans<<endl;
 return 0;
}