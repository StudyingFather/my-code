#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],f1[105],f2[105];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  f1[i]=f2[i]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   if(a[i]>a[j])f1[i]=max(f1[j]+1,f1[i]);
 for(int i=n;i>=1;i--)
  for(int j=n;j>i;j--)
   if(a[j]<a[i])f2[i]=max(f2[j]+1,f2[i]);
 for(int i=1;i<=n;i++)
  ans=max(ans,f1[i]+f2[i]);
 printf("%d\n",n-ans+1);
 return 0;
}
