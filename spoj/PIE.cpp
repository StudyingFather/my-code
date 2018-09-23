#include <cstdio>
#include <algorithm>
#define PI 3.1415926535897
using namespace std;
int n,f;
double maxx,a[10010];
bool qgs(double mid)
{
 int js=0;
 for(int i=1;i<=n;i++)
  js+=a[i]/mid;
 if(js>=f+1)return true;
 return false;
}
int main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
  scanf("%d%d",&n,&f);
  for(int i=1;i<=n;i++)
  {
   int p;
   scanf("%d",&p);
   a[i]=p*p*PI;
   if(a[i]>maxx)maxx=a[i];
  }
  sort(a+1,a+n+1);
  double l=0,r=maxx;
  while(r-l>0.0000001)
  {
   double mid=(l+r)/2;
   if(qgs(mid))l=mid;
   else r=mid;
  }
  printf("%.4lf\n",l);
 }
 return 0;
}
