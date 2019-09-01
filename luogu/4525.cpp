/*
 Name: luogu P4525
 Author: StudyingFather
 Date: 2019/08/07 16:00
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
double a,b,c,d,l,r;
double f(double x)
{
 return (c*x+d)/(a*x+b);
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
 scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r);
 printf("%.6lf",asr(l,r,1e-8,simpson(l,r)));
 return 0;
}