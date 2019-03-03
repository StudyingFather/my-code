#include <stdio.h>
#include <string.h>
struct edge
{
 int v,next;
}e[10005];
int head[205],cnt,vis[205],march[205];
bool find(int x)
{
 for(int i=head[x];i;i=e[i].next)
  if(!vis[e[i].v])
  {
   vis[e[i].v]=1;
   if(!march[e[i].v]||find(march[e[i].v]))
   {
    march[e[i].v]=x;
    return true;
   }
  }
 return false;
}
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int m,n,u,v,ans=0;
 scanf("%d%d",&m,&n);
 while((~scanf("%d%d",&u,&v))&&(~u)&&(~v))
  addedge(u,v);
 for(int i=1;i<=n;i++)
 {
  memset(vis,0,sizeof(vis));
  if(find(i))ans++;
 }
 printf("%d\n",ans);
 return 0;
}
