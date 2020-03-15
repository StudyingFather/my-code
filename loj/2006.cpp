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
 }e[500005];
 int s,t,cnt;
 int head[505],cur[505],dis[505],vis[505];
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
int a[255][255],n,m,k;
bool check(int x)
{
 int s=n+m+1,t=n+m+2;
 g.init(s,t);
 for(int i=1;i<=n;i++)
  g.addedge(s,i,1),g.addedge(i,s,0);
 for(int i=1;i<=m;i++)
  g.addedge(i+n,t,1),g.addedge(t,i+n,0);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   if(a[i][j]<=x)
    g.addedge(i,j+n,1),g.addedge(j+n,i,0);
 return g.maxflow()>=n-k+1;
}
int main()
{
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   cin>>a[i][j];
 int l=1,r=1e9,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid))ans=mid,r=mid-1;
  else l=mid+1;
 }
 cout<<ans<<endl;
 return 0;
}