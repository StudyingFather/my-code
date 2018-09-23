#include <stdio.h>
#define MOD 100000000
int a[15][15],f[13][4105],F[15],ans;
bool s[4105];
int main()
{
 int m,n;
 scanf("%d%d",&m,&n);
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
   F[i]=(F[i]<<1)+a[i][j];
 for(int i=0;i<(1<<n);i++)
  s[i]=((i&(i<<1))==0)&&((i&(i>>1))==0);
 f[0][0]=1;
 for(int i=1;i<=m;i++)
  for(int j=0;j<(1<<n);j++)
   if(s[j]&&((j&F[i])==j))
    for(int k=0;k<(1<<n);k++)
     if(!(k&j))f[i][j]=(f[i][j]+f[i-1][k])%MOD;
 for(int i=0;i<(1<<n);i++)
  ans=(ans+f[m][i])%MOD;
 printf("%d",ans);
 return 0;
}
