#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,w,next;
}e[3005];
int f[3005][3005],head[3005],siz[3005],cnt,n,m;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u)
{
 if(u>=n-m+1)
  siz[u]=1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  dfs(v);
  siz[u]+=siz[v];
  for(int j=siz[u];j>=0;j--)
   for(int k=0;k<=siz[v];k++)
    f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]-e[i].w);
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 memset(f,191,sizeof(f));
 for(int i=1;i<=n;i++)
  f[i][0]=0;
 for(int i=1;i<=n-m;i++)
 {
  int k;
  scanf("%d",&k);
  while(k--)
  {
   int v,w;
   scanf("%d%d",&v,&w);
   addedge(i,v,w);
  }
 }
 for(int i=n-m+1;i<=n;i++)
  scanf("%d",&f[i][1]);
 dfs(1);
 for(int i=m;;i--)
  if(f[1][i]>=0)
  {
   printf("%d\n",i);
   return 0;
  }
}