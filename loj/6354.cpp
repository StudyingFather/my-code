#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
 int x,y;
 bool operator<(const node&a)const
 {
  return y>a.y;
 }
};
struct edge
{
 int v,w,next;
}e[5000005];
priority_queue<node> q;
int dist[100005],vis[100005],head[100005],cnt;
inline void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n,m,c,a,b;
 scanf("%d%d%d",&n,&m,&c);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
 }
 for(int i=0;i<=n;i++)
  for(int j=1;j<=n;j<<=1)
   if((i^j)<=n)addedge(i,i^j,j*c);
 scanf("%d%d",&a,&b);
 memset(dist,INF,sizeof(dist));
 q.push((node){a,0});
 dist[a]=0;
 while(!q.empty())
 {
  int p=q.top().x;
  q.pop();
  if(vis[p])continue;
  vis[p]=1;
  for(int i=head[p];i;i=e[i].next)
   if(dist[p]+e[i].w<dist[e[i].v])
   {
	dist[e[i].v]=dist[p]+e[i].w;
	q.push((node){e[i].v,dist[e[i].v]});
   }
 }
 printf("%d\n",dist[b]);
 return 0;
}