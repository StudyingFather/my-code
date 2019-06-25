#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 1e-8 
using namespace std;
double a[15][15],b[15][15],d[15];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n+1;i++)
  for(int j=1;j<=n;j++)
   scanf("%lf",&a[i][j]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   b[i][j]=2*(a[i][j]-a[i+1][j]);
   d[i]+=(a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j]);
  }
 for(int i=1;i<=n;i++)
 {
  for(int j=i;j<=n;j++)
   if(fabs(b[j][i])>eps)
   {
    for(int k=1;k<=n;k++)
     swap(b[i][k],b[j][k]);
    swap(d[i],d[j]);
   }
  for(int j=1;j<=n;j++)
  {
   if(i==j)continue;
   double x=b[j][i]/b[i][i];
   for(int k=1;k<=n;k++)
    b[j][k]-=x*b[i][k];
   d[j]-=d[i]*x;
  }
 }
 for(int i=1;i<=n;i++)
  printf("%.3lf ",d[i]/b[i][i]);
 return 0;
}
