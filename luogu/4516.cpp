#include <cstdio>
#include <algorithm>
#define MOD 1000000007
using namespace std;
struct edge
{
 int v,next;
}e[200005];
int f[100005][105][2][2],g[105][2][2],siz[100005],head[100005],cnt,n,k;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 siz[u]=1,f[u][0][0][0]=f[u][1][1][0]=1;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=fa)
  {
   int v=e[i].v;
   dfs(v,u);
   for(int j=0;j<=min(siz[u],k);j++)
   {
    g[j][0][0]=f[u][j][0][0],f[u][j][0][0]=0;
    g[j][0][1]=f[u][j][0][1],f[u][j][0][1]=0;
    g[j][1][0]=f[u][j][1][0],f[u][j][1][0]=0;
    g[j][1][1]=f[u][j][1][1],f[u][j][1][1]=0;
   }
   for(int i=0;i<=min(k,siz[u]);i++)
    for(int j=0;j<=min(k-i,siz[v]);j++)
    {
     f[u][i+j][0][0]=(f[u][i+j][0][0]+(long long)g[i][0][0]*f[v][j][0][1])%MOD;
     f[u][i+j][0][1]=(f[u][i+j][0][1]+(long long)g[i][0][1]*(f[v][j][1][1]+f[v][j][0][1])%MOD
                     +(long long)g[i][0][0]*f[v][j][1][1])%MOD;
     f[u][i+j][1][0]=(f[u][i+j][1][0]+(long long)g[i][1][0]*(f[v][j][0][0]+f[v][j][0][1]))%MOD;
     f[u][i+j][1][1]=(f[u][i+j][1][1]+(long long)g[i][1][0]*(f[v][j][1][0]+f[v][j][1][1])%MOD
                     +(long long)g[i][1][1]*((long long)f[v][j][0][1]+f[v][j][1][1]+f[v][j][0][0]+f[v][j][1][0]))%MOD;
    }
   siz[u]+=siz[v];
  }
}
int main()
{
 scanf("%d%d",&n,&k);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 dfs(1,0);
 printf("%d\n",(f[1][k][0][1]+f[1][k][1][1])%MOD);
 return 0;
}