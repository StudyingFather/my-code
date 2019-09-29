#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int a[55][15],f[55][155][155],g[55][155][155],c[55][155],t[155];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 int maxm=(1<<m)-1;
 for(int i=1;i<=n;i++)
 {
  for(int j=0;j<m;j++)
   scanf("%d",&a[i][j]);
  for(int j=0;j<=maxm;j++)
  {
   int cnt=0;
   for(int k=0;k<m;k++)
    if(j&(1<<k))c[i][j]+=a[i][k],cnt++;
   t[j]=cnt;
  }
 }
 memset(f,INF,sizeof(f));
 memset(g,INF,sizeof(g));
 for(int i=0;i<=maxm;i++)
  f[1][i][0]=c[1][i],g[1][i][0]=t[i];
 for(int i=2;i<=n+1;i++)
  for(int j=0;j<=maxm;j++)
   for(int k=0;k<=maxm;k++)
    for(int p=0;p<=maxm;p++)
     if(((j|k|p|(j<<1)|(j>>1))&maxm)==maxm)
     {
      if(f[i-1][j][k]+c[i][p]<f[i][p][j])
      {
       f[i][p][j]=f[i-1][j][k]+c[i][p];
       g[i][p][j]=g[i-1][j][k]+t[p];
      }
      else if(f[i-1][j][k]+c[i][p]==f[i][p][j]&&g[i-1][j][k]+t[p]<g[i][p][j])
       g[i][p][j]=g[i-1][j][k]+t[p];
     }
 int ans=INF,num=INF;
 for(int i=0;i<=maxm;i++)
  if(ans>f[n+1][0][i])
  {
   ans=f[n+1][0][i];
   num=g[n+1][0][i];
  }
  else if(ans==f[n+1][0][i]&&num>g[n+1][0][i])
   num=g[n+1][0][i];
 printf("%d %d\n",num,ans);
 return 0;
}