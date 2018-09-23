#include <stdio.h>
int f[25];
int main()
{
 int n;
 scanf("%d",&n);
 f[0]=f[1]=1;
 for(int i=2;i<=n;i++)
  for(int j=0;j<i;j++)
   f[i]+=f[j]*f[i-j-1];
 printf("%d",f[n]);
 return 0;
}
