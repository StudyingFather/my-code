#include <stdio.h>
double a,b,c,d;
double f(double x)
{
 return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
 scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
 for(double x=-10000;x<=10000;x++)
 {
  double x1=(x-0.5)/100,x2=(x+0.5)/100;
  if((f(x1)*f(x2)<0)||(f(x1)==0))printf("%.2lf ",x*1.0/100);
 }
 return 0;
}
