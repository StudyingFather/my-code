#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[5000005];
int head[500005],cur[500005],cnt=1;
int dis[500005],vis[500005],s,t;
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
 memset(dis,INF,sizeof(dis));
 memcpy(cur,head,sizeof(cur));
 dis[s]=0,vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(e[i].w&&dis[v]>dis[u]+1)
   {
    dis[v]=dis[u]+1;
    if(!vis[v])q.push(v),vis[v]=1;
   }
  }
 }
 return dis[t]!=INF;
}
int dfs(int u,int flow)
{
 if(u==t)return flow;
 int used=0;
 for(int i=cur[u];i;i=e[i].next)
 {
  int v=e[i].v;
  cur[u]=i;
  if(e[i].w&&dis[v]==dis[u]+1)
  {
   int f=dfs(v,min(flow-used,e[i].w));
   e[i].w-=f;
   e[i^1].w+=f;
   used+=f;
   if(used==flow)break;
  }
 }
 return used;
}
int main()
{
 int n,ans=0;
 cin>>n;
 s=n+n*n+1,t=n+n*n+2;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   int x,p=n+(i-1)*n+j;
   cin>>x;
   ans+=x;
   addedge(s,p,x);
   addedge(p,s,0);
   addedge(p,i,INF),addedge(i,p,0);
   addedge(p,j,INF),addedge(j,p,0);
  }
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  addedge(i,t,x);
  addedge(t,i,0);
 }
 while(bfs())
  ans-=dfs(s,INF);
 cout<<ans<<endl;
 return 0;
}