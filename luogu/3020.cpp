#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[500005];
struct point
{
 int dist,id;
 bool operator<(const point&a)const
 {
  return dist>a.dist;
 }
};
int head[100005],cnt,dist[100005],vis[100005];
priority_queue<point> q;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,w);
 }
 memset(dist,INF,sizeof(dist));
 dist[1]=0,vis[1]=1;
 point p;
 p.dist=0,p.id=1;
 q.push(p);
 while(!q.empty())
 {
  int curp=q.top().id,curd=q.top().dist;
  vis[curp]=1;
  q.pop();
  if(curd!=dist[curp])continue;
  for(int i=head[curp];i;i=e[i].next)
   if(vis[e[i].v]==0&&dist[curp]+e[i].w<dist[e[i].v])
   {
    p.dist=dist[curp]+e[i].w;
    p.id=e[i].v;
    dist[e[i].v]=dist[curp]+e[i].w;
    q.push(p);
   }
 }
 printf("%d\n",dist[n]);
 return 0;
}
