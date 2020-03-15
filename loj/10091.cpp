#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
struct edge
{
 int v,next;
}e[50005];
stack<int> s;
int head[10005],dfn[10005],low[10005],vis[10005],col[10005],siz[10005],t[10005];
int cnte,cntp,cntc;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
void dfs(int u)
{
 dfn[u]=low[u]=++cntp;
 vis[u]=1;
 s.push(u);
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(!dfn[v])
  {
   dfs(v);
   low[u]=min(low[u],low[v]);
  }
  else if(vis[v])low[u]=min(low[u],dfn[v]);
 }
 if(dfn[u]==low[u])
 {
  cntc++;
  while(1)
  {
   int p=s.top();
   s.pop();
   vis[p]=0;
   col[p]=cntc;
   siz[cntc]++;
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
 for(int i=1;i<=n;i++)
  for(int j=head[i];j;j=e[j].next)
   if(col[i]!=col[e[j].v])
    t[col[i]]++;
 int res=0;
 for(int i=1;i<=cntc;i++)
  if(!t[i])
  {
   if(res)
   {
    puts("0");
    return 0;
   }
   else res=i;
  }
 printf("%d\n",siz[res]);
 return 0;
}