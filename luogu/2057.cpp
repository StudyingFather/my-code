#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
int s,t,cnt=1;
int head[305],cur[305],dep[305],vis[305];
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool bfs()
{
 queue<int> q;
 memset(dep,INF,sizeof(dep));
 memset(vis,0,sizeof(vis));
 memcpy(cur,head,sizeof(head));
 vis[s]=1;
 dep[s]=0;
 q.push(s);
 while(!q.empty())
 {
  int p=q.front();
  vis[p]=0;
  q.pop();
  for(int i=head[p];i;i=e[i].next)
   if(dep[e[i].v]>dep[p]+1&&e[i].w)
   {
    dep[e[i].v]=dep[p]+1;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
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
    if(used==w)break;
   }
  }
 }
 return used;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 s=n+1,t=n+2;
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  if(x==0)addedge(s,i,1),addedge(i,s,0);
  else addedge(i,t,1),addedge(t,i,0);
 }
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v,1);
  addedge(v,u,1);
 }
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}