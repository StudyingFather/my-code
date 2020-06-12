#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005],ans;
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  a[i]+=a[i-1];
 }
 for(int i=k+1;i<=n;i++)
  ans=max(ans,a[i]-a[i-k-1]);
 printf("%d\n",ans);
 return 0;
}