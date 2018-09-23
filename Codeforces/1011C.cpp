#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],b[1005];
bool is_equal(double x,double y)
{
 return abs(x-y)<=1e-9;
}
double solve(int x,double y)
{
 if(x==1||is_equal(-1,y))return -1;
 return y+y*1.0/(x-1);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 double f=m;
 f=solve(b[1],f);
 f=solve(a[n],f);
 for(int i=n-1;i>=1;i--)
 {
  f=solve(b[i+1],f);
  f=solve(a[i],f);
 }
 if(is_equal(-1,f))printf("-1");
 else printf("%.10lf",f-m);
 return 0;
}
