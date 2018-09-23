#include <stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 for(int a=2;a<=n;a++)
  for(int b=2;b<=n;b++)
   for(int c=b;c<=n;c++)
    for(int d=c;d<=n;d++)
     if(a*a*a==b*b*b+c*c*c+d*d*d)printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
 return 0;
}
