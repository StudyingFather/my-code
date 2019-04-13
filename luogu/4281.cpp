#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[1000005];
int head[500005],dep[500005],cnt,fa[500005][25],path[500005];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int cur,int d)
{
 dep[cur]=d;
 path[d]=cur;
 for(int i=head[cur];i;i=e[i].next)
  if(dep[e[i].v]==-1)dfs(e[i].v,d+1);
 for(int i=0;(1<<i)<=d;i++)
  fa[cur][i]=path[d-(1<<i)];
 path[d]=0;
 return;
}
int lca(int x,int y)
{
 if(dep[x]>dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[y]-dep[x]-(1<<i)>=0)y=fa[y][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   x=fa[x][i];
   y=fa[y][i];
  }
 return fa[x][0];
}
int calc_dep(int x,int y)
{
 return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 memset(dep,-1,sizeof(dep));
 for(int i=1;i<n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  addedge(x,y);
  addedge(y,x);
 }
 dfs(1,0);
 for(int i=1;i<=m;i++)
 {
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  int l1=lca(x,y),l2=lca(x,z),l3=lca(y,z);
  int ans;
  if(l1==l2)ans=l3;
  else if(l1==l3)ans=l2;
  else ans=l1;
  printf("%d %d\n",ans,calc_dep(ans,x)+calc_dep(ans,y)+calc_dep(ans,z));
 }
 return 0;
}