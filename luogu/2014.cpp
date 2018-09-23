#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[305];
int head[305],f[305][305],cnt,s[305];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int dfs(int a)
{
 int p=1;
 f[a][1]=s[a];
 for(int t=head[a];t;t=e[t].next)
 {
  int v=e[t].v;
  int now=dfs(v);
  for(int i=p;i;i--)
   for(int j=1;j<=now;j++)
    f[a][i+j]=max(f[a][i+j],f[a][i]+f[v][j]);
  p+=now;
 }
 return p;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  int u;
  scanf("%d%d",&u,&s[i]);
  addedge(u,i);
 }
 dfs(0);
 printf("%d",f[0][m+1]);
 return 0;
}
