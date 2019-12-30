#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double a;
double f(double x)
{
 return pow(x,a/x-x);
}
double simpson(double l,double r)
{
 double mid=(l+r)/2;
 return (r-l)*(f(l)+4*f(mid)+f(r))/6;
}
double asr(double l,double r,double eqs,double ans)
{
 double mid=(l+r)/2;
 double fl=simpson(l,mid),fr=simpson(mid,r);
 if(abs(fl+fr-ans)<=15*eqs)return fl+fr-(fl+fr-ans)/15;
 return asr(l,mid,eqs/2,fl)+asr(mid,r,eqs/2,fr);
}
int main()
{
 scanf("%lf",&a);
 if(a<0)puts("orz");
 else printf("%.5lf\n",asr(1e-10,15,1e-8,simpson(0,15)));
 return 0;
}