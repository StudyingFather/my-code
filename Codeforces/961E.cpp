#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[200005],ans;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 ans=n*(n-1);
 for(int i=1;i<=n;i++)
  ans-=max(n-a[i],0);
 printf("%d",max(0,(ans+1)/2));
 return 0;
}
