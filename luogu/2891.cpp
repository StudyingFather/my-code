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
int n,f,d,s,t,cnt=1;
int head[405],dep[405],vis[405],cur[405];
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
 scanf("%d%d%d",&n,&f,&d);
 s=2*n+f+d+1,t=2*n+f+d+2;
 for(int i=1;i<=n;i++)
 {
  addedge(2*i-1,2*i,1);
  addedge(2*i,2*i-1,0);
 }
 for(int i=1;i<=f;i++)
 {
  addedge(s,2*n+i,1);
  addedge(2*n+i,s,0);
 }
 for(int i=1;i<=d;i++)
 {
  addedge(2*n+f+i,t,1);
  addedge(t,2*n+f+i,0);
 }
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  for(int j=1;j<=x;j++)
  {
   int num;
   scanf("%d",&num);
   addedge(2*n+num,2*i-1,1);
   addedge(2*i-1,2*n+num,0);
  }
  for(int j=1;j<=y;j++)
  {
   int num;
   scanf("%d",&num);
   addedge(2*i,2*n+f+num,1);
   addedge(2*n+f+num,2*i,0);
  }
 }
 int ans=0;
 while(bfs())
  ans+=dfs(s,INF);
 printf("%d\n",ans);
 return 0;
}