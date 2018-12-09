#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[1000005];
int head[500005],cnt,fa[500005][25],vis[500005],path[500005];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int cur,int d)
{
 vis[cur]=d;
 path[d]=cur;
 for(int i=head[cur];i;i=e[i].next)
  if(vis[e[i].v]==-1)dfs(e[i].v,d+1);
 for(int i=0;(1<<i)<=d;i++)
  fa[cur][i]=path[d-(1<<i)];
 path[d]=0;
 return;
}
int find_fa(int x,int y)
{
 if(vis[x]>vis[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(vis[y]-vis[x]-(1<<i)>=0)y=fa[y][i];
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   x=fa[x][i];
   y=fa[y][i];
  }
 return fa[x][0];
}
int main()
{
 int n,m,s;
 scanf("%d%d%d",&n,&m,&s);
 memset(vis,-1,sizeof(vis));
 for(int i=1;i<n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  addedge(x,y);
  addedge(y,x);
 }
 dfs(s,0);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  printf("%d\n",find_fa(x,y));
 }
 return 0;
}
