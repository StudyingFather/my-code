#include <stdio.h>
int a[10005];
int main()
{
 int x;
 a[0]=1;
 for(int i=1;i<=10000;i++)
 {
  a[i]=a[i-1]*i;
  while(a[i]%10==0)a[i]/=10;
  a[i]=a[i]%100000;
 }
 while(~scanf("%d",&x))
  printf("%5d -> %d\n",x,a[x]%10);
 return 0;
}
