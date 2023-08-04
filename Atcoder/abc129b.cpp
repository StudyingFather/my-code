#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],sum,s1;
int main()
{
 int n,ans=100000;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  sum+=a[i];
 }
 for(int i=1;i<=n;i++)
 {
  s1+=a[i];
  ans=min(ans,abs(2*s1-sum));
 }
 printf("%d\n",ans);
 return 0;
}