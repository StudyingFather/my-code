#include <cstdio>
#include <algorithm>
#define INF1 1000000
#define INF2 10000000000
using namespace std;
int n,f,a[100005];
double b[100005],sum[100005];
int main()
{
 scanf("%d%d",&n,&f);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 double l=-INF1,r=INF1,eps=0.00001;
 while(r-l>eps)
 {
  double mid=(l+r)/2;
  for(int i=1;i<=n;i++)
   b[i]=a[i]-mid;//计算与平均值的差
  for(int i=1;i<=n;i++)
   sum[i]=sum[i-1]+b[i];
  double ans=-INF2,minv=INF2;
  for(int i=f;i<=n;i++)
  {
   minv=min(minv,sum[i-f]);
   ans=max(ans,sum[i]-minv);
  }
  if(ans>=0)l=mid;
  else r=mid;
 }
 printf("%d",int(r*1000));
 return 0;
}
