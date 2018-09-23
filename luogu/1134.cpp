#include <stdio.h>
int main()
{
 int n;
 long long f=1;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  f*=i;
  while(f%10==0)f/=10;
  f%=10000000;
 }
 printf("%d",(int)f%10);
 return 0;
}
