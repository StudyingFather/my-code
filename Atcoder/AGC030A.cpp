#include <stdio.h>
int main()
{
 int a,b,c;
 scanf("%d%d%d",&a,&b,&c);
 if(a+b+1>=c)printf("%d\n",b+c);
 else printf("%d\n",a+2*b+1);
 return 0;
}