#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],s[105];
int main()
{
 int n,sum=0,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  sum+=a[i];
 }
 sum/=n;
 for(int i=1;i<=n;i++)
 {
  a[i]-=sum;
  s[i]=s[i-1]+a[i];
 }
 sort(s+1,s+n+1);
 for(int i=1;i<=n;i++)
  ans+=abs(s[n/2+1]-s[i]);
 printf("%d\n",ans);
 return 0;
}