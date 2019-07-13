#include <cstdio>
#include <algorithm>
#define eqs 1e-6
using namespace std;
int a[100005],b[100005],n,k;
double c[100005];
bool cmp(double x,double y)
{
 return x>y;
}
bool check(double x)
{
 double sum=0;
 for(int i=1;i<=n;i++)
  c[i]=a[i]-x*b[i];
 sort(c+1,c+n+1,cmp);
 for(int i=1;i<=k;i++)
  sum+=c[i];
 return sum>=0;
}
int main()
{
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 double l=0,r=1e11;
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))l=mid;
  else r=mid;
 }
 printf("%.4lf\n",l);
 return 0;
}