#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,c,w,next;
}e[30005];
struct pre
{
 int v,e;
}p[405];
int head[405],dist[405],vis[405],n,m,cnt=1;
void addedge(int u,int v,int c,int w)
{
 e[++cnt].v=v;
 e[cnt].c=c;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa()
{
 queue<int> q;
 memset(dist,INF,sizeof(dist));
 dist[1]=0;
 vis[1]=1;
 q.push(1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=head[u];i;i=e[i].next)
   if(dist[e[i].v]>dist[u]+e[i].w&&e[i].c)
   {
    dist[e[i].v]=dist[u]+e[i].w;
    p[e[i].v].e=i,p[e[i].v].v=u;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 return dist[n]!=INF;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int s,t,c,w;
  scanf("%d%d%d%d",&s,&t,&c,&w);
  addedge(s,t,c,w);
  addedge(t,s,0,-w);
 }
 int cost=0,flow=0;
 while(spfa())
 {
  int minf=INF;
  for(int i=n;i!=1;i=p[i].v)
   minf=min(minf,e[p[i].e].c);
  flow+=minf;
  cost+=minf*dist[n];
  for(int i=n;i!=1;i=p[i].v)
  {
   e[p[i].e].c-=minf;
   e[p[i].e^1].c+=minf;
  }
 }
 printf("%d %d\n",flow,cost);
 return 0;
}