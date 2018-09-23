#include <cstdio>
#include <algorithm>
using namespace std;
int p[100005],a[100005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 a[1]=max(0,a[1]-k+1);
 for(int i=2;i<=n;i++)
  if(a[i]-a[i-1]<=k-1&&a[i-1]<=a[i])a[i]=a[i-1];
  else if(a[i]-a[i+1]<=k-1&&a[i+1]<=a[i])a[i]=min(a[i],a[i+1]);
  else a[i]=max(0,a[i]-k+1);
 for(int i=1;i<=n;i++)
  printf("%d ",a[i]);
 return 0;
}
