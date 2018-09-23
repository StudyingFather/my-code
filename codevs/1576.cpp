#include <cstdio>
#include <algorithm>
using namespace std;
int f[5005],a[5005],ans;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  f[i]=1;
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
  {
   if(a[i]>a[j])f[i]=max(f[j]+1,f[i]);
   ans=max(f[i],ans);
  }
 printf("%d",ans);
 return 0;
}
