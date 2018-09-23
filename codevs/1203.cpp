#include <stdio.h>
#include <math.h>
double a,b;
int main()
{
 scanf("%lf%lf",&a,&b);
 if(fabs(a-b)<=0.00000001)printf("yes");
 else printf("no");
 return 0;
}
