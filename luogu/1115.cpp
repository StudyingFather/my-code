#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005],sum,maxs=-2000000000;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  sum+=a[i];
  maxs=max(sum,maxs);
  if(sum<0)sum=0;
 }
 printf("%d",maxs);
 return 0;
}
