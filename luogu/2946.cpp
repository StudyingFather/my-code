#include <stdio.h>
#define MOD 100000000
int f[2005][1005],a[2005];
int main()
{
 int n,F;
 scanf("%d%d",&n,&F);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  f[i][a[i]%F]=1;
 }
 for(int i=1;i<=n;i++)
  for(int j=0;j<F;j++)
   f[i][j]+=(f[i-1][j]+f[i-1][((j-a[i])%F+F)%F])%MOD,f[i][j]%=MOD;
 printf("%d",f[n][0]);
 return 0;
}
