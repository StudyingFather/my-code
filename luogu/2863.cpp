#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
struct edge
{
 int v,next;
}e[50005];
int dfn[10005],low[10005],col[10005],vis[10005],head[10005],cnte,cntp,cntc,ans;
stack<int> s;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
void dfs(int u)
{
 dfn[u]=low[u]=++cntp;
 s.push(u);
 vis[u]=1;
 for(int i=head[u];i;i=e[i].next)
  if(!dfn[e[i].v])
  {
   dfs(e[i].v);
   low[u]=min(low[u],low[e[i].v]);
  }
  else if(vis[e[i].v])low[u]=min(low[u],dfn[e[i].v]);
 if(dfn[u]==low[u])
 {
  cntc++;
  while(1)
  {
   int p=s.top();
   s.pop();
   vis[p]=0;
   col[cntc]++;
   if(p==u)break;
  }
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
 }
 for(int i=1;i<=n;i++)
  if(!dfn[i])dfs(i);
 for(int i=1;i<=cntc;i++)
  if(col[i]>1)ans++;
 printf("%d\n",ans);
 return 0;
}