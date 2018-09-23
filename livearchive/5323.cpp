#include <stdio.h>
int main()
{
 for(int a=2;a<=200;a++)
  for(int b=2;b<=200;b++)
   for(int c=b;c<=200;c++)
    for(int d=c;d<=200;d++)
     if(a*a*a==b*b*b+c*c*c+d*d*d)printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
 return 0;
}
