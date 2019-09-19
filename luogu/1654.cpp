#include <cstdio>
double a[100005],b[100005],ans[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  double x;
  scanf("%lf",&x);
  a[i]=(a[i-1]+1)*x;
  b[i]=(b[i-1]+2*a[i-1]+1)*x;
  ans[i]=ans[i-1]+(3*b[i-1]+3*a[i-1]+1)*x;
 }
 printf("%.1lf\n",ans[n]);
 return 0;
}