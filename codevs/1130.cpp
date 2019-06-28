#include <stdio.h>
int main()
{
 int a,n,m=0;
 scanf("%d",&n);
 while(n)
 {
  a=n%10;
  m=m*10+a;
  n=n/10;
 }
 printf("%d",m);
 return 0;
}
