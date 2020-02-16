#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,next;
  long long c;
 }e[500005];
 struct node
 {
  int v,e;
 }p[2005];
 int head[2005],vis[2005];
 long long dis[2005];
 int n,s,t,cnt=1;
 void init(int N,int S,int T)
 {
  n=N,s=S,t=T;
 }
 void addedge(int u,int v,int w,int c)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].c=c;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 bool spfa()
 {
  queue<int> q;
  memset(dis,63,sizeof(dis));
  dis[s]=0,vis[s]=1;
  q.push(s);
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   vis[u]=0;
   for(int i=head[u];i;i=e[i].next)
    if(e[i].w&&dis[u]+e[i].c<dis[e[i].v])
    {
     dis[e[i].v]=dis[u]+e[i].c;
     p[e[i].v].v=u;
     p[e[i].v].e=i;
     if(!vis[e[i].v])
     {
      vis[e[i].v]=1;
      q.push(e[i].v);
     }
    }
  }
  return dis[t]<=1e18;
 }
 long long mcmf()
 {
  long long maxw=0;
  while(spfa())
  {
   int minw=INF;
   for(int i=t;i!=s;i=p[i].v)
    minw=min(minw,e[p[i].e].w);
   for(int i=t;i!=s;i=p[i].v)
   {
    e[p[i].e].w-=minw;
    e[p[i].e^1].w+=minw;
   }
   maxw+=minw;
  }
  return maxw;
 }
}g1,g2;
int vis[505],n,m;
void build()
{
 queue<int> q;
 q.push(1),vis[1]=1;
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=g1.head[u];i;i=g1.e[i].next)
  {
   int v=g1.e[i].v;
   if(g1.dis[v]==g1.dis[u]+g1.e[i].c)
   {
    g2.addedge(u+n,v,INF,g1.e[i].c);
    g2.addedge(v,u+n,0,-g1.e[i].c);
    if(!vis[v])q.push(v),vis[v]=1;
   }
  }
 }
}
int main()
{
 cin>>n>>m;
 g1.init(n,1,n);
 g2.init(n,n+1,n);
 for(int i=1;i<=m;i++)
 {
  int u,v,c;
  cin>>u>>v>>c;
  g1.addedge(u,v,INF,c);
  g1.addedge(v,u,INF,c);
 }
 g1.spfa();
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  g2.addedge(i,i+n,x,0);
  g2.addedge(i+n,i,0,0);
 }
 build();
 cout<<g2.mcmf()<<endl;
 return 0;
}