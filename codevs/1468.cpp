#include <stdio.h>
#include <math.h>
double p,s,a,b,c;
double area(double a,double b,double c)
{
 p=(a+b+c)/2;
 return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
 scanf("%lf%lf%lf",&a,&b,&c);
 if(a+b<=c||b+c<=a||c+a<=b)puts("No answer");
 else printf("%.2lf",area(a,b,c));
 return 0;
}
