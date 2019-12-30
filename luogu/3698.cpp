#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[205];
int head[105],dep[105],maxd,cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 dep[u]=dep[fa]+1;
 maxd=max(maxd,dep[u]);
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=fa)dfs(e[i].v,u);
}
int main()
{
 int v,n;
 scanf("%d%d",&v,&n);
 for(int i=1;i<v;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  addedge(x,y);
  addedge(y,x);
 }
 dep[0]=-1;
 dfs(0,0);
 if(maxd>=n)printf("%d\n",n+1);
 else printf("%d\n",min(v,maxd+1+(n-maxd)/2));
 return 0;
}