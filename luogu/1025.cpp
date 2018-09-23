#include <stdio.h>
int f[500][500];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 f[0][0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=k;j++)
   if(i>=j)
    f[i][j]=f[i-j][j]+f[i-1][j-1];
 printf("%d",f[n][k]);
 return 0;
}
