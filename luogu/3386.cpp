#include <stdio.h>
#include <string.h>
struct edge
{
 int v,next;
}e[1000005];
int vis[2005],head[2005],march[2005],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool dfs(int x)
{
 for(int i=head[x];i;i=e[i].next)
  if(!vis[e[i].v])
  {
   vis[e[i].v]=1;
   if((!march[e[i].v])||dfs(march[e[i].v]))
   {
    march[e[i].v]=x;
    return true;
   }
  }
 return false;
}
int main()
{
 int n,m,x,ans=0;
 scanf("%d%d%d",&n,&m,&x);
 for(int i=1;i<=x;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  if(v>m)continue;
  addedge(u,v+n);
 }
 for(int i=1;i<=n;i++)
 {
  memset(vis,0,sizeof(vis));
  if(dfs(i))ans++;
 }
 printf("%d\n",ans);
 return 0;
}
