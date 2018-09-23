#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],f1[105],f2[105],n;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  f1[i]=f2[i]=1;
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
   if(a[i]>a[j])f1[i]=max(f1[i],f1[j]+1);
 for(int i=n;i>=1;i--)
  for(int j=i+1;j<=n;j++)
   if(a[i]>a[j])f2[i]=max(f2[i],f2[j]+1);
 int ans=n;
 for(int i=1;i<=n;i++)
  ans=min(ans,n-f1[i]-f2[i]+1);
 printf("%d",ans);
 return 0;
}
