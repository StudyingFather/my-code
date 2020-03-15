#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define eqs 1e-9
using namespace std;
struct edge
{
 int v,next;
 double w;
}e[10005];
double dist[3005];
int head[3005],t[3005],vis[3005],cnt,n,m;
void addedge(int u,int v,double w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool spfa(int u,double d)
{
 vis[u]=1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(dist[v]>dist[u]+e[i].w-d)
  {
   if(vis[v])return true;
   dist[v]=dist[u]+e[i].w-d;
   if(spfa(v,d))return true;
  }
 }
 vis[u]=0;
 return false;
}
bool check(double d)
{
 memset(vis,0,sizeof(vis));
 memset(dist,0,sizeof(dist));
 for(int i=1;i<=n;i++)
  if(!vis[i]&&spfa(i,d))return true;
 return false;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  double w;
  scanf("%d%d%lf",&u,&v,&w);
  addedge(u,v,w);
 }
 double l=-1e7,r=1e7;
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))r=mid;
  else l=mid;
 }
 printf("%.8lf",l);
 return 0;
}