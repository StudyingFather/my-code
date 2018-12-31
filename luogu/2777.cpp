#include <cstdio>
#include <algorithm>
using namespace std;
int a[300005],b[300005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 sort(b+1,b+n+1);
 for(int i=1;i<=n;i++)
  a[i]=b[i]+n-i+1;
 int maxs=0,ans=0;
 for(int i=1;i<=n;i++)
  maxs=max(maxs,a[i]);
 for(int i=n;i>=1;i--)
  if(b[i]+n>=maxs)ans++;
  else break;
 printf("%d\n",ans);
 return 0;
}
