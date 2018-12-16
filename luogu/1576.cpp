#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
 int v,next;
 double w;
}e[400005];
struct point
{
 int id;
 double dist;
 bool operator<(const point&a)const
 {
  return a.dist>dist;
 }
}p[2005];
int cnt,vis[2005],head[2005];
priority_queue<point> q;
void addedge(int u,int v,double w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n,m,a,b;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,1-(double)w/100);
  addedge(v,u,1-(double)w/100);
 }
 scanf("%d%d",&a,&b);
 for(int i=1;i<=n;i++)
  p[i].id=i;
 p[a].dist=1;
 q.push(p[a]);
 while(!q.empty())
 {
  int cur=q.top().id;
  vis[cur]=0;
  q.pop();
  for(int i=head[cur];i;i=e[i].next)
   if(p[e[i].v].dist<p[cur].dist*e[i].w)
   {
   	p[e[i].v].dist=p[cur].dist*e[i].w;
   	if(!vis[e[i].v])
   	{
   	 q.push(p[e[i].v]);
   	 vis[e[i].v]=1;
   	}
   }
 }
 printf("%.8lf\n",100/p[b].dist);
 return 0;
}
