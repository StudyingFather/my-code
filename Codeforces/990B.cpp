#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005],f[1000005];
int main()
{
 int n,k,ans=0;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  f[a[i]]++;
 }
 sort(a+1,a+n+1);
 for(int i=1;i<n;i++)
  if(a[i+1]<=a[i]+k&&a[i+1]>a[i])f[a[i]]=0;
 for(int i=1;i<=1000000;i++)
  ans+=f[i];
 printf("%d",ans);
 return 0;
}
