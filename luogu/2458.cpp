#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int a[1505],head[1505],cnt;
int f[1505][5];
struct edge
{
 int v,next;
}e[5005];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 int sum=0;
 f[u][2]=a[u];
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  dfs(v,u);
  sum+=min(f[v][1],f[v][2]);
  f[u][2]+=min(f[v][0],min(f[v][1],f[v][2]));
 }
 f[u][0]=sum,f[u][1]=INF;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v==fa)continue;
  f[u][1]=min(f[u][1],sum-min(f[v][1],f[v][2])+f[v][2]);
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int u,m;
  scanf("%d",&u);
  scanf("%d%d",&a[u],&m);
  while(m--)
  {
   int v;
   scanf("%d",&v);
   addedge(u,v);
   addedge(v,u);
  }
 }
 dfs(1,0);
 printf("%d\n",min(f[1][1],f[1][2]));
 return 0;
}