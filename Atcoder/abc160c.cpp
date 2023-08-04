#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
 int k,n,ans=0;
 scanf("%d%d",&k,&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 a[n+1]=a[1]+k;
 for(int i=1;i<=n;i++)
  ans=max(ans,a[i+1]-a[i]);
 printf("%d\n",k-ans);
 return 0;
}