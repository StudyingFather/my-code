#include <stdio.h>
#include <math.h>
int zs(int a)
{
 int zd=1;
 for(int i=1;i<sqrt(a);i++)
 {
  if(a%i==0&&i>zd)zd=i;
 }
 return a/zd;
}
int main()
{
 int a;
 scanf("%d",&a);
 a=zs(a);
 printf("%d",a);
 return 0;
}
