#include <stdio.h>
int f[5005][5005];
int main()
{
 int n,k;
 while(~scanf("%d%d",&n,&k)&&n&&k)
 {
  f[0][0]=1;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=k;j++)
    if(i>=j)
     f[i][j]=(f[i-j][j]+f[i-1][j-1])%1988;
  printf("%d\n",f[n][k]%1988);
 }
 return 0;
}
