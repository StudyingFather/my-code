#include <stdio.h>
int f[25],n;
int main()
{
 scanf("%d%d%d",&f[0],&f[1],&n);
 for(int i=2;i<=n;i++)
  f[i]=f[i-1]+f[i-2];
 printf("%d",f[n]);
 return 0;
}
