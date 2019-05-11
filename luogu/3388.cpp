#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
int head[20005],dfn[20005],low[20005],vis[20005],flag[20005],t,ans,cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 vis[u]=true;
 dfn[u]=low[u]=++t;
 int son=0;
 for(int i=head[u];i;i=e[i].next)
  if(!vis[e[i].v])
  {
   son++;
   dfs(e[i].v,u);
   low[u]=min(low[u],low[e[i].v]);
   if(low[e[i].v]>dfn[u]&&(!flag[u])&&u!=fa)
   {
    flag[u]=1;
    ans++;
   }
  }
  else if(e[i].v!=fa)low[u]=min(low[u],dfn[e[i].v]);
 if(fa==u&&(!flag[u])&&son>=2)
 {
  flag[u]=1;
  ans++;
 }
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   t=0;
   dfs(i,i);
  }
 printf("%d\n",ans);
 for(int i=1;i<=n;i++)
  if(flag[i])printf("%d ",i);
 return 0;
}