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
int head[100005],dep[100005],vis[100005],cur[100005];
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
 int n,p,q;
 scanf("%d%d%d",&n,&p,&q);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=p;j++)
  {
   int x;
   scanf("%d",&x);
   if(x==1)
   {
    addedge(j,p+i,1);
    addedge(p+i,j,0);
   }
  }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=q;j++)
  {
   int x;
   scanf("%d",&x);
   if(x==1)
   {
    addedge(n+p+q+i,p+n+j,1);
    addedge(p+n+j,n+p+q+i,0);
   }
  }
 for(int i=1;i<=n;i++)
  addedge(p+i,n+p+q+i,1),addedge(n+p+q+i,p+i,0);
 t=n*2+p+q+1;
 for(int i=1;i<=p;i++)
  addedge(s,i,1),addedge(i,s,0);
 for(int i=1;i<=q;i++)
  addedge(n+p+i,t,1),addedge(t,n+p+i,0);
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}