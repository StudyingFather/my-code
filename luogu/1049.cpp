#include <cstdio>
#include <algorithm>
using namespace std;
int a[35],f[20005],ans;
int main()
{
 int v,n;
 scanf("%d",&v);
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  for(int j=v;j>=a[i];j--)
   f[j]=max(f[j-a[i]]+a[i],f[j]),ans=max(f[j],ans);
 printf("%d",v-ans);
 return 0;
}
