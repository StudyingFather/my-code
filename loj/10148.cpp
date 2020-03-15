#include <cstdio>
#include <algorithm>
using namespace std;
int a[205],f[205][205],ans;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  a[i+n]=a[i];
 }
 for(int i=2;i<=2*n;i++)
  for(int j=i-1;i-j<n&&j;j--)
   for(int k=j;k<i;k++)
   {
    f[j][i]=max(f[j][i],f[j][k]+f[k+1][i]+a[j]*a[k+1]*a[i+1]);
    ans=max(ans,f[j][i]);
   }
 printf("%d\n",ans);
 return 0;
}