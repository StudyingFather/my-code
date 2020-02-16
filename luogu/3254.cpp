#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[100005];
int s,t,cnt=1;
int head[1005],dep[1005],vis[1005],cur[1005],nxt[1005];
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
 int m,n,sum=0,ans=0;
 scanf("%d%d",&m,&n);
 s=m+n+1,t=m+n+2;
 for(int i=1;i<=m;i++)
 {
  int x;
  scanf("%d",&x);
  sum+=x;
  addedge(s,i,x);
  addedge(i,s,0);
  for(int j=n;j;j--)
  {
   addedge(i,m+j,1);
   addedge(m+j,i,0);
  }
 }
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  addedge(m+i,t,x);
  addedge(t,m+i,0);
 }
 while(bfs())
  ans+=dfs(s,INF);
 if(ans!=sum)puts("0");
 else
 {
  puts("1");
  for(int u=1;u<=m;u++)
  {
   for(int i=head[u];i;i=e[i].next)
   {
    if(e[i].v==s)continue;
    for(int j=1;j<=e[i^1].w;j++)
     printf("%d ",e[i].v-m);
   }
   puts("");
  }
 }
 return 0;
}