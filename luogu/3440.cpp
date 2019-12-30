#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct graph
{
 #define INF 0x3f3f3f3f
 struct edge
 {
  int v,w,c,next;
 }e[100005];
 struct node
 {
  int v,e;
 }p[10005];
 int head[505],dist[505],vis[505],s,t,cnt;
 void addedge(int u,int v,int w,int c)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].c=c;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 void init(int S,int T,int n)
 {
  s=S,t=T;
  cnt=1;
  for(int i=1;i<=n;i++)
  {
   addedge(s,i,1,0);
   addedge(i,s,0,0);
   addedge(i+n,t,1,0);
   addedge(t,i+n,0,0);
  }
 }
 bool spfa()
 {
  queue<int> q;
  memset(dist,INF,sizeof(dist));
  q.push(s);
  dist[s]=0;
  vis[s]=1;
  while(!q.empty())
  {
   int cur=q.front();
   q.pop();
   vis[cur]=0;
   for(int i=head[cur];i;i=e[i].next)
    if(e[i].w&&dist[cur]+e[i].c<dist[e[i].v])
    {
     dist[e[i].v]=dist[cur]+e[i].c;
     p[e[i].v].v=cur;
     p[e[i].v].e=i;
     if(!vis[e[i].v])
     {
      vis[e[i].v]=1;
      q.push(e[i].v);
     }
    }
  }
  return dist[t]!=INF;
 }
 pair<int,int> mcmf()
 {
  int maxw=0,minf=0;
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
   minf+=minw*dist[t];
  }
  return make_pair(maxw,minf);
 }
}g;
int main()
{
 int n;
 scanf("%d",&n);
 g.init(2*n+1,2*n+2,n);
 for(int i=1;i<=n;i++)
 {
  int m,a,b,k;
  scanf("%d%d%d%d",&m,&a,&b,&k);
  for(int j=a;j<=b;j++)
  {
   int c=abs(m-j)*k;
   g.addedge(i,j+n,1,c);
   g.addedge(j+n,i,0,-c);
  }
 }
 auto ans=g.mcmf();
 if(ans.first!=n)puts("NIE");
 else printf("%d\n",ans.second);
 return 0;
}