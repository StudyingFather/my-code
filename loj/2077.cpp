#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,next;
 }e[1000005];
 int s,t,cnt;
 int head[1005],cur[1005],dis[1005],vis[1005];
 void addedge(int u,int v,int w)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 void init(int S,int T)
 {
  s=S,t=T;
  memset(head,0,sizeof(head));
  cnt=1;
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
 int maxflow()
 {
  int ans=0;
  while(bfs())
   ans+=dfs(s,INF);
  return ans;
 }
}g;
struct line
{
 int x,y,d;
}a[505];
int p[505],T[505][505],f[505][505];
int main()
{
 int n,m;
 cin>>n>>m;
 int s=2*m+1,t=2*m+2;
 g.init(s,t);
 for(int i=1;i<=n;i++)
  cin>>p[i];
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   cin>>T[i][j];
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(i!=j)f[i][j]=T[i][j]+p[j];
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
 for(int i=1;i<=m;i++)
 {
  cin>>a[i].x>>a[i].y>>a[i].d;
  g.addedge(s,i,1),g.addedge(i,s,0);
  g.addedge(i+m,t,1),g.addedge(t,i+m,0);
 }
 for(int i=1;i<=m;i++)
  for(int j=1;j<=m;j++)
  {
   int u=a[i].x,v=a[i].y,w=a[j].x;
   if(a[i].d+T[u][v]+p[v]+f[v][w]<=a[j].d)
    g.addedge(i,j+m,1),g.addedge(j+m,i,0);
  }
 cout<<m-g.maxflow()<<endl;
 return 0;
}