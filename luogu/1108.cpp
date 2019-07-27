#include <cstdio>
#include <algorithm>
using namespace std;
int a[5005],f[5005],g[5005],n;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  f[i]=1;
 }
 int ans1=1,ans2=0;
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
  {
   if(a[i]<a[j])f[i]=max(f[i],f[j]+1);
   ans1=max(ans1,f[i]);
  }
 for(int i=1;i<=n;i++)
 {
  if(f[i]==1)g[i]=1;
  for(int j=1;j<i;j++)
   if(f[i]==f[j]+1&&a[i]<a[j])g[i]+=g[j];
   else if(f[i]==f[j]&&a[i]==a[j])g[i]=0;
  if(f[i]==ans1)ans2+=g[i];
 }
 printf("%d %d\n",ans1,ans2);
 return 0;
}