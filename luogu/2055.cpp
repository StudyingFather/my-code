#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[50005];
int n,m,s,t,cnt=1;
int head[505],dep[505],vis[505],cur[505],sch[505];
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
 dep[s]=0;
 vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int p=q.front();
  q.pop();
  vis[p]=0;
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
 int T;
 scanf("%d",&T);
 while(T--)
 {
  memset(head,0,sizeof(head));
  memset(e,0,sizeof(e));
  cnt=1;
  int tot=0,ans=0;
  scanf("%d",&n);
  s=0,t=2*n+1;
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&sch[i]);
   if(sch[i])addedge(i+n,t,1),addedge(t,i+n,0);
   else addedge(s,i,1),addedge(i,s,0),tot++;
  }
  for(int i=1;i<=n;i++)
  {
   int x;
   scanf("%d",&x);
   if(sch[i]&&(!x))
   {
    addedge(s,i,1);
    addedge(i,s,0);
    addedge(i,i+n,INF);
    addedge(i+n,i,0);
    tot++;
   }
  }
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
   {
    int x;
    scanf("%d",&x);
    if(sch[j]&&x)addedge(i,j+n,INF),addedge(j+n,i,0);
   }
  while(bfs())
   ans+=dfs(s,INF);
  if(ans>=tot)puts("^_^");
  else puts("T_T");
 }
 return 0;
}