#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int c[2005],d[2005],dist[305][305];
double k[2005],f[2005][2005][2];
int main()
{
 int n,m,v,e;
 memset(dist,INF,sizeof(dist));
 scanf("%d%d%d%d",&n,&m,&v,&e);
 for(int i=1;i<=n;i++)
  scanf("%d",&c[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&d[i]);
 for(int i=1;i<=n;i++)
  scanf("%lf",&k[i]);
 for(int i=1;i<=e;i++)
 {
  int a,b,w;
  scanf("%d%d%d",&a,&b,&w);
  dist[a][b]=dist[b][a]=min(dist[a][b],w);
 }
 for(int i=1;i<=v;i++)
  dist[i][i]=0;
 for(int k=1;k<=v;k++)
  for(int i=1;i<=v;i++)
   for(int j=1;j<=v;j++)
    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
 for(int i=1;i<=n;i++)
  for(int j=0;j<=m;j++)
   f[i][j][0]=f[i][j][1]=INF;
 f[1][0][0]=f[1][1][1]=0;
 for(int i=2;i<=n;i++)
  for(int j=0;j<=min(m,i);j++)
  {
   f[i][j][0]=min(f[i-1][j][0]+dist[c[i-1]][c[i]],
                  f[i-1][j][1]+k[i-1]*dist[d[i-1]][c[i]]
                  +(1-k[i-1])*dist[c[i-1]][c[i]]);
   if(j!=0)
    f[i][j][1]=min(f[i-1][j-1][0]+k[i]*dist[c[i-1]][d[i]]
                   +(1-k[i])*dist[c[i-1]][c[i]],
                   f[i-1][j-1][1]+k[i-1]*k[i]*dist[d[i-1]][d[i]]
                   +k[i-1]*(1-k[i])*dist[d[i-1]][c[i]]
                   +(1-k[i-1])*k[i]*dist[c[i-1]][d[i]]
                   +(1-k[i-1])*(1-k[i])*dist[c[i-1]][c[i]]);
  }
 double ans=INF;
 for(int i=0;i<=m;i++)
  ans=min(ans,min(f[n][i][0],f[n][i][1]));
 printf("%.2lf\n",ans);
 return 0;
}