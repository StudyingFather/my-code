#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[15005];
struct node
{
 int p,dist;
 bool operator<(const node&a)const
 {
  return dist>a.dist;
 }
};
int dist[2505],vis[2505],head[2505],cnt;
priority_queue<node> q;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n,m,s,t;
 scanf("%d%d%d%d",&n,&m,&s,&t);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,w);
 }
 memset(dist,INF,sizeof(dist));
 dist[s]=0;
 q.push({s,0});
 while(!q.empty())
 {
  int u=q.top().p;
  q.pop();
  if(vis[u])continue;
  vis[u]=1;
  for(int i=head[u];i;i=e[i].next)
  {
   if(dist[e[i].v]>dist[u]+e[i].w)
   {
    dist[e[i].v]=dist[u]+e[i].w;
    q.push({e[i].v,dist[e[i].v]});
   }
  }
 }
 printf("%d\n",dist[t]);
 return 0;
}