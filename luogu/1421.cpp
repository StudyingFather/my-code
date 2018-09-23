#include <stdio.h>
int main()
{
 int yuan,jiao,a;
 double money;
 scanf("%d%d",&yuan,&jiao);
 money=yuan+jiao/10.0;
 a=money/1.9;
 printf("%d",a);
 return 0;
}
