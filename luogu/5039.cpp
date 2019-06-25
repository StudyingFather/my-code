#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int u,v,w;
}a[805];
struct edge
{
 int v,w,next;
}e[3505];
int head[505],cur[505],dep[505],vis[505],s,t,cnt=1;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int bfs()
{
 queue<int> q;
 memset(vis,0,sizeof(vis));
 memset(dep,INF,sizeof(dep));
 memcpy(cur,head,sizeof(head));
 dep[s]=0;
 vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(dep[e[i].v]>dep[u]+1&&e[i].w)
   {
    dep[e[i].v]=dep[u]+1;
    if(!vis[e[i].v])
    {
     q.push(e[i].v);
     vis[e[i].v]=1;
    }
   }
 }
 if(dep[t]==INF)return 0;
 return 1;
}
int dfs(int p,int w)
{
 if(p==t)return w;
 int used=0;
 for(int i=cur[p];i;i=e[i].next)
 {
  cur[p]=i;
  if(dep[e[i].v]==dep[p]+1&&e[i].w)
  {
   int flow=dfs(e[i].v,min(w-used,e[i].w));
   if(flow)
   {
    used+=flow;
    e[i].w-=flow;
    e[i^1].w+=flow;
    if(flow==used)break;
   }
  }
 }
 return used;
}
int main()
{
 int n,m,lab,ans=0;
 scanf("%d%d%d",&n,&m,&lab);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
 for(int i=1;i<=m;i++)
  if(a[i].w<=a[lab].w&&i!=lab)
  {
   addedge(a[i].u,a[i].v,a[lab].w-a[i].w+1);
   addedge(a[i].v,a[i].u,0);
   addedge(a[i].v,a[i].u,a[lab].w-a[i].w+1);
   addedge(a[i].u,a[i].v,0);
  }
 s=a[lab].u,t=a[lab].v;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}