#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
 int v,w,next;
}e[40005];
int head[10005],vis[10005],tot[10005],cnt,que[10005],l,r,flag;
long long ans,dist[10005];
inline void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs_spfa(int x)
{
 vis[x]=1;
 for(int i=head[x];i;i=e[i].next)
  if(dist[x]+e[i].w>dist[e[i].v])
  {
   if(vis[e[i].v]||flag)
   {
    flag=1;
    return;
   }
   dist[e[i].v]=dist[x]+e[i].w;
   dfs_spfa(e[i].v);
  }
 vis[x]=0;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int op,x,y,z;
  scanf("%d",&op);
  if(op==1)
  {
   scanf("%d%d%d",&x,&y,&z);
   addedge(y,x,z);
  }
  else if(op==2)
  {
   scanf("%d%d%d",&x,&y,&z);
   addedge(x,y,-z);
  }
  else
  {
   scanf("%d%d",&x,&y);
   addedge(x,y,0);
   addedge(y,x,0);
  }
 }
 for(int i=1;i<=n;i++)
  addedge(0,i,0);
 memset(dist,-0x3f,sizeof(dist));
 dist[0]=0;
 dfs_spfa(0);
 puts(flag?"No":"Yes");
 return 0;
}