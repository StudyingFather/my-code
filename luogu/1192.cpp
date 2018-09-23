#include <stdio.h>
int f[100005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 f[0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=k&&i>=j;j++)
   f[i]+=f[i-j],f[i]%=100003;
 printf("%d",f[n]);
 return 0;
}
