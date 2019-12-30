#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,next;
 }e[1000005];
 struct node
 {
  int u;
  long long dis;
  bool operator<(const node&a)const
  {
   return dis>a.dis;
  }
 };
 int head[100005],vis[100005],cnt;
 long long dis[100005];
 int s,t;
 priority_queue<node> q;
 void init(int n)
 {
  memset(head,0,sizeof(head));
  cnt=0;
  s=n+1,t=n+2;
 }
 void addedge(int u,int v,int w)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 long long dijkstra()
 {
  memset(dis,63,sizeof(dis));
  memset(vis,0,sizeof(vis));
  dis[s]=0;
  q.push({s,0});
  while(!q.empty())
  {
   int u=q.top().u;
   q.pop();
   if(vis[u])continue;
   vis[u]=1;
   for(int i=head[u];i;i=e[i].next)
   {
    int v=e[i].v;
    if(dis[v]>dis[u]+e[i].w)
    {
     dis[v]=dis[u]+e[i].w;
     q.push({v,dis[v]});
    }
   }
  }
  return dis[t];
 }
}g,g1;
int p[100005];
int main()
{
 //ios::sync_with_stdio(false);
 int T;
 cin>>T;
 while(T--)
 {
  int n,m,k;
  cin>>n>>m>>k;
  g.init(n);
  g1.init(n);
  int s=n+1,t=n+2;
  for(int i=1;i<=m;i++)
  {
   int u,v,w;
   scanf("%d%d%d",&u,&v,&w);
   g1.addedge(u,v,w);
  }
  for(int i=1;i<=k;i++)
   cin>>p[i];
  long long ans=1e18;
  for(int i=0;(1<<i)<=k;i++)
  {
   g=g1;
   for(int j=1;j<=k;j++)
    if(j&(1<<i))
     g.addedge(s,p[j],0);
    else
     g.addedge(p[j],t,0);
   ans=min(ans,g.dijkstra());
   g=g1;
   for(int j=1;j<=k;j++)
    if(j&(1<<i))
     g.addedge(p[j],t,0);
    else
     g.addedge(s,p[j],0);
   ans=min(ans,g.dijkstra());
  }
  cout<<ans<<endl;
 }
 return 0;
}