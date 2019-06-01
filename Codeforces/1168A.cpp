#include <cstdio>
#include <algorithm>
using namespace std;
int a[300005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int l=-1,r=m;
 while(l+1<r)
 {
  int mid=(l+r)>>1,pre=0;
  bool flag=true;
  for(int i=1;i<=n;i++)
  {
   int lf=a[i],rf=a[i]+mid;
   if((lf<=pre&&pre<=rf)||(lf<=pre+m&&pre+m<=rf))continue;
   if(pre>lf)
   {
    flag=false;
    break;
   }
   else pre=lf;
  }
  if(!flag)l=mid;
  else r=mid;
 }
 printf("%d\n",r);
 return 0;
}