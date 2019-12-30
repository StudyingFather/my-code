#include <cstdio>
#include <algorithm>
using namespace std;
double p[1000005],ans;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%lf",&p[i]);
  p[i]/=1e6;
  ans=max(ans,p[i]);
 }
 double x=1,y=0;
 for(int l=1,r=0;l<=n;l++)
 {
  while(r<n&&y<1)
  {
   r++;
   x*=1-p[r],y+=p[r]/(1-p[r]);
  }
  ans=max(ans,x*y);
  x/=1-p[l],y-=p[l]/(1-p[l]);
 }
 printf("%d\n",int(ans*1e6));
 return 0;
}