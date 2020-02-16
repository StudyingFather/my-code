#include <cstdio>
#include <algorithm>
using namespace std;
int p[200005],a[200005];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 a[0]=n+1;
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&p[i]);
  a[i]=min(a[i-1],p[i]);
  ans+=(a[i]==p[i]);
 }
 printf("%d\n",ans);
 return 0;
}