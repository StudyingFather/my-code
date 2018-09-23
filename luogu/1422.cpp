#include <stdio.h>
const double c1=0.4463;
const double c2=0.4663;
const double c3=0.5663;
int main()
{
 int a;
 double c;
 scanf("%d",&a);
 if(a<=150)c=a*c1;
 else if(a<=400)c=150*c1+(a-150)*c2;
 else c=150*c1+250*c2+(a-400)*c3;
 printf("%.1lf",c);
 return 0;
}
