#include <stdio.h>
int n;
double f[55];
int main()
{
 f[1]=f[2]=1;
 scanf("%d",&n);
 for(int i=3;i<=n;i++)
  f[i]=f[i-1]+f[i-2];
 printf("%.2lf",f[n]);
 return 0;
}
